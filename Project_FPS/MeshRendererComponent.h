#pragma once

#include "SimpleRenderer.h"

#include "Component.h"

//==============================
// ëOï˚êÈåæ
//==============================
class TransformComponent;
class CameraComponent;

//==============================
// MeshRendererComponent
//==============================
class MeshRendererComponent final
    : public Component
{
public:

    MeshRendererComponent(
        ID3D11Device* device,
        ID3D11DeviceContext* context);

    ~MeshRendererComponent() override
        = default;

    //====================
    // èâä˙âª
    //====================
    bool Initialize() override;

    //====================
    // ï`âÊ
    //====================
    void Draw() override;

    //====================
    // Cameraê›íË
    //====================
    void SetCamera(
        CameraComponent* camera)
    {
        m_camera = camera;
    }

private:

    ID3D11Device* m_device = nullptr;

    ID3D11DeviceContext* m_context
        = nullptr;

    CameraComponent* m_camera
        = nullptr;

    SimpleRenderer m_renderer;
};