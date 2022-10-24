//
// Created by Matthew MacEachern on 10/16/22.
//

#ifndef ASSIGNMENT_2_FRACTION_19MAM37_H
#define ASSIGNMENT_2_FRACTION_19MAM37_H
#include <iostream>
#include <exception>
#include <vector>
#include <sstream>
using namespace std;

class Fraction {
    public:
        //Numerator and Denominator values
        int numeratorr;
        int denominatorr;

        //Accessor methods
        const int& numerator() const;
        const int& denominator() const;

        vector<string> numerAndDenom;

        Fraction(int numerators = 0, int denominators = 1); //Constructor set to a default value of numerator 0 and denominator 1

        int GCD(const int& a, const int& b);    //Greatest common denominator function

        //Unary Operator Overloading
        Fraction& operator++(); //Pre-increment
        Fraction operator++(int);   //Post-increment
        Fraction& operator-();  //Negation

        //Binary Operator Overloading
        Fraction& operator+=(const Fraction& rightH);
        friend ostream& operator<<(ostream& out, const Fraction& fraction);
        friend istream& operator>>(istream& out, Fraction& fraction);
};

//Exception Class
class FractionException : public exception {
public:
    FractionException(const string& errorMessage);
    string& what();
private:
    string errorMessage;
};

//Binary Operator Overloading
Fraction operator+(const Fraction& leftH, const Fraction& rightH);

Fraction operator-(const Fraction& leftH, const Fraction& rightH);

Fraction operator*(const Fraction& leftH, const Fraction& rightH);

Fraction operator/(const Fraction& leftH, const Fraction& rightH);

//Binary Comparison Operator Overloading
bool operator<(const Fraction& leftH, const Fraction& rightH);

bool operator>(const Fraction& leftH, const Fraction& rightH);

bool operator>=(const Fraction& leftH, const Fraction& rightH);

bool operator<=(const Fraction& leftH, const Fraction& rightH);

bool operator==(const Fraction& leftH, const Fraction& rightH);

bool operator!=(const Fraction& leftH, const Fraction& rightH);

#endif //ASSIGNMENT_2_FRACTION_19MAM37_H
