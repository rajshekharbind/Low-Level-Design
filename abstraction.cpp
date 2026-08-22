// #include<bits/stdc++.h>
// using namespace std;

// // Abstract class representing a generic Car
// class Car {
//     public:
//     virtual void startEngine() = 0; // Pure virtual function
//     virtual void shiftGear(int gear) = 0; // Pure virtual function
//     virtual void accelerate() = 0; // Pure virtual function
//     virtual void brake() = 0; // Pure virtual function
//     virtual void stopEngine() = 0; // Pure virtual function
//     virtual ~Car() {} // Virtual destructor
   
// };

// class SportsCar : public Car {
//     public:
//     string model;
//     string brand;
//     bool isEngineRunning;
//     int currentGear;
//     int speed;
//     SportsCar(string model, string brand) {
//         this->model = model;
//         this->brand = brand;
//         this->isEngineRunning = false;
//         this->currentGear = 0;
//         this->speed = 0;
//     }

//     void startEngine() {
//         isEngineRunning = true;
//         cout << "SportsCar engine started." << endl;
//     }

//     void shiftGear(int gear) {
//         if(!isEngineRunning) {
//             cout<<brand<<" "<<model<<" engine is not running. Cannot shift gear."<<endl;
//             return;
//         }
//         currentGear = gear;
//         cout << "SportsCar gear shifted to " << gear << "." << endl;
//     }


//     void accelerate() override {
//         if(!isEngineRunning) {
//             cout<<brand<<" "<<model<<" engine is not running. Cannot accelerate."<<endl;
//             return;
//         }
//         speed += 10;
//         cout << "SportsCar is accelerating to " << speed << " mph." << endl;
//     }



//     void brake() override {
//         speed = -10;
//         if(speed < 0) speed = 0;
//             cout<<brand<<" "<<model<<" is braking. Current speed: "<<speed<<" mph."<<endl;
//     }

//     void stopEngine() override {
//         isEngineRunning = false;
//         currentGear = 0;
//         speed = 0;
//         cout<<brand<<" "<<model<<" engine stopped."<<endl;
//     }
// };


// int main() {
//     Car* myCar = new SportsCar("Mustang", "Ford");
//     myCar->startEngine();
//     myCar->shiftGear(1);
//     myCar->accelerate();
//     myCar->brake();
//     myCar->stopEngine();
//     delete myCar;
//     return 0;
// }




#include<bits/stdc++.h>
using namespace std;

class Car{
    public:
    virtual void StartEngine() =0;
    virtual void shiftGear(int gear)=0;
    virtual void accelerate()=0;
    virtual void breake()=0;
    virtual void stopEngine()=0;
    virtual ~Car(){}
};

class MahindraCars: public Car{
    public:
    string model;
    string brand;
    bool isEngine;
    int curGear;
    int CurSpeed;

    MahindraCars(string model, string brand){
        this->model = model;
        this->brand= brand;
        this->isEngine= false;
        this->curGear=0;
        this->CurSpeed=0;
    }

    void StartEngine(){
        isEngine=true;
        cout<<brand<<" "<<model<<"engine started"<<endl;
    }

    void shiftGear(int gear){
        if(!isEngine){
            cout<<brand<<" "<<model<<" enine is not startted : Cannot shift gear"<<endl;
            return;
        }
        curGear = gear;
        cout<<brand<<" "<<model<<" gear shifted to "<<gear<<endl;
    }

    void accelerate() override{
        if(!isEngine){
            cout<<brand<<" "<<model<<" engine is not started : cacont accelerate"<<endl;
            return;
        }
        CurSpeed += 10;
        cout<<brand<<" "<<model<<" is accelerating to "<<CurSpeed<<" mph"<<endl;
    }

    void breake() override{
        if(!isEngine){
            cout<<brand<<" "<<model<<" engine is not started : cannot brake"<<endl;
            return;
        }
        CurSpeed -= 10;
        if(CurSpeed < 0) CurSpeed = 0;
        cout<<brand<<" "<<model<<" is braking. Current speed: "<<CurSpeed<<" mph."<<endl;
    }

    void stopEngine() override{
        isEngine= false;
        curGear=0;
        CurSpeed=0;
        cout<<brand<<" "<<model<<" engine stopped"<<endl;
    }

};

int main(){
    Car* myCar = new MahindraCars("Thar", "Mahindra");
    myCar->StartEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->breake();
    myCar->stopEngine();
    delete myCar;
    return 0;
}
