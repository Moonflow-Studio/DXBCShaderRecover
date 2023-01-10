#include "CodePages.h"

#include <iostream>

#include "../imgui/imgui_impl_win32.h"
#include "../imgui/imgui_impl_dx11.h"
#include "../imgui/imgui_internal.h"

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
            if(ImGui::MenuItem("Open Source Vertex Shader Code", "Shift+Alt+v")){}
            if(ImGui::MenuItem("Open Source Fragment Shader Code", "Shift+Alt+f")){}
            ImGui::EndMenu();
        }
        if(ImGui::BeginMenu("View Mode"))
        {
            if(ImGui::MenuItem(sideMode ? R"(√ Sync View)" : "Sync View", "Shift+Alt+v")){layoutType = Side;}
            if(ImGui::MenuItem(sideMode ? "Single View" : R"(√ Single View)", "Shift+Alt+f")){layoutType = FullScreen;}
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }
    
    //Current View Menu
    {
        ImGui::BeginTabBar("Current View");
        if(ImGui::TabItemButton(sideMode ? "Vertex" : "Source Vertex"))
        {
        }
        if(ImGui::TabItemButton(sideMode ? "Fragment" : "Source Fragment"))
        {
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
