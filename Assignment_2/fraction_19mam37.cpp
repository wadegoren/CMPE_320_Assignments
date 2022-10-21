//
// Created by Matthew MacEachern on 10/16/22.
//
#include <iostream>
#include<cmath>
#include "fraction_19mam37.h"

Fraction::Fraction(int numerator, int denominator) {
    numeratorr = numerator != 0 || denominator != 1 ? numerator / GCD(numerator, denominator) : numerator;
    denominatorr = numerator != 0 || denominator != 1 ? denominator / GCD(numerator, denominator) : denominator;
    if (denominator == 0) {
        throw FractionException("Denominator equals 0");
    }
    if (numeratorr < 0 && denominatorr < 0) { //both negative
        numeratorr = -numeratorr;
        denominatorr = -denominatorr;
    } else if (numeratorr >= 0 && denominatorr < 0){
        numeratorr = -numeratorr;
        denominatorr = -denominatorr;
    }
}

int Fraction::GCD(const int& a, const int& b) {
    if (b == 0 || a == 0) return 1;
    int a_abs = abs(a);
    int b_abs = abs(b);
    if (b_abs <= a_abs && a_abs % b_abs == 0) {
        return b_abs;
    } else if (a_abs < b_abs) {
        return GCD(b_abs, a_abs);
    } else {
        return GCD(b_abs, a_abs % b_abs);
    }
}

ostream& operator<<(ostream& out, const Fraction& fraction){
    out << fraction.numeratorr  << '/' << fraction.denominatorr;
    return out;
}

istream& operator<<(istream& out, const Fraction& fraction){
    out << fraction.numeratorr  << '/' << fraction.denominatorr;
    return out;
}

Fraction operator+(const Fraction& leftH, const Fraction& rightH){
    int numer = (leftH.numerator() * rightH.denominator()) + (rightH.numerator() * leftH.denominator());
    int denom = leftH.denominator() * rightH.denominator();
    return Fraction(numer, denom);
}

Fraction operator-(const Fraction& leftH, const Fraction& rightH){
    int numer = (leftH.numerator() * rightH.denominator()) - (rightH.numerator() * leftH.denominator());
    int denom = leftH.denominator() * rightH.numerator();
    return Fraction(numer, denom);
}

Fraction operator*(const Fraction& leftH, const Fraction& rightH){
    int numer = leftH.numerator() * rightH.numerator();
    int denom = leftH.denominator() * rightH.denominator();
    return Fraction(numer, denom);
}

Fraction operator/(const Fraction& leftH, const Fraction& rightH){
    int numer = leftH.numerator() * rightH.denominator();
    int denom = leftH.denominator() * rightH.numerator();
    return Fraction(numer, denom);
}

Fraction& Fraction::operator++(){   //Pre-increment
    numeratorr = denominator() + numerator();
    return *this;
}

Fraction Fraction::operator++(int unused) { //Post-increment
    Fraction clone(numeratorr, denominatorr);
    numeratorr = denominator() + numerator();
    return clone;
}

bool operator<(const Fraction& leftH, const Fraction& rightH){
    if (leftH.numerator() * rightH.denominator() < rightH.numerator() * leftH.denominator()){
        return true;
    } else {
        return false;
    }
}

bool operator>(const Fraction& leftH, const Fraction& rightH){
    if (leftH.numerator() * rightH.denominator() > rightH.numerator() * leftH.denominator()){
        return true;
    } else {
        return false;
    }
}

bool operator>=(const Fraction& leftH, const Fraction& rightH){
    if (leftH.numerator() * rightH.denominator() >= rightH.numerator() * leftH.denominator()){
        return true;
    } else {
        return false;
    }
}

bool operator<=(const Fraction& leftH, const Fraction& rightH){
    if (leftH.numerator() * rightH.denominator() <= rightH.numerator() * leftH.denominator()){
        return true;
    } else {
        return false;
    }
}

bool operator==(const Fraction& leftH, const Fraction& rightH){
    if (leftH.numerator() * rightH.denominator() == rightH.numerator() * leftH.denominator()){
        return true;
    } else {
        return false;
    }
}

bool operator!=(const Fraction& leftH, const Fraction& rightH){
    if (leftH.numerator() * rightH.denominator() != rightH.numerator() * leftH.denominator()){
        return true;
    } else {
        return false;
    }
}

Fraction& Fraction::operator+=(const Fraction& rightH){
    numeratorr = (numeratorr * rightH.numeratorr) + (rightH.numeratorr * denominatorr);
    denominatorr = denominatorr * rightH.denominatorr;
    return *this;
}

Fraction& Fraction::operator-(){
    numeratorr = -numeratorr;
    return *this;
}

const int& Fraction::numerator() const{
    return numeratorr;
}

const int& Fraction::denominator() const{
    return denominatorr;
}

FractionException::FractionException(const string& errorMessage) : errorMessage(errorMessage){}
string& FractionException::what() {return errorMessage;}
