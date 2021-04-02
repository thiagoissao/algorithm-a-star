#include "state.h"
#include "utils.h"
#include "heuristic.h"
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
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

  for (int i = 0; i < A.size(); i++)
  {
    // logTree(A, "A");
    if (A[i].getPositions() == T)
    {
      cout << "HERE" << endl;
      break;
    }

    State v = A.back();
    A.pop_back();

    K = calculateK(v);

    // logTree(A, "A");
    // logTree(K, "K");

    for (int i = 0; i < K.size(); i++)
    {
      K[i].setG(v.getG() + 1); //calcule G
      State m = K[i];

      for (int j = 0; j < A.size(); j++)
      {
        State ml = A[j];
        if (ml.getPositions() == m.getPositions() &&
            m.getG() < ml.getG())
        {
          cout << "REMOVER DE A PORQUE ENCONTRAMOS UM CAMINHO MELHOR " << endl;
          logPositions(ml.getPositions());
          cout << "A -> f: " << ml.getH();
          logPositions(m.getPositions());
          cout << "K -> f: " << m.getH();
          cout << endl;

          logTree(A, "A");

          A.back();
          A.pop_back();

          logTree(A, "A");
        }
      }

      if (!belongsToAOrF(m, A, F))
      {
        A.push_back(m);
        push_heap(A.begin(), A.end(), compare);
        K[i].setH(h1(T, m.getPositions()));
      }
    }
  }

  State v = A.back();
  A.pop_back();

  if (v.getPositions() == T)
  {
    cout << "SUCESSO";
  }
  else
  {
    cout << "FRACASSO";
  }

  return 0;
}
