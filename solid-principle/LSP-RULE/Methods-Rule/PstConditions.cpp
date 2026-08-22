#include<bits/stdc++.h>
using namespace std;
// Postcondition Rule :
// A Postcondition must be statisfied after a method executed.
//Sub classes can strengthen the Postcondition but cannot weaken it.

class Car {
    protected:
        int speed;
    public:
        Car() {
            speed = 0;
        }
        void accelerate() {
            cout << "Car accelerated to " << speed << " km/h" << endl;
            speed += 10;
        }

        //Postcondition: Speed must be reduce after breaking.
        virtual void brake() {
            cout << "Car slowed down to " << speed << " km/h" << endl;
            speed -= 10;
        }
};

class HybrideCar : public Car {
    private:
        int charge;
    public:
        HybrideCar() : Car() {
            charge = 100;
        }

        //Postcondition: Speed must be reduce after breaking and charge must be reduced.
        void brake() override {
            cout << "Hybride Car slowed down to " << speed << " km/h and charge reduced to " << charge << "%" << endl;
            speed -= 10;
            charge -= 5;
        }
};

int main() {
    Car* car = new Car();
    car->accelerate();
    car->brake(); // Valid braking

    Car* hybrideCar = new HybrideCar();
    hybrideCar->accelerate();
    hybrideCar->brake(); // This should be allowed, and it is due to strengthening of Postcondition

    return 0;
}