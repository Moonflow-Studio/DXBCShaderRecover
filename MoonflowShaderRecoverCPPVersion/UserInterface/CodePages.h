#pragma once
#include <string>

#include "../imgui/imgui.h"
// #include <commdlg.h>
// #include <fileapi.h>
// #include <iostream>
// #include <minwinbase.h>
// #include <winnt.h>

#include "../imgui/imgui_impl_win32.h"
#include "../imgui/imgui_impl_dx11.h"
#include "../imgui/imgui_internal.h"
#include "../d3d/ImGuiD3DHelper.h"

class CodePages
{
public:
    enum CodePageLayoutType
    {
        FullScreen,
        Side,
    };
    enum TextCodeType
    {
        Vertex,
        Fragment
    };
    static std::string SourceCodeV;
    static std::string SourceCodeP;
    bool isActive = true;
    void ShowPage();

private:
    CodePageLayoutType layoutType;
    ImVec2 size = {600, 400};
    bool isInit = false;
    std::string sourceShow;
    std::string resultShow;
    void ReadSourceText(TextCodeType type);
    std::string ReadFile();
};
