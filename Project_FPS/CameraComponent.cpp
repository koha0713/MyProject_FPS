#include "CameraComponent.h"
#include "TransformComponent.h"
#include "GameObject.h"

//==============================
// 更新
//==============================
void CameraComponent::Update()
{
	//====================
	// TransformComponentの取得
	//====================
	auto transform =
		GetOwner()->GetComponent<
		TransformComponent>();

	if (!transform)
	{
		return;
	}

	//====================
	// Camera更新
	//====================
	m_camera.Update(
		transform->GetPosition(),
		transform->GetRotation());

}