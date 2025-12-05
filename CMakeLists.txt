cmake_minimum_required(VERSION 3.19)
project(labs8 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(labs8
    main.cpp
    employee.h employee.cpp
)

target_link_libraries(labs8
    PRIVATE
        Qt::Core
)

include(GNUInstallDirs)

install(TARGETS labs8
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
