#include<iostream>
using namespace std;

class Engine{
    bool isRunning;
    public:
    Engine() : isRunning(false) {
        cout<<"Engine created"<<endl;
    }
    
    void start(){
        if(!isRunning){
            isRunning = true;
            cout<<"Engine started"<<endl;
        } else {
            cout<<"Engine is already runing"<<endl;
        }      
    }
    void stop(){
        if(isRunning){
            isRunning = false;
            cout<<"Engine stopped"<<endl;
        } else {
            cout<<"Engine is already stopped"<<endl;
        }
         
    }
    ~Engine(){
        cout<<"Engine destroyed"<<endl;
    }
};

class Car{
    Engine engine;
    public:
    Car(){
        cout<<"Car created"<<endl;
    }
    void startCar(){
        engine.start();
    }
    void stopCar(){
        engine.stop();
    }
    ~Car(){
        cout<<"Car destroyed"<<endl;
    }
};



int main(){
    Car myCar;
    myCar.startCar();
    myCar.stopCar();
}
