#ifndef CALLCOSTRECORD_HH_
#define CALLCOSTRECORD_HH_

#include "call_data/CallRecord.hh"

namespace CallData{

	class CallCostRecord{
		public:
	        CallCostRecord(const CallRecord& callRec,double cost);
	        operator string();
		private:
	        const CallRecord& _callRec;
	        double _cost;
	};
}

#endif /* CALLCOSTRECORD_HH_ */
