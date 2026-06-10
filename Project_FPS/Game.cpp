#include "Game.h"

//==============================
// ゲーム実行
//==============================
int Game::Run()
{
	//=================
	// ゲーム初期化
	//=================
	if (!Initialize())
	{
		return -1;
	}

	//=================
	// ゲームループ
	//=================
	while (true)
	{
		// メッセージ処理
		if (!m_window->ProcessMessage())
		{
			break;
		}

		// ゲーム更新
		Update();

		// ゲーム描画
		Draw();

	}
	
	//=================
	// ゲーム終了
	//=================
	Finalize();

	return 0;
}

//==============================
// ゲーム初期化
//==============================
bool Game::Initialize()
{
	//=================
	// ウィンドウ生成
	//=================
	m_window = std::make_unique<Window>();
	
	if (!m_window->Create(L"BEAT BREAKER", 1280, 720))
	{
		return false;
	}

	//=================
	// グラフィックスデバイス生成
	//=================
	m_graphics = std::make_unique<GraphicsDevice>();
	
	if (!m_graphics->Initialize(m_window.get()))
	{
		return false;
	}

	//=================
	// カメラObj
	//=================
	auto cameraObject =
		std::make_shared<GameObject>();

	// Transform
	auto cameraTransform =
		cameraObject->AddComponent<
		TransformComponent>();

	cameraTransform->SetPosition(
		0.0f,
		0.0f,
		-5.0f);

	// Camera
	auto camera =
		cameraObject->AddComponent<
		CameraComponent>();

	// 保持
	m_gameObjects.emplace_back(
		cameraObject);

	//=================
	// 三角Obj
	//=================
	auto triangleObject =
		std::make_shared<GameObject>();

	// Transform
	triangleObject->AddComponent<
		TransformComponent>();

	// Renderer
	auto renderer =
		triangleObject->AddComponent<
		MeshRendererComponent>(
			m_graphics->GetDevice(),
			m_graphics->GetContext());

	// Camera設定
	renderer->SetCamera(camera);

	// 保持
	m_gameObjects.emplace_back(
		triangleObject);

	return true;

}

//==============================
// ゲーム終了
//==============================
void Game::Finalize()
{
	// ウィンドウ破棄
	m_window.reset();
}

//==============================
// ゲーム更新
//==============================
void Game::Update()
{
	// ゲームオブジェクト更新
	for (auto& object : m_gameObjects)
	{
		object->Update();
	}
}

//==============================
// ゲーム描画
//==============================
void Game::Draw()
{
	m_graphics->Clear();

	//=======================
	// ゲームオブジェクト描画
	//=======================
	for (auto& object : m_gameObjects)
	{
		object->Draw();
	}

	m_graphics->Present();
}

