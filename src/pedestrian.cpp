#include "pedestrian.h"
/*Initiatializes the probability matrix as a 3x3 matrix of zeros*/
void pedestrian::initProbMat()
{
 const unsigned width = 3;
 probMat.resize(width);
 for (unsigned i = 0; i < width; i++)
  {
   const unsigned height = 3;
   probMat[i].resize(height, 0);
  }
 
}

/*Runs through the probability matrix and selects the cell the pedestrian will move to*/
void pedestrian::move()
{
 double maxTemp = 0;
 int newX = 0;
 int newY = 0;
 for (int i = 0; i < 3; i++)
  {
   for (int j = 0; j < 3; j++)
    {
     if (probMat[1][0] + probMat[0][1] + probMat[1][2] + probMat[2][1] == 0)
      {
       newX = 1;
       newY = 1;
      }
     else if (probMat[i][j] > maxTemp)
      {
       maxTemp = probMat[i][j];
       probMax = maxTemp;
       newX = i;
       newY = j;
      }
    }
  }
 
 position[0] += (newX - 1);
 position[1] += (newY - 1);
 
}

void pedestrian::chooseMove()
{
 double maxTemp = 0;
 int newX = 0;
 int newY = 0;
 for (int i = 0; i < 3; i++)
  {
   for (int j = 0; j < 3; j++)
    {
     if (probMat[i][j] > maxTemp)
      {
       maxTemp = probMat[i][j];
       probMax = maxTemp;
       newX = i;
       newY = j;
      }
    }
  }
 
 desiredMove[0] = position[0] + (newX - 1);
 desiredMove[1] = position[1] + (newY - 1);
 
 std::cout << "Current position (" << position[0] << ", " << position[1] << ")" << std::endl;
 std::cout << "New position     (" << desiredMove[0] << ", " << desiredMove[1] << ") with probability " << probMax << std::endl;
 std::cout << std::endl;
        
}




void pedestrian::returnProbMat() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << probMat[i][j] << ":";
		}
		std::cout << "\n";
	}
}

std::vector<int> pedestrian::returnPosition() {
	return position;
}

