#pragma once
#include "../imgui/imgui.h"
#include <d3d11.h>
#include <tchar.h>

static ID3D11Device*            g_pd3dDevice/* = NULL*/;
static ID3D11DeviceContext*     g_pd3dDeviceContext/* = NULL*/;
static IDXGISwapChain*          g_pSwapChain/* = NULL*/;
static ID3D11RenderTargetView*  g_mainRenderTargetView/* = NULL*/;


void CreateRenderTarget();
void CleanupRenderTarget();
bool CreateDeviceD3D(HWND hWnd, IDXGISwapChain** pSwapChain, ID3D11Device** pd3dDevice, ID3D11DeviceContext**  pd3dDeviceContext);
void CleanupDeviceD3D();

