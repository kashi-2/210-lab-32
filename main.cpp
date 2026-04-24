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
    const int NUM_LANES = 4;
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

    // Simulation loop (milestone 4)
    for (int time = 1; time <= TIME_PERIODS; time++) {
        cout << "\nTime: " << time << endl;

        // process each lane
        for (int i = 0; i < NUM_LANES; i++) {

            cout << "Lane: " << i + 1 << " ";

            //if lane empty (50/50)
            if (lanes[i].empty()) {
                if (rand() % 2 == 0) {
                    Car c;
                    lanes[i].push_back(c);
                    cout << "Joined: ";
                    c.print();
                    cout << endl;
                }
                else {
                    cout << "No operation\n";
                }
                continue;
            }

            int r = rand() % 100;
        //Milestone 5  
        // Pay
            if (r < PAY_PROB) {
                Car c = lanes[i].front();
                lanes[i].pop_front();

                cout << "Paid: ";
                c.print();
                cout << endl;
            }
            // Join
            else if (r < PAY_PROB + JOIN_PROB) {
                Car c;
                lanes[i].push_back(c);

                cout << "Joined: ";
                c.print();
                cout << endl;
            }
            // Switch
            else {
                // only if more than 1 lane has cars
                if (!lanes[i].empty()) {
                    Car c = lanes[i].back();
                    lanes[i].pop_back();

                    int newLane;
                    do {
                        newLane = rand() % NUM_LANES;
                    } while (newLane == i);

                    lanes[newLane].push_back(c);

                    cout << "Switched: ";
                    c.print();
                    cout << endl;
                }
            }
        }

        // print queues after all operations (milestone 4)
        for (int i = 0; i < NUM_LANES; i++) {
            cout << "Lane " << i + 1 << " Queue:\n";

            if (lanes[i].empty()) {
                cout << "    empty\n";
            }
            else {
                displayLane(lanes[i]);
            }
        }
    }

    return 0;
}

//function to display function
void displayQueue(deque<Car>& lane) {
    for (int i = 0; i < lane.size(); i++) {
        cout << "    ";
        lane[i].print();
        cout << endl;
    }
}