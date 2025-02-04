#include<iostream>
#include<cstdlib>
using namespace std;

class Glass{
    public:
        int LiquidLevel = 200;
    void Drink(int milliliters){
        LiquidLevel = 200 - milliliters;
        if(LiquidLevel < 100 && LiquidLevel >= 0){
            Refill();
        }
    }
    void Refill(){
        LiquidLevel = 200;
        cout<<"Glass refilled!"<<endl;
    }
};

int main(int argc, const char* argv[]){
    Glass glass;
    cout<<"Enter amout of liter: (-1 to stop)"<< endl;
    while(1){
        int value;
        cin>>value;
        glass.Drink(value);
        if(value == -1){
            return 1;
        }
        // int i=1;
        // if(atoi(argv[i]) == 0){
        //     return 1;
        //     }
        // glass.Drink(atoi(argv[i]));
        // i++;
    }   
    return 0;
}