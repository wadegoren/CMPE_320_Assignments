#include "insultgenerator_19mam37.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <time.h>
#include <algorithm>
#include <random>

using namespace std;

void InsultGenerator::initialize(){
    srand(time(NULL));
    ifstream insultFile ("/Users/matthewmaceachern/Downloads/CMPE_320_Assignments/Assignment_1/InsultsSource.txt");

    if (insultFile.is_open()){
        string fileLine;
        while (getline(insultFile, fileLine)){  //Obtains each line of the file
            istringstream iss(fileLine);
            vector <string> allColumns; //Must be declared here to ensure that it fills correctly
            string singleString;
            while (getline(iss, singleString, '\t')){    //Split each line based on the tab delimiter
                allColumns.push_back(singleString); //allColumns vector is holding all the individual lines, each as a vector space
            }
            columnOne.push_back(allColumns[0]);
            columnTwo.push_back(allColumns[1]);
            columnThree.push_back(allColumns[2]);
        }
    }
}

string InsultGenerator::talkToMe() {
    int num1 = randomNumberGenerator();
    string firstInsult = columnOne[num1];
    int num2 = randomNumberGenerator();
    string secondInsult = columnTwo[num2];
    int num3 = randomNumberGenerator();
    string thirdInsult = columnThree[num3];
    return firstInsult + " " + secondInsult + " " + thirdInsult;
}

int InsultGenerator::randomNumberGenerator() {
    return rand() % 50;
}

vector<string> InsultGenerator::generate(const int& numberOfInsults) {
    string insult1;
    vector<string> insults2;
    if (numberOfInsults > 10000){
        throw NumInsultsOutOfBounds("Invalid Request: The number of insults is over 10,000");
    }
    if (numberOfInsults < 0){
        throw NumInsultsOutOfBounds("Invalid Request: The number of insults is less than 0");
    }
    for (int i = 0; i < numberOfInsults; i++){
        insult1 = talkToMe();
        insults2.push_back(insult1);
//        cout << insults2[i] << '\n';
    }
    return insults2;
}

bool InsultGenerator::compareFunc(string one, string two){
    return one<two;
}

void InsultGenerator::generateAndSave(const string& fileName, const int& numberInsults) {
    if (numberInsults > 10000 || numberInsults < 0){
        ofstream file(fileName);
        throw NumInsultsOutOfBounds("Invalid Request: The number of insults is invalid");
    }
    vector<string> insultsFull = generate(numberInsults);
    sort(insultsFull.begin(), insultsFull.end());
    ofstream file(fileName);
    for (auto & i : insultsFull){
        file << i << endl;
    }
    file.close();
}

FileException::FileException(const string& errorMessage) : errorMessage(errorMessage) {}
string& FileException::what() {return errorMessage;}

NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string &errorMessage) : errorMessage(errorMessage) {}
string& NumInsultsOutOfBounds::what() {return errorMessage;}
