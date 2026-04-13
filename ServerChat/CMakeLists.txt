cmake_minimum_required(VERSION 3.16)

project(ServerChat LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 🔴 ДОБАВЛЯЕМ Network и SQL!
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Network Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Network Sql)

add_executable(ServerChat
    main.cpp
    server.h
    clienthandler.h
    database.h
    server.cpp
    clienthandler.cpp
    database.cpp
    message.h
)

# 🔴 ЛИНКУЕМ ВСЕ ТРИ МОДУЛЯ!
target_link_libraries(ServerChat
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Network
    Qt${QT_VERSION_MAJOR}::Sql
)

include(GNUInstallDirs)
install(TARGETS ServerChat
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
