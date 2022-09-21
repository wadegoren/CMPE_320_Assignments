#include "insultgenerator_19mam37.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <time.h>
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

//vector<string> InsultGenerator::generate(int numOfInsults) {
//    cout << numOfInsults;
//}

vector<string> InsultGenerator::generate(const int& numOfInsults) {
    cout << numOfInsults;
    string insult1;
    vector<string> insults2;
    for (int i = 0; i < numOfInsults; i++){
        insult1 = talkToMe();
        insults2[i] = insult1;
        cout << insults2[i] << '\n';
    }
    return insults2;
}


FileException::FileException(const string &errorMessage){}

string FileException::what() {
    return {"errorrrrrr"};
}

