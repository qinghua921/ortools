cmake_minimum_required(VERSION 3.15)
cmake_policy(SET CMP0091 NEW)
cmake_policy(SET CMP0042 NEW)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)

# Find all .proto files
file(GLOB_RECURSE PROTO_FILES "cmake/or-tools-9.6/ortools/*.proto")
string(REPLACE "D:" " D:" PROTO_FILES_LIST "${PROTO_FILES}")
message(STATUS "Found .proto files:\n${PROTO_FILES_LIST}")

# protoc.exe --proto_path= --cpp_out=D:/code/tsortools/build/generated/ortools/sat

# Define the project
project(ortools_binding LANGUAGES CXX)

# Add library target
add_library(${PROJECT_NAME} SHARED ./src/index.cpp ${CMAKE_JS_SRC})

# Set compile definitions
target_compile_definitions(
  ${PROJECT_NAME}
  PRIVATE
  NAPI_VERSION=8
  NAPI_DISABLE_CPP_EXCEPTIONS
  NODE_ADDON_API_DISABLE_DEPRECATED
  GDEBUG
)

# Set include directories
target_include_directories(
  ${PROJECT_NAME}
  PRIVATE
  ${CMAKE_JS_INC}
  ${PROJECT_SOURCE_DIR}/node_modules/node-addon-api
  ${PROJECT_SOURCE_DIR}/node_modules/node-api-headers/include
  ${PROJECT_SOURCE_DIR}/cmake/or-tools_x64_VisualStudio2019_cpp_v9.6.2534/include
  ${PROJECT_SOURCE_DIR}/src/ortools_proto
)

# Set target properties
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")

# Link libraries
target_link_libraries(
  ${PROJECT_NAME}
  ${CMAKE_JS_LIB}
  ${PROJECT_SOURCE_DIR}/cmake/or-tools_x64_VisualStudio2019_cpp_v9.6.2534/lib/ortools_full.lib
)

# Set MSVC runtime library
if(MSVC)
  set_property(TARGET ${PROJECT_NAME} PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
endif(MSVC)

# Generate node.lib if needed
if(MSVC AND CMAKE_JS_NODELIB_DEF AND CMAKE_JS_NODELIB_TARGET)
  execute_process(COMMAND ${CMAKE_AR} /def:${CMAKE_JS_NODELIB_DEF} /out:${CMAKE_JS_NODELIB_TARGET} ${CMAKE_STATIC_LINKER_FLAGS})
endif()
