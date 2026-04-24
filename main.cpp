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