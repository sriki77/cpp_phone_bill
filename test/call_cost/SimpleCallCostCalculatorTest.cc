#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <boost/filesystem/operations.hpp>
#include <iostream>
using namespace std;

#include "../TestCommon.hh"
#include "call_cost/CallCostCalculator.hh"
#include "call_cost/SimpleCallCostCalculator.hh"
#include "call_parser/CallDataParser.hh"
#include "call_parser/FileBasedCallDataParser.hh"
#include "call_data/CallCostRecord.hh"

using CallCost::CallCostCalculator;
using CallCost::SimpleCallCostCalculator;
using namespace boost::filesystem;
using CallParser::CallDataParser;
using CallParser::FileBasedCallDataParser;
using TestCommon::release;

#define TEST_CASE SimpleCallCostCalculatorTest

string toString(string caller, int duration, double cost) {
    ostringstream os;
    os << "Summary for " << caller << endl;
    os << "Total mins: " << duration << endl;
    os << "Total cost: " << cost << endl;
    return os.str();
}

list<string>* getExpectedOutput() {
    list<string>* expOutList=new list<string>;
    expOutList->push_back(toString("Nick",5,2.5));
    expOutList->push_back(toString("Dale",1,1));
    expOutList->push_back(toString("Nick",30,60));
    return expOutList;
}

GTEST(shouldGenerateCallRecordForValidInputFile)
{
    const char *if_cur_dir_is_root = "test/call_parser/call_data_small.txt";
    const char *if_cur_dir_is_test = "call_parser/call_data_small.txt";
    const char *data_file_name =
            exists(if_cur_dir_is_root) ? if_cur_dir_is_root
                    : if_cur_dir_is_test;
    CallDataParser *dataParser = new FileBasedCallDataParser(data_file_name);
    list<CallRecord*>* dataRecords = dataParser->parseRecords();

    EXPECT_TRUE(dataRecords != NULL);
    EXPECT_EQ(3,dataRecords->size());

    CallCostCalculator* costCalc=new SimpleCallCostCalculator();
    list<CallCostRecord*> *callCostRecs = costCalc->calculateCost(dataRecords);
    list<string>* expOutput=getExpectedOutput();

    BOOST_FOREACH(CallCostRecord* costRec,*callCostRecs) {
        cout<<costRec->operator string()<<endl;
        string expOutStr=expOutput->front();
        ASSERT_EQ(expOutStr,costRec->operator string());
        expOutput->pop_front();
    }
    release(expOutput);
    release(dataRecords);
}

