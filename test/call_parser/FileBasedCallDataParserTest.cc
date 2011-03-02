#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <list>
using namespace std;

#include "call_parser/FileBasedCallDataParser.hh"
#include "call_data/CallRecord.hh"
using namespace CallData;
using namespace CallParser;

#include "../TestCommon.hh"
using namespace TestCommon;

#define TEST_CASE FileBasedCallDataParserTest

GTEST(shouldGenerateCallRecordForValidInputFile)
{
    CallDataParser* dataParser = new FileBasedCallDataParser("test/call_data/call_data_small.txt");
    list<CallRecord*>* dataRecords = dataParser->parseRecords();

    EXPECT_TRUE(dataRecords != NULL);
    EXPECT_EQ(0,dataRecords->size());

    release(dataRecords);
}
