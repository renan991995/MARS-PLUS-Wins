cmake_minimum_required (VERSION 2.6)

#set(CMAKE_CXX_COMPILER "$ENV{CONDA_PREFIX}/bin/x86_64-conda-linux-gnu-g++")
#set(CMAKE_C_COMPILER "$ENV{CONDA_PREFIX}/bin/x86_64-conda-linux-gnu-gcc")
file(TO_CMAKE_PATH $ENV{CONDA_PREFIX} envdir)
#set(CMAKE_C_COMPILER "${envdir}/Library/mingw-w64/bin/gcc.exe")
#set(CMAKE_CXX_COMPILER "${envdir}/Library/mingw-w64/bin/g++.exe")
set(CMAKE_C_COMPILER "${envdir}/Library/bin/clang.exe")
set(CMAKE_RC_COMPILER "${envdir}/Library/bin/clang.exe")
set(CMAKE_CXX_COMPILER "${envdir}/Library/bin/clang.exe")

set(filename	
		CASES_NEU.cpp		CASES_NEU.h
		CASES_IL.cpp		CASES_IL.h
		CASES_IL_INDEPENDENT.cpp		CASES_IL_INDEPENDENT.h
		UTILITY.cpp			UTILITY.h
		MOLECULE.cpp		MOLECULE.h
		IL.cpp				IL.h
		ELEMENTS.cpp		ELEMENTS.h
		PARAMETER.h
		main.cpp			
	)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
project(MARS-PLUS)

#OBabel setting
#include_directories( "$ENV{CONDA_PREFIX}/include/openbabel3" )
include_directories( "${envdir}/Library/include/openbabel3" )

#g++ setting
#include_directories("$ENV{CONDA_PREFIX}/x86_64-conda-linux-gnu/include")
include_directories("${envdir}/Library/mingw-w64/include")


#include_directories("$ENV{CONDA_PREFIX}/include/eigen3")
include_directories("${envdir}/Library/include/eigen3")



add_executable(MARS-PLUS ${filename})
#target_link_libraries(MARS-PLUS "$ENV{CONDA_PREFIX}/lib/libopenbabel.so.7") 
#target_link_libraries(MARS-PLUS "${envdir}/Library/bin/openbabel-3.lib") 
target_link_libraries(MARS-PLUS "${envdir}/Library/bin/openbabel-3.dll") 



message("Default build type is ${CMAKE_BUILD_TYPE}")

message("CMAKE_C_FLAGS_DEBUG is ${CMAKE_C_FLAGS_DEBUG}")
message("CMAKE_C_FLAGS_RELEASE is ${CMAKE_C_FLAGS_RELEASE}")
message("CMAKE_C_FLAGS_RELWITHDEBINFO is ${CMAKE_C_FLAGS_RELWITHDEBINFO}")
message("CMAKE_C_FLAGS_MINSIZEREL is ${CMAKE_C_FLAGS_MINSIZEREL}")

message("CMAKE_CXX_FLAGS_DEBUG is ${CMAKE_CXX_FLAGS_DEBUG}")
message("CMAKE_CXX_FLAGS_RELEASE is ${CMAKE_CXX_FLAGS_RELEASE}")
message("CMAKE_CXX_FLAGS_RELWITHDEBINFO is ${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")
message("CMAKE_CXX_FLAGS_MINSIZEREL is ${CMAKE_CXX_FLAGS_MINSIZEREL}")

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to Release")
    set(CMAKE_BUILD_TYPE "debug")
endif()


