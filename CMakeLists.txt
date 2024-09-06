cmake_minimum_required(VERSION 3.15)
cmake_policy(SET CMP0091 NEW)
cmake_policy(SET CMP0042 NEW)

set(CMAKE_CXX_STANDARD 20)

project(ortools_binding LANGUAGES CXX)

add_definitions(
  -DNAPI_VERSION=8
  -DNAPI_DISABLE_CPP_EXCEPTIONS
  -DNODE_ADDON_API_DISABLE_DEPRECATED
  -DGDEBUG
)

include_directories(
  ${CMAKE_JS_INC}
  ${PROJECT_SOURCE_DIR}/node_modules/node-addon-api
  ${PROJECT_SOURCE_DIR}/node_modules/node-api-headers/include
  ${PROJECT_SOURCE_DIR}/cmake/or-tools_x64_VisualStudio2019_cpp_v9.6.2534/include
)

add_library(${PROJECT_NAME} SHARED ./src/index.cpp ${CMAKE_JS_SRC})

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")

target_link_libraries(
  ${PROJECT_NAME}
  ${CMAKE_JS_LIB}
  ${PROJECT_SOURCE_DIR}/cmake/or-tools_x64_VisualStudio2019_cpp_v9.6.2534/lib/ortools_full.lib
)

set_property(TARGET ${PROJECT_NAME} PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")

if(MSVC AND CMAKE_JS_NODELIB_DEF AND CMAKE_JS_NODELIB_TARGET)
  # Generate node.lib
  execute_process(COMMAND ${CMAKE_AR} /def:${CMAKE_JS_NODELIB_DEF} /out:${CMAKE_JS_NODELIB_TARGET} ${CMAKE_STATIC_LINKER_FLAGS})
endif()