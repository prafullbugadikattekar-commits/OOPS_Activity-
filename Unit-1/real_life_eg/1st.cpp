#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Real-world example: Agricultural IoT Soil Moisture Sensor Monitor
class SoilSensor{
    private:
        string sensorld;
        double moistureLevel;
        string timestamp;

    public:
        // Parameterized constructor using member initializer list
        SoilSensor(string id,double moisture,string time)
            :sensorld(id),moistureLevel(moisture),timestamp(time){}

        // Member function definition to update sensor readings
        void readSensor(double newMoisture,string newTime){
            moistureLevel = newMoisture;
            timestamp = newTime;
        }

        // const member function: guarantees it will not modify any member variables of the object
        void DisplayData()const{
            cout<<"Sensor:"<<sensorld<<"| Moisture :"<<moistureLevel<<"%"<<"| Time:"<<timestamp<<endl;
        }

};

int main(){
    vector<SoilSensor> farmSensors;
    // emplace_back constructs objects in-place inside the vector
    farmSensors.emplace_back("S001",45.2,"08:00");
    farmSensors.emplace_back("S002",55.2,"08:00");
    farmSensors.emplace_back("S003",84.2,"08:00");

    cout<<"===Morning Sensor Readings ===="<<endl;
    // Range-based for loop using const reference (&): prevents copies of SoilSensor objects
    for(const auto& sensor:farmSensors){
        // Member function calling
        sensor.DisplayData();
    }

    // Function calling to update readings and display updated values
    farmSensors[0].readSensor(47.5,"09:00");
    cout<<"\n ===Updated reading ==="<<endl;
    farmSensors[0].DisplayData();
}
