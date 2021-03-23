#include <iostream>
#include <vector>
#include <cstring>
#include <string.h>
#include <sstream>

using namespace std;
std::stringstream ss;

vector<int> EXPECTED_FINAL_STATE = {1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15, 4, 8, 12, 0};

void log(vector<int> vec)
{
  for (int i = 0; i < vec.size(); i++)
  {
    cout << vec[i] << " ";
  }
}

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

int h1(vector<int> finalState, vector<int> currentState)
{
  int sumOfPartsOutPlace = 0;
  for (int i = 0; i < finalState.size(); i++)
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
  vector<int> currentState = split(initialState);

  int sumH1 = h1(EXPECTED_FINAL_STATE, currentState);

  cout << sumH1 << endl;

  return 0;
}
