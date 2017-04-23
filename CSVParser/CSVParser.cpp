#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#define TOKEN ','

using namespace std;

class CSVParser {

	public:
		/*
		bool isFileValid(ifstream fileReader) {
			int cCnt = 0;
			int rCnt = 0;
			string cLine;
			while ( getline(fileReader, cLine) ) {
				rCnt++;
				istringstream str(cLine);
				string pch;
				vector<string> cData;
				while ( getline(str, pch, TOKEN)) {	
					
				}
		}
		*/

		vector< vector<string> > parseFile(const string fileName) {
			try {
				vector< vector<string> > data;
				ifstream fileReader;
				fileReader.open(fileName.c_str(), ios::in);
				if (fileReader.is_open()) {
					string cLine;
					while ( getline(fileReader, cLine) ) {
						istringstream str(cLine);
						string pch;
						vector<string> cData;
						while ( getline(str, pch, TOKEN)) {	
							cData.push_back(pch);
						}
						data.push_back(cData);
					}
				}
				else {
					cerr << "Could not open file : " << fileName << endl;
				}
				return data;
			}
			catch (exception& e) {
				cerr << "Failed to parse the CSV file : Exception = " << e.what() << endl;
			}
		}

		void printFile(const string fileName) {
			vector< vector<string> > data = parseFile(fileName.c_str());
			for(unsigned int i = 0; i < data.size(); i++) {
				for (unsigned int j = 0; j < data[i].size(); j++) {
					cout << data[i][j] << "\t" ;
				}
				cout << endl;
			}
		}

		int getNumberOfRecords(const string fileName) {
			vector< vector<string> > data = parseFile(fileName.c_str());
			return data.size();
		}

		int getNumberOfFields(const string fileName) {
			vector< vector<string> > data = parseFile(fileName.c_str());
			return data[0].size();
		}
};

