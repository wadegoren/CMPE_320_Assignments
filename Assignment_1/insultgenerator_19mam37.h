#pragma once

#include <vector>
#include <exception>
#include <string>

using namespace std;

class InsultGenerator {
    public:
        void initialize();  //Method reading insults from a file and allocating to a vector
        vector <string> columnOne, columnTwo, columnThree;  //Vectors holding the columns of insults
        int randomNumberGenerator();    //Method generating random variables
        string talkToMe();  //Randomly accessing spaces in the vector using randomNumberGenerator
        vector<string> generate(const int& numOfInsults);   //Method generating the requested number of insults
        void generateAndSave(const string& fileName, const int& numInsults);    //Method saving the generated insults to a file
};

class FileException : public exception {
    public:
        FileException(const string& errorMessage);
        string& what(); //Used for returning a given error message when the exception is caught
    private:
        string errorMessage;
};

class NumInsultsOutOfBounds : public exception {
    public:
        NumInsultsOutOfBounds(const string& errorMessage);
        string& what(); //Used for returning a given error message when the exception is caught
    private:
        string errorMessage;
};