# 3D-Physics-Engine

Core Logic: C++20 for the ECS Registry and System logic

Physics Foundation: Derived from Ian Millington’s Game Physics Engine Development

Graphics & UI: OpenGL 4.5 (Core Profile), GLAD, GLFW, and Dear ImGui for the debug suite

Build & Test: CMake for cross platform builds and Catch2 for verifying physics integrators

System Architecture:
IntegratorSystem: (Transform, RigidBody) -> Updates position/rotation.
CollisionSystems: (Transform, Collider) -> Checks GJK/EPA and creates Contact components. 
ImpulseSystem: (RigidBody, Contact) -> Resolves velocities based on collision data.
RenderSystem: (Transform, Mesh) -> Gives data to OpenGL. 

From Millington:
The Contact Resolver (Ch. 14):
The Force Generator (Ch. 5):
The Inertia Tensor (Ch. 9): 

# To build
1. Generate build files:
    'cmake -S . -B build'
2. Compile:
    'cmake --build build
3. For Windows, run :
    ./build/Debug/ECS_Physics_Engine.exe
   For Linux, run:
     ./build/ECS_Physics_Engine
