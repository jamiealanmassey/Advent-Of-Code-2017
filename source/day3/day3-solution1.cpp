#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int previousSegment = 0;
int previousCount = 1;
int previousLast = 1;

int currentSegment = 1;
int currentCount = 8;
int currentLast = previousLast + currentCount;

int steps = 0;

bool evaluate(int number)
{
  if (number == 1)
    return true;

  // Number has been found in this range
  if (number > previousLast && number <= currentLast)
  {
    int coordX = 0;
    int coordY = 0;

    int segment1 = currentCount / 4;
    int segment2 = segment1 * 2;
    int segment3 = segment1 * 3;
    int segment4 = segment1 * 4;
    int foundSegment = -1;

    if (previousLast + segment4 > number && previousLast + segment3 < number)
      foundSegment = 3;
    else if (previousLast + segment3 > number && previousLast + segment2 < number)
      foundSegment = 2;
    else if (previousLast + segment2 > number && previousLast + segment1 < number)
      foundSegment = 1;
    else if (previousLast + segment1 > number)
      foundSegment = 0;

    if (foundSegment == 0)
    {
      coordX = currentSegment;
      coordY = (segment1 / 2) - (number - previousLast);
      printf("segment 0 | coord X: %d, coord Y: %d\n", coordX, coordY);
    }
    else if (foundSegment == 1)
    {
      coordX = (segment1 + (segment1 / 2)) - (number - previousLast);
      coordY = currentSegment;
      printf("segment 1 | coord X: %d, coordY: %d\n", coordX, coordY);
    }
    else if (foundSegment == 2)
    {
      coordX = currentSegment;
      coordY = (segment2 + (segment1 / 2)) - (number - previousLast);
      printf("segment 2 | coord X: %d, coord Y: %d\n", coordX, coordY);
    }
    else if (foundSegment == 3)
    {
      coordX = (segment3 + (segment1 / 2)) - (number - previousLast);
      coordY = currentSegment;
      printf("segment 3 | coord X: %d, coord Y: %d\n", coordX, coordY);
    }
    else
    {
      coordX = currentSegment;
      coordY = currentSegment;
      printf("segment corner | coordX: %d, coord Y: %d\n", coordX, coordY);
    }

    steps = abs(coordX) + abs(coordY);
    return true;
  }

  previousSegment = currentSegment;
  previousCount = currentCount;
  previousLast = currentLast;

  currentSegment++;
  currentCount += 8;
  currentLast = previousLast + currentCount;
  return false;
}

int main(int argc, char* argv[])
{
  if (argc < 2)
    return 1;

  int targetNumber = atoi(argv[1]);
  while (!evaluate(targetNumber));
  printf("finished evaluation of the spiral tree\n");
  printf("number of steps to 1 is %d\n", steps);

  return 0;
}
