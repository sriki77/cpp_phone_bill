#ifndef CALLCOSTCALCULATOR_HH_
#define CALLCOSTCALCULATOR_HH_

#include <list>
#include "call_data/CallRecord.hh"
#include "call_data/CallCostRecord.hh"
using namespace CallData;
using namespace std;

namespace CallCost {
	class CallCostCalculator{
		public:
	        list<CallCostRecord*>* calculateCost(list<CallRecord*> callRecs);
		private:
	};
}

#endif /* CALLCOSTCALCULATOR_HH_ */
