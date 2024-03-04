set(VAR0_PROJECT_NAME "${CMAKE_PROJECT_NAME}-Example")

###
cmake_minimum_required(VERSION "3.24.2")
project("${VAR0_PROJECT_NAME}")
##-
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

###
include(FetchContent)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_Declare(
  googletest
  DOWNLOAD_EXTRACT_TIMESTAMP OFF
  URL "${CMAKE_SOURCE_DIR}/_deps/googletest.zip"
  URL_HASH "MD5=611067c2affbf9eafb919df5db1ea7f6"
)
FetchContent_MakeAvailable(googletest)

###
FILE(GLOB_RECURSE ARR0_PROJECT_CXX_SOURCE "${PROJECT_SOURCE_DIR}/cxx_src_gtest/*.cxx")
add_executable(
  "${VAR0_PROJECT_NAME}"
  "${ARR0_PROJECT_CXX_SOURCE}"
)
target_link_libraries(
  "${VAR0_PROJECT_NAME}" PRIVATE
  "${CMAKE_PROJECT_NAME}-Separate-Common"
  "${CMAKE_PROJECT_NAME}-Separate-CommonBoost"
  "${CMAKE_PROJECT_NAME}-Member01-TaifexMp-Origin"
  "${CMAKE_PROJECT_NAME}-Member02-TaifexMp-Widget"
  #
  "GTest::gtest_main"
  "GTest::gmock_main"
)
