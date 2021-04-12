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

vector<int> T = { 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15, 4, 8, 12, 0};

void init(vector<State> &A, State &S)
{
  S.setG(0);
  //S.setH(h1(T, S.getPositions()));
  //S.setH(h2(S.getPositions()));
  S.setH(h3(T, S.getPositions()));
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

  init(A, S);
  State v = A[0];
  int vIndex = 0;
  int belongsToA = -1;

  while (v.getPositions() != T && belongsToA == -1)
  {
    A.erase(A.begin() + vIndex);
    F.push_back(v);

    K = calculateK(v);

    for (long unsigned int i = 0; i < K.size(); i++)
    {
      K[i].setG(K[i].getG() + 1);
      State m = K[i];

      int indexMl = -1;
      for (long unsigned int j = 0; j < A.size(); j++)
      {
        if (A[j].getPositions() == m.getPositions() &&
            m.getG() < A[j].getG())
        {
          indexMl = j;
        }
      }

      if (indexMl != -1)
      {
        A.erase(A.begin() + indexMl);
        vIndex = findMinIndex(A, v);
      }

      if (!belongsToAOrF(m, A, F))
      {
        //m.setH(h1(T, m.getPositions()));
        //m.setH(h2(m.getPositions()));
        m.setH(h3(T, m.getPositions()));
        A.push_back(m);
        vIndex = findMinIndex(A, v);
      }
    }

    belongsToA = getIndexIfBelongsToA(A, T);
    vIndex = findMinIndex(A, v);
  }
  if (belongsToA == -1)
    cout << v.getG() << endl;

  if (belongsToA != -1)
    cout << A[belongsToA].getG() << endl;
  return 0;
}
