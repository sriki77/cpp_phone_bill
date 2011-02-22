#ifndef TESTCOMMON_HH_
#define TESTCOMMON_HH_

#include <list>
#include <memory>
#include <boost/foreach.hpp>

using namespace std;

#define GTEST(testName) TEST(TEST_CASE,testName)

namespace TestCommon {

    template<typename T> void release(T* srcPtr) {
        delete srcPtr;
    }

    template<typename T> void release(list<T*>* srcListPtr) {
        BOOST_FOREACH(T* srcPtr, *srcListPtr)
         {
               release(srcPtr);
         }

        delete srcListPtr;
    }

}

#endif /* TESTCOMMON_HH_ */
