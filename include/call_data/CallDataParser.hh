#ifndef CALLDATAPARSER_HH_
#define CALLDATAPARSER_HH_

#include <list>
using namespace std;

#include "CallRecord.hh"

namespace CallData {
    //Represents a Call Data Parser
	class CallDataParser{
		public:
	        virtual list<CallRecord*>* parseRecords()=0;
	        inline virtual ~CallDataParser(){};
	};
}




#endif /* CALLDATAPARSER_HH_ */
