#pragma once

#include <memory>

class GraphicsDevice;
class IScene;

enum class SceneID;

//==============================
// SceneID
//==============================
enum class SceneID
{
	Test
};

//==============================
// Sceneê∂ê¨ÉNÉâÉX
//==============================
class SceneRoot
{
public:

    static std::shared_ptr<IScene> CreateScene(
        SceneID id,
        GraphicsDevice* graphics);
};