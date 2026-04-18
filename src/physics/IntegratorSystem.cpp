#include "../core/ECS.hpp"
#include <cmath>
#include <glm/glm.hpp>

// function that will update the physics with every frame
void updatePhysics(Registry& reg, float dt) {
    // Loop through all entities and update their physics
    for (Entity i = 0; i < MAX_ENTITIES; i++) {
        // Only update active entities
        if (reg.active[i]) {
            // Get the particle and transform components for the entity
            auto& p = reg.particles[i];
            auto& t = reg.transforms[i];

            // Skip entities with infinite mass (inverseMass <= 0)
            if (p.inverseMass <= 0.0f) continue;
    
            // Update pos based on velocity (semi implicit)
            t.position += p.velocity * dt;

            // Work out acceleration from force ( a = F * invM)
            glm::vec resultingAcc = p.acceleration;

            // Update velocity
            p.velocity += resultingAcc * dt;

            // Apply damping (Millington Ch 3.3.1)
            p.velocity *= pow(p.damping, dt);
        }
    }
}