cmake_minimum_required(VERSION 3.15.0)
project(pylibmorton)

include(FetchContent)
FetchContent_Declare(
    pybind11
    GIT_REPOSITORY https://github.com/pybind/pybind11.git
    GIT_TAG v2.13.1
)
FetchContent_MakeAvailable(pybind11)

include_directories(${CMAKE_SOURCE_DIR}/include)

pybind11_add_module(pylibmorton pylibmorton.cpp)
target_link_libraries(pylibmorton PRIVATE libmorton::libmorton)

install(TARGETS pylibmorton
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})