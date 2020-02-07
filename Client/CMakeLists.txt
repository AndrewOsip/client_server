cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project (client)

set(SOURCES
    	main.cpp
	
	IConnection/Connection/Connection.cpp
	InitialConditions/JSONSerialize/JsonInitialConditions.cpp   	
)

add_executable(client ${SOURCES})

include_directories(client
    PRIVATE
        ${PROJECT_SOURCE_DIR}/
)

get_filename_component(RAPIDJSON_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(RAPIDJSON_INCLUDE_DIRS "usr/include")
message(STATUS "RapidJSON found. Headers: ${RAPIDJSON_INCLUDE_DIRS}")
