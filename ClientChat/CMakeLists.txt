cmake_minimum_required(VERSION 3.16)

project(ClientChat LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Клиенту нужны Core и Network (SQL не нужен)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Network)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

add_executable(ClientChat
  main.cpp
  client.h
  client.cpp
  loginwindow.h
  loginwindow.cpp
  chatwindow.h
  chatwindow.cpp
  message.h

  mainwindow.h
  mainwindow.cpp
  mainwindow.ui
  loginwindow.ui
  chatwidget.h
  chatwidget.cpp
  chatwidget.ui
  chatwidget.h


)
target_link_libraries(ClientChat
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Network
    Qt${QT_VERSION_MAJOR}::Widgets
)

include(GNUInstallDirs)
install(TARGETS ClientChat
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
