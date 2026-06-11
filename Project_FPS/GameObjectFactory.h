#pragma once

#include <memory>

class GameObject;

//==============================
// GameObjectê∂ê¨
//==============================
class GameObjectFactory
{
public:

    static std::unique_ptr<GameObject>
        Create();
};