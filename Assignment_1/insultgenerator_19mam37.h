#pragma once

#include <vector>
#include <exception>
#include <string>

using namespace std;

class InsultGenerator {
    public:
        void initialize();
        vector <string> columnOne, columnTwo, columnThree;
        int randomNumberGenerator();
        string talkToMe();
//        vector<string> insults2;
        vector<string> generate(const int& numOfInsults);
        bool compareFunc(string one, string two);
        void generateAndSave(const string& fileName, const int& numInsults);
};

class FileException : public exception {
    public:
        FileException(const string& errorMessage);
        string& what();
    private:
        string errorMessage;
};

class NumInsultsOutOfBounds : public exception {
    public:
        NumInsultsOutOfBounds(const string& errorMessage);
        string& what();
    private:
        string errorMessage;
};