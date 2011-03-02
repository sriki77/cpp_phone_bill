#ifndef CALLTYPE_HH_
#define CALLTYPE_HH_
#include <string>
#include <stdexcept>
using namespace std;

namespace CallData {

    //Represents the call type
    class CallType {
        public:
            const static CallType LOCAL;
            const static CallType STD;
            const static CallType ISD;
            static CallType toCallType(string code)throw(invalid_argument);

            operator const char*() const;
            double costFor(int mins) const;
        private:
            CallType(string code,double costPerMin);
            string _code;
            double _costPerMin;
            const static CallType ALL_CALL_TYPES[];
    };


}

#endif /* CALLTYPE_HH_ */
