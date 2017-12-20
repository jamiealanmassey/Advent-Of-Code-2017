#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>

using namespace std;

vector<int> numbers;
int totalSum = 0;
int currentNum = 0;

string calculateSlice(string input)
{
  for (int y = 0; y < input.length(); y++)
  {
    if (!isdigit(input[y]) && y > 0)
    {
      string slice = input.substr(1, y-1);
      numbers.push_back(atoi(slice.c_str()));
      cout << numbers.back() << "\n";
      return input.substr(y);
    }
  }

  return "";
}

void calculateLine(string line)
{
  printf("\ncalculating next line");

  if (isdigit(line[0]))
    line = " " + line;

  if (isdigit(line[line.length()-1]))
    line = line + " ";

  string current = line;
  int loop = 0;

  while (current.length() > 0 && loop < 100)
  {
    loop++;
    current = calculateSlice(current);
  }

  for (int i = 0; i < numbers.size(); i++)
  {
    for (int x = 0; x < numbers.size(); x++)
    {
      if (x == i)
        continue;

      if ((numbers[i] % numbers[x]) == 0)
      {
        totalSum += numbers[i] / numbers[x];
        printf("number i is %d\n", numbers[i]);
        printf("number x is %d\n", numbers[x]);
        printf("division is %d\n", numbers[i] / numbers[x]);
      }
    }
  }

  numbers.clear();
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
