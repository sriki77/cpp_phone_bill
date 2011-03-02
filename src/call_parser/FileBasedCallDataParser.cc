#include "call_parser/FileBasedCallDataParser.hh"

#include <fstream>
#include <iostream>
#include <iomanip>
#include <boost/xpressive/xpressive.hpp>

using namespace std;
using namespace boost::xpressive;

namespace CallParser {

    FileBasedCallDataParser::FileBasedCallDataParser(string fileName) :
        _fileName(fileName) {
    }

    FileBasedCallDataParser::~FileBasedCallDataParser() {
    }

    list<CallRecord*>* FileBasedCallDataParser::parseRecords() {
        list<CallRecord*>* callRecordList = new list<CallRecord*> ;

        ifstream recFile(_fileName.c_str());

        if (!recFile) {
            cerr << "Unable to open file: " << _fileName << endl;
            return callRecordList;
        }

        string line;

        while (std::getline(recFile, line)) {
            cout << line << endl;
            CallRecord* callRec = toCallRecord(line);
        }

        recFile.close();

        return callRecordList;
    }

    CallRecord* FileBasedCallDataParser::toCallRecord(string line) {
        sregex rex =
                sregex::compile("([^ ]+) ([^ ]+) ([^ ]+) ([^ ]+) ([^ ]+)");
        smatch what;

        CallRecord* callRec=NULL;

        if (regex_match(line, what, rex)) {
//            callRec=new CallRecord;
        }
        return NULL;
    }

}
