#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int hits = 0;

vector<string> parseFile(string file_location)
{
  vector<string> lines;
  string nextLine = "";
  ifstream file(file_location.c_str());

  if (file.is_open())
  {
    while (getline(file, nextLine))
    {
      if (!nextLine.empty())
        lines.push_back(nextLine);
    }

    file.close();
  }

  return lines;
}

bool validatePhrase(string word1, string word2)
{
  return (word1.compare(word2) == 0);
}

bool validateAnagram(string word1, string word2)
{
  vector<char> word1collection;
  vector<char> word2collection;
  int matches = 0;

  if (word1.length() != word2.length())
    return false;

  for (int i = 0; i < word1.length(); i++)
    word1collection.push_back(word1[i]);

  for (int i = 0; i < word2.length(); i++)
    word2collection.push_back(word2[i]);

  for (int x = 0; x < word1collection.size(); x++)
  {
    for (int y = 0; y < word2collection.size(); y++)
    {
      if (word1collection[x] == word2collection[y])
      {
        matches++;
        word2collection.erase(word2collection.begin() + y);
        break;
      }
    }
  }

  if (matches == word1.length())
  {
    cout << word1 << " is an anagram of " << word2 << "\n";
    return true;
  }

  return false;
}

void evaluateLine(string line)
{
  if (!isspace(line[0]))
    line = " " + line;

  if (!isspace(line[line.length()-1]))
    line = line + " ";

  vector<string> words;
  int lastIndex = 0;
  bool clashes = false;

  for (int z = 1; z < line.length(); z++)
  {
    if (isspace(line[z]))
    {
      string word = line.substr(lastIndex + 1, z - lastIndex - 1);
      words.push_back(word);
      lastIndex = z;
      cout << "word is: " << word << "\n";
    }
  }

  for (int x = 0; x < words.size(); x++)
  {
    for (int y = 0; y < words.size(); y++)
    {
      if (x == y)
        continue;

      if (validatePhrase(words[x], words[y]) || validateAnagram(words[x], words[y]))
        clashes = true;
    }
  }

  if (!clashes)
    hits++;
}

void evaluate(vector<string> lines)
{
  for (int i = 0; i < lines.size(); i++)
  {
    cout << "\nEvaluating next line\n";
    evaluateLine(lines[i]);
  }
}

int main(int argc, char* argv[])
{
  if (argc < 2)
    return 1;

  vector<string> lines = parseFile(argv[1]);
  evaluate(lines);

  printf("\nevaluated each lines, complete\n");
  printf("number of valid phrases: %d\n", hits);

  return 0;
}
