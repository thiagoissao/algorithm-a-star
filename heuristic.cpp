#include "heuristic.h"
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;
using namespace H;

int getManhattanDistance(int num, int index)
{
  vector<int> originalPositions = {
      15,
      0, 4, 8, 12,
      1, 5, 9, 13,
      2, 6, 10, 14,
      3, 7, 11};

  return abs(index - originalPositions[num]);
}

int H::h1(vector<int> final, vector<int> current)
{
  int sumOfPartsOutPlace = 0;
  for (int i = 0; i < final.size(); i++)
  {
    if (final[i] != 0 && final[i] != current[i])
    {
      sumOfPartsOutPlace += 1;
    }
  }
  return sumOfPartsOutPlace;
}

int H::h2(vector<int> current)
{
  int sum = 0;
  for (int i = 1; i < current.size(); i++)
  {
    if (current[i] - 1 != current[i - 1] && current[i] != 0)
    {
      sum++;
    }
  }
  return sum;
}

int H::h3(vector<int> final, vector<int> current)
{
  int sum = 0;
  for (int i = 0; i < current.size(); i++)
  {
    if (current[i] != 0 && current[i] != final[i])
    {
      sum += getManhattanDistance(current[i], i);
    }
  }

  return sum;
}
