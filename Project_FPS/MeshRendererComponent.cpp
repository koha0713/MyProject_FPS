#include "MeshRendererComponent.h"

#include "TransformComponent.h"
#include "CameraComponent.h"

#include "GameObject.h"

//==============================
// コンストラクタ
//==============================
MeshRendererComponent::
MeshRendererComponent(
    ID3D11Device* device,
    ID3D11DeviceContext* context)
    :
    m_device(device),
    m_context(context)
{
}

//==============================
// 初期化
//==============================
bool MeshRendererComponent::Initialize()
{
    return m_renderer.Initialize(
        m_device);
}

//==============================
// 描画
//==============================
void MeshRendererComponent::Draw()
{
    //====================
    // Camera確認
    //====================
    if (!m_camera)
    {
        return;
    }

    //====================
    // Transform取得
    //====================
    auto transform =
        GetOwner()->GetComponent<
        TransformComponent>();

    if (!transform)
    {
        return;
    }

    //====================
    // Camera取得
    //====================
    auto& camera =
        m_camera->GetCamera();

    //====================
    // 描画
    //====================
    m_renderer.Draw(
        m_context,

        transform->GetWorldMatrix(),

        camera.GetView(),

        camera.GetProjection());
}