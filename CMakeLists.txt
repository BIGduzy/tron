cmake_minimum_required(VERSION 3.6)
project(Tron2_6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/LightCycle/Player.h src/LightCycle/Player.cpp src/Game.cpp src/Game.h src/States/PlayState.cpp src/States/PlayState.h src/States/State.cpp src/States/State.h src/LightCycle/SimpleAI.cpp src/LightCycle/SimpleAI.h)
add_executable(Tron2_6 ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Tron2_6 ${SFML_LIBRARIES})
endif()