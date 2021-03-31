#ifndef UTILS_H
#define UTILS_H
#include <vector>
#include "state.h"

using namespace A;
using namespace std;

namespace Utils
{
  bool compare(State a1, State a2);
  vector<State> calculateK(State v);
}
#endif
