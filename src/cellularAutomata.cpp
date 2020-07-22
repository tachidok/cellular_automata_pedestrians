﻿#include <iostream>
#include <ctime>
#include <cmath>
#include "pedestrian.h"
#include "floorPed.h"

// Generate as many n people with random initial positions in the
// stage
void ranPed(int n, floorPed& f1, int w, int h)
{
 if (n >= (w - 2)*(h - 2))
  {
   std::cout << "Thats too many" << "\n";
   std::exit(1);
  }
 
 for (int i = 0; i < n; i++)
  {
   const unsigned x_position = 1 + (rand() % (w - 2));
   const unsigned y_position = 1 + (rand() % (h - 2));
   pedestrian temp = pedestrian(x_position, y_position);
   // Ensure whether position has not been previously used or occupied
   // by any other stuff (obstacle, wall)
   if (f1.addPed(temp) == 0)
    {
     i--;
    }
  }
}

int main(int argc, char *argv[])
{
 
 // Set seed to 0
 srand(0);
 
 const unsigned n = 1000; //Number of runs
 const unsigned width = 10; //  width of room
 const unsigned height = 10; // height of room
 const unsigned p = 10; //Number of pedestrians in room
 
 // A vector including doors positions
 std::vector<std::vector<int>> doors;
 
 std::vector<int> d1 = { 0,5 };
 std::vector<int> d2 = { 50,99 };
 std::vector<int> d3 = { 0,50 };
 std::vector<int> d4 = { 99,50 };
 std::vector<int> d5 = { 0,10 };
 std::vector<int> d6 = { 0,80 };

 // Add the doors to the scenario
 doors.push_back(d1);
 //doors.push_back(d2);
 //doors.push_back(d3);
 //doors.push_back(d4);
 //doors.push_back(d5);
 //doors.push_back(d6);

 // Create the floor field
 const double kS = 1.0;
 const double kD = 0.0;
 const double alpha = 0.7;
 const double beta = 0.8;
 floorPed f1 = floorPed(width, height, kS, kD, alpha, beta, doors);
 // Add people to the stage
 ranPed(p, f1, width, height);
 
 std::cout << "init # ped: " << f1.numberOfPed() << "\n";
 
 f1.writeStatField2File("RESLT/staticField");
 f1.writeMovements2File("RESLT/initialPosition");
 
 /*for (int i = 0; i < n; i++) {
   f1.singleRunDiag();
   }*/
 
 unsigned it = 0;
 while (f1.numberOfSavedPed() != f1.numberOfPed() && it <= n)
  {
   it++;
   f1.singleRunDiag();
   std::string fileName = "RESLT/iteration" + std::to_string(it);
   f1.writeMovements2File(fileName);
   //std::cout << it << "\n";
  }
 
 f1.writeMovements2File("RESLT/finalPosition");
 
 std::cout << "number of saved pedestrians: " << f1.numberOfSavedPed() << "\n";
 std::cout << "final # ped: " << f1.numberOfPed() - f1.numberOfSavedPed() << "\n";
 
 return 0;
 
}
