#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Real-world Mini Project 1: Smart Home Automation Device Controller
class SmartDevice {
private:
    string deviceId;
    string deviceType;
    string location;
    bool status; // true: ON, false: OFF
    string lastUpdated;

public:
    // Parameterized constructor with default argument for initial status
    SmartDevice(string id, string type, string loc, string time, bool initStatus = false)
        : deviceId(id), deviceType(type), location(loc), status(initStatus), lastUpdated(time) {}

    // Member function definitions to control device power state
    void turnOn(string time) {
        status = true;
        lastUpdated = time;
    }

    void turnOff(string time) {
        status = false;
        lastUpdated = time;
    }

    void toggleStatus(string time) {
        status = !status;
        lastUpdated = time;
    }

    // const member function: returns device ID without altering object state
    string getId() const { return deviceId; }

    // const member function: displays device telemetry without modifying object state
    void displayStatus() const {
        cout << "ID: " << deviceId 
             << " | Type: " << deviceType 
             << " | Location: " << location 
             << " | Status: " << (status ? "ON" : "OFF") 
             << " | Last Updated: " << lastUpdated << endl;
    }
};

int main() {
    vector<SmartDevice> dashboard;

    // Populating device collection using emplace_back
    dashboard.emplace_back("D101", "Light", "Living Room", "07:00 AM", false);
    dashboard.emplace_back("D102", "Thermostat", "Bedroom", "07:00 AM", true);
    dashboard.emplace_back("D103", "Camera", "Front Door", "07:00 AM", true);
    dashboard.emplace_back("D104", "Door Lock", "Main Entrance", "07:00 AM", true);

    cout << "================ SMART HOME DASHBOARD ================" << endl;
    // Range-based for loop using const reference (&): avoids copying SmartDevice objects
    for (const auto& device : dashboard) {
        // Calling const member function
        device.displayStatus();
    }

    cout << "\n--- Updating Devices ---" << endl;
    // Calling state-modifying member functions
    dashboard[0].turnOn("08:15 AM");
    dashboard[1].turnOff("08:30 AM");

    cout << "\n================ UPDATED DASHBOARD ================" << endl;
    // Iterating with const reference (&) to show updated states
    for (const auto& device : dashboard) {
        device.displayStatus();
    }

    return 0;
}
