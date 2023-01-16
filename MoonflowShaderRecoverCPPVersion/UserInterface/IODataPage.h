#pragma once
#include "../Data/Variables.h"
class IODataPage
{
public:
    enum class BufferStage
    {
        Properties,
        Attributes,
        V2F,
        GBuffer,
        TexDef,
    };

private:
    enum class IODataPanelType
    {
        PropertiesPanel,
        StagePanel
    };

    void ShowPropDef(Variables::PropDef);
    
};
