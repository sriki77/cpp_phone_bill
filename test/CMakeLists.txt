find_package(GTest REQUIRED)
find_library(GMOCK_LIB libgmock)
find_path(GMOCK_INC gmock/gmock.h)

include_directories(${GMOCK_INC})
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB_RECURSE TEST_FILES "*.cc") 
add_executable(${TEST_EXEC} ${TEST_FILES})
target_link_libraries(${TEST_EXEC} ${SRC_OBJ} ${GTEST_BOTH_LIBRARIES} pthread ${Boost_SYSTEM_LIBRARY} ${Boost_FILESYSTEM_LIBRARY})
add_test(${TEST_EXEC} ${TEST_EXEC})


