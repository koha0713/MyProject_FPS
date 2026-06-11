#include "SceneManager.h"
#include "IScene.h"

//==============================
// 更新
//==============================
void SceneManager::Update()
{
	if (m_scene)
	{
		m_scene->Update();
	}
}

//==============================
// 描画
//==============================
void SceneManager::Draw()
{
	if (m_scene)
	{
		m_scene->Draw();
	}
}

//==============================
// シーンの切り替え
//==============================
bool SceneManager::ChangeScene(std::shared_ptr<IScene> scene)
{
	if (m_scene)
	{
		m_scene->Finalize();
	}

	m_scene = scene;

	if (!m_scene)
	{
		return false;
	}

	// 新シーン初期化
	return m_scene->Initialize();
}