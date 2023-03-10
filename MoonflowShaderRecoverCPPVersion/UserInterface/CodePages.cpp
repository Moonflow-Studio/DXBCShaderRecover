#include "CodePages.h"

#include <fstream>
#include <iostream>


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
            selection_result = false;
        }
        if(ImGui::TabItemButton(sideMode ? "Fragment" : "Source Fragment"))
        {
            source_show_ = &source_code_p;
            selection_result = false;
        }
        if(!sideMode)
        {
            if(ImGui::TabItemButton("Result Vertex"))
            {
                result_show_ = &result_code_v;
                selection_result = true;
            }
            if(ImGui::TabItemButton("Result Fragment"))
            {
                result_show_ = &result_code_p;
                selection_result = true;
            }
        }
        ImGui::EndTabBar();
    }

    if(sideMode)
    {
        ImGui::Columns(2);
        source_text_area();
        ImGui::NextColumn();
        result_text_area();
        ImGui::EndColumns();
    }
    else
    {
        if(!selection_result)
        {
            source_text_area();
        }
        else
        {
            result_text_area();
        }
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
    OPENFILENAME ofn = { 0 };       // common dialog box structure
    WCHAR szFile[260];       // buffer for file name 
    HWND hwnd;              // owner window
    HANDLE hf;              // file handle

    // Initialize OPENFILENAME
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = nullptr;
    ofn.lpstrFile = szFile;
    // Set lpstrFile[0] to '\0' so that GetOpenFileName does not 
    // use the contents of szFile to initialize itself.
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = reinterpret_cast<LPCWSTR>("All\0*.*\0Text\0*.TXT\0");
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    // Display the Open dialog box. 

    if (GetOpenFileName(&ofn)==true)
    {
         //?????????????????????????????????????????????ifstream??????open
    }
    
    try
    {
        std::string data;
        std::string onfind;
        std::ifstream infile;

        infile.open(szFile, std::ios::in);
        if(!infile.is_open())
        {
            std::cout<<"fail read data"<<std::endl;
        }
        else
        {
            while(std::getline(infile, onfind))
            {
                // infile>>data;
                std::cout<<onfind<<std::endl;
                data.append(onfind + '\n');
            }
        }
        infile.close();
        
        return data;
    }
    catch (...)
    {
        return "have something wrong opening file";
    }
    
     return test ? "test source Vertex" : "test source Fragment";
}

