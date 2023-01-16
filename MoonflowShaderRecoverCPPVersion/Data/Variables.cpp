#include "Variables.h"

void ShaderData::Init()
{
    shader_data = new ShaderData();
    shader_data->properties = new std::list<std::list<PropDef>>();
    shader_data->attributes = new std::list<PropDef>();
    shader_data->v2f = new std::list<PropDef>();
    shader_data->gbuffer = new std::list<PropDef>();
    shader_data->Textures = new std::list<PropDef>();
}

void ShaderData::InitCBuffer(int num)
{
    for (int i = 0; i < num; ++i)
    {
        shader_data->properties->
    }
}

