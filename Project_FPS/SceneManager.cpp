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
void SceneManager::ChangeScene(std::shared_ptr<IScene> scene)
{
	m_scene = scene;
}