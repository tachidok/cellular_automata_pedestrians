
#include "stdafx.h"
#include <iostream>
#include "pedestrian.h"
#include "floorPed.h"

void ranPed(int n, floorPed& f1, int x, int y) {

	if (n >= (x - 2)*(y - 2)) {
		std::cout << "Thats too many" << "\n";
	}
	for (int i = 0; i < n; i++) {
		pedestrian temp = pedestrian(1 + rand() % (x - 2), 1 + rand() % (y - 2));
		if (f1.addPed(temp) == 0) {
			i--;
		}
	}
}

int main() {
	int n = 4000; //Number of runs
	int x = 1000; //x-dimension of room
	int y = 1000; //y-dimension of room
	int p = 2; //Number of pedestrians in room

	std::vector<std::vector<int>> doors;

	std::vector<int> d1 = { 0,3 };
	std::vector<int> d2 = { 10,20 };
	std::vector<int> d3 = { 0,4 };
	std::vector<int> d4 = { 0,5 };
	std::vector<int> d5 = { 0,6 };
	std::vector<int> d6 = { 0,7 };

	doors.push_back(d1);
	//doors.push_back(d2);
	//doors.push_back(d3);
	//doors.push_back(d4);
	//doors.push_back(d5);
	//doors.push_back(d6);


	floorPed f1 = floorPed(x, y, 1, 0, 1, doors);
	ranPed(p, f1, x, y);
	std::cout << "init # ped: " << f1.numberOfPed() << "\n";

	f1.writeMovements2File("initialPosition");

	f1.writeStatField2File("staticField");

	int i = 0;
	
	for (int i = 0; i < n; i++) {
		f1.singleRun();
		if (i % 100 == 0) {
			std::cout << i << "\n";
		}
	}

	std::cout << "final # ped: " << f1.numberOfPed() << "\n";
	f1.writeMovements2File("finalPosition");

}

