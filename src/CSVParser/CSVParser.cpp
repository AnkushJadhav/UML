#include "CSVParser.h"

vector< vector<string> > CSVParser::parseFile(const string fileName) {
	try {
		int token_count = 0;
		bool initial_row = true;
		vector< vector<string> > data;
		ifstream fileReader;
		fileReader.open(fileName.c_str(), ios::in);
		if (fileReader.is_open()) {
			string cLine;
			while ( getline(fileReader, cLine) ) {
				istringstream str(cLine);
				string pch;
				vector<string> cData;
				int current_token_count = 0;
				while ( getline(str, pch, TOKEN)) {
					cData.push_back(pch);
					if (initial_row)
						token_count++;
					else
						current_token_count++;
				}
				if (!initial_row) {
					if (current_token_count != token_count) {
						throw "Invalid CSV file.";
					}
				}
				initial_row = false;
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
	catch (const char* msg) {
		cerr << "Failed to parse the CSV file : Exception = " << msg << endl;
	}
}

void CSVParser::printFile(const string fileName) {
	vector< vector<string> > data = parseFile(fileName.c_str());
	for(unsigned int i = 0; i < data.size(); i++) {
		for (unsigned int j = 0; j < data[i].size(); j++) {
			cout << data[i][j] << "\t" ;
		}
	cout << endl;
	}
}

int CSVParser::getNumberOfRecords(const string fileName) {
	vector< vector<string> > data = parseFile(fileName.c_str());
	return data.size();
}

int CSVParser::getNumberOfFields(const string fileName) {
	vector< vector<string> > data = parseFile(fileName.c_str());
	return data[0].size();
}
