cmake_minimum_required(VERSION 3.0.0)
project(canvas3 VERSION 0.1.0)

INCLUDE_DIRECTORIES(/opt/homebrew/Cellar/sfml/2.5.1_2/include)
LINK_DIRECTORIES(/opt/homebrew/Cellar/sfml/2.5.1_2/lib)

include(CTest)
enable_testing()

add_executable(canvas3 main.cpp src/Canvas.cpp src/Ellipse.cpp src/Line.cpp src/Point.cpp src/Polygon.cpp src/Rectangle.cpp src/Shape.cpp)

TARGET_LINK_LIBRARIES(canvas3 /opt/homebrew/Cellar/sfml/2.5.1_2/lib/libsfml-audio.2.5.1.dylib /opt/homebrew/Cellar/sfml/2.5.1_2/lib/libsfml-graphics.2.5.1.dylib /opt/homebrew/Cellar/sfml/2.5.1_2/lib/libsfml-network.2.5.1.dylib /opt/homebrew/Cellar/sfml/2.5.1_2/lib/libsfml-system.2.5.1.dylib /opt/homebrew/Cellar/sfml/2.5.1_2/lib/libsfml-window.2.5.1.dylib)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
