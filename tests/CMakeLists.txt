cmake_minimum_required(VERSION 3.16)
project(Tests LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Network)

add_executable(test_auth test_auth.cpp)
target_link_libraries(test_auth Qt6::Core)

add_executable(test_message test_message.cpp)
target_link_libraries(test_message Qt6::Core)

add_executable(test_network test_network.cpp)
target_link_libraries(test_network Qt6::Core Network)

enable_testing()
add_test(NAME AuthTest COMMAND test_auth)
add_test(NAME MessageTest COMMAND test_message)
add_test(NAME NetworkTest COMMAND test_network)
