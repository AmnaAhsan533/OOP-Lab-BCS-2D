#include<iostream>
#include<vector>
using namespace std;

class BigInteger{
    vector<int>digits;
    bool isNegative;
    static BigInteger add(const BigInteger& a, const BigInteger& b){
        BigInteger result;
        result.digits.clear();

        int carry = 0;
        for(size_t i =0; i < max(a.digits.size(), b.digits.size()) || carry; i++){
            int sum = carry;
            if(i < a.digits.size()) sum += a.digits[i];
            if(i < b.digits.size()) sum += b.digits[i];
            result.digits.push_back(sum % 10);
            carry = sum/10;
        }
        return result;
    }
    static BigInteger subtract(const BigInteger &a, const BigInteger &b) {
        BigInteger result;
        result.digits.clear();
        int borrow = 0;
        for (size_t i = 0; i < a.digits.size(); i++) {
            int diff = a.digits[i] - (i < b.digits.size() ? b.digits[i] : 0) - borrow;
            borrow = (diff < 0);
            if (borrow) diff += 10;
            result.digits.push_back(diff);
        }
        while (result.digits.size() > 1 && result.digits.back() == 0) result.digits.pop_back();
        return result;
    }  
    static int compareMag(const BigInteger &a, const BigInteger &b) {
        if (a.digits.size() != b.digits.size())
            return a.digits.size() - b.digits.size();
        for (int i = a.digits.size() - 1; i >= 0; i--)
            if (a.digits[i] != b.digits[i])
                return a.digits[i] - b.digits[i];
        return 0;
    }
    BigInteger negate() const {
        BigInteger result = *this;
        result.isNegative = !result.isNegative;
        return result;
    }
    public:
    BigInteger(string number = "0"){
        isNegative = (number[0] == '-');
        for(int i = number.length() - 1; i >= (isNegative? 1 : 0); i-- ){
            digits.push_back(number[i] - '0'); 
        }
    }

    BigInteger operator+(const BigInteger& other){
        if(isNegative == other.isNegative){
            BigInteger result = add(*this, other);
            result.isNegative = isNegative;
            return result;
        }
        return (isNegative? other.subtract(other, *this): subtract(*this, other));
    }
    BigInteger operator-(const BigInteger& other){
        if(isNegative != other.isNegative){
            BigInteger result = add(*this, other);
                result.isNegative = isNegative;
                return result;
        }
        return (compareMag(*this, other) >= 0? subtract(*this, other) : subtract(other, *this).negate());
    }
    bool operator==(const BigInteger &other) const {
        return (isNegative == other.isNegative && digits == other.digits);
    }
    bool operator!=(const BigInteger &other) const {
        return !(*this == other);
    }
    bool operator<(const BigInteger &other) const {
        if (isNegative != other.isNegative) return isNegative;
        return (compareMag(*this, other) < 0) ^ isNegative;
    }
    bool operator>(const BigInteger &other) const {
        return other < *this;
    }
    friend ostream &operator<<(ostream &out, const BigInteger &num) {
        if (num.isNegative && !(num.digits.size() == 1 && num.digits[0] == 0))
            out << "-";
        for (int i = num.digits.size() - 1; i >= 0; i--)
            out << num.digits[i];
        return out;
    }

    friend istream &operator>>(istream &in, BigInteger &num) {
        string input;
        in >> input;
        num = BigInteger(input);
        return in;
    }
};

int main() {
    BigInteger num1, num2;
    cout << "Enter first large number: ";
    cin >> num1;
    cout << "Enter second large number: ";
    cin >> num2;

    cout << "Sum: " << num1 + num2 << endl;
    cout << "Difference: " << num1 - num2 << endl;

    return 0;
}