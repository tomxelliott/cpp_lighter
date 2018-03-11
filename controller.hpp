#include <iostream>
#include <string>
#include <thread>
#include <vector>

#include "lights.hpp"
#include "helper.hpp"

using namespace chrono;
using namespace std;

class Controller {
public:
	// Constructor and Destructor
	Controller(int numberOfLights) {
		this -> numberOfLights = numberOfLights;
		this -> state = false;
	}

	~Controller() {}

	// Prototypes
	void run();
	void initialize(int numberOfColours);
	void defaultInit();
	void formatState();
	void controllerStatus(int index);

	// Getters and setters.
	void setState(bool state) { this -> state = state; }
	bool getState() const { return state; }
	int getNumberOfLights() const { return numberOfLights; }

private:
	Helper helper;
	int numberOfLights;
	bool state;
	vector <Light> lightSet;
};

// Function Definitions

void Controller::run() {
	int i = 0;
	while(i < numberOfLights) {
    	controllerStatus(i%lightSet.size());
		setState(true);
		this_thread::sleep_for(seconds(1));	
    	controllerStatus(i%lightSet.size());
    	setState(false);
    	this_thread::sleep_for(seconds(1));
    	i++;
  	}
}

void  Controller::initialize(int numberOfColours) {
	lightSet.clear();
	int counter = 0;
	while(counter < numberOfColours) {
		string choice;
		cout << "Enter the name of light number " << counter + 1 << ": ";
		cin >> choice;
		Light light(choice);
		lightSet.push_back(light);
		counter++;
	}
}

void Controller::defaultInit() {
	lightSet.clear();
	Light red("red");
	Light blue("blue");
	Light green("green");
	Light yellow("yellow");
	lightSet.push_back(red);
	lightSet.push_back(blue);
	lightSet.push_back(green);
	lightSet.push_back(yellow);
}

void Controller::controllerStatus(int index) {
	helper.getTime();
	formatState();
	cout <<  "\t" << index+1 << " " << lightSet.at(index).getColour() << endl;
}

void Controller::formatState() {
	if(state) {
		cout << " On ";
	} else {
		cout << " Off ";
	}
}
