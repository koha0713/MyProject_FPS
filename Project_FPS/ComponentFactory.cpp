#include "ComponentFactory.h"

#include "TransformComponent.h"
#include "CameraComponent.h"
#include "MeshRendererComponent.h"

//==============================
// ComponentçÏê¨
//==============================
std::unique_ptr<Component>
ComponentFactory::Create(
    const std::string& type)
{
    if (type == "Transform")
    {
        return
            std::make_unique<
            TransformComponent>();
    }

    if (type == "Camera")
    {
        return
            std::make_unique<
            CameraComponent>();
    }

    return nullptr;
}