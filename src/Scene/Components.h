#pragma once

#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Ataraxia {

    // Componente de Etiqueta / Nombre
    struct TagComponent {
        std::string Tag;

        TagComponent() = default;
        TagComponent(const std::string& tag) : Tag(tag) {}
    };

    // Componente de Transformación (Posición, Rotación, Escala)
    struct TransformComponent {
        glm::vec3 Position{ 0.0f, 0.0f, 0.0f };
        glm::vec3 Rotation{ 0.0f, 0.0f, 0.0f }; // En radianes o grados
        glm::vec3 Scale{ 1.0f, 1.0f, 1.0f };

        TransformComponent() = default;
        TransformComponent(const glm::vec3& position) : Position(position) {}

        glm::mat4 GetTransform() const {
            glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), Rotation.z, { 0.0f, 0.0f, 1.0f });
            return glm::translate(glm::mat4(1.0f), Position) * rotation * glm::scale(glm::mat4(1.0f), Scale);
        }
    };

    // Componente de Renderizado de Sprite 2D
    struct SpriteRendererComponent {
        glm::vec4 Color{ 1.0f, 1.0f, 1.0f, 1.0f };

        SpriteRendererComponent() = default;
        SpriteRendererComponent(const glm::vec4& color) : Color(color) {}
    };

}