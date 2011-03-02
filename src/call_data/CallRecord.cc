#include "call_data/CallRecord.hh"
#include <boost/lexical_cast.hpp>
#include <cctype>

namespace CallData {

    CallRecord::CallRecord(string date, CallType callType, int duration,
            string caller, string callerNum) :
        _date(date), _callType(callType), _duration(duration), _caller(caller),
                _callerNum(callerNum) {
    }

    CallRecord::operator string() const {
        string strRep("");
        strRep = strRep + _date + " " + (_callType.operator const char *())
                + " " + boost::lexical_cast<string>(_duration) + " " + _caller + " " + _callerNum;

        return strRep.c_str();
    }
}
