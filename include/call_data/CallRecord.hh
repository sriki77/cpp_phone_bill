#ifndef CALLRECORD_HH_
#define CALLRECORD_HH_

#include "CallType.hh"
#include <string>
using namespace std;

namespace CallData {
    //Represents a call record
	class CallRecord{
		public:
	        CallRecord(string date,CallType callType,int duration,string caller, string callerNum);
	        int duration() const;
	        string caller() const;
	        CallType callType() const;
	        operator string() const;
		private:
	        string _date;
	        CallType _callType;
	        int _duration;
	        string _caller;
	        string _callerNum;
	};
}

inline int CallData::CallRecord::duration() const
{
    return _duration;
}



inline string CallData::CallRecord::caller() const
{
    return _caller;
}



inline CallData::CallType CallData::CallRecord::callType() const
{
    return _callType;
}

#endif /* CALLRECORD_HH_ */
