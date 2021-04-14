cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(Project_final LANGUAGES CXX)
add_executable(${PROJECT_NAME} main.cpp widget.hpp widget.cpp widget.ui)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_EXTENSIONS OFF
    WIN32_EXECUTABLE ON
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
)

include(FindPkgConfig)
pkg_check_modules(ICU REQUIRED IMPORTED_TARGET icu-io icu-uc icu-i18n)
find_package(Qt5 5.11 REQUIRED COMPONENTS Widgets)
target_link_libraries(${PROJECT_NAME} PRIVATE PkgConfig::ICU Qt5::Widgets)
