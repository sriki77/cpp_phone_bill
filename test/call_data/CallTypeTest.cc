#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../TestCommon.hh"
#include "call_data/CallType.hh"
#include <stdexcept>
using namespace CallData;

#define TEST_CASE CallTypeTest

GTEST(shouldProvideThreeCallTypes) {
    ASSERT_STREQ("LOC",CallType::LOCAL);
    ASSERT_STREQ("STD",CallType::STD);
    ASSERT_STREQ("ISD",CallType::ISD);
}

GTEST(shouldConvertStringToCallType) {
    ASSERT_EQ(CallType::STD,CallType::toCallType("STD"));
    ASSERT_EQ(CallType::LOCAL,CallType::toCallType("LOC"));
    ASSERT_EQ(CallType::ISD,CallType::toCallType("ISD"));
}

GTEST(shouldThrowErrorWhenAnInvalidCodeIsPassedToString) {
    ASSERT_THROW(CallType::toCallType("XXX"),invalid_argument);
}

GTEST(shouldCalculateTheCorrectCostForCallType) {
    ASSERT_EQ(10,CallType::LOCAL.costFor(20));
    ASSERT_EQ(20,CallType::STD.costFor(20));
    ASSERT_EQ(40,CallType::ISD.costFor(20));
}
