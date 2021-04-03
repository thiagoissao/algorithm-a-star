#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include "heuristic.h"
#include "state.h"
#include "utils.h"

using namespace std;
using namespace H;
using namespace A;
using namespace Utils;

vector<int> FINAL_STATE = {1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15, 4, 8, 12, 0};

vector<int> CURRENT_CASE1 = {0, 1, 5, 9, 2, 6, 10, 13, 3, 7, 11, 14, 4, 8, 12, 15};
int EXPECTED_CASE1 = 6;

vector<int> CURRENT_CASE2 = {2, 1, 5, 9, 3, 6, 10, 13, 4, 7, 11, 14, 0, 8, 12, 15};
int EXPECTED_CASE2 = 9;

vector<int> CURRENT_CASE3 = {2, 1, 10, 9, 3, 5, 11, 13, 4, 6, 12, 14, 0, 7, 8, 15};
int EXPECTED_CASE3 = 15;

vector<int> CURRENT_CASE6 = {1, 6, 5, 9, 0, 2, 10, 13, 3, 7, 11, 14, 4, 8, 12, 15};
int EXPECTED_CASE6 = 7;

vector<int> CURRENT_CASE7 = {1, 5, 10, 9, 2, 6, 0, 13, 3, 7, 11, 14, 4, 8, 12, 15};
vector<int> CURRENT_CASE8 = {1, 6, 5, 9, 2, 7, 10, 13, 3, 11, 0, 14, 4, 8, 12, 15};
vector<int> CURRENT_CASE9 = {6, 0, 5, 9, 1, 2, 10, 13, 3, 7, 11, 14, 4, 8, 12, 15};

int main()
{
  vector<State> A;
  State S;
  int expected_case1 = h1(FINAL_STATE, CURRENT_CASE1);
  int expected_case2 = h1(FINAL_STATE, CURRENT_CASE2);
  int expected_case3 = h1(FINAL_STATE, CURRENT_CASE3);
  int expected_case6 = h1(FINAL_STATE, CURRENT_CASE6);

  cout << "CASE 7: " << h1(FINAL_STATE, CURRENT_CASE7) << endl;
  cout << "CASE 8: " << h1(FINAL_STATE, CURRENT_CASE8) << endl;
  cout << "CASE 9: " << h1(FINAL_STATE, CURRENT_CASE9) << endl;

  cout << "Expected case 1: " << (expected_case1 == EXPECTED_CASE1 ? "PASSED" : "FAILED") << endl;
  cout << "Expected case 2: " << (expected_case2 == EXPECTED_CASE2 ? "PASSED" : "FAILED") << endl;
  cout << "Expected case 3: " << (expected_case3 == EXPECTED_CASE3 ? "PASSED" : "FAILED") << endl;
  cout << "Expected case 6: " << (expected_case6 == EXPECTED_CASE6 ? "PASSED" : "FAILED") << endl;

  S.setG(0);
  S.setH(0);
  S.setNode(0);

  make_heap(A.begin(), A.end(), compare);

  A.push_back(S);
  push_heap(A.begin(), A.end(), compare);

  S.setG(1);
  S.setH(1);
  S.setNode(1);

  A.push_back(S);
  push_heap(A.begin(), A.end(), compare);

  S.setG(1);
  S.setH(0);
  S.setNode(2);

  A.push_back(S);
  push_heap(A.begin(), A.end(), compare);

  S.setG(3);
  S.setH(0);
  S.setNode(3);

  A.push_back(S);
  push_heap(A.begin(), A.end(), compare);

  auto expected_case4 = A.back();
  A.pop_back();

  auto expected_case5 = A.back();
  A.pop_back();

  //Valores de F inseridos => 0 | 2 | 1 | 3
  //Valores de F removidos => 0 | 1
  cout << "Expected case 4: " << (expected_case4.getF() == 0 ? "PASSED" : "FAILED") << endl;
  cout << "Expected case 5: " << (expected_case5.getF() == 1 ? "PASSED" : "FAILED") << endl;

  return 0;
}
