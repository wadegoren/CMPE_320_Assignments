#pragma once

#include <vector>
using namespace std;

class InsultGenerator {
    public:
        void initialize();
        vector <string> columnOne, columnTwo, columnThree;
        int randomNumberGenerator();
        string talkToMe();
//        vector<string> insults2;
        vector<string> generate(const int& numOfInsults);
};

class FileException {
public:
    FileException(const string& errorMessage);
    string what();

};