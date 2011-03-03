#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <list>
#include <fstream>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/filesystem/operations.hpp>
using namespace std;
namespace io = boost::iostreams;

#include "call_parser/FileBasedCallDataParser.hh"
#include "call_data/CallRecord.hh"
using namespace CallData;
using namespace CallParser;

#include "../TestCommon.hh"
using namespace TestCommon;
using namespace boost::filesystem;

#define TEST_CASE FileBasedCallDataParserTest

GTEST(shouldGenerateCallRecordForValidInputFile)
{
    const char *if_cur_dir_is_root = "test/call_parser/call_data_small.txt";
    const char *if_cur_dir_is_test = "call_parser/call_data_small.txt";
    const char *data_file_name=exists(if_cur_dir_is_root)?if_cur_dir_is_root:if_cur_dir_is_test;
    CallDataParser *dataParser = new FileBasedCallDataParser(data_file_name);
    list<CallRecord*>* dataRecords = dataParser->parseRecords();

    EXPECT_TRUE(dataRecords != NULL);
    EXPECT_EQ(3,dataRecords->size());

    ifstream recFile(data_file_name);
    io::filtering_istream in(recFile);

    BOOST_FOREACH(CallRecord* rec,*dataRecords){
        string output;
        getline(in, output);
        EXPECT_EQ(output,rec->operator string());
    }

    release(dataRecords);
}
