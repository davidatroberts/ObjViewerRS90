cmake_minimum_required(VERSION 3.1)
project(objviewer)

find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)
find_package(SDL_ttf REQUIRED)
find_package(ZLIB REQUIRED)

add_executable(objviewer 
    src/main.cpp
    src/PixelBuffer.cpp
    src/Timer.cpp
    src/Context.cpp
    src/Text.cpp
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