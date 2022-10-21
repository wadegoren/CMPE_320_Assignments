//
// Created by Matthew MacEachern on 10/16/22.
//
#include <iostream>
#include<cmath>
#include "fraction_19mam37.h"

Fraction::Fraction(int numerator, int denominator) {
    if (denominator == 0) {
        throw FractionException("Denominator equals 0");
    }
    if (numerator < 0 && denominator < 0){ //if both negative
        numerator = numerator * -1;
        denominator = denominator * -1;
    }
    if (numerator >= 0 && denominator < 0){
        numerator = numerator * -1;
        denominator = denominator * -1;
    }
}


ostream& operator<<(ostream& out, const Fraction fraction){
    out << fraction.numeratorr  << '/' << fraction.denominatorr;
    return out;
}

istream& operator<<(istream& out, const Fraction fraction){
    out << fraction.numeratorr  << '/' << fraction.denominatorr;
    return out;
}

Fraction operator+(const Fraction& leftH, const Fraction& rightH){
    int numer = (leftH.getNumerator() * rightH.getDenominator()) + (rightH.getNumerator() * leftH.getDenominator());
    int denom = leftH.getDenominator() * rightH.getDenominator();
    return Fraction(numer, denom);
}

Fraction operator-(const Fraction& leftH, const Fraction& rightH){
    int numer = (leftH.getNumerator() * rightH.getDenominator()) - (rightH.getNumerator() * leftH.getDenominator());
    int denom = leftH.getDenominator() * rightH.getNumerator();
    return Fraction(numer, denom);
}

Fraction operator*(const Fraction& leftH, const Fraction& rightH){
    int numer = leftH.getNumerator() * rightH.getNumerator();
    int denom = leftH.getDenominator() * rightH.getDenominator();
    return Fraction(numer, denom);
}

Fraction operator/(const Fraction& leftH, const Fraction& rightH){
    int numer = leftH.getNumerator() * rightH.getDenominator();
    int denom = leftH.getDenominator() * rightH.getNumerator();
    return Fraction(numer, denom);
}

Fraction& Fraction::operator++(){   //pre-increment
    numeratorr = getDenominator() + getNumerator();
    return *this;
}

Fraction Fraction::operator++(int unused) { //post-increment
    Fraction clone(numeratorr, denominatorr);
    numeratorr = getDenominator() + getNumerator();
    return clone;
}

Fraction& Fraction::operator+=(const Fraction& rightH){
    numeratorr = numeratorr + rightH.numeratorr;
    denominatorr = denominatorr + rightH.denominatorr;
    return *this;
}

Fraction& Fraction::operator-(){
    numeratorr = -numeratorr;
    return *this;
}

const int& Fraction::getNumerator() const{
    return numeratorr;
}

const int& Fraction::getDenominator() const{
    return denominatorr;
}

FractionException::FractionException(const string& errorMessage) : errorMessage(errorMessage){}
string& FractionException::what() {return errorMessage;}
