cmake_minimum_required(VERSION 3.14)
project(LearnCMake)

set(CMAKE_CXX_STANDARD 14)

add_executable(LearnCMake main.cpp)

message(STATUS "\n------------------------------------------------------")

# 为C/C++代码添加宏定义
message(STATUS "add definitions")
add_definitions(-DCAT)
add_definitions(-DPLATFORM="${CMAKE_SYSTEM_NAME}")
# CMAKE_SYSTEM_NAME表示编译目标系统名，比如在Windows上交叉编译Android的库，那么CMAKE_SYSTEM_NAME就是Android
# CMAKE_HOST_SYSTEM_NAME表示编译环境设备系统名，比如在Windows上编译Android的库，那么CMAKE_HOST_SYSTEM_NAME就是Windows
message(STATUS "CMAKE_SYSTEM_NAME is :${CMAKE_SYSTEM_NAME}")
message(STATUS "CMAKE_HOST_SYSTEM_NAME is :${CMAKE_HOST_SYSTEM_NAME}")
message(STATUS "CMAKE_HOST_SYSTEM is :${CMAKE_HOST_SYSTEM}")
message(STATUS "CMAKE_HOST_WIN32 is :${CMAKE_HOST_WIN32}")
message(STATUS "CMAKE_HOST_UNIX is :${CMAKE_HOST_UNIX}")
message(STATUS "CMAKE_HOST_APPLE is :${CMAKE_HOST_APPLE}")
message(STATUS "CMAKE_HOST_SOLARIS is :${CMAKE_HOST_SOLARIS}")

if (${CMAKE_BUILD_TYPE} MATCHES "Debug")
    add_definitions(-DDebug)
else ()
    add_definitions(-DRelease)
endif ()
message(STATUS "\n------------------------------------------------------")

# 内建变量
message(STATUS "internal variables")
message(STATUS "CMAKE_VERSION is: ${CMAKE_VERSION}")
message(STATUS "CMAKE_BUILD_TYPE is: ${CMAKE_BUILD_TYPE}")
message(STATUS "CMAKE_SYSTEM is: ${CMAKE_SYSTEM}")
message(STATUS "CMAKE_SYSTEM_NAME is: ${CMAKE_SYSTEM_NAME}")
message(STATUS "CMAKE_SOURCE_DIR is: ${CMAKE_SOURCE_DIR}")
message(STATUS "\n------------------------------------------------------")

# 文件操作
message(STATUS "file operations")
get_filename_component(parent_dir ${CMAKE_SOURCE_DIR} DIRECTORY)
get_filename_component(current_dir ${CMAKE_SOURCE_DIR} ABSOLUTE)
get_filename_component(current_dir_name ${CMAKE_SOURCE_DIR} NAME)
file(READ ${CMAKE_SOURCE_DIR}/config file_content)
file(GLOB_RECURSE allSources ${CMAKE_SOURCE_DIR}/ *.cpp)
message(STATUS "GLOB_RECURSE allSources ${CMAKE_SOURCE_DIR}/ *.cpp")
foreach (source1 ${allSources})
    message(STATUS "source1 is ${source1}")
endforeach ()
file(GLOB directSources ${CMAKE_SOURCE_DIR}/ *.cpp)
message(STATUS "GLOB directSources ${CMAKE_SOURCE_DIR}/ *.cpp")
foreach (source2 ${directSources})
    message(STATUS "source2 is ${source2}")
endforeach ()

message(STATUS "file_content is: ${file_content}")
message(STATUS "parent_dir is: ${parent_dir}")
message(STATUS "current_dir is: ${current_dir}")
message(STATUS "current_dir_name is: ${current_dir_name}")
message(STATUS "\n------------------------------------------------------")

# 变量操作
set(varList a)
message(STATUS "varList is: ${varList}")
set(varList ${varList} b)
message(STATUS "varList is: ${varList}")
set(varList ${varList} c)
message(STATUS "varList is: ${varList}")
message(STATUS "print all variable in varList:")
foreach (var ${varList})
    message(STATUS "var is ${var}")
endforeach ()
message(STATUS "\n------------------------------------------------------")