#include <iostream>
#include <boost/foreach.hpp>
using namespace std;

#include "call_cost/SimpleCallCostCalculator.hh"

namespace CallCost {

    list<CallCostRecord*>* SimpleCallCostCalculator::calculateCost(
            list<CallRecord*>* callRecs) {
        list<CallCostRecord*>* cosRecList = new list<CallCostRecord*>();

        BOOST_FOREACH(CallRecord* callRec, *callRecs)
        {
            double callCost = callRec->callType().costFor(callRec->duration());
            CallCostRecord *costRec = new CallCostRecord(*callRec,callCost);
            cosRecList->push_back(costRec);
        }

        return cosRecList;
    }

}
