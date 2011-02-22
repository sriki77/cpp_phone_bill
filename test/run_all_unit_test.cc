#include <iostream>
#include <gtest/gtest.h>
using namespace std;

int main(int argc, char** argv) {

	cout << "CTEST_FULL_OUTPUT" << endl;

	cout<< "Running All Tests..."<< endl;

	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();

}
