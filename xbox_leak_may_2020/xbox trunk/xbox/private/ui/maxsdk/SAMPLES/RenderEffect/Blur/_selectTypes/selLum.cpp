/* -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------

   FILE: selLum.cpp

	 DESCRIPTION: luminance selection type - class definitions

	 CREATED BY: michael malone (mjm)

	 HISTORY: created November 4, 1998

	 Copyright (c) 1998, All Rights Reserved

// -----------------------------------------------------------------------------
// -------------------------------------------------------------------------- */

// precompiled header
#include "pch.h"

// local includes
#include "selLum.h"
#include "..\blurMgr.h"


SelLum::~SelLum()
{
	if (mp_radMap)
		delete[] mp_radMap;
}

void SelLum::notifyPrmChanged(int prmID)
{
	switch (prmID)
	{
		case prmLumMin:
		case prmLumMax:
			m_selectValid = m_featherValid = m_compValid = false;
			break;
		case prmLumFeathRad:
		{
			for (int i=0; i<m_imageSz; i++)
			{
				if ( mp_radMap[i] > 0.0f )
					mp_radMap[i] = 1.0f;
			}
			m_featherValid = m_compValid = false;
			break;
		}
		case prmLumBrighten:
		case prmLumBlend:
			m_compValid = false;
			break;
	}
}

bool SelLum::doSelect()
{
	float lum;
	int mapIndex, srcIndex;
	mp_nameCurProcess = GetString(IDS_PROCESS_SELECT);

	int interval = 3*m_imageW;
	for (mapIndex=0; mapIndex<m_imageSz; mapIndex++)
	{
		srcIndex = mapIndex*3;
		lum = luminanceNormFloat(mp_srcMap[srcIndex], mp_srcMap[srcIndex+1], mp_srcMap[srcIndex+2]); // grabs specular hilights better than max(r,g,b)
		if ((lum >= m_min) && (lum <= m_max))
			mp_radMap[mapIndex] = 0.0f;
		else
			mp_radMap[mapIndex] = 1.0f;
		if ( ( (mapIndex%interval) == 0 ) && mp_blurMgr->progress(mp_nameCurProcess, mapIndex, m_imageSz) )
			return false;
	}
	return true;
}

bool SelLum::doFeather()
{
	mp_nameCurProcess = GetString(IDS_PROCESS_FEATHER);

	// NOTE: there is _alot_ of room for optimization in this function

	// compute normalized radii mask for feathered pixels
	if (m_normRadMaskW != 2*m_feathRad + 1) {
		if (m_normRadMask)
			delete[] m_normRadMask;
		m_normRadMaskW = m_normRadMaskH = 2*m_feathRad + 1;
		m_normRadMask = new float[m_normRadMaskW*m_normRadMaskH];
		int index = -1;
		float x_dist, y_dist;
		for (int i=0; i<m_normRadMaskW; i++) {
			for (int j=0; j<m_normRadMaskH; j++) {
				x_dist = (float)i-m_feathRad;
				y_dist = (float)j-m_feathRad;
				m_normRadMask[++index] = (float)(sqrt(sqr(x_dist)+sqr(y_dist)) / (float)m_feathRad);
				m_normRadMask[index] = (m_normRadMask[index] > 1.0f) ? 1.0f : m_normRadMask[index];
			}
		}
	}

	// find feathered pixels
	int index, normRadIdx;
	int interval = 3*m_imageW;
	for (int mapIndex=0; mapIndex<m_imageSz; mapIndex++)
	{
		if (mp_radMap[mapIndex] == 0.0f) // a selected pixel
		{
			int y = mapIndex / m_imageW;
			int x = mapIndex % m_imageW;

			// skip pixel if surrounded by other selected pixels
			// lots of opportunity to optimize, but no time
			if (
				 ( ( x>0 )			&& (mp_radMap[mapIndex-1] == 0.0f) ) &&
				 ( ( x<m_imageW-1 ) && (mp_radMap[mapIndex+1] == 0.0f) ) &&
				 ( ( y>0 )			&& (mp_radMap[mapIndex-m_imageW] == 0.0f) ) &&
				 ( ( y<m_imageH-1 ) && (mp_radMap[mapIndex+m_imageW] == 0.0f) )
			   )
			   continue;
			
			// set offset and weight of the feathered pixels
			for (int v=-m_feathRad; v<=m_feathRad; v++)
			{
				for (int u=-m_feathRad; u<=m_feathRad; u++)
				{
					if ( !inBounds(x+u, y+v, m_imageW, m_imageH) )
						continue;

					// compute offsets
					index = (mapIndex + v*m_imageW + u);
					if (mp_radMap[index] != 0.0f)
					{
						normRadIdx = (u+m_feathRad) + (v+m_feathRad)*m_normRadMaskW;
						mp_radMap[index] = min(mp_radMap[index], m_normRadMask[normRadIdx]);
					}
				}
			}
		}
		if ( ( (mapIndex%interval) == 0 ) && mp_blurMgr->progress(mp_nameCurProcess, mapIndex, m_imageSz) )
			return false;
	}
	return true;
}

bool SelLum::doComposite(CompMap &compMap)
{
	// should hook up a curve control here for falloffs
	for (int mapIndex=0; mapIndex<m_imageSz; mapIndex++)
	{
		if ( mp_radMap[mapIndex] < 1.0f )
		{
			compMap[mapIndex].brighten = max( compMap[mapIndex].brighten, calcBrighten(mp_radMap[mapIndex]) );
			compMap[mapIndex].blend = max( compMap[mapIndex].blend, calcBlend(mp_radMap[mapIndex]) );
		}
	}
	return true;
}

void SelLum::select(TimeValue t, CompMap &compMap, Bitmap *bm, RenderGlobalContext *gc)
{
	float fTemp;
	int type;

	mp_srcAlpha = (WORD*)bm->GetAlphaPtr(&type);
	mp_srcMap = (WORD*)bm->GetStoragePtr(&type);
	assert(type == BMM_TRUE_48);

	// if source bitmap has changed since last call
	if ( m_lastBMModifyID != bm->GetModifyID() )
	{
		m_lastBMModifyID = bm->GetModifyID();
		m_selectValid = m_featherValid = m_compValid = false;
		if ( (bm->Width() != m_imageW) || (bm->Height() != m_imageH) )
		{
			m_imageW = bm->Width();
			m_imageH = bm->Height();
			m_imageSz = m_imageW * m_imageH;
			if (m_imageSz > m_mapSz)
			{
				if (mp_radMap)
					delete[] mp_radMap;
				mp_radMap = new float[m_imageSz];
				m_mapSz = m_imageSz;
			}
		}
	}

	if (!m_selectValid)
	{
		mp_blurMgr->getSelValue(prmLumMin, t, fTemp, FOREVER);
		LimitValue(fTemp, 0.0f, 100.0f); // mjm - 9.30.99
		m_min = fTemp*PERCENT2DEC;

		mp_blurMgr->getSelValue(prmLumMax, t, fTemp, FOREVER);
		LimitValue(fTemp, 0.0f, 100.0f); // mjm - 9.30.99
		m_max = fTemp*PERCENT2DEC;

		m_selectValid = doSelect();
	}
	
	if (!m_featherValid)
	{
		mp_blurMgr->getSelValue(prmLumFeathRad, t, fTemp, FOREVER);
		LimitValue(fTemp, 0.0f, 1000.0f); // mjm - 9.30.99
		m_feathRad = (int)floor(max(m_imageW, m_imageH)*(fTemp*PERCENT2DEC));
		m_featherValid = SelLum::doFeather();
	}

	mp_blurMgr->getSelValue(prmLumBrighten, t, fTemp, FOREVER);
	LimitValue(fTemp, 0.0f, 1000.0f); // mjm - 9.30.99
	m_brighten = fTemp*PERCENT2DEC;

	mp_blurMgr->getSelValue(prmLumBlend, t, fTemp, FOREVER);
	LimitValue(fTemp, 0.0f, 100.0f); // mjm - 9.30.99
	m_blend = fTemp*PERCENT2DEC;

	m_compValid = SelLum::doComposite(compMap);
}