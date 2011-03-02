#ifndef FILEBASEDCALLDATAPARSER_HH_
#define FILEBASEDCALLDATAPARSER_HH_

#include <string>
using namespace std;

#include "CallDataParser.hh"

namespace CallParser {

	class FileBasedCallDataParser : public CallDataParser {

	    public:
	      FileBasedCallDataParser(string fileName);
	      ~FileBasedCallDataParser();
	       virtual list<CallRecord*>* parseRecords();
		private:
	       CallRecord* toCallRecord(string line);

	       string _fileName;
	};
}


#endif /* FILEBASEDCALLDATAPARSER_HH_ */
