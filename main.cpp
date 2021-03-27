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
Game INITIAL_STATE = {0, 1, 5, 9, 2, 6, 10, 13, 3, 7, 11, 14, 4, 8, 12, 15};

void logGameItemVector(vector<GameItem> vec)
{
  for (int i = 0; i < vec.size(); i++)
  {
    cout << vec[i] << " ";
  }
}

void logGame(Game game)
{
  for (int i = 0; i < game.size(); i++)
  {
    cout << game[i] << " ";
  }
}

void logAllGame(vector<Game> games)
{
  for (int i = 0; i < games.size(); i++)
  {
    for (int j = 0; j < games[i].size(); j++)
    {
      cout << games[i][j] << " ";
    }
    cout << endl;
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

int getPositionZero(Game node)
{
  int pos = 0;
  for (int i = 0; i < node.size(); i++)
  {
    if (node[i] == 0)
    {
      pos = i;
      break;
    }
  }
  return pos;
}

vector<Game> calcTSuccessor(Game node)
{
  vector<Game> newNode;
  GameItem pos0 = getPositionZero(node);

  //Quatro cantos
  if (pos0 == 0)
  {
    vector<GameItem> firstChild = node, secondChild = node;

    firstChild[pos0] = node[pos0 + 1];
    firstChild[pos0 + 1] = 0;

    secondChild[pos0] = node[pos0 + 4];
    secondChild[pos0 + 4] = 0;

    newNode.push_back(firstChild);
    newNode.push_back(secondChild);
    return newNode;
  }

  if (pos0 == 3)
  {
    vector<GameItem> firstChild = node, secondChild = node;

    firstChild[pos0] = node[pos0 - 1];
    firstChild[pos0 - 1] = 0;

    secondChild[pos0] = node[pos0 + 4];
    secondChild[pos0 + 4] = 0;

    newNode.push_back(firstChild);
    newNode.push_back(secondChild);
    return newNode;
  }

  if (pos0 == 12)
  {
    vector<GameItem> firstChild = node, secondChild = node;

    firstChild[pos0] = node[pos0 - 4];
    firstChild[pos0 - 4] = 0;

    secondChild[pos0] = node[pos0 + 1];
    secondChild[pos0 + 1] = 0;

    newNode.push_back(firstChild);
    newNode.push_back(secondChild);
    return newNode;
  }

  //Laterais sem os cantos
  if (pos0 == 1 || pos0 == 2)
  {
    vector<GameItem> firstChild = node,
                     secondChild = node, thirdChild = node;

    firstChild[pos0] = node[pos0 - 1];
    firstChild[pos0 - 1] = 0;

    secondChild[pos0] = node[pos0 + 1];
    secondChild[pos0 + 1] = 0;

    thirdChild[pos0] = node[pos0 + 4];
    thirdChild[pos0 + 4] = 0;

    newNode.push_back(firstChild);
    newNode.push_back(secondChild);
    newNode.push_back(thirdChild);
    return newNode;
  }

  if (pos0 == 4 || pos0 == 8)
  {
    vector<GameItem> firstChild = node,
                     secondChild = node, thirdChild = node;

    firstChild[pos0] = node[pos0 - 4];
    firstChild[pos0 - 4] = 0;

    secondChild[pos0] = node[pos0 + 1];
    secondChild[pos0 + 1] = 0;

    thirdChild[pos0] = node[pos0 + 4];
    thirdChild[pos0 + 4] = 0;

    newNode.push_back(firstChild);
    newNode.push_back(secondChild);
    newNode.push_back(thirdChild);
    return newNode;
  }

  if (pos0 == 7 || pos0 == 11)
  {
    vector<GameItem> firstChild = node,
                     secondChild = node, thirdChild = node;

    firstChild[pos0] = node[pos0 - 4];
    firstChild[pos0 - 4] = 0;

    secondChild[pos0] = node[pos0 - 1];
    secondChild[pos0 - 1] = 0;

    thirdChild[pos0] = node[pos0 + 4];
    thirdChild[pos0 + 4] = 0;

    newNode.push_back(firstChild);
    newNode.push_back(secondChild);
    newNode.push_back(thirdChild);
    return newNode;
  }

  if (pos0 == 13 || pos0 == 14)
  {
    vector<GameItem> firstChild = node,
                     secondChild = node, thirdChild = node;

    firstChild[pos0] = node[pos0 - 4];
    firstChild[pos0 - 4] = 0;

    secondChild[pos0] = node[pos0 - 1];
    secondChild[pos0 - 1] = 0;

    thirdChild[pos0] = node[pos0 + 1];
    thirdChild[pos0 + 1] = 0;

    newNode.push_back(firstChild);
    newNode.push_back(secondChild);
    newNode.push_back(thirdChild);
    return newNode;
  }

  //Centro
  vector<GameItem> firstChild = node,
                   secondChild = node,
                   thirdChild = node,
                   fourthChild = node;

  firstChild[pos0] = node[pos0 - 4];
  firstChild[pos0 - 4] = 0;

  secondChild[pos0] = node[pos0 - 1];
  secondChild[pos0 - 1] = 0;

  thirdChild[pos0] = node[pos0 + 1];
  thirdChild[pos0 + 1] = 0;

  fourthChild[pos0] = node[pos0 + 4];
  fourthChild[pos0 + 4] = 0;

  newNode.push_back(firstChild);
  newNode.push_back(secondChild);
  newNode.push_back(thirdChild);
  return newNode;
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
    Game removed = A[v];
    A.erase(A.begin() + v);

    cout << "Removed ";
    logGame(removed);
    cout << endl;
    cout << "F ";
    logGameItemVector(F);

    cout << "\nALL GAME: " << endl;
    logAllGame(calcTSuccessor(removed));

    //Teste
    if (i == 1)
    {
      break;
    }

    return 0;
  }
}
