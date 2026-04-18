cmake_minimum_required(VERSION 3.20)
project(ECS_Physics_Engine LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

# Fetch Dependencies
include(FetchContent)

# GLFW & GLM Dear ImGui libraries
FetchContent_Declare(glfw GIT_REPOSITORY https://github.com/glfw/glfw GIT_TAG 3.3.8)
FetchContent_Declare(glm GIT_REPOSITORY https://github.com/g-truc/glm GIT_TAG master)
FetchContent_Declare(imgui GIT_REPOSITORY https://github.com/ocornut/imgui GIT_TAG docking)

FetchContent_MakeAvailable(glfw glm imgui)

# Collect allproject source files
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.c")

# Collect the ImGui source files from the FetchContent directory
set(IMGUI_SRCS
    ${imgui_SOURCE_DIR}/imgui.cpp
    ${imgui_SOURCE_DIR}/imgui_draw.cpp
    ${imgui_SOURCE_DIR}/imgui_tables.cpp
    ${imgui_SOURCE_DIR}/imgui_widgets.cpp
    ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
    ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
)

#Create execeutable
add_executable(${PROJECT_NAME} ${SOURCES} ${IMGUI_SRCS})

# tell the compiler where to find headers
target_include_directories(${PROJECT_NAME} PRIVATE 
    src/
    src/core/
    src/physics/
    src/renderer/      
    ${imgui_SOURCE_DIR} 
    ${imgui_SOURCE_DIR}/backends
)

# 5. Link the libraries
target_link_libraries(${PROJECT_NAME} PRIVATE 
    glfw 
    glm
    ${CMAKE_DL_LIBS} # Added for Linux/Fedora compatibility
)
target_include_directories(${PROJECT_NAME} PRIVATE src/ src/core src/physics/)