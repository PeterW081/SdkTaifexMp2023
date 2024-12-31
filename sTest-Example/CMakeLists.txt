###
set(VAR_project_name "0TESTEXE-${VAR_package_name}-Example")

###
cmake_minimum_required(VERSION "${VAR_cmake_version}")
project("${VAR_project_name}")

###
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
##X
find_package("GTest" REQUIRED CONFIG COMPONENTS "GTest" "GMock")

###
file(
  GLOB_RECURSE ARR_cxx_src
  "${PROJECT_SOURCE_DIR}/cxx_xxx_example/*.cxx"
)
list(
  APPEND ARR_cxx_include
  "${PROJECT_SOURCE_DIR}/cxx_xxx_example/"
)
list(
  APPEND ARR_cxx_library
  "${VAR_package_name}-sLibz-Common"
  "${VAR_package_name}-sLibz-CommonBoost"
  "${VAR_package_name}-sLibx-TaifexMpBasic"
  "${VAR_package_name}-sLibx-TaifexMpExtra"
  #
  "GTest::gtest_main"
  "GTest::gmock_main"
  #
)
##X
add_executable(
  "${VAR_project_name}"
)
target_sources(
  "${VAR_project_name}" PUBLIC
  PRIVATE "${ARR_cxx_src}"
)
target_include_directories(
  "${VAR_project_name}" PUBLIC
  "${ARR_cxx_include}"
)
target_link_libraries(
  "${VAR_project_name}" PUBLIC
  "${ARR_cxx_library}"
)
