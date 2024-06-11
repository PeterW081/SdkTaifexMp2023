set(VAR0_PROJECT_NAME "XplumSdk-TaifexMp")
set(OPT0_IS_ENABLE_EXAMPLE ON)

###
cmake_minimum_required(VERSION "3.24.2")
project("${VAR0_PROJECT_NAME}" VERSION 0.08.019879)
##-
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

###
find_package(Boost REQUIRED COMPONENTS system)
add_subdirectory("${PROJECT_SOURCE_DIR}/subdir_Member01-TaifexMp-Origin")
add_subdirectory("${PROJECT_SOURCE_DIR}/subdir_Member02-TaifexMp-Widget")
add_subdirectory("${PROJECT_SOURCE_DIR}/subdir_Separate-Common")
add_subdirectory("${PROJECT_SOURCE_DIR}/subdir_Separate-CommonBoost")
if("${OPT0_IS_ENABLE_EXAMPLE}")
  add_subdirectory("${PROJECT_SOURCE_DIR}/subdir_Example")
endif()
