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

    bool is_active = true;
    
    void show_page();
    std::string source_code_v = "None Source Vertex Code";
    std::string source_code_p = "None Source Fragment Code";
    std::string result_code_v = "None Result Vertex Code";
    std::string result_code_p = "None Result Fragment Code";

private:
    CodePageLayoutType layout_type_ = FullScreen;
    ImVec2 size_ = {600, 400};
    bool is_init_ = false;
    bool selection_result = false;
    std::string* source_show_ = nullptr;
    std::string* result_show_ = nullptr;
    static void read_source_text(TextCodeType type);
    static std::string read_file(bool);

    // void (CodePages::*single_text_area)() = nullptr;
    void result_text_area();
    void source_text_area();
};
