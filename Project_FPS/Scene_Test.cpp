#include "Scene_Test.h"

#include "GraphicsDevice.h"
#include "GameObject.h"

#include "TransformComponent.h"
#include "CameraComponent.h"
#include "MeshRendererComponent.h"

//==============================
// コンストラクタ
//==============================
Scene_Test::Scene_Test(
	GraphicsDevice* graphics)
	: graphics_(graphics)
{
}

//==============================
// 初期化
//==============================
bool Scene_Test::Initialize()
{
	//====================
	// ゲームオブジェクトの作成
	//====================

	//====================
	// カメラコンポーネント
	//====================
	{
		
		auto cameraObject = std::make_unique<GameObject>();
		
		auto cameraTransform = 
			cameraObject->AddComponent<TransformComponent>();
		cameraTransform->SetPosition(0.0f, 0.0f, -5.0f);

		auto camera = 
			cameraObject->AddComponent<CameraComponent>();
		m_mainCamera = camera;

		m_gameObjects.push_back(std::move(cameraObject));

	}

	//====================
	// 三角形描画
	//====================
	{
		auto triangleObject = std::make_unique<GameObject>();
		triangleObject->AddComponent<TransformComponent>();
		auto renderer = triangleObject->AddComponent<MeshRendererComponent>(
			graphics_->GetDevice(),
			graphics_->GetContext());
		renderer->SetCamera(m_mainCamera);
		m_gameObjects.push_back(std::move(triangleObject));
	}

	BaseScene::Initialize();

	return true;
}

//==============================
// 更新
//==============================
void Scene_Test::Update()
{
	BaseScene::Update();
}

//==============================
// 描画
//==============================
void Scene_Test::Draw()
{
	BaseScene::Draw();
}

//==============================
// 終了
//==============================
void Scene_Test::Finalize()
{
	BaseScene::Finalize();

	m_mainCamera = nullptr;
}