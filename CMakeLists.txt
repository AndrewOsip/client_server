cmake_minimum_required(VERSION 2.8)

project (server)

set(SOURCES
    	main.cpp
    	Entities/ClientRequestConverter.cpp

    	Executor/IExecutor.cpp
    	Executor/FunctionExecutor.cpp

    	Parsers/XmlParser.cpp
    	Parsers/JSONParser.cpp
    	Parsers/IDataParser.cpp
)

add_executable(server ${SOURCES})

include_directories(server
    PRIVATE
        ${PROJECT_SOURCE_DIR}/
)


add_subdirectory(pugi)
target_link_libraries(server pugixml)

get_filename_component(RAPIDJSON_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(RAPIDJSON_INCLUDE_DIRS "usr/include")
message(STATUS "RapidJSON found. Headers: ${RAPIDJSON_INCLUDE_DIRS}")
