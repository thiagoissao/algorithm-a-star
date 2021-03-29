#include "heuristic.h"
#include <vector>
#include <iostream>

using namespace std;
using namespace H;

int Heuristic::h1(vector<int> final, vector<int> current)
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
