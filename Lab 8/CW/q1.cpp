#include<iostream>
using namespace std;

class Fraction{
    private:
    int numerator, denominator;

    int gcd(int a, int b){
        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    void reduce(){
        int gcdVal = gcd(abs(numerator), abs(denominator));
        numerator /= gcdVal;
        denominator /= gcdVal;

        if(denominator < 0){
            numerator = -numerator;
            denominator = -denominator;
        }
    }
    public:
    Fraction(int num = 0, int den = 1){
        if(den == 0){
            throw invalid_argument("Denominator cannot be zero!");
        }
        numerator = num;
        denominator = den;
        reduce();
    }
    Fraction operator+(const Fraction& f) const{
        return Fraction(numerator * f.denominator + denominator * f.numerator, denominator * f.numerator);
    }
    Fraction operator-(const Fraction& f) const{
        return Fraction(numerator * f.denominator - denominator * f.numerator, denominator * f.numerator);
    }
    Fraction operator*(const Fraction& f) const{
        return Fraction(numerator * f.numerator, denominator * f.denominator);
    }
    Fraction operator/(const Fraction& f) const {
        if (f.numerator == 0) {
            throw invalid_argument("Division by zero!");
        }
        return Fraction(numerator * f.denominator, denominator * f.numerator);
    }

    bool operator==(const Fraction& f) const {
        return numerator * f.denominator == denominator * f.numerator; // a*d == b*c for a/b and c/d
    }
    bool operator!=(const Fraction& f) const {
        return !(*this == f);
    }
    bool operator<(const Fraction& f) const {
        return numerator * f.denominator < denominator * f.numerator; // a*d == b*c for a/b and c/d
    }
    bool operator>(const Fraction& f) const {
        return numerator * f.denominator > denominator * f.numerator; // a*d == b*c for a/b and c/d
    }
    bool operator<=(const Fraction& f) const {
        return !(*this > f);
    }
    bool operator>=(const Fraction& f) const {
        return !(*this < f);
    }
    friend ostream& operator<<(ostream& os, const Fraction& f){
        if (f.denominator == 1) {
            os << f.numerator;  // Output only the numerator if denominator is 1
        } else {
            os << f.numerator << "/" << f.denominator;  // Otherwise, show fraction
        }
        return os;
    }
    friend istream& operator>>(istream& is, Fraction& f){
        char slash;
        is >> f.numerator >> slash >> f.denominator;
        if (f.denominator == 0) {
            throw invalid_argument("Invalid fraction: denominator cannot be zero!");
        }
        f.reduce();
        return is;
    }
};

int main() {
    Fraction f1(5, -10), f2(3, 6);
    cout << "f1: " << f1 << ", f2: " << f2 << endl;

    cout << "f1 + f2 = " << (f1 + f2) << endl;
    cout << "f1 - f2 = " << (f1 - f2) << endl;
    cout << "f1 * f2 = " << (f1 * f2) << endl;
    cout << "f1 / f2 = " << (f1 / f2) << endl;

    cout << "f1 == f2: " << (f1 == f2 ? "true" : "false") << endl;
    cout << "f1 < f2: " << (f1 < f2 ? "true" : "false") << endl;

    Fraction f3;
    cout << "Enter a fraction (numerator/denominator): ";
    cin >> f3;
    cout << "You entered: " << f3 << endl;

    return 0;
}