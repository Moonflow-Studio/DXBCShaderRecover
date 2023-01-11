#include "CodePages.h"




void CodePages::ShowPage()
{
    ImGui::Begin("Codes", &isActive, ImGuiWindowFlags_MenuBar);
    
    //Set Page
    if(!isInit)
    {
        ImGui::SetWindowSize(size);
        isInit = true;
    }
    
    bool sideMode = layoutType == Side;
    //Set Menu
    if(ImGui::BeginMenuBar())
    {
        if(ImGui::BeginMenu("File"))
        {
            if(ImGui::MenuItem("Open Source Vertex Shader Code", "Shift+Alt+v"))
            {
                // CodePages::SourceCodeV.clear();
                // SourceCodeV.append(ReadFile());
            }
            if(ImGui::MenuItem("Open Source Fragment Shader Code", "Shift+Alt+f"))
            {
                // SourceCodeP = ReadFile();
            }
            ImGui::EndMenu();
        }
        if(ImGui::BeginMenu("View Mode"))
        {
            if(ImGui::MenuItem(sideMode ? "** Sync View **" : "Sync View", "Shift+Alt+v")){layoutType = Side;}
            if(ImGui::MenuItem(sideMode ? "Single View" : "** Single View **", "Shift+Alt+f")){layoutType = FullScreen;}
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }
    
    //Current View Menu
    {
        ImGui::BeginTabBar("Current View");
        if(ImGui::TabItemButton(sideMode ? "Vertex" : "Source Vertex"))
        {
            // sourceShow = SourceCodeV;
        }
        if(ImGui::TabItemButton(sideMode ? "Fragment" : "Source Fragment"))
        {
            // sourceShow = SourceCodeP;
        }
        if(!sideMode)
        {
            if(ImGui::TabItemButton("Result Vertex"))
            {
            }
            if(ImGui::TabItemButton("Result Fragment"))
            {
            }
        }
        ImGui::EndTabBar();
    }
    ImGui::End();
}

void CodePages::ReadSourceText(TextCodeType type)
{
    switch (type)
    {
        case TextCodeType::Vertex:{}break;
        case TextCodeType::Fragment:{}break;
        default:break;
    }
}

std::string CodePages::ReadFile()
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
     return "test source";
}

