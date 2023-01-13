#include "CodePages.h"


void CodePages::result_text_area()
{
    if(result_show_ != nullptr)
    {
        ImGui::Text(result_show_ -> c_str());
    }else
    {
        ImGui::Text("No Result Code");
    }
}

void CodePages::source_text_area()
{
    if(source_show_ != nullptr)
    {
        ImGui::Text(source_show_ -> c_str());
    }
    else
    {
        ImGui::Text("No source code");
    }
}

void CodePages::show_page()
{
    ImGui::Begin("Codes", &is_active, ImGuiWindowFlags_MenuBar);
    
    //Set Page
    if(!is_init_)
    {
        ImGui::SetWindowSize(size_);
        is_init_ = true;
    }
    
    bool sideMode = layout_type_ == Side;
    
    //Set Menu
    if(ImGui::BeginMenuBar())
    {
        if(ImGui::BeginMenu("File"))
        {
            if(ImGui::MenuItem("Open Source Vertex Shader Code", "Shift+Alt+v"))
            {
                // CodePages::SourceCodeV.clear();
                // SourceCodeV.append(ReadFile());
                source_code_v = std::string(read_file(true));
            }
            if(ImGui::MenuItem("Open Source Fragment Shader Code", "Shift+Alt+f"))
            {
                source_code_p = std::string(read_file(false));
            }
            ImGui::EndMenu();
        }
        if(ImGui::BeginMenu("View Mode"))
        {
            if(ImGui::MenuItem(sideMode ? "** Sync View **" : "Sync View", "Shift+Alt+v")){layout_type_ = Side;}
            if(ImGui::MenuItem(sideMode ? "Single View" : "** Single View **", "Shift+Alt+f")){layout_type_ = FullScreen;}
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }
    
    //Current View Menu
    {
        ImGui::BeginTabBar("Current View");
        if(ImGui::TabItemButton(sideMode ? "Vertex" : "Source Vertex"))
        {
            source_show_ = &source_code_v;
            // single_text_area = source_text_area;
        }
        if(ImGui::TabItemButton(sideMode ? "Fragment" : "Source Fragment"))
        {
            source_show_ = &source_code_p;
            // single_text_area = source_text_area;
        }
        if(!sideMode)
        {
            if(ImGui::TabItemButton("Result Vertex"))
            {
                result_show_ = &result_code_v;
                // single_text_area = result_text_area;
            }
            if(ImGui::TabItemButton("Result Fragment"))
            {
                result_show_ = &result_code_p;
                // single_text_area = result_text_area;
            }
        }
        ImGui::EndTabBar();
    }

    if(sideMode)
    {
        ImGui::Columns(2);
        result_text_area();
        source_text_area();
        ImGui::EndColumns();
    }
    else
    {
        // if(single_text_area!=nullptr)
            // single_text_area();
    }
    
    ImGui::End();
}

void CodePages::read_source_text(TextCodeType type)
{
    switch (type)
    {
        case TextCodeType::Vertex:{}break;
        case TextCodeType::Fragment:{}break;
        default:break;
    }
}

std::string CodePages::read_file(bool test)
{
//     OPENFILENAME ofn = { 0 };       // common dialog box structure
//     WCHAR szFile[260];       // buffer for file name 
//     HWND hwnd;              // owner window
//     HANDLE hf;              // file handle
//
//     // Initialize OPENFILENAME
//     ZeroMemory(&ofn, sizeof(ofn));
//     ofn.lStructSize = sizeof(ofn);
//     ofn.hwndOwner = hwnd;
//     ofn.lpstrFile = szFile;
//     // Set lpstrFile[0] to '\0' so that GetOpenFileName does not 
//     // use the contents of szFile to initialize itself.
//     ofn.lpstrFile[0] = '\0';
//     ofn.nMaxFile = sizeof(szFile);
//     ofn.lpstrFilter = "All\0*.*\0Text\0*.TXT\0";
//     ofn.nFilterIndex = 1;
//     ofn.lpstrFileTitle = NULL;
//     ofn.nMaxFileTitle = 0;
//     ofn.lpstrInitialDir = NULL;
//     ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
//
//     // Display the Open dialog box. 
//
//     if (GetOpenFileName(&ofn)==true) 
//         hf = CreateFile(ofn.lpstrFile, 
//                         GENERIC_READ,
//                         0,
//                         (LPSECURITY_ATTRIBUTES) NULL,
//                         OPEN_EXISTING,
//                         FILE_ATTRIBUTE_NORMAL,
//                         (HANDLE) NULL);
     return test ? "test source Vertex" : "test source Fragment";
}

