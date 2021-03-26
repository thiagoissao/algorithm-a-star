#include <iostream>
#include <vector>
#include <cstring>
#include <string.h>
#include <sstream>

using namespace std;
std::stringstream ss;

typedef int GameItem;
typedef vector<GameItem> Game;

Game FINAL_STATE = {1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15, 4, 8, 12, 0};

void log(vector<GameItem> vec)
{
  for (int i = 0; i < vec.size(); i++)
  {
    cout << vec[i] << " ";
  }
}

Game split(const string &str, char delim = ' ')
{
  stringstream ss(str);
  string tok;
  Game vec;
  while (getline(ss, tok, delim))
  {
    if (!tok.empty())
      vec.push_back(stoi(tok));
  }
  return vec;
}

int h1(Game finalState, Game currentState)
{
  GameItem sumOfPartsOutPlace = 0;
  for (int i = 0; i < finalState.size(); i++)
  {
    if (finalState[i] != 0 && finalState[i] != currentState[i])
    {
      sumOfPartsOutPlace += 1;
    }
  }
  return sumOfPartsOutPlace;
}

void initialize(vector<Game> &A, vector<GameItem> &h, vector<GameItem> &g, vector<GameItem> &P)
{
  for (int i = 0; i < A.size(); i++)
  {
    h.push_back(h1(FINAL_STATE, A[i]));
    P.push_back(0);
    g.push_back(0);
  }
}

GameItem calculateF(vector<Game> A, vector<GameItem> h, vector<GameItem> g, vector<GameItem> &F, GameItem &index)
{
  vector<GameItem> newF;
  GameItem min = h1(FINAL_STATE, A[0]) + g[0];
  index = 0;
  newF.push_back(min);

  for (int i = 1; i < A.size(); i++)
  {
    GameItem minAux = h1(FINAL_STATE, A[i]) + g[i];
    newF.push_back(minAux);

    if (minAux < min)
    {
      index = i;
      min = minAux;
    }
  }

  F = newF;
  return min;
}

int main()
{
  string initialState;
  getline(cin, initialState);

  Game currentState = split(initialState);

  vector<Game> A = {currentState};
  vector<Game> T = {FINAL_STATE};
  vector<GameItem> F;
  vector<GameItem> h;
  vector<GameItem> g;
  vector<GameItem> P;

  initialize(A, h, g, P);

  for (int i = 0; i < A.size(); i++)
  {
    if (h1(FINAL_STATE, A[i]) == 0)
    {
      break;
    }
    GameItem v;
    calculateF(A, h, g, F, v);
    A.erase(A.begin() + v);

    cout << "F ";
    log(F);

    //Teste
    if (i == 1)
    {
      break;
    }

    return 0;
  }
}
