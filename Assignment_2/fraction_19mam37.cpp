//
// Created by Matthew MacEachern on 10/16/22.
//
#include "fraction_19mam37.h"

//Constructor
Fraction::Fraction(int numerator, int denominator) {
    numeratorr = numerator != 0 || denominator != 1 ? numerator / GCD(numerator, denominator) : numerator;
    denominatorr = numerator != 0 || denominator != 1 ? denominator / GCD(numerator, denominator) : denominator;
    if (denominator == 0) {
        throw FractionException("Illegal: Denominator equals 0");
    }
    if (numeratorr < 0 && denominatorr < 0) { //both negative
        numeratorr = -numeratorr;
        denominatorr = -denominatorr;
    } else if (numeratorr >= 0 && denominatorr < 0){    //denominator negative and numerator non-negative
        numeratorr = -numeratorr;
        denominatorr = -denominatorr;
    }
}

//Greatest Common Denominator
int Fraction::GCD(const int& a, const int& b) {
    if (b == 0 || a == 0) return 1;
    int aabs = abs(a);  //absolute value of a and b
    int babs = abs(b);
    if (babs <= aabs && aabs % babs == 0) {
        return babs;
    } else if (aabs < babs) {
        return GCD(babs, aabs);
    } else {
        return GCD(babs, aabs % babs);
    }
}

//Output Overload
ostream& operator<<(ostream& out, const Fraction& fraction){
    out << fraction.numeratorr  << '/' << fraction.denominatorr;
    return out;
}

// Splits the input (string) using stringstream and a delimeter of '/' and stores the values in a vector
istream& operator>>(istream& input, Fraction& fraction){
    vector<string> numerAndDenom;
    string input_value;
    input >> input_value;
    stringstream ss(input_value);
    string numberS;

    while(getline(ss, numberS, '/')){
        numerAndDenom.push_back(numberS);
    }
    if (numerAndDenom.size() < 2){
        fraction.denominatorr = 1;
        fraction.numeratorr = stoi(input_value);
    } else if(stoi(numerAndDenom[1]) == 0){
        throw FractionException("Illegal: Fraction has a Denominator of Zero");
    } else{
        fraction.numeratorr = stoi(numerAndDenom[0]);
        fraction.denominatorr = stoi(numerAndDenom[1]);
    }
    return input;
}

//Addition Overload
Fraction operator+(const Fraction& leftH, const Fraction& rightH){
    int numer = (leftH.numerator() * rightH.denominator()) + (rightH.numerator() * leftH.denominator());
    int denom = leftH.denominator() * rightH.denominator();
    return Fraction(numer, denom);
}

//Subtraction Overload
Fraction operator-(const Fraction& leftH, const Fraction& rightH){
    int numer = (leftH.numerator() * rightH.denominator()) - (rightH.numerator() * leftH.denominator());
    int denom = leftH.denominator() * rightH.denominator();
    return Fraction(numer, denom);
}

//Multiplication Overload
Fraction operator*(const Fraction& leftH, const Fraction& rightH){
    int numer = leftH.numerator() * rightH.numerator();
    int denom = leftH.denominator() * rightH.denominator();
    return Fraction(numer, denom);
}

//Division Overload
Fraction operator/(const Fraction& leftH, const Fraction& rightH){
    int numer = leftH.numerator() * rightH.denominator();
    int denom = leftH.denominator() * rightH.numerator();
    return Fraction(numer, denom);
}

//Pre-Increment Overload
Fraction& Fraction::operator++(){   //Pre-increment
    numeratorr = denominator() + numerator();
    return *this;
}

//Post-Increment Overload
Fraction Fraction::operator++(int unused) { //Post-increment
    Fraction clone(numeratorr, denominatorr);
    numeratorr = denominator() + numerator();
    return clone;
}

// Less-Than Overload
bool operator<(const Fraction& leftH, const Fraction& rightH){
    if (leftH.numerator() * rightH.denominator() < rightH.numerator() * leftH.denominator()){
        return true;
    } else {
        return false;
    }
}

//Greater-Than Overload
bool operator>(const Fraction& leftH, const Fraction& rightH){
    if (leftH.numerator() * rightH.denominator() > rightH.numerator() * leftH.denominator()){
        return true;
    } else {
        return false;
    }
}

//Greater-Than-Equal-To Overload
bool operator>=(const Fraction& leftH, const Fraction& rightH){
    if (leftH.numerator() * rightH.denominator() >= rightH.numerator() * leftH.denominator()){
        return true;
    } else {
        return false;
    }
}

//Less-Than-Equal-To Overload
bool operator<=(const Fraction& leftH, const Fraction& rightH){
    if (leftH.numerator() * rightH.denominator() <= rightH.numerator() * leftH.denominator()){
        return true;
    } else {
        return false;
    }
}

//Equal-To Overload
bool operator==(const Fraction& leftH, const Fraction& rightH){
    if (leftH.numerator() * rightH.denominator() == rightH.numerator() * leftH.denominator()){
        return true;
    } else {
        return false;
    }
}

//Not-Equal-To Overload
bool operator!=(const Fraction& leftH, const Fraction& rightH){
    if (leftH.numerator() * rightH.denominator() != rightH.numerator() * leftH.denominator()){
        return true;
    } else {
        return false;
    }
}

//Add And Assign Overload
Fraction& Fraction::operator+=(const Fraction& rightH){
    numeratorr = (numeratorr * rightH.denominatorr) + (rightH.numeratorr * denominatorr); //FIX THIS LINE**************************************
    denominatorr = denominatorr * rightH.denominatorr;
    int gcd = GCD(numeratorr, denominatorr);
    numeratorr /= gcd;
    denominatorr /= gcd;
    return *this;
}

//Negation Overload
Fraction& Fraction::operator-(){
    numeratorr = -numeratorr;
    return *this;
}

//Numerator Accessor
const int& Fraction::numerator() const{
    return numeratorr;
}

//Denominator Accessor
const int& Fraction::denominator() const{
    return denominatorr;
}

//Exception Class
FractionException::FractionException(const string& errorMessage) : errorMessage(errorMessage){}
string& FractionException::what() {return errorMessage;}
