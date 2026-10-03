#pragma once

#include <vector>
#include <memory>
#include <cstdint>
#include <string>

namespace Ataraxia {

    class Entity;

    class Scene {
    public:
        Scene();
        ~Scene();

        Entity CreateEntity(const std::string& name = "Entity");
        void OnUpdate(float ts);

    private:
        friend class Entity;
        uint32_t m_EntityCounter = 0;
    };

}