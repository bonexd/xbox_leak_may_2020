/*******************************************************************************

Copyright (c) 2000 Microsoft Corporation.  All rights reserved.

File Name:

    test.cpp

Description:

    Test functions.

*******************************************************************************/

#include <xtl.h>
#include <tchar.h>
#include <stdio.h>
#include <math.h>
#include <xgraphics.h>
#include <xgmath.h>
#include "test.h"

//******************************************************************************
// main
//******************************************************************************

//******************************************************************************
//
// Function:
//
//     main
//
// Description:
//
//     Entry point for the application.
//
// Arguments:
//
//     None.
//
// Return Value:
//
//     None.
//
//******************************************************************************
void __cdecl main()
{
    CTest* pTest;

    // Seed the pseudo-random number generator
    srand(GetTickCount());

    pTest = new CTest();
    if (!pTest) {
        return;
    }

    if (!pTest->Create()) {
        DebugString(TEXT("CTest::Create failed"));
        delete pTest;
        return;
    }

    pTest->Run();

    delete pTest;
}

//******************************************************************************
CTest::CTest() {

    m_pd3d = NULL;
    m_pDevice = NULL;
    m_pd3dr = NULL;
}

//******************************************************************************
CTest::~CTest() {

    ReleaseScene();

    if (m_pd3d) {
        m_pd3d->Release();
        m_pd3d = NULL;
    }
}

//******************************************************************************
void CTest::ReleaseScene() {

    if (m_pd3dr) {
        m_pd3dr->Release();
        m_pd3dr = NULL;
    }

    if (m_pDevice) {
        m_pDevice->Release();
        m_pDevice = NULL;
    }
}

//******************************************************************************
BOOL CTest::Create() {

    m_pd3d = Direct3DCreate8(D3D_SDK_VERSION);
    if (!m_pd3d) {
        DebugString(TEXT("Direct3DCreate8 failed"));
        return FALSE;
    }

    return TRUE;
}

//******************************************************************************
BOOL CTest::CreateScene() {

    D3DPRESENT_PARAMETERS   d3dpp;
    D3DVIEWPORT8            viewport = {0, 0, 640, 480, 0.0f, 1.0f};
    XGMATRIX                mTransform;
    PLVERTEX                plrVertices;
    HRESULT                 hr;

    // Initialize the presentation parameters
    memset(&d3dpp, 0, sizeof(D3DPRESENT_PARAMETERS));
    d3dpp.BackBufferWidth                   = 640;
    d3dpp.BackBufferHeight                  = 480;
    d3dpp.BackBufferFormat                  = D3DFMT_A8R8G8B8;
    d3dpp.MultiSampleType                   = D3DMULTISAMPLE_NONE;
    d3dpp.AutoDepthStencilFormat            = D3DFMT_D24S8;
    d3dpp.FullScreen_RefreshRateInHz        = 0;
    d3dpp.FullScreen_PresentationInterval   = D3DPRESENT_INTERVAL_ONE;
    d3dpp.BackBufferCount                   = 1;
    d3dpp.SwapEffect                        = D3DSWAPEFFECT_DISCARD;
    d3dpp.hDeviceWindow                     = NULL;
    d3dpp.Windowed                          = FALSE;
    d3dpp.EnableAutoDepthStencil            = TRUE;

    // Create the device
    hr = m_pd3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, NULL, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &m_pDevice);
    if (ResultFailed(hr, TEXT("IDirect3D8::CreateDevice failed"))) {
        return FALSE;
    }

    // Set a viewport
    hr = m_pDevice->SetViewport(&viewport);
    if (ResultFailed(hr, TEXT("IDirect3DDevice8::SetViewport"))) {
        return FALSE;
    }

    // Initialize the view matrix
    XGMatrixLookAtLH(&mTransform, &XGVECTOR3(0.0f, 0.0f, -50.0f), &XGVECTOR3(0.0f, 0.0f, 0.0f), &XGVECTOR3(0.0f, 1.0f, 0.0f));
    hr = m_pDevice->SetTransform(D3DTS_VIEW, &mTransform);
    if (FAILED(hr)) {
        DebugString(TEXT("IDirect3DDevice8::SetTransform failed"));
    }

    // Initialize the projection matrix
    XGMatrixPerspectiveFovLH(&mTransform, 3.14159f / 4.0f, 640.0f / 480.0f, 0.1f, 1000.0f);
    hr = m_pDevice->SetTransform(D3DTS_PROJECTION, &mTransform);
    if (FAILED(hr)) {
        DebugString(TEXT("IDirect3DDevice8::SetTransform failed"));
    }

    hr = m_pDevice->CreateVertexBuffer(3 * sizeof(LVERTEX), 0, FVF_LVERTEX, D3DPOOL_DEFAULT, &m_pd3dr);
    if (ResultFailed(hr, TEXT("IDirect3DDevice8::CreateVertexBuffer"))) {
        return FALSE;
    }

    hr = m_pd3dr->Lock(0, 3 * sizeof(LVERTEX), (LPBYTE*)&plrVertices, 0);
    if (ResultFailed(hr, TEXT("IDirect3DVertexBuffer8::Lock"))) {
        return FALSE;
    }

    plrVertices[0] = LVERTEX(XGVECTOR3(-10.0f, -10.0f, 0.0f), D3DCOLOR_RGBA(255, 0, 0, 255), 0, 0.0f, 0.0f);
    plrVertices[1] = LVERTEX(XGVECTOR3(  0.0f,  10.0f, 0.0f), D3DCOLOR_RGBA(0, 0, 255, 255), 0, 0.0f, 0.0f);
    plrVertices[2] = LVERTEX(XGVECTOR3( 10.0f, -10.0f, 0.0f), D3DCOLOR_RGBA(0, 255, 0, 255), 0, 0.0f, 0.0f);

    hr = m_pd3dr->Unlock();
    if (ResultFailed(hr, TEXT("IDirect3DVertexBuffer8::Unlock"))) {
        return FALSE;
    }

    return TRUE;
}

/*
//******************************************************************************
BOOL CTest::Run() {

    int   KickOffSizeExponent = 15; // 2 ^ 15 = 32768 = default
    int   PushBufferSizeMultiple = 16; // 32768 * 16 = 524288 = default
    DWORD dwKickOffSize;
    DWORD dwPushBufferSize;
    int   i, j;

    for (i = KickOffSizeExponent; i >= 0; i--) {

        dwKickOffSize = 0x1 << i;

        for (j = PushBufferSizeMultiple; j > 0; j--) {

            dwPushBufferSize = dwKickOffSize * j;

            DebugString(TEXT("Push buffer size: %d, kick off size: %d"), dwPushBufferSize, dwKickOffSize);

            m_pd3d->SetPushBufferSize(dwPushBufferSize, dwKickOffSize);

            if (!CreateScene()) {
                break;
            }
            if (!DisplayScene()) {
                break;
            }
            ReleaseScene();
        }
    }

    return TRUE;
}
*/

//******************************************************************************
BOOL CTest::Run() {

    int   KickOffSizeExponent = 15; // 2 ^ 15 = 32768 = default
    int   PushBufferSizeMultiple = 16; // 32768 * 16 = 524288 = default
    DWORD dwKickOffSize;
    DWORD dwPushBufferSize;
    int   i, j;

    for (i = KickOffSizeExponent; i > 10; i--) {

        dwKickOffSize = 0x1 << i;

        for (j = PushBufferSizeMultiple + 65536 / dwKickOffSize; j > 3 && dwKickOffSize * j >= 65536; j--) {

            dwPushBufferSize = dwKickOffSize * j;

            DebugString(TEXT("Push buffer size: %d, kick off size: %d"), dwPushBufferSize, dwKickOffSize);

            m_pd3d->SetPushBufferSize(dwPushBufferSize, dwKickOffSize);

            if (!CreateScene()) {
                break;
            }
            if (!DisplayScene()) {
                break;
            }
            ReleaseScene();
        }
    }

    return TRUE;
}

//******************************************************************************
BOOL CTest::DisplayScene() {

    UINT i;

    for (i = 0; i < 60; i++) {

        // Clear the rendering target
        m_pDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0, 1.0f, 0);

        // Begin the scene
        m_pDevice->BeginScene();

        // Disable lighting
        m_pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

        // Use a fixed function shader
        m_pDevice->SetVertexShader(FVF_LVERTEX);

        m_pDevice->SetStreamSource(0, m_pd3dr, sizeof(LVERTEX));

        // Draw a triangle
        m_pDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);

        // End the scene
        m_pDevice->EndScene();

        // Update the screen
        m_pDevice->Present(NULL, NULL, NULL, NULL);

    }

    return TRUE;
}

//******************************************************************************
//
// Function:
//
//     DebugString
//
// Description:
//
//     Take the formatted output and send the output to the debugger.
//
// Arguments:
//
//     LPCTSTR szFormat         - Formatting string describing the output
//
//     Variable argument list   - Data to be placed in the output string
//
// Return Value:
//
//     None.
//
//******************************************************************************
void DebugString(LPCTSTR szFormat, ...) {

    va_list vl;
    TCHAR*  szBuffer = (LPTSTR)HeapAlloc(GetProcessHeap(), 0, 2304 * sizeof(TCHAR));
    if (!szBuffer) {
        OutputDebugString(TEXT("Insufficient memory for logging buffer allocation\n"));
        __asm int 3;
    }

    va_start(vl, szFormat);
    _vstprintf(szBuffer, szFormat, vl);
    va_end(vl);

    _tcscat(szBuffer, TEXT("\r\n"));

    OutputDebugString(szBuffer);

    HeapFree(GetProcessHeap(), 0, szBuffer);
}

//******************************************************************************
//
// Function:
//
//     ResultFailed
//
// Description:
//
//     Test a given return code: if the code is an error, output a debug 
//     message with the error value.  If the code is a warning, output
//     a debug message with the warning value.
//
// Arguments:
//
//     HRESULT hr               - Return code to test for an error
//
//     LPCTSTR sz               - String describing the method that produced 
//                                the return code
//
// Return Value:
//
//     TRUE if the given return code is an error, FALSE otherwise.
//
//******************************************************************************
BOOL ResultFailed(HRESULT hr, LPCTSTR sz) {

    TCHAR szError[256];

    if (SUCCEEDED(hr)) {
        return FALSE;
    }

//    XGGetErrorString(hr, szError, 256);

    if (FAILED(hr)) {
        DebugString(TEXT("%s failed with %s [0x%X]"), sz, szError, hr);
        return TRUE;
    }
    else {
        DebugString(TEXT("%s returned %s [0x%X]"), sz, szError, hr);
    }

    return FALSE;
}