#include <iostream>

using namespace std;

class Fraction{
public:
    int numerator;
    int denominator;

    Fraction(int num, int denom){
        numerator = num;
        denominator = denom;
    }

    ~Fraction(){}

    Fraction operator+(Fraction f){
        int new_num = numerator*f.denominator + f.numerator*denominator;
        if(new_num == 0) return Fraction(0,0);
        int new_denom = denominator*f.denominator;
        this->flow();
        return Fraction(new_num, new_denom);
    }

    Fraction operator-(Fraction f){
        int new_num = numerator*f.denominator - f.numerator*denominator;
        if(new_num == 0) return Fraction(0,0);
        int new_denom = denominator*f.denominator;
        this->flow();
        return Fraction(new_num, new_denom);
    }

    Fraction operator*(Fraction f){
        int new_num = numerator*f.numerator;
        if(new_num == 0) return Fraction(0,0);
        int new_denom = denominator*f.denominator;
        this->flow();
        return Fraction(new_num, new_denom);
    }

    Fraction operator/(Fraction f){
        int new_num = numerator*f.denominator;
        if(new_num == 0) return Fraction(0,0);
        int new_denom = denominator*f.numerator;
        this->flow();
        return Fraction(new_num, new_denom);
    }

    bool operator==(Fraction f){
        if(numerator == f.numerator && denominator == f.denominator)
            return true;
        else return false;
    }

    void operator+=(Fraction &f){
        numerator = numerator*f.denominator + f.numerator*denominator;
        denominator = denominator*f.denominator;
        this->flow();
    }

    void operator-=(Fraction &f){
        numerator = numerator*f.denominator - f.numerator*denominator;
        denominator = denominator*f.denominator;
        this->flow();
    }

    void operator*=(Fraction &f){
        numerator = numerator*f.numerator;
        denominator = denominator*f.denominator;
        this->flow();
    }

    void operator/=(Fraction &f){
        numerator = numerator*f.denominator;
        denominator = denominator*f.numerator;
        this->flow();
    }

    void show(){
        if(denominator == 1) cout << numerator << endl;
        else cout << numerator << "/" << denominator << endl;
    }
    // Метод сокращения дроби
    void flow ()
    {
        int j, less;
        do{
            if(numerator < denominator)
                less = numerator;
            else
                less = denominator;
            for(j = less; j > 0; j--){
                if(!(numerator % j) && !(denominator % j)){
                    numerator /= j;
                    denominator /= j;
                    break;
                }
            }
        }while(j != 1);
    }
};

int main()
{
    Fraction f1(1,5);
    Fraction f2(1,2);
    Fraction f(2,6);
    f /= f1;
    f.show();
    return 0;
}
