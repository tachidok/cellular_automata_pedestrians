cmake_minimum_required (VERSION 3.5)
project (CAP)

MESSAGE( STATUS "-----------------------------------------------------------------------" )
MESSAGE( STATUS "-----------------------------------------------------------------------" )
MESSAGE( STATUS "-----------------------------------------------------------------------" )

SET(CELLULAR_AUTOMATON_C_FLAGS "-O0 -g -Wall -Wshadow")
SET(CELLULAR_AUTOMATON_CXX_FLAGS "-O0 -g -Wall -Wshadow -std=c++11")

# ----------------------------------------------------------------------
# Set modified compilation variables
# ----------------------------------------------------------------------
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CELLULAR_AUTOMATON_C_FLAGS}" )
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CELLULAR_AUTOMATON_CXX_FLAGS}" )

ADD_SUBDIRECTORY(src)

MESSAGE( STATUS "-----------------------------------------------------------------------" )
MESSAGE( STATUS "-----------------------------------------------------------------------" )
MESSAGE( STATUS "-----------------------------------------------------------------------" )