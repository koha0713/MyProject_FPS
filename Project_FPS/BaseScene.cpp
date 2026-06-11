#include "BaseScene.h"
#include "GameObject.h"

//==============================
// èâä˙âª
//==============================
bool BaseScene::Initialize()
{
    for (auto& object : m_gameObjects)
    {
        object->Initialize();
    }
	return true;
}

//==============================
// çXêV
//==============================
void BaseScene::Update()
{
    for (auto& object : m_gameObjects)
    {
        object->Update();
    }
}

//==============================
// ï`âÊ
//==============================
void BaseScene::Draw()
{
    for (auto& object : m_gameObjects)
    {
        object->Draw();
    }
}

//==============================
// èIóπ
//==============================
void BaseScene::Finalize()
{
    m_gameObjects.clear();
}