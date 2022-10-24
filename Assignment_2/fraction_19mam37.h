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

        //Constructor set to a default value of numerator 0 and denominator 1
        Fraction(int numerators = 0, int denominators = 1);

        //Greatest Common Denominator Function
        int GCD(const int& a, const int& b);

        //Unary Operator Overloading
        Fraction& operator++(); //Pre-increment
        Fraction operator++(int);   //Post-increment
        Fraction& operator-();  //Negation

        //Binary Operator Overloading
        Fraction& operator+=(const Fraction& rightH);   //Add and Assign
        friend ostream& operator<<(ostream& out, const Fraction& fraction); //Output
        friend istream& operator>>(istream& out, Fraction& fraction);   //Input
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
Fraction operator+(const Fraction& leftH, const Fraction& rightH);  //Addition

Fraction operator-(const Fraction& leftH, const Fraction& rightH);  //Subtraction

Fraction operator*(const Fraction& leftH, const Fraction& rightH);  //Multiplication

Fraction operator/(const Fraction& leftH, const Fraction& rightH);  //Division

//Binary Comparison Operator Overloading
bool operator<(const Fraction& leftH, const Fraction& rightH);  //Less than

bool operator>(const Fraction& leftH, const Fraction& rightH);  //Greater than

bool operator>=(const Fraction& leftH, const Fraction& rightH); //Greater than equal to

bool operator<=(const Fraction& leftH, const Fraction& rightH); //Less than equal to

bool operator==(const Fraction& leftH, const Fraction& rightH); //Equal to

bool operator!=(const Fraction& leftH, const Fraction& rightH); //Not equal to

#endif //ASSIGNMENT_2_FRACTION_19MAM37_H
