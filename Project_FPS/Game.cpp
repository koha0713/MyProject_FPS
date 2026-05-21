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
	// レンダラー初期化
	//=================
	if (!m_renderer.Initialize(
		m_graphics->GetDevice()))
	{
		return false;
	}

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

}

//==============================
// ゲーム描画
//==============================
void Game::Draw()
{
	m_graphics->Clear();

	//=======================
	// レンダラー描画
	//=======================
	m_renderer.Draw(
		m_graphics->GetContext());

	m_graphics->Present();
}

