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
        const int& getNumerator() const;
        const int& getDenominator() const;
        Fraction(int numerators = 0, int denominators = 1);
//        Fraction(int numFrac);
        Fraction& operator++();
        Fraction& operator-();
        Fraction operator++(int);
//    private:
        int numeratorr;
        int denominatorr;
};

Fraction operator+(const Fraction& leftH, const Fraction& rightH);

Fraction operator-(const Fraction& leftH, const Fraction& rightH);

Fraction operator*(const Fraction& leftH, const Fraction& rightH);

Fraction operator/(const Fraction& leftH, const Fraction& rightH);

ostream& operator<<(ostream& out, const Fraction& fraction);

istream& operator<<(istream& out, const Fraction fraction);

class FractionException : public exception {
    public:
        FractionException(const string& errorMessage);
        string& what();
    private:
        string errorMessage;
};

#endif //ASSIGNMENT_2_FRACTION_19MAM37_H
