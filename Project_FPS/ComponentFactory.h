#pragma once

#include <memory>
#include <string>

class Component;

//==============================
// Componentê∂ê¨
//==============================
class ComponentFactory
{
public:

    static std::unique_ptr<Component>
        Create(
            const std::string& type);
};