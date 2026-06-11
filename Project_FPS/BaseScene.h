#pragma once

#include <vector>
#include <memory>

#include "IScene.h"

class GameObject;

//==============================
// シーン基底クラス
//==============================
class BaseScene : public IScene
{
public:
    //====================
    // デストラクタ
    //====================
    virtual ~BaseScene() override = default;

    //====================
    // ライフサイクル
    //====================
    bool Initialize() override;
    void Update() override;
    void Draw() override;
    void Finalize() override;

protected:

    std::vector<
        std::unique_ptr<GameObject>>
        m_gameObjects;
};