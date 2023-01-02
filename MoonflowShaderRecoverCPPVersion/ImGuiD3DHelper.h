#pragma once
#include "imgui/imgui.h"
#include <d3d11.h>
#include <tchar.h>


class ImGuiD3DHelper
{

public:
    static bool CreateDeviceD3D(HWND hWnd, ID3D11Device* g_pd3dDevice, ID3D11DeviceContext* g_pd3dDeviceContext);
    
    static void CleanupDeviceD3D(ID3D11Device* g_pd3dDevice, ID3D11DeviceContext* g_pd3dDeviceContext);
    
    static void CreateRenderTarget(ID3D11Device* g_pd3dDevice);

    static void CleanupRenderTarget();
    
};
