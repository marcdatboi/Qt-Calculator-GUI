



cmake_minimum_required(VERSION 3.16)
project(qt_calculator_gui LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(SOURCES
    src/main.cpp
    src/mainwindow.cpp
    mainwindow.ui
)

set(CMAKE_PREFIX_PATH "C:/DevFolder/tools/Frameworks/Qt/6.10.2/mingw_64")
find_package(Qt6 REQUIRED COMPONENTS Widgets Gui Core)

qt_add_executable(qt_calculator_gui
    ${SOURCES}
    include/mainwindow.h
)

target_include_directories(qt_calculator_gui PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(qt_calculator_gui PRIVATE
    Qt6::Widgets
    Qt6::Gui
    Qt6::Core
)

