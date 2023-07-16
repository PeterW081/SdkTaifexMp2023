set(VAR_PROJECT_NAME "XplumSdk-TaifexMp")
set(Enable_GTest ON)
#--
set(VARS_INCLUDE_DIRS)

###
cmake_minimum_required(VERSION 3.24)
project("${VAR_PROJECT_NAME}")
set(CMAKE_CXX_STANDARD 20)

###
find_package(Boost REQUIRED COMPONENTS system)
list(
  APPEND VARS_INCLUDE_DIRS "${Boost_INCLUDE_DIRS}"
)

###
FILE(
  GLOB VARS_PROJECT_CXX_SOURCE
  "${CMAKE_SOURCE_DIR}/cxx_src/*.cxx"
  "${CMAKE_SOURCE_DIR}/separate_0CxxCommon-cxx_src/*.cxx"
)
add_library(
  "${VAR_PROJECT_NAME}"
  "${VARS_PROJECT_CXX_SOURCE}"
)
target_include_directories(
  "${VAR_PROJECT_NAME}" PUBLIC
  "${CMAKE_SOURCE_DIR}/cxx_include/"
  "${CMAKE_SOURCE_DIR}/separate_0CxxCommon-cxx_include/"
)
target_include_directories(
  "${VAR_PROJECT_NAME}" PRIVATE
  "${VARS_INCLUDE_DIRS}"
)

###
add_executable(
  "${VAR_PROJECT_NAME}-Main"
  "${CMAKE_SOURCE_DIR}/main.cxx"
)
target_include_directories(
  "${VAR_PROJECT_NAME}-Main" PRIVATE
  "${VARS_INCLUDE_DIRS}"
)
target_link_libraries(
  "${VAR_PROJECT_NAME}-Main" PRIVATE
  "${VAR_PROJECT_NAME}"
)
