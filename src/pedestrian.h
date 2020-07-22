#include <vector>
#include <iostream>
#include <cmath>

#ifndef PEDESTRIAN_H
#define PEDESTRIAN_H

class pedestrian {
	
	friend class floorPed;

	//class variables
	std::vector<int> position; //Will hold two elements only, x and y
	std::vector<std::vector<double>> probMat; //3x3 matrix that show the probability of the pedestrian to move to each cell
	std::vector<int> desiredMove; //Hold the chosen cell the pedestrian wants to move to. Will be used to detect and deal with conflicts
	double probMax; //Holds the probability of the choosen cell the pedestrian wants to move to
	bool escape;//0 if not at the door, 1 when at the door
	
	void initializePedestrian(int x, int y) {
		position.push_back(x);
		position.push_back(y);
		desiredMove = { 0,0 };
		escape = 0;
		initProbMat();
	}

public:
	
	void move();
	void chooseMove();
	void initProbMat();
	void returnProbMat();
	std::vector<int> returnPosition();
	
	pedestrian(int x_, int y_) {
		initializePedestrian(x_, y_);
	}

};

#endif // #ifndef PEDESTRIAN_H
