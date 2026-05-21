#include "Camera.h"

using namespace DirectX;

//==============================
// 更新
//==============================
void Camera::Update(
	const XMFLOAT3& position,
	const XMFLOAT3& rotation)
{
    //====================
    // 回転行列
    //====================
    XMMATRIX rotationMatrix =
        XMMatrixRotationRollPitchYaw(
            XMConvertToRadians(rotation.x),
            XMConvertToRadians(rotation.y),
            XMConvertToRadians(rotation.z));

    //====================
    // 前方向
    //====================
    XMVECTOR forward =
        XMVector3TransformCoord(
            XMVectorSet(0, 0, 1, 0),
            rotationMatrix);

    //====================
    // カメラ位置
    //====================
    XMVECTOR eye =
        XMVectorSet(
            position.x,
            position.y,
            position.z,
            1.0f);

    //====================
    // 注視点
    //====================
    XMVECTOR focus =
        eye + forward;

    //====================
    // 上方向
    //====================
    XMVECTOR up =
        XMVectorSet(0, 1, 0, 0);

    //====================
    // View
    //====================
    m_view =
        XMMatrixLookAtLH(
            eye,
            focus,
            up);

    //====================
    // Projection
    //====================
    m_projection =
        XMMatrixPerspectiveFovLH(
            XMConvertToRadians(60.0f),
            1280.0f / 720.0f,
            0.1f,
            1000.0f);
}