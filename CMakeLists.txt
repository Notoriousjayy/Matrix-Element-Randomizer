cmake_minimum_required(VERSION 3.10)
project(MatrixRandomElement C)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

add_executable(MatrixRandomElement main.c)

target_link_libraries(MatrixRandomElement ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
