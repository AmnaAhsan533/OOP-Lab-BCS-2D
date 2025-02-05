#include<iostream>
#include<cstdlib>
using namespace std;

class Glass{
    public:
        int LiquidLevel = 200;
    void Drink(int milliliters){
        LiquidLevel = 200 - milliliters;
        if (LiquidLevel < 0) {
            cout<<"Invalid input!"<<endl;
        } else {
            cout<<"Drank: "<<milliliters<<"ml. Remaining: "<<LiquidLevel<<"ml."<<endl;
        }
        
        if(LiquidLevel < 100 && LiquidLevel >= 0){
            Refill();
        }
    }
    void Refill(){
        LiquidLevel = 200;
        cout<<"Glass refilled to 200ml."<<endl;
    }
};

int main(int argc, const char* argv[]){
    Glass glass;
    //cout<<"Enter amout of liter: (-1 to stop)"<< endl;
    while(1){
        // int value;
        // cin>>value;
        
        // if(value == -1){
        //     return 1;
        // }
        // glass.Drink(value);
        for(int i=1; i<argc; i++){
            int value = atoi(argv[i]);
            if(value >= 0){
                glass.Drink(value);
            } else{
                return 1;
            }
        }
    }   
    return 0;
}
