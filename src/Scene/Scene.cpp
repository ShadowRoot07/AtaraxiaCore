#include "Scene/Scene.h"
#include "Scene/Entity.h"
#include "Scene/Components.h"
#include "Render/Renderer2D.hpp"

namespace Ataraxia {

    Scene::Scene() {}
    Scene::~Scene() {}

    Entity Scene::CreateEntity(const std::string& name) {
        return Entity(m_EntityCounter++, this);
    }

    void Scene::OnUpdate(float ts) {
    }

}