cmake_minimum_required(VERSION 3.15)
cmake_policy(SET CMP0091 NEW)
cmake_policy(SET CMP0042 NEW)

set(CMAKE_CXX_STANDARD 20)

project(ortools_binding LANGUAGES CXX)

add_library(${PROJECT_NAME} SHARED ./src/index.cpp ${CMAKE_JS_SRC})

target_compile_definitions(
  ${PROJECT_NAME}
  PRIVATE
  NAPI_VERSION=8
  NODE_ADDON_API_ENABLE_TYPE_CHECK_ON_AS
  NAPI_DISABLE_CPP_EXCEPTIONS
  NOMINMAX
)

target_include_directories(
  ${PROJECT_NAME}
  PRIVATE
  ${CMAKE_JS_INC}
  ${PROJECT_SOURCE_DIR}/node_modules/node-addon-api
  ${PROJECT_SOURCE_DIR}/node_modules/node-api-headers/include
  ${PROJECT_SOURCE_DIR}/cmake/or-tools_x64_VisualStudio2022_cpp_v9.11.4210/include
)

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")

target_link_libraries(
  ${PROJECT_NAME}
  ${CMAKE_JS_LIB}
  ${PROJECT_SOURCE_DIR}/cmake/or-tools_x64_VisualStudio2022_cpp_v9.11.4210/lib/ortools_full.lib
  ${PROJECT_SOURCE_DIR}/cmake/or-tools_x64_VisualStudio2022_cpp_v9.11.4210/lib/utf8_validity.lib
)

if(MSVC)
  set_property(TARGET ${PROJECT_NAME} PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
endif(MSVC)

if(MSVC AND CMAKE_JS_NODELIB_DEF AND CMAKE_JS_NODELIB_TARGET)
  execute_process(COMMAND ${CMAKE_AR} /def:${CMAKE_JS_NODELIB_DEF} /out:${CMAKE_JS_NODELIB_TARGET} ${CMAKE_STATIC_LINKER_FLAGS})
endif()
