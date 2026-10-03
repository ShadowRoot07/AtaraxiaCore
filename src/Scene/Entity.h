#pragma once

#include <cstdint>

namespace Ataraxia {

    class Scene;

    class Entity {
    public:
        Entity() = default;
        Entity(uint32_t handle, Scene* scene) : m_EntityHandle(handle), m_Scene(scene) {}

        operator bool() const { return m_EntityHandle != 0; }
        uint32_t GetID() const { return m_EntityHandle; }

    private:
        uint32_t m_EntityHandle{ 0 };
        Scene* m_Scene = nullptr;
    };

}