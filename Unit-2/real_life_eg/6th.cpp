#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

// Real-world example: Commercial Logistics Fleet Management System
class Vehicle{
    protected:
        string vehicleId;
        string registrationNumber;
        double fuelLevel;
        
    public:
        // Parameterized constructor initializing fuel at full capacity (100.0%)
        Vehicle(string vid,string reg)
            :vehicleId(vid),registrationNumber(reg),fuelLevel(100.0){}

        // const member function: outputs engine start status
        void startEngine()const{
            cout<<"Vehicle"<<vehicleId<<"engine started."<<endl;
        }

        // Member function definition to refuel vehicle
        void refuel(double amount){
            fuelLevel+=amount;
            if (fuelLevel>100.0){
                fuelLevel=100.0;
            }
        }

        // virtual member function: allows derived classes to override display format
        virtual void displayInfo()const{
            cout<<"Vehicle ID:"<<vehicleId<<"|Registration:"<<registrationNumber<<"|Fuel: "<<fuelLevel<<"%"<<endl;
        }

        // Virtual destructor ensures proper destruction via base pointers
        virtual ~Vehicle() = default;
};

class Truck : public Vehicle{
    private: 
        double cargoCapacity;
    
    public:
        Truck(string vid,string reg,double capacity)
            :Vehicle(vid,reg),cargoCapacity(capacity){}

        // override keyword: customizes displayInfo for cargo payload
        void displayInfo() const override{
            cout<<"Cargo Capacity: "<<cargoCapacity<<"tonnes"<<endl;
        }
};

class Delivery_Van : public Vehicle{
    private: 
        double pacakageCount;
    
    public:
        Delivery_Van(string vid,string reg,double package)
            :Vehicle(vid,reg),pacakageCount(package){}

        // Overrides displayInfo for package count
        void displayInfo() const override{
            cout<<"Package loaded: "<<pacakageCount<<endl;
        }
};

class Bike : public Vehicle{
    private: 
        bool hasDeliveryBox;
    
    public:
        Bike(string vid,string reg,double hasBox)
            :Vehicle(vid,reg),hasDeliveryBox(hasBox){}

        // Overrides displayInfo while explicitly calling base implementation
        void displayInfo() const override{
            cout<<"Delivery: "<<endl;
            Vehicle::displayInfo(); // Access displayInfo using scope resolution operator (::) from base class
            cout<<"Delivery box: "<<(hasDeliveryBox?"Available":"Not Available")<<endl;
        }
};

int main()
{
    // Managing polymorphic fleet objects using vector of unique_ptr
    vector<unique_ptr<Vehicle>> fleet;
    fleet.push_back(make_unique<Truck>("V001","MH12-AB-1234",10.5));
    fleet.push_back(make_unique<Delivery_Van>("V002","MH12-CD-5678",50));
    fleet.push_back(make_unique<Bike>("V003","MH12-EF-9012",true));

    cout<<"===Fleet Status==="<<endl;
    // Range-based for loop using const reference (&): prevents copying unique_ptr
    for(const auto& vehicle: fleet){
        // Runtime polymorphic function calls
        vehicle->startEngine();
        vehicle->displayInfo();
        cout<<endl;
    }
}
