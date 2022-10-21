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
        int numeratorr;
        int denominatorr;

        const int& numerator() const;
        const int& denominator() const;

        Fraction(int numerators = 0, int denominators = 1); //Constructor set to a default value of numerator 0 and denominator 1

        int GCD(const int& a, const int& b);    //Greatest common denominator function

        //Unary Operators
        Fraction& operator++(); //Pre-increment
        Fraction& operator-();  //Negation
        Fraction operator++(int);   //Post-increment

        Fraction& operator+=(const Fraction& rightH);

        friend ostream& operator<<(ostream& out, const Fraction& fraction);
        friend istream& operator<<(istream& out, const Fraction fraction);
};

class FractionException : public exception {
public:
    FractionException(const string& errorMessage);
    string& what();
private:
    string errorMessage;
};

Fraction operator+(const Fraction& leftH, const Fraction& rightH);

bool operator<(const Fraction& leftH, const Fraction& rightH);

bool operator>(const Fraction& leftH, const Fraction& rightH);

bool operator>=(const Fraction& leftH, const Fraction& rightH);

bool operator<=(const Fraction& leftH, const Fraction& rightH);

bool operator==(const Fraction& leftH, const Fraction& rightH);

bool operator!=(const Fraction& leftH, const Fraction& rightH);

Fraction operator-(const Fraction& leftH, const Fraction& rightH);

Fraction operator*(const Fraction& leftH, const Fraction& rightH);

Fraction operator/(const Fraction& leftH, const Fraction& rightH);

//ostream& operator<<(ostream& out, const Fraction& fraction);
//
//istream& operator<<(istream& out, const Fraction fraction);

#endif //ASSIGNMENT_2_FRACTION_19MAM37_H
