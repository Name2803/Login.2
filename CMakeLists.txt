cmake_minimum_required(VERSION 3.13 FATAL_ERROR)


set(PROJECT_NAME Login)
project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} 
	src/main.cpp
	secr/secr.h
	secr/secr.cpp
	secv/secv.h
	secv/secv.cpp
	server/data.txt
	server/lpdata.txt
	server/server.h
	server/server.cpp
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)