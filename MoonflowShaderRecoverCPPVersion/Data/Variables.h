#pragma once
#include <list>
#include <string>

enum DataType
{
    Bool,
    Float,
    Vector2,
    Vector3,
    Vector4,
    Sampler,
    Texture2D,
    Texture3D,
    Buffer
};

enum DefChannel
{
    POSITION,
    NORMAL,
    TANGENT,
    COLOR,
    TEXCOORD0,
    TEXCOORD1,
    TEXCOORD2,
    TEXCOORD3,
    TEXCOORD4,
    TEXCOORD5,
    TEXCOORD6,
    TEXCOORD7,
    TEXCOORD8,
    TEXCOORD9,
    TEXCOORD10,
    TEXCOORD11,
    TEXCOORD12,
    TEXCOORD13,
    TEXCOORD14,
    TEXCOORD15,
};

struct PropDef
{
    std::string propName;
    DataType propType;
    DefChannel channel;
};

class ShaderData
{
public:
    std::list<std::list<PropDef>>* properties;
    std::list<PropDef>* attributes;
    std::list<PropDef>* v2f;
    std::list<PropDef>* gbuffer;
    std::list<PropDef>* Textures;
    void Init();
    void InitCBuffer(int);
    void Init(int);
    void Delete();
private:
    
    
};

static ShaderData* shader_data;

