cmake_minimum_required(VERSION 3.14)

project(hd_json_cyclone-dx_writer_plugin LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(
  hd_json_cyclone-dx_writer_plugin SHARED
  rz_header_docu_plugins.h hd_json_cyclonedx_writer_plugin.cpp
  hd_json_cyclonedx_writer_plugin.h)

target_link_libraries(hd_json_cyclone-dx_writer_plugin
                      PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(hd_json_cyclone-dx_writer_plugin
                           PRIVATE HD_JSON_CYCLONEDX_WRITER_PLUGIN_LIBRARY)
