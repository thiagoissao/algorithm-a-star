#include <iostream>
#include <vector>
#include "heuristic.h"

using namespace std;
using namespace H;

vector<int> FINAL_STATE = {1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15, 4, 8, 12, 0};

vector<int> CURRENT_CASE1 = {0, 1, 5, 9, 2, 6, 10, 13, 3, 7, 11, 14, 4, 8, 12, 15};
int EXPECTED_CASE1 = 6;

vector<int> CURRENT_CASE2 = {2, 1, 5, 9, 3, 6, 10, 13, 4, 7, 11, 14, 0, 8, 12, 15};
int EXPECTED_CASE2 = 9;

vector<int> CURRENT_CASE3 = {2, 1, 10, 9, 3, 5, 11, 13, 4, 6, 12, 14, 0, 7, 8, 15};
int EXPECTED_CASE3 = 15;

int main()
{
  Heuristic heuristic;
  int expected_case1 = heuristic.h1(FINAL_STATE, CURRENT_CASE1);
  int expected_case2 = heuristic.h1(FINAL_STATE, CURRENT_CASE2);
  int expected_case3 = heuristic.h1(FINAL_STATE, CURRENT_CASE3);

  cout << "Expected case 1: " << (expected_case1 == EXPECTED_CASE1 ? "PASSED" : "FAILED") << endl;
  cout << "Expected case 2: " << (expected_case2 == EXPECTED_CASE2 ? "PASSED" : "FAILED") << endl;
  cout << "Expected case 3: " << (expected_case3 == EXPECTED_CASE3 ? "PASSED" : "FAILED") << endl;

  return 0;
}
