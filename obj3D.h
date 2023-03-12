#pragma once

#include <string>
#include <cmath>

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"


namespace obj3D
{
    Mesh* CreateTrack(const std::string& name, glm::vec3 leftBottomCorner);
    Mesh* CreateGrass(const std::string& name, glm::vec3 leftBottomCorner);
    Mesh* CreateSimpleCar(const std::string& name, glm::vec3 leftBottomCorner);
    Mesh* CreateTree(const std::string& name, glm::vec3 centerTree);
}
