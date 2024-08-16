cmake_minimum_required(VERSION 3.20)
cmake_policy(SET CMP0091 NEW)
cmake_policy(SET CMP0042 NEW)

set(CMAKE_CXX_STANDARD 20)
set(ORTOOLS_ROOT ${CMAKE_SOURCE_DIR}/cmake/or-tools_x64/)

project(ortools_binding LANGUAGES CXX)

# FIXME 生产, 开发
add_definitions(
  -DNAPI_VERSION=18
  -DNAPI_DISABLE_CPP_EXCEPTIONS
  -DNODE_ADDON_API_DISABLE_DEPRECATED
  -DKAIFA1
)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${ORTOOLS_ROOT})
find_package(ortools REQUIRED)

include_directories(${ORTOOLS_INCLUDE_DIRS})

aux_source_directory(cppsrc cppsrc)
aux_source_directory(cppsrc/operations_research cppsrc_operations_research)

message("#### CMAKE_JS_SRC  " ${CMAKE_JS_SRC})

add_library(${PROJECT_NAME} SHARED
  ${cppsrc}
  ${cppsrc_operations_research}
  ${CMAKE_JS_SRC}
)
target_include_directories(${PROJECT_NAME}
  PUBLIC
  ${CMAKE_JS_INC}
  ${PROJECT_SOURCE_DIR}/node_modules/node-addon-api
  ${PROJECT_SOURCE_DIR}/node_modules/node-api-headers/include
)
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")

message("#### ORTOOLS_LIBRARIES  " ${ORTOOLS_LIBRARIES})

target_link_libraries(${PROJECT_NAME} ${ORTOOLS_LIBRARIES} ${CMAKE_JS_LIB})

set_property(TARGET ${PROJECT_NAME} PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")

if(MSVC AND CMAKE_JS_NODELIB_DEF AND CMAKE_JS_NODELIB_TARGET)
  # Generate node.lib
  execute_process(COMMAND ${CMAKE_AR} /def:${CMAKE_JS_NODELIB_DEF} /out:${CMAKE_JS_NODELIB_TARGET} ${CMAKE_STATIC_LINKER_FLAGS})
endif()
