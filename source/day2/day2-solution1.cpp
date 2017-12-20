#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int lowestNum = 9999999;
int highestNum = 0;
int totalSum = 0;
int currentNum = 0;

string calculateSlice(string input)
{
  if (isdigit(input[0]))
    input = " " + input;

  if (isdigit(input[input.length()-1]))
    input = input + " ";

  for (int y = 0; y < input.length(); y++)
  {
    if (!isdigit(input[y]) && y > 0)
    {
      string slice = input.substr(1, y-1);
      currentNum = atoi(slice.c_str());

      cout << input << "\n";
      cout << currentNum << "\n";
      lowestNum = min(lowestNum, currentNum);
      highestNum = max(highestNum, currentNum);
      return input.substr(y);
    }
  }

  return "";
}

void calculateLine(string line)
{
  int looped = 0;
  string currentString = line;
  lowestNum = 99999;
  highestNum = 0;
  currentNum = 0;

  while (currentString.length() > 0 && looped < 200)
  {
    looped++;
    currentString = calculateSlice(currentString);
  }

  totalSum += (highestNum - lowestNum);
  printf("highest num %d\n", highestNum);
  printf("lowest num %d\n", lowestNum);
  printf("total sum %d\n", totalSum);
}

int main(int argc, char* argv[])
{
  if (argc < 2)
    return 1;

  ifstream file(argv[1]);
  vector<string> lines;
  string next = "";

  if (file.is_open())
  {
    while (getline(file, next))
      lines.push_back(next);

    file.close();
  }

  for (int i = 0; i < lines.size(); i++)
    calculateLine(lines[i]);

  printf("\n");
  printf("summation complete\n");
  printf("total sum is %d\n", totalSum);

  return 0;
}
