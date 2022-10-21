//
// Created by Matthew MacEachern on 10/16/22.
//

#ifndef ASSIGNMENT_2_FRACTION_19MAM37_H
#define ASSIGNMENT_2_FRACTION_19MAM37_H
#include <iostream>
#include <exception>
using namespace std;

class Fraction {
    public:
        int numerator();
        int denominator();
        Fraction(int numerators = 0, int denominators = 1);
        Fraction(int numFrac);
//    private:
        int numeratorr;
        int denominatorr;
};

class FractionException : public exception {
    public:
        FractionException(const string& errorMessage);
        string& what();
    private:
        string errorMessage;
};

#endif //ASSIGNMENT_2_FRACTION_19MAM37_H
