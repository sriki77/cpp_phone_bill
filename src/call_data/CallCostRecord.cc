#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

#include "call_data/CallCostRecord.hh"

namespace CallData {

    CallCostRecord::CallCostRecord(const CallRecord& callRec, double cost) :
        _callRec(callRec), _cost(cost) {
    }

    CallCostRecord::operator string() {
        ostringstream os;
        os << "Summary for " << _callRec.caller() << endl;
        os << "Total mins: " << _callRec.duration() << endl;
        os << "Total cost: " << _cost << endl;
        return os.str();
    }

}
