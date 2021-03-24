#include <iostream>
#include <vector>
#include <cstring>
#include <string.h>
#include <sstream>

using namespace std;
std::stringstream ss;

typedef unsigned int GameItem;
typedef vector<GameItem> Game;

Game FINAL_STATE = {1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15, 4, 8, 12, 0};

void log(Game vec)
{
  for (unsigned int i = 0; i < vec.size(); i++)
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

unsigned int h1(Game finalState, Game currentState)
{
  unsigned int sumOfPartsOutPlace = 0;
  for (unsigned int i = 0; i < finalState.size(); i++)
  {
    if (finalState[i] != 0 && finalState[i] != currentState[i])
    {
      sumOfPartsOutPlace += 1;
    }
  }
  return sumOfPartsOutPlace;
}

int main()
{
  string initialState;
  getline(cin, initialState);

  Game currentState = split(initialState);

  vector<Game> A = {currentState};
  vector<Game> T = {FINAL_STATE};
  vector<Game> F;
  vector<GameItem> h;
  vector<GameItem> g;
  vector<int> P;

  for (int i = 0; i < A.size(); i++)
  {
    h.push_back(h1(FINAL_STATE, A[i]));
    P.push_back(0);
    g.push_back(0);
  }

  return 0;
}
