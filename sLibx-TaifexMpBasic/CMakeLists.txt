###
set(VAR_project_name "${VAR_package_name}-sLibx-TaifexMpBasic")

###
cmake_minimum_required(VERSION "${VAR_cmake_version}")
project("${VAR_project_name}")

###
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
##X
find_package("Boost" REQUIRED COMPONENTS "headers")

###
unset(ARR_cxx_src)
unset(ARR_cxx_include)
unset(ARR_cxx_library)
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
  "Boost::headers"
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
