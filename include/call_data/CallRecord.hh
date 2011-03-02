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

		private:
	        string _date;
	        CallType _callType;
	        int _duration;
	        string _caller;
	        string _callerNum;
	};
}


#endif /* CALLRECORD_HH_ */
