cmake_minimum_required(VERSION 3.19)
project(33var LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(33var
    main.cpp
    DynamicArray.h
    DynamicArray.cpp
    MinMaxArray.h
    MinMaxArray.cpp
    BetweenSumArray.h
    BetweenSumArray.cpp
    ReorderArray.h
    ReorderArray.cpp
)

target_link_libraries(33var
    PRIVATE
        Qt::Core
)

include(GNUInstallDirs)

install(TARGETS 33var
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
