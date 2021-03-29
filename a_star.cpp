#include "state.h"
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace A;

vector<int> T = {
    1, 5, 9, 13,
    2, 6, 10, 14,
    3, 7, 11, 15,
    4, 8, 12, 0};

bool compare(State a1, State a2)
{
  return a1.getF() < a2.getF();
}

void init(vector<State> &A, State &S)
{
  S.setG(0);
  S.setH(1);
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

  cout << "A size: " << A.size();

  return 0;
}
