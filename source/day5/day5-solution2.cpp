#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int lastoffset = 0;
int instruction = 0;
int steps = 0;

// Trim function to remove whitepsape from a string
// credit: https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
string trim(string str)
{
  const char* ws = " \t\n\r\f\v";
  size_t endpos = str.find_last_not_of(ws);
  size_t startpos = str.find_first_not_of(ws);

  if (string::npos != endpos)
  {
    str = str.substr(0, endpos+1);
    str = str.substr(startpos);
  }
  else
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());

  startpos = str.find_first_not_of(ws);
  if (string::npos != startpos)
    str = str.substr(startpos);

  return str;
}

vector<int> parseDigitList(string file_input)
{
  ifstream file(file_input.c_str());
  vector<int> digits;

  if (file.is_open())
  {
    string nextLine = "";
    while (getline(file, nextLine))
    {
      if (!nextLine.empty())
      {
        nextLine = trim(nextLine);
        digits.push_back(atoi(nextLine.c_str()));
        //printf("Found the instruction %d\n", atoi(nextLine.c_str()));
      }
    }

    file.close();
  }

  return digits;
}

void evaluate(vector<int> digits)
{
  while (instruction < digits.size())
  {
    /*for (int i = 0; i < digits.size(); i++)
      printf("%d ", digits[i])*/

    //printf("| %d -> ", instruction);
    int current = instruction;
    steps++;
    lastoffset = digits[instruction];
    instruction += lastoffset;

    if (lastoffset >= 3)
      digits[current]--;
    else
      digits[current]++;

    //printf("%d\n", instruction);
  }
}

int main(int argc, char* argv[])
{
  if (argc < 2)
    return 1;

  evaluate(parseDigitList(argv[1]));

  printf("\n");
  printf("solved the instruction set in %d steps\n", steps);
  return 0;
}

