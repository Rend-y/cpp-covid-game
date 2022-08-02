cmake_minimum_required(VERSION 3.0.0)
project(cpp_covid_game VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(cpp_covid_game src/main.cpp)
add_library(vector2 src/vector2/vector2.cpp)
target_link_libraries(cpp_covid_game vector2)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
