#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../TestCommon.hh"
#include "call_data/CallRecord.hh"
using namespace CallData;

#define TEST_CASE CallRecordTest

GTEST(shouldReturnAValidStringRepresentation)
{
    CallRecord rec("21/02/2011",CallType::LOCAL,5,"Nick","974503244");
    ASSERT_STREQ("21/02/2011 LOC 5 Nick 974503244",rec.operator string().c_str());
}

