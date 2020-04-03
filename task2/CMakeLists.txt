cmake_minimum_required(VERSION 2.8)

project(finish)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY  ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(finish C/main.cpp)

add_subdirectory(B)

target_link_libraries(finish library)

execute_process(
	COMMAND python3 ${PROJECT_SOURCE_DIR}/A/preparing.py ${PROJECT_SOURCE_DIR}/A/index.h
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/A
)

include_directories(.)
