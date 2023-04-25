cmake_minimum_required(VERSION 3.0)
project(qt_meterial_widgets)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")
# set(Qt5_DIR $ENV{QTDIR}/lib/cmake/Qt5)
include("$ENV{VCPKG}/scripts/buildsystems/vcpkg.cmake")
find_package(Qt5 COMPONENTS 
# Multimedia 
# MultimediaWidgets 
Gui Widgets Network OpenGL REQUIRED)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/examples
    ${CMAKE_CURRENT_SOURCE_DIR}/components
    ${CMAKE_CURRENT_SOURCE_DIR}/components/lib
    ${CMAKE_CURRENT_SOURCE_DIR}/components/layouts
)
file(GLOB
    LIIBRARY_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/components/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/components/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/components/*.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/components/*.qrc
    ${CMAKE_CURRENT_SOURCE_DIR}/components/lib/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/components/lib/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/components/layout/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/components/layout/*.h
    )
add_library(
    material
    ${LIIBRARY_SRC}
)
target_link_libraries(
    material
    Qt5::Gui
    Qt5::Widgets
    Qt5::Network
    Qt5::OpenGL
)
file(GLOB
    SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/examples/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/examples/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/examples/*.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/examples/*.qrc
)
aux_source_directory(
    ${CMAKE_CURRENT_SOURCE_DIR}/examples
    SRC_2
)
# message("src_2 = " ${SRC_2})

add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME}
    # Qt5::Multimedia
    # Qt5::MultimediaWidgets
    material
    Qt5::Gui
    Qt5::Widgets
    Qt5::Network
    Qt5::OpenGL
)