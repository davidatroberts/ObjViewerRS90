cmake_minimum_required(VERSION 3.1)
project(objviewer)

find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)
find_package(SDL_ttf REQUIRED)
find_package(ZLIB REQUIRED)

add_executable(objviewer 
    src/Context.cpp
    src/main.cpp
    src/ObjViewerState.cpp
    src/PixelBuffer.cpp
    src/Text.cpp
    src/Timer.cpp
    src/ObjParser.cpp
)

target_link_libraries(objviewer ${SDL_LIBRARY})
target_link_libraries(objviewer ${SDL_TTF_LIBRARY})
target_link_libraries(objviewer ${ZLIB_LIBRARY})

target_compile_options(objviewer PUBLIC -lc)
target_compile_options(objviewer PUBLIC -lgcc)
target_compile_options(objviewer PUBLIC -no-pie)
target_compile_options(objviewer PUBLIC -Wl,--gc-sections)
target_compile_options(objviewer PUBLIC -flto)
target_compile_options(objviewer PUBLIC -s)

add_custom_target(
    opk
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/package_rs90.sh
    DEPENDS objviewer
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

# unit test setup
include(CTest)
enable_testing()
add_library(Catch2::Catch IMPORTED INTERFACE)
set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/extern/catch)
set_property(TARGET Catch2::Catch PROPERTY INTERFACE_INCLUDE_DIRECTORIES "${CATCH_INCLUDE_DIR}")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(unit_tests 
    tests/test_main.cpp
    tests/test_ObjParser.cpp
    src/ObjParser.cpp
)

target_link_libraries(unit_tests
    Catch2::Catch
)

add_test(test_all unit_tests)