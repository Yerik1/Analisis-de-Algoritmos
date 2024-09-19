cmake_minimum_required(VERSION 3.16)

project(Tarea2 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Encontrar paquetes de Qt necesarios
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Charts)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Charts)

set(PROJECT_SOURCES
        main.cpp
        ventana.cpp
        ventana.h
        ventana.ui
        mediciones.h
        mediciones.cpp
        Algorithms.h
        Algorithms.cpp
        LinkedList.h
        LinkedList.cpp
        BinaryTree.h
        BinaryTree.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Tarea2
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
    )

else()
    if(ANDROID)
        add_library(Tarea2 SHARED
                ${PROJECT_SOURCES}
        )

    else()
        add_executable(Tarea2
                ${PROJECT_SOURCES}
        )
    endif()
endif()

# Enlazar las bibliotecas de Qt necesarias
target_link_libraries(Tarea2 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Charts)


if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Tarea2)
endif()
set_target_properties(Tarea2 PROPERTIES
        ${BUNDLE_ID_OPTION}
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Tarea2
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Tarea2)
endif()
