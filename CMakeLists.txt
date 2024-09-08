cmake_minimum_required(VERSION 3.15)
cmake_policy(SET CMP0091 NEW)
cmake_policy(SET CMP0042 NEW)

set(CMAKE_CXX_STANDARD 20)

# Transform all .proto files
# file(GLOB_RECURSE PROTO_FILES "./cmake/or-tools-9.6/ortools/*.proto")
# string(REPLACE ";" "\n" PROTO_FILES_LIST "${PROTO_FILES}")
# message(STATUS ${PROTO_FILES_LIST})
# .\cmake\protoc-21.12-win64\bin\protoc.exe --proto_path=.\cmake\or-tools-9.6 --cpp_out=.\src\ortools_proto
#
project(ortools_binding LANGUAGES CXX)

add_library(${PROJECT_NAME} SHARED ./src/index.cpp ${CMAKE_JS_SRC})

target_compile_definitions(
  ${PROJECT_NAME}
  PRIVATE
  NAPI_VERSION=8
  NAPI_DISABLE_CPP_EXCEPTIONS
  NODE_ADDON_API_DISABLE_DEPRECATED
  GDEBUG
)

target_include_directories(
  ${PROJECT_NAME}
  PRIVATE
  ${CMAKE_JS_INC}
  ${PROJECT_SOURCE_DIR}/node_modules/node-addon-api
  ${PROJECT_SOURCE_DIR}/node_modules/node-api-headers/include
  ${PROJECT_SOURCE_DIR}/cmake/or-tools_x64_VisualStudio2019_cpp_v9.6.2534/include
  ${PROJECT_SOURCE_DIR}/src
)

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")

target_link_libraries(
  ${PROJECT_NAME}
  ${CMAKE_JS_LIB}
  ${PROJECT_SOURCE_DIR}/cmake/or-tools_x64_VisualStudio2019_cpp_v9.6.2534/lib/ortools_full.lib
)

if(MSVC)
  set_property(TARGET ${PROJECT_NAME} PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
endif(MSVC)

if(MSVC AND CMAKE_JS_NODELIB_DEF AND CMAKE_JS_NODELIB_TARGET)
  execute_process(COMMAND ${CMAKE_AR} /def:${CMAKE_JS_NODELIB_DEF} /out:${CMAKE_JS_NODELIB_TARGET} ${CMAKE_STATIC_LINKER_FLAGS})
endif()
