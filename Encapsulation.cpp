#include<bits/stdc++.h>
using namespace std;

class SportsCar {
private:
//charecter
    string model;
    string brand;
    bool isEngineRunning;
    int currentGear;
    int speed;
public:
    SportsCar(string model, string brand) {
        this->model = model;
        this->brand = brand;
        this->isEngineRunning = false;
        this->currentGear = 0;
        this->speed = 0;
    }


    //getters and setters
    int getSpeed() {
        return this->speed;
    }

    void setSpeed(int newSpeed) {
        this->speed = newSpeed;
    }

     //behaviours--->methods
    void startEngine() {
        isEngineRunning = true;
        cout << "SportsCar engine started." << endl;
    }

    void shiftGear(int gear) {
        if(!isEngineRunning) {
            cout<<brand<<" "<<model<<" engine is not running. Cannot shift gear."<<endl;
            return;
        }
        currentGear = gear;
        cout << "SportsCar gear shifted to " << gear << "." << endl;
    }


    void accelerate() {
        if(!isEngineRunning) {
            cout<<brand<<" "<<model<<" engine is not running. Cannot accelerate."<<endl;
            return;
        }
        speed += 20;
        cout << "SportsCar is accelerating to " << speed << " mph." << endl;
    }


    void brake() {
        speed -= 10;
        if(speed < 0) speed = 0;
            cout<<brand<<" "<<model<<" is braking. Current speed: "<<speed<<" mph."<<endl;

    }


     void stopEngine() {
        isEngineRunning = false;
        speed = 0;
        currentGear = 0;
        cout << "SportsCar engine stopped." << endl;
     }

};

int main() {
    SportsCar* myCar = new SportsCar("Mustang", "Ford");
    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();

    cout << "------------------------" << endl;
    cout << "Speed: " << myCar->getSpeed() << " mph." << endl;
    delete myCar;
    return 0;
}