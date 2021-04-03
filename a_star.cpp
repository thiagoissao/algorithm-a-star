#include "state.h"
#include "utils.h"
#include "heuristic.h"
#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;
using namespace Utils;
using namespace A;
using namespace H;
std::stringstream ss;

vector<int> split(const string &str, char delim = ' ')
{
  stringstream ss(str);
  string tok;
  vector<int> vec;
  while (getline(ss, tok, delim))
  {
    if (!tok.empty())
      vec.push_back(stoi(tok));
  }
  return vec;
}

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

  string initialState;
  getline(cin, initialState);

  vector<int> initialPositions = split(initialState);

  S.setPositions(initialPositions);

  make_heap(A.begin(), A.end(), compare);
  make_heap(F.begin(), F.end(), compare);
  make_heap(K.begin(), K.end(), compare);

  init(A, S);
  push_heap(A.begin(), A.end(), compare);

  State v = A[0];

  while (v.getPositions() != T)
  {
    int vIndex = findMinIndex(A, v);
    A.erase(A.begin() + vIndex);
    pop_heap(A.begin(), A.end(), compare);

    F.push_back(v);
    push_heap(F.begin(), F.end(), compare);

    K = calculateK(v);

    for (int i = 0; i < K.size(); i++)
    {
      K[i].setG(v.getG() + 1);
      State m = K[i];

      for (int j = 0; j < A.size(); j++)
      {
        State ml = A[j];

        if (ml.getPositions() == m.getPositions() &&
            m.getG() < ml.getG())
        {
          A.erase(A.begin() + j);
          pop_heap(A.begin(), A.end(), compare);
        }
      }

      if (!belongsToAOrF(m, A, F))
      {
        m.setH(h1(T, m.getPositions()));
        A.push_back(m);
        push_heap(A.begin(), A.end(), compare);
      }
    }
  }

  cout << v.getG() << endl;
  return 0;
}
