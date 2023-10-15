cmake_minimum_required(VERSION 3.5)

project(calculator-CMake VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

include_directories(${PROJECT_SOURCE_DIR}/inc/) # 添加头文件目录
file(GLOB SOURCE_FILE ${PROJECT_SOURCE_DIR}/src/*.c*) # 把src里面的*.c*文件添加到 SOURCE_FILE
file(GLOB INCLUDE_FILE ${PROJECT_SOURCE_DIR}/inc/*.h) # 把src里面的*.c*文件添加到 SOURCE_FILE
file(GLOB RESOURCE_FILE ${PROJECT_SOURCE_DIR}/src/*.ui) # 把src里面的*.c*文件添加到 SOURCE_FILE

set(PROJECT_SOURCES
    ${SOURCE_FILE}
    ${INCLUDE_FILE}
    ${RESOURCE_FILE}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(calculator-CMake
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET calculator-CMake APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(calculator-CMake SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(calculator-CMake
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(calculator-CMake PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(calculator-CMake PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS calculator-CMake
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(calculator-CMake)
endif()
