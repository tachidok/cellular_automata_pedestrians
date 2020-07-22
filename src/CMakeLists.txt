# Indicate source files
SET(SRC_cap cellularAutomata.cpp floorPed.cpp pedestrian.cpp)

# Create executable
ADD_EXECUTABLE(demo_cap ${SRC_cap})

# Indicate linking libraries
# SET(LIB_cap general_lib problem_lib)
# ... and link againts them  
#TARGET_LINK_LIBRARIES(demo_basic_interpolation ${LIB_cap})
#TARGET_LINK_LIBRARIES(demo_cap)

# Check if the output/bin directory exists
IF(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/bin)
  # Then create the directory
  FILE(MAKE_DIRECTORY "${bin}")
ENDIF(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# Set directory where to create the executables
set_target_properties( demo_cap
  PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
  )