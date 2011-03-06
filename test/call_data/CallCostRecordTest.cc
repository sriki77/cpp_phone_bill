#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sstream>
#include <iomanip>
#include "../TestCommon.hh"
#include "call_data/CallCostRecord.hh"
using namespace CallData;
using namespace std;

#define TEST_CASE CallCostRecordTest

GTEST(shouldGenerateValidStringRep) {
    const char *caller = "James Bond";
    int duration = 10;
    CallRecord callRec("xxx", CallType::LOCAL, duration, caller, "007");
    int callCost = 5;
    CallCostRecord costRec(callRec, callCost);

    ostringstream os;
    os<<"Summary for "<<caller<<endl;
    os<<"Total mins: "<<duration<<endl;
    os<<"Total cost: "<<callCost<<endl;

    ASSERT_EQ(os.str(),costRec.operator string());
}
