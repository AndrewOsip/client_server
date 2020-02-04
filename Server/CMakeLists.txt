cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project (server)

set(SOURCES
    	main.cpp

	Connection/TCP/ClientWorker/TCPConncetion.cpp
	
	Converter/ClientRequestConverter.cpp

    	Executor/FunctionExecutor.cpp
	
	Serializer/JSON/JSONSerializer.cpp
	Serializer/JSON/JSONDeserializer.cpp
	Serializer/XML/XmlDeserializer.cpp
	Serializer/XML/XMLSerializer.cpp
	
)

add_executable(server ${SOURCES})

include_directories(server
    PRIVATE
        ${PROJECT_SOURCE_DIR}/
)


add_subdirectory(lib/pugi)
target_link_libraries(server pugixml)

get_filename_component(RAPIDJSON_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(RAPIDJSON_INCLUDE_DIRS "usr/include")
message(STATUS "RapidJSON found. Headers: ${RAPIDJSON_INCLUDE_DIRS}")
