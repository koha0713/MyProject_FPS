#include "GameObject.h"

//==============================
// ‰Šú‰»
//==============================
void GameObject::Initialize()
{
	for (auto& component : m_components)
	{
		component->Initialize();
	}
}

//==============================
// XV
//==============================
void GameObject::Update()
{
	for (auto& component : m_components)
	{
		component->Update();
	}
}

//==============================
// •`‰æ
//==============================
void GameObject::Draw()
{
	for (auto& component : m_components)
	{
		component->Draw();
	}
}