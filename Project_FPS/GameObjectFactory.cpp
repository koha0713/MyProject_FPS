#include "GameObjectFactory.h"
#include "GameObject.h"

//==============================
// GameObjectçÏê¨
//==============================
std::unique_ptr<GameObject>
GameObjectFactory::Create()
{
    return std::make_unique<GameObject>();
}