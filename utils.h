#ifndef UTILS_H
#define UTILS_H
#include <vector>
#include <string>
#include "state.h"

using namespace A;
using namespace std;

namespace Utils
{
  bool compare(State a1, State a2);
  bool belongsToAOrF(State m, vector<State> A, vector<State> F);
  vector<State> calculateK(State v);
  void logPositions(vector<int> positions);
  void logTree(vector<State> tree, string treeName);
  int findMinIndex(vector<State> tree, State &state);
}
#endif
