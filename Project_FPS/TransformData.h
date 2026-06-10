#pragma once

#include <DirectXMath.h>

//------------------------------------------------------------
// GPU“]‘——p
//------------------------------------------------------------
struct TransformData
{
    DirectX::XMMATRIX world;
    DirectX::XMMATRIX view;
    DirectX::XMMATRIX projection;
};