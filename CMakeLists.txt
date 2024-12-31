set(VAR_cmake_version "3.12")
set(VAR_package_name "XplumSdk-TaifexMp")
##X
set(OPT_IS_ENABLE_EXAMPLE ON)

###
cmake_minimum_required(VERSION "${VAR_cmake_version}")
project("${VAR_package_name}" VERSION 0.08.020088)

###
add_subdirectory("${PROJECT_SOURCE_DIR}/sLibx-TaifexMpBasic/")
add_subdirectory("${PROJECT_SOURCE_DIR}/sLibx-TaifexMpExtra/")
add_subdirectory("${PROJECT_SOURCE_DIR}/sLibz-Common/")
add_subdirectory("${PROJECT_SOURCE_DIR}/sLibz-CommonBoost/")
##X
if("${OPT_IS_ENABLE_EXAMPLE}")
  add_subdirectory("${PROJECT_SOURCE_DIR}/sTest-Example/")
endif()

