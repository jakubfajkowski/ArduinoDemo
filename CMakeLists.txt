cmake_minimum_required(VERSION 3.7)
project(CoAPLib)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/CoAPLib.h
        src/CoAPLib/Array.hpp
        src/CoAPLib/CoAPConstants.h
        src/CoAPLib/CoAPHandler.cpp
        src/CoAPLib/CoAPHandler.h
        src/CoAPLib/CoAPMessage.cpp
        src/CoAPLib/CoAPMessage.h
        src/CoAPLib/CoAPMessageListener.h
        src/CoAPLib/CoAPOption.cpp
        src/CoAPLib/CoAPOption.h
        src/CoAPLib/CoAPResources.cpp
        src/CoAPLib/CoAPResources.h
        src/Environment.h
        src/RadioLib.h
        src/RadioLib/RadioMessage.hpp
        src/RadioLib/RadioMessageListener.hpp
        src/RadioLib/RadioConstants.h)

add_library(CoAPLib SHARED ${SOURCE_FILES})
set_target_properties(CoAPLib PROPERTIES PREFIX "")

enable_testing()

add_executable(ArrayTest tests/ArrayTest/ArrayTest.cpp tests/ArrayTest/Test.hpp)
target_link_libraries(ArrayTest CoAPLib)
add_test(NAME ArrayTest COMMAND ArrayTest)

add_executable(CoAPHandlerTest tests/CoAPHandlerTest/CoAPHandlerTest.cpp tests/CoAPHandlerTest/Test.hpp)
target_link_libraries(CoAPHandlerTest CoAPLib)
add_test(NAME CoAPHandlerTest COMMAND CoAPHandlerTest)

add_executable(CoAPMessageTest tests/CoAPMessageTest/CoAPMessageTest.cpp tests/CoAPMessageTest/Test.hpp)
target_link_libraries(CoAPMessageTest CoAPLib)
add_test(NAME CoAPMessageTest COMMAND CoAPMessageTest)

add_executable(CoAPOptionTest tests/CoAPOptionTest/CoAPOptionTest.cpp tests/CoAPOptionTest/Test.hpp)
target_link_libraries(CoAPOptionTest CoAPLib)
add_test(NAME CoAPOptionTest COMMAND CoAPOptionTest)

add_executable(CoAPResourcesTest tests/CoAPResourcesTest/CoAPResourcesTest.cpp tests/CoAPResourcesTest/Test.hpp)
target_link_libraries(CoAPResourcesTest CoAPLib)
add_test(NAME CoAPResourcesTest COMMAND CoAPResourcesTest)


