#include "TransformComponent.h"

using namespace DirectX;

//==============================
// 更新
//==============================
void TransformComponent::Update()
{
	UpdateMatrix();
}

//==============================
// 位置の設定
//==============================
void TransformComponent::SetPosition(const XMFLOAT3& position)
{
	m_position = position;
	UpdateMatrix();
}

//==============================
// 回転の設定
//==============================
void TransformComponent::SetRotation(const XMFLOAT3& rotation)
{
	m_rotation = rotation;
	UpdateMatrix();
}

//==============================
// スケールの設定
//==============================
void TransformComponent::SetScale(const XMFLOAT3& scale)
{
	m_scale = scale;
	UpdateMatrix();
}

//==============================
// ワールド行列の更新
//==============================
void TransformComponent::UpdateMatrix()
{
	// スケーリング行列の生成
	XMMATRIX scaleMatrix = XMMatrixScaling(
		m_scale.x,
		m_scale.y,
		m_scale.z);
	
	// 回転行列の生成
	XMMATRIX rotationMatrix =
		XMMatrixRotationRollPitchYaw(
			XMConvertToRadians(m_rotation.x),
			XMConvertToRadians(m_rotation.y),
			XMConvertToRadians(m_rotation.z));
	
	// 平行移動行列の生成
	XMMATRIX translationMatrix = XMMatrixTranslation(
		m_position.x,
		m_position.y,
		m_position.z);

	// ワールド行列の生成
	m_worldMatrix = scaleMatrix * rotationMatrix * translationMatrix;

}