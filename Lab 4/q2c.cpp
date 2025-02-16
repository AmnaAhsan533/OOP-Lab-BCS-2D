#include<iostream>
#include<cmath>
using namespace std;

class Polynomial{
    double *coefficients;
    int degree;
public:
    Polynomial(){
        coefficients = new double[1]{0};
        degree = 0;
    }
    Polynomial(int deg, double *arr){
        degree = deg;
        coefficients = new double[degree + 1];
        for(int i=0; i<=degree; ++i){
            coefficients[i] = arr[i];
        }
    }
    Polynomial(const Polynomial& other){
        degree = other.degree;
        coefficients = new double[degree + 1];
        for(int i=0; i<=degree; ++i){
            coefficients[i] = other.coefficients[i];
        }
    }
    Polynomial(Polynomial&& other) noexcept : degree(other.degree), coefficients(other.coefficients){
        other.coefficients = nullptr;
        other.degree =0;
    }
    ~Polynomial(){
        delete[] coefficients;
    }
    int getDegree() const {return degree;}
    double evaluate(double x) const {
        double  result = 0.0;
        for(int i=0; i<=  degree; ++i){
            result += coefficients[i] * pow(x, i);
        }
        return result;
    }
    Polynomial add(const Polynomial & other) const{
        int maxDegree = max(degree, other.degree);
        double *newCoeff = new double[maxDegree + 1]{0};
        for(int i=0; i<=degree; ++i){
            newCoeff[i] += coefficients[i];
        }
        for (int i = 0; i <= other.degree; ++i) {
            newCoeff[i] += other.coefficients[i];
        }
        return Polynomial(maxDegree, newCoeff);
    }
    Polynomial multiply(const Polynomial& other) const {
        int newDegree = degree + other.degree;
        double *newCoeff = new double[newDegree + 1]{0};

        for(int i=0; i<=degree; ++i){
            for(int j=0; j<=other.degree; ++j){
                newCoeff[i+j] += coefficients[i] * other.coefficients[j];
            }
        }
        return Polynomial(newDegree, newCoeff);
    }
    void Display() const {
        for(int i= degree; i>=0; --i){
            cout<<coefficients[i]<<"x^"<<i;
            if(i>0) cout<<" + ";
        }
        cout<<endl;
    }
};

int main(){
    double coeffs1[] = {2,3,4};
    double coeff2[] = {1,0,5};

    Polynomial p1(2, coeffs1);
    Polynomial p2(2, coeff2);

    cout<<"Polynomial 1: ";
    p1.Display();
    cout<<"Polynomial 2: ";
    p2.Display();

    Polynomial sum = p1.add(p2);
    cout<<"Sum: ";
    sum.Display();

    Polynomial product = p1.multiply(p2);
    cout<<"Product: ";
    product.Display();

    cout<<"Evaluation of p1 at x = 2: "<<p1.evaluate(2)<<endl;

    return 0;

}