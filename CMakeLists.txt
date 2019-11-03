cmake_minimum_required(VERSION 3.5)

project(cpu LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(cpu WIN32
  src/circuitos_basicos.cpp
  src/circuitos_cpu.cpp
  src/cpu.cpp
  src/main.cpp
  src/mainwindow.cpp
  src/mainwindow.h
  src/mainwindow.ui
  src/mate.cpp
)

target_link_libraries(cpu PRIVATE Qt5::Widgets)
