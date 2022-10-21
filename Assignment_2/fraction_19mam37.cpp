//
// Created by Matthew MacEachern on 10/16/22.
//

#include "fraction_19mam37.h"

Fraction::Fraction(int numerator, int denominator) {
    if (denominator == 0) {
        throw FractionException("Denominator equals 0");
    }
    if (numerator < 0 && denominator < 0){ //if both negative
        numerator = numerator * -1;
        denominator = denominator * -1;
    }
    if (numerator < 0 && denominator >= 0){  //if only one is negative
        return;
    }else if (numerator >= 0 && denominator < 0){
        numerator = numerator * -1;
    }
}

ostream& operator<<(ostream& out, const Fraction fraction){
    out << fraction.numeratorr  << '/' << fraction.denominatorr;
    return out;
}

int Fraction::numerator(){
    return numeratorr;
}

int Fraction::denominator() {
    return denominatorr;
}

Fraction::Fraction(int fraction) {

}


FractionException::FractionException(const string& errorMessage) : errorMessage(errorMessage){}
string& FractionException::what() {return errorMessage;}
