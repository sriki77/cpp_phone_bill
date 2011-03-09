#ifndef SIMPLECALLCOSTCALCULATOR_HH_
#define SIMPLECALLCOSTCALCULATOR_HH_
#include "call_cost/CallCostCalculator.hh"

namespace CallCost {
    class SimpleCallCostCalculator: public CallCostCalculator {
        public:
           virtual list<CallCostRecord*>* calculateCost(list<CallRecord*>* callRecs);
        private:
    };
}

#endif /* SIMPLECALLCOSTCALCULATOR_HH_ */
