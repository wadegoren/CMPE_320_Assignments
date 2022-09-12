#include "insultgenerator_19mam37.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

string InsultGenerator::initialize()
{
    fstream file;
    file.open("/Users/matthewmaceachern/Downloads/CMPE_320_Assignments/Assignment_1/InsultsSource.txt");
    string vals;
    cout << vals << "SUCCESS";
    // getline(file, vals);
    return vals;
}


// string FileException::what()
// {
//     return "Error the file could not be read";
// }