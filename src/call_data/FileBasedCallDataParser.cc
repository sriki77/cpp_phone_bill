#include "call_data/FileBasedCallDataParser.hh"

#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

namespace CallData {


    FileBasedCallDataParser::FileBasedCallDataParser(string fileName):_fileName(fileName)
    {
    }


    FileBasedCallDataParser::~FileBasedCallDataParser()
    {
    }


    list<CallRecord*>* FileBasedCallDataParser::parseRecords()
    {
        list<CallRecord*>* callRecordList= new list<CallRecord*>;

        ifstream recFile(_fileName.c_str());

        if(!recFile){
            cerr<<"Unable to open file: "<<_fileName <<endl;
            return callRecordList;
        }

        string line;

        while(std::getline(recFile,line)){
            cout<<line<<endl;
        }

        recFile.close();

        return callRecordList;
    }


}
