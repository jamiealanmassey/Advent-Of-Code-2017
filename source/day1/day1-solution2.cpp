#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(void)
{
  string input = "";
  int nextIndex = 0;
  int totalSum = 0;
  int midpoint = 0;

  printf("Day 1 second solution to Advent of Code\n");
  printf("Please input number stream to be summed: ");

  cin >> input;

  printf("\n");
  midpoint = input.length() / 2;
  printf("midpoint is %d\n\n", midpoint);

  for (int i = 0; i < input.length(); i++)
  {
    if ((nextIndex = i+midpoint) > input.length()-1)
      nextIndex = nextIndex - input.length();

    char character0 = input[i];
    char character1 = input[nextIndex];

    printf("index is %d\n", i);
    printf("index after is %d\n", nextIndex);
    printf("character0 is %d\n", character0);
    printf("character1 is %d\n\n", character1);

    int digit0 = character0 - '0';
    int digit1 = character1 - '0';

    if (digit0 == digit1)
      totalSum += digit0;
  }

  printf("\n");
  printf("calculated the solution\n");
  printf("result of the solution is %d\n", totalSum); 

  return 0;
}
