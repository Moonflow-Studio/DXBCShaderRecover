#pragma once
#include <string>

#include "../imgui/imgui.h"

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
    void ReadSourceText(TextCodeType type);
    void ReadFile();
};
