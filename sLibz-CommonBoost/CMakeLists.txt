###
set(VAR_project_name "${VAR_package_name}-sLibz-CommonBoost")

###
cmake_minimum_required(VERSION "${VAR_cmake_version}")
project("${VAR_project_name}")

###
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
##X
find_package(Boost REQUIRED COMPONENTS system)

###
file(
  GLOB_RECURSE ARR_cxx_src
  "${PROJECT_SOURCE_DIR}/cxx_src/*.cxx"
)
list(
  APPEND ARR_cxx_include
  "${PROJECT_SOURCE_DIR}/cxx_include/"
)
list(
  APPEND ARR_cxx_library
  "${VAR_package_name}-sLibz-Common"
  #
  "Boost::system"
  #
)
##X
add_library(
  "${VAR_project_name}" OBJECT
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
