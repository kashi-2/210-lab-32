// Comsc-210 lab 32 || Akashdeep Singh
// Simulates a toll booth line using std::deque 

#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"

using namespace std;

// function prototypes
void displayLane(deque<Car>& lane);

int main() {
    srand(time(0));

    //Milestone 2: creating array of lanes
    const int NUM_LANES = 4
    deque<Car> lanes[NUM_LANES];
    
    //constants 
    const int INITIAL_SIZE = 2;
    const int TIME_PERIODS = 20;

    const int PAY_PROB = 46;
    const int JOIN_PROB = 39;
    const int SWITCH_PROB = 15;

    // Milestone 3: Populate each lane with 2 cars
     for (int i = 0; i < NUM_LANES; i++) {
        for (int j = 0; j < INITIAL_SIZE; j++) {
            Car c;
            lanes[i].push_back(c);
        }
    }

    // Initial output (milestone 3)
    cout << "Initial queue:\n";
    for (int i = 0; i < NUM_LANES; i++) {
        cout << "Lane " << i + 1 << ":\n";
        displayLane(lanes[i]);
    }

    //Milestone runs until empty
    while (!lane.empty()) {
        int r =rand() % 100;

        cout << "\nTime: " << timeStep << " "; 

        if (r < 55) {
            //car pays and than leaves
            Car frontCar = lane.front();
            lane.pop_front();

            cout << "Operation: Car paid: ";
            frontCar.print();
            cout << endl;
        }
        else {
            // new car joins 
            Car newCar;
            lane.push_back(newCar);

            cout << "Operation: Joined lane: ";
            newCar.print();
            cout << endl;
        }

        cout << "Queue:\n";
        if (lane.empty()) {
            cout << "    Empty\n";
        }
        else {
            displayQueue(lane);
        }

        timeStep++; 
    }
    
    return 0;
}

//function to display queue
void displayQueue(deque<Car>& lane) {
    for (int i = 0; i < lane.size(); i++) {
        cout << "    ";
        lane[i].print();
        cout << endl;
    }
}