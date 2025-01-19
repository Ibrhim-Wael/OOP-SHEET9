#include <iostream>
#include <string>

using namespace std;

// Base class
class Vehicle {
protected:
    string brand;
    double fuelCapacity;
public:

    Vehicle(string b, double fuel) : brand(b), fuelCapacity(fuel) {}
    virtual void displayInfo() const {
        cout << "Vehicle brand: " << brand << endl;
        cout << "Fuel Capacity: " << fuelCapacity << " liters" << endl;
    }

    void vehicleType() const {
        cout << "This is a generic vehicle." << endl;
    }

    virtual double calculateFuelEfficiency() const = 0;
};


class Car : public Vehicle {
private:
    double mileage; 
public:
    
    Car(string b, double fuel, double m) : Vehicle(b, fuel), mileage(m) {}

    
    void displayInfo() const override {
        Vehicle::displayInfo();
        cout << "Vehicle Type: Car" << endl;
    }

    double calculateFuelEfficiency() const override {
        return mileage; 
    }

    void vehicleType() const {
        cout << "This is a Car." << endl;
    }
};


class Truck : public Vehicle {
private:
    double loadCapacity; 
    double fuelEfficiency; 
public:
    
    Truck(string b, double fuel, double load, double efficiency) : Vehicle(b, fuel), loadCapacity(load), fuelEfficiency(efficiency) {}
    
    void displayInfo() const override {
        Vehicle::displayInfo();
        cout << "Vehicle Type: Truck" << endl;
    }

    double calculateFuelEfficiency() const override {
        return fuelEfficiency; // in km/l
    }
    void vehicleType() const {
        cout << "This is a Truck." << endl;
    }
};



int main() {
    // Static Binding
    Vehicle* V_ptr;

    Car car("Toyota", 40.0, 15.0);
    car.vehicleType(); // Calls Car's static function

    Truck truck("Volvo", 120.0, 10.0, 8.0);
    truck.vehicleType(); // Calls Truck's static function
    // Dynamic Binding
V_ptr=&car;
    V_ptr->displayInfo();
    cout << "Fuel Efficiency: " << V_ptr->calculateFuelEfficiency() << " km/l" << endl;
    V_ptr=&truck;
    V_ptr->displayInfo();
    cout << "Fuel Efficiency: " << V_ptr->calculateFuelEfficiency() << " km/l" << endl;
    V_ptr->vehicleType(); // Calls Vehicle's static function  
}
