#include "state.h"
#include "utils.h"
#include "heuristic.h"
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace Utils;
using namespace A;
using namespace H;

vector<int> T = {
    1, 5, 9, 13,
    2, 6, 10, 14,
    3, 7, 11, 15,
    4, 8, 12, 0};

void init(vector<State> &A, State &S)
{
  S.setG(0);
  S.setH(h1(T, S.getPositions()));
  S.setNode(0);
  A.push_back(S);
}

int main()
{
  vector<State> A;
  vector<State> F;
  vector<State> K;
  State S;

  make_heap(A.begin(), A.end(), compare);
  make_heap(F.begin(), F.end(), compare);
  make_heap(K.begin(), K.end(), compare);

  init(A, S);
  push_heap(A.begin(), A.end(), compare);
  cout << "A node: " << A.front().getNode();

  for (int i = 0; i < A.size(); i++)
  {
    if (A[i].getPositions() == T)
      break;

    State v = A.back();
    A.pop_back();

    K = calculateK(v);
  }

  return 0;
}
