#include <iostream>
#include <boost/foreach.hpp>
using namespace std;

#include "call_data/CallType.hh"
#include <stdexcept>

namespace CallData {

    const CallType::CallType CallType::LOCAL("LOC",0.5);
    const CallType::CallType CallType::STD("STD",1);
    const CallType::CallType CallType::ISD("ISD",2);
    const CallType CallType::ALL_CALL_TYPES[] = { LOCAL, STD, ISD };

    CallType::operator const char*() const {
        return _code.c_str();
    }

    CallType::CallType(string code,double costPerMin) :
        _code(code),_costPerMin(costPerMin) {
    }

    CallType CallType::toCallType(string code)throw(invalid_argument) {
        BOOST_FOREACH(CallType type,ALL_CALL_TYPES)
        {
            if(code==string(type)){
                return type;
            }
        }

        throw invalid_argument("Invalid Argument passed: "+code);

    }

    double CallType::costFor(int mins) const
    {
        return mins*_costPerMin;
    }



}
