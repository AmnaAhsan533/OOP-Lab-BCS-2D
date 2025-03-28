#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class Polynomial;

class PolynomialUtils{
    public:
    static int evaluate(const Polynomial &p, int x);  
    static Polynomial derivative(const Polynomial &p);
};

class Polynomial{
    private:
    vector<int>coefficients;
    void trim(){
        while(!coefficients.empty() && coefficients.back() == 0){
            coefficients.pop_back();
        }
    }
    public:
    Polynomial(){}
    Polynomial(vector<int>coeff): coefficients(coeff) {
        trim();
    }
    friend class PolynomialUtils;

    Polynomial operator+(Polynomial& p) {
        int maxSize = max(coefficients.size(), p.coefficients.size());
        vector<int> result(maxSize, 0);
        for(int i=0; i<maxSize; i++){
            if(i<coefficients.size()) result[i] += coefficients[i];
            if(i<p.coefficients.size()) result[i] += p.coefficients[i];
        }
        return Polynomial(result);
    }
    Polynomial operator-(Polynomial& p){
        int maxSize = max(coefficients.size(), p.coefficients.size());
        vector<int> result(maxSize, 0);
        for(int i=0; i<maxSize; i++){
            if(i<coefficients.size()) result[i] += coefficients[i];
            if(i<p.coefficients.size()) result[i] -= p.coefficients[i];
        }
        return Polynomial(result);
    }
    Polynomial operator*(Polynomial& p){
        int newSize = coefficients.size() + p.coefficients.size() - 1;
        vector<int> result(newSize, 0);
        for(int i=0; i<coefficients.size(); i++){
            for(int j=0; j<p.coefficients.size(); j++){
                result[i+j] += coefficients[i] * p.coefficients[j];
            }
        }
        return Polynomial(result);
    }
    friend ostream& operator<<(ostream& os, const Polynomial& p){
        bool first = true;
        for(int i=p.coefficients.size()-1; i>=0; i--){
            int coeff = p.coefficients[i];
            if(coeff != 0){
                if(!first){
                    os << (coeff > 0? " + " : " - ");
                } else if (coeff < 0) os <<"-";

                if(abs(coeff) != 1 || i == 0)  os << abs(coeff);
                if(i > 0) os << "x";
                if(i > 1) os <<"^"<<i;

                first = false;
            }
        }
        if (first) os << "0";  // If polynomial is empty, print 0
        return os;
    }
};

int PolynomialUtils::evaluate(const Polynomial &p, int x){
    int power = 1;
    int result = 0;
    for (int coeff : p.coefficients){
        result += coeff*power;
        power *= x;
    }
    return result;
}

Polynomial PolynomialUtils::derivative(const Polynomial &p){
    if(p.coefficients.size() <=1) return Polynomial(); //derivative of constant is 0
    vector<int> deriv(p.coefficients.size() - 1);
    for(int i=1; i<p.coefficients.size(); i++){
        deriv[i-1] = p.coefficients[i] * i;
    }
    return Polynomial(deriv);
}

int main() {
    Polynomial p1({2, 3, 0, 2});  // 2 + 3x + 2x^3
    Polynomial p2({1, -1, 2});    // 1 - x + 2x^2

    cout << "P1: " << p1 << endl;
    cout << "P2: " << p2 << endl;

    Polynomial sum = p1 + p2;
    cout<<"\n-----Addition-----\n";
    cout << "P1 + P2: " << sum << endl;

    Polynomial diff = p1 - p2;
    cout<<"\n-----Subtraction-----\n";
    cout << "P1 - P2: " << diff << endl;

    Polynomial prod = p1 * p2;
    cout<<"\n-----Multiplication-----\n";
    cout << "P1 * P2: " << prod << endl;

    int x1 = 3;
    int x2 =2;
    cout<<"\n-----Evaluate-----\n";
    cout << "P1(" << x1 << ") = " << PolynomialUtils::evaluate(p1, x1) << endl;
    cout << "P1(" << x2 << ") = " << PolynomialUtils::evaluate(p1, x2) << endl;

    Polynomial deriv = PolynomialUtils::derivative(p1);
    cout<<"\n-----Derivative-----\n";
    cout << "P1': " << deriv << endl;

    return 0;
}