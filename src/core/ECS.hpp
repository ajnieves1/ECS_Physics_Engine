#include <vector>
#include <bitset>
#include <cstdint>
#pragma once
#include <glm/glm.hpp> 
#include <vector>
#include <cstdint>

using Entity = uint32_t;
const uint32_t MAX_ENTITIES = 5000;

// Components of a particle
struct Particle {
    glm::vec3 velocity;
    glm::vec3 acceleration;
    float damping = 0.99f;
    float inverseMass;
};

// Struct that defines a transformation
struct Transform {
    glm::vec3 position; 
};

// Registry that holds all the components and active entities
class Registry {
public:
    std::vector<Transform> transforms;
    std::vector<Particle> particles;
    std::vector<bool> active;

    // Constructor to initialize the registry with the maximum number of entities
    Entity createEntity() {
        for (uint32_t i =0; i < MAX_ENTITIES; i++) {
            if (!active[i]) {
                active[i] = true;
                return i;
            }
        }
        return -1;
    }
};