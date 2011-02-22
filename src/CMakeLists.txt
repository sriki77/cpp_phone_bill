file(GLOB_RECURSE SRC_FILES "*.cc") 
add_library(${SRC_OBJ} SHARED ${SRC_FILES})

