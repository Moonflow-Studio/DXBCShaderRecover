#include "CodePages.h"

#include <iostream>

#include "../imgui/imgui_impl_win32.h"
#include "../imgui/imgui_impl_dx11.h"
#include "../imgui/imgui_internal.h"

void CodePages::ShowPage()
{
    ImGui::Begin("Codes"/*, &isActive, ImGuiWindowFlags_MenuBar*/);
    
    //Set Page
    if(!isInit)
    {
        ImGui::SetWindowSize(size);
        isInit = true;
    }
    
    //Set Menu
    if(ImGui::BeginMenuBar())
    {
        if(ImGui::BeginMenu("File"))
        {
            if(ImGui::MenuItem("Open Source Vertex Shader Code", "Shift+Alt+v")){}
            if(ImGui::MenuItem("Open Source Fragment Shader Code", "Shift+Alt+f")){}
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }

    //View Mode Menu
    ImGui::BeginColumns("View Mode", 2, ImGuiOldColumnFlags_None);
    if(ImGui::Button("Sync View"))
    {
        layoutType = Side;
        std::cout<< "Set To Side View"<<std::endl;
    }
    ImGui::NextColumn();
    if(ImGui::Button("Single View"))
    {
        layoutType = FullScreen;
        std::cout<< "Set To FullScreen View"<<std::endl;
    }
    ImGui::EndColumns();

    //Current View Menu
    bool sideMode = layoutType == Side;
    ImGui::BeginColumns("Current View", sideMode ? 2 : 4, ImGuiOldColumnFlags_None);
    if(ImGui::Button(sideMode ? "Vertex" : "Source Vertex"))
    {
    }
    ImGui::NextColumn();
    if(ImGui::Button(sideMode ? "Fragment" : "Source Fragment"))
    {
    }
    if(!sideMode)
    {
        ImGui::NextColumn();
        if(ImGui::Button("Result Vertex"))
        {
        }
        ImGui::NextColumn();
        if(ImGui::Button("Result Fragment"))
        {
        }
    }
    ImGui::EndColumns();
    ImGui::End();
}
