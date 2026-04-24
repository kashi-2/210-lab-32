// Comsc-210 lab 32 || Akashdeep Singh
// Simulates a toll booth line using std::deque 

#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"

using namespace std;

// function prototypes
void displayQueue(deque<Car>& lane);

int main() {
    srand(time(0));

    const int INITIAL_SIZE = 2;

    deque<Car> lane;

    // initialize deque with 2 cars
    for (int i = 0; i < INITIAL_SIZE; i++) {
        Car c;
        lane.push_back(c);
    }

    cout << "Initial queue:\n";
    displayQueue(lane);

    int timeStep = 1;

    //Milestone 2 
    while (!lane.empty()) {
        int r =raand() % 100;

        cout << "Time: " << timeStep << " "; 

        if (r < 55) {
            
            Car frontCar = lane.front();
            lane.pop_front();

            cout << "Operation: Car paid: ";
            frontCar.print();
            cout << endl;
        }
        else {
            Car newCar;
            lane.push_back(newCar);

            cout << "Operation: Joined lane: ";
            newCar.print();
            cout << endl;
        }

        cout << "Queue: \n";
        if (lane.empty()) {
            cout << " Empty\n";
        }
        else {
            displayQueue(lane);
        }

        timeStep++; 
    }
    return 0;
}