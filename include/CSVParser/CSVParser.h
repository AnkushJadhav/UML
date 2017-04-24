#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#define TOKEN ','

using namespace std;

class CSVParser {
	public:
		vector< vector<string> > parseFile(const string fileName);
		void printFile(const string fileName);
		int getNumberOfRecords(const string fileName);
		int getNumberOfFields(const string fileName);
};
