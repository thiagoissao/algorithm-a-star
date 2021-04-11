#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <math.h>

using namespace std;
std::stringstream ss;

class State
{
  private:
    int h;
    int g;
    int node;
    vector<int> positions;

  public:
    void setH(int h)
    {
        this->h = h;
    }

    void setG(int g)
    {
        this->g = g;
    }

    void setNode(int node)
    {
        this->node = node;
    }

    int getH()
    {
        return this->h;
    }

    int getG()
    {
        return this->g;
    }

    int getF()
    {
        return this->h + this->g;
    }

    int getNode()
    {
        return this->node;
    }

    vector<int> getPositions()
    {
        return this->positions;
    }

    void setPositions(vector<int> p)
    {
        this->positions = p;
    }
};

void logPositions(vector<int> positions)
{
  cout << "POSITIONS: ";
  for (long unsigned int i = 0; i < positions.size(); i++)
  {
    cout << positions[i] << " ";
  }
  cout << endl;
}

void logTree(vector<State> tree, string treeName)
{
  cout << "Printing: " << treeName << endl;
  for (long unsigned int i = 0; i < tree.size(); i++)
  {
    cout << "Node: " << i << " ";
    logPositions(tree[i].getPositions());
  }
  cout << endl;
}

bool compare(State a1, State a2)
{
  return a1.getF() < a2.getF();
}

int findMinIndex(vector<State> tree, State &state)
{
  State min = tree[0];
  int index = 0;
  for (long unsigned int i = 1; i < tree.size(); i++)
  {
    if (tree[i].getF() < min.getF())
    {
      min = tree[i];
      index = i;
    }
  }
  state = min;
  return index;
}

int getPositionZero(State node)
{
  int pos = 0;
  for (long unsigned int i = 0; i < node.getPositions().size(); i++)
  {
    if (node.getPositions()[i] == 0)
    {
      pos = i;
      break;
    }
  }
  return pos;
}

vector<State> calculateK(State v)
{
  vector<State> K;
  int pos0 = getPositionZero(v);

  //Quatro cantos
  if (pos0 == 0)
  {
    State firstChild = v, secondChild = v;

    vector<int> firstPositions = v.getPositions();
    firstPositions[pos0] = firstPositions[pos0 + 1];
    firstPositions[pos0 + 1] = 0;
    firstChild.setPositions(firstPositions);

    vector<int> secondPositions = v.getPositions();
    secondPositions[pos0] = secondPositions[pos0 + 4];
    secondPositions[pos0 + 4] = 0;
    secondChild.setPositions(secondPositions);

    K.push_back(firstChild);
    K.push_back(secondChild);
    push_heap(K.begin(), K.end(), compare);
    return K;
  }

  if (pos0 == 3)
  {
    State firstChild = v, secondChild = v;

    vector<int> firstPositions = v.getPositions();
    firstPositions[pos0] = firstPositions[pos0 - 1];
    firstPositions[pos0 - 1] = 0;
    firstChild.setPositions(firstPositions);

    vector<int> secondPositions = v.getPositions();
    secondPositions[pos0] = secondPositions[pos0 + 4];
    secondPositions[pos0 + 4] = 0;
    secondChild.setPositions(secondPositions);

    K.push_back(firstChild);
    K.push_back(secondChild);
    push_heap(K.begin(), K.end(), compare);
    return K;
  }

  if (pos0 == 12)
  {
    State firstChild = v, secondChild = v;

    vector<int> firstPositions = v.getPositions();
    firstPositions[pos0] = firstPositions[pos0 + 1];
    firstPositions[pos0 + 1] = 0;
    firstChild.setPositions(firstPositions);

    vector<int> secondPositions = v.getPositions();
    secondPositions[pos0] = secondPositions[pos0 - 4];
    secondPositions[pos0 - 4] = 0;
    secondChild.setPositions(secondPositions);

    K.push_back(firstChild);
    K.push_back(secondChild);
    push_heap(K.begin(), K.end(), compare);
    return K;
  }

  if (pos0 == 15)
  {
    State firstChild = v, secondChild = v;

    vector<int> firstPositions = v.getPositions();
    firstPositions[pos0] = firstPositions[pos0 - 1];
    firstPositions[pos0 - 1] = 0;
    firstChild.setPositions(firstPositions);

    vector<int> secondPositions = v.getPositions();
    secondPositions[pos0] = secondPositions[pos0 - 4];
    secondPositions[pos0 - 4] = 0;
    secondChild.setPositions(secondPositions);

    K.push_back(firstChild);
    K.push_back(secondChild);
    push_heap(K.begin(), K.end(), compare);
    return K;
  }

  //Laterais sem os cantos
  if (pos0 == 1 || pos0 == 2)
  {

    State firstChild = v, secondChild = v, thirdChild = v;

    vector<int> firstPositions = v.getPositions();
    firstPositions[pos0] = firstPositions[pos0 + 1];
    firstPositions[pos0 + 1] = 0;
    firstChild.setPositions(firstPositions);

    vector<int> secondPositions = v.getPositions();
    secondPositions[pos0] = secondPositions[pos0 - 1];
    secondPositions[pos0 - 1] = 0;
    secondChild.setPositions(secondPositions);

    vector<int> thirdPositions = v.getPositions();
    thirdPositions[pos0] = thirdPositions[pos0 + 4];
    thirdPositions[pos0 + 4] = 0;
    thirdChild.setPositions(thirdPositions);

    K.push_back(firstChild);
    K.push_back(secondChild);
    K.push_back(thirdChild);
    push_heap(K.begin(), K.end(), compare);
    return K;
  }

  if (pos0 == 4 || pos0 == 8)
  {
    State firstChild = v, secondChild = v, thirdChild = v;

    vector<int> firstPositions = v.getPositions();
    firstPositions[pos0] = firstPositions[pos0 + 1];
    firstPositions[pos0 + 1] = 0;
    firstChild.setPositions(firstPositions);

    vector<int> secondPositions = v.getPositions();
    secondPositions[pos0] = secondPositions[pos0 - 4];
    secondPositions[pos0 - 4] = 0;
    secondChild.setPositions(secondPositions);

    vector<int> thirdPositions = v.getPositions();
    thirdPositions[pos0] = thirdPositions[pos0 + 4];
    thirdPositions[pos0 + 4] = 0;
    thirdChild.setPositions(thirdPositions);

    K.push_back(firstChild);
    K.push_back(secondChild);
    K.push_back(thirdChild);
    push_heap(K.begin(), K.end(), compare);
    return K;
  }

  if (pos0 == 7 || pos0 == 11)
  {
    State firstChild = v, secondChild = v, thirdChild = v;

    vector<int> firstPositions = v.getPositions();
    firstPositions[pos0] = firstPositions[pos0 - 1];
    firstPositions[pos0 - 1] = 0;
    firstChild.setPositions(firstPositions);

    vector<int> secondPositions = v.getPositions();
    secondPositions[pos0] = secondPositions[pos0 - 4];
    secondPositions[pos0 - 4] = 0;
    secondChild.setPositions(secondPositions);

    vector<int> thirdPositions = v.getPositions();
    thirdPositions[pos0] = thirdPositions[pos0 + 4];
    thirdPositions[pos0 + 4] = 0;
    thirdChild.setPositions(thirdPositions);

    K.push_back(firstChild);
    K.push_back(secondChild);
    K.push_back(thirdChild);
    push_heap(K.begin(), K.end(), compare);
    return K;
  }

  if (pos0 == 7 || pos0 == 11)
  {
    State firstChild = v, secondChild = v, thirdChild = v;

    vector<int> firstPositions = v.getPositions();
    firstPositions[pos0] = firstPositions[pos0 - 1];
    firstPositions[pos0 - 1] = 0;
    firstChild.setPositions(firstPositions);

    vector<int> secondPositions = v.getPositions();
    secondPositions[pos0] = secondPositions[pos0 + 4];
    secondPositions[pos0 + 4] = 0;
    secondChild.setPositions(secondPositions);

    vector<int> thirdPositions = v.getPositions();
    thirdPositions[pos0] = thirdPositions[pos0 - 4];
    thirdPositions[pos0 - 4] = 0;
    thirdChild.setPositions(thirdPositions);

    K.push_back(firstChild);
    K.push_back(secondChild);
    K.push_back(thirdChild);
    push_heap(K.begin(), K.end(), compare);
    return K;
  }

  if (pos0 == 13 || pos0 == 14)
  {
    State firstChild = v, secondChild = v, thirdChild = v;

    vector<int> firstPositions = v.getPositions();
    firstPositions[pos0] = firstPositions[pos0 + 1];
    firstPositions[pos0 + 1] = 0;
    firstChild.setPositions(firstPositions);

    vector<int> secondPositions = v.getPositions();
    secondPositions[pos0] = secondPositions[pos0 - 1];
    secondPositions[pos0 - 1] = 0;
    secondChild.setPositions(secondPositions);

    vector<int> thirdPositions = v.getPositions();
    thirdPositions[pos0] = thirdPositions[pos0 - 4];
    thirdPositions[pos0 - 4] = 0;
    thirdChild.setPositions(thirdPositions);

    K.push_back(firstChild);
    K.push_back(secondChild);
    K.push_back(thirdChild);
    push_heap(K.begin(), K.end(), compare);
    return K;
  }

  //Centro
  State firstChild = v, secondChild = v, thirdChild = v, fourthChild = v;

  vector<int> firstPositions = v.getPositions();
  firstPositions[pos0] = firstPositions[pos0 + 1];
  firstPositions[pos0 + 1] = 0;
  firstChild.setPositions(firstPositions);

  vector<int> secondPositions = v.getPositions();
  secondPositions[pos0] = secondPositions[pos0 - 1];
  secondPositions[pos0 - 1] = 0;
  secondChild.setPositions(secondPositions);

  vector<int> thirdPositions = v.getPositions();
  thirdPositions[pos0] = thirdPositions[pos0 + 4];
  thirdPositions[pos0 + 4] = 0;
  thirdChild.setPositions(thirdPositions);

  vector<int> fourthPositions = v.getPositions();
  fourthPositions[pos0] = fourthPositions[pos0 - 4];
  fourthPositions[pos0 - 4] = 0;
  fourthChild.setPositions(fourthPositions);

  K.push_back(firstChild);
  K.push_back(secondChild);
  K.push_back(thirdChild);
  K.push_back(fourthChild);
  push_heap(K.begin(), K.end(), compare);
  return K;
}

bool belongsToAOrF(State m, vector<State> A, vector<State> F)
{
  for (long unsigned int i = 0; i < A.size(); i++)
  {
    if (m.getPositions() == A[i].getPositions())
      return true;
  }

  for (long unsigned int i = 0; i < F.size(); i++)
  {
    if (m.getPositions() == F[i].getPositions())
      return true;
  }
  return false;
}


int getManhattanDistance(int num, int index)
{
  vector<int> originalPositions = {
      15,
      0, 4, 8, 12,
      1, 5, 9, 13,
      2, 6, 10, 14,
      3, 7, 11};

  return abs(index - originalPositions[num]);
}

int h1(vector<int> final, vector<int> current)
{
  int sumOfPartsOutPlace = 0;
  for (long unsigned int i = 0; i < final.size(); i++)
  {
    if (final[i] != 0 && final[i] != current[i])
    {
      sumOfPartsOutPlace += 1;
    }
  }
  return sumOfPartsOutPlace;
}

int h2(vector<int> current)
{
  int sum = 0;
  for (long unsigned int i = 1; i < current.size(); i++)
  {
    if (current[i] - 1 != current[i - 1] && current[i] != 0)
    {
      sum++;
    }
  }
  return sum;
}

int h3(vector<int> final, vector<int> current)
{
  int sum = 0;
  for (long unsigned int i = 0; i < current.size(); i++)
  {
    if (current[i] != 0 && current[i] != final[i])
    {
      sum += getManhattanDistance(current[i], i);
    }
  }

  return sum;
}

int h5(vector<int> final, vector<int> current)
{
  int first = h1(final, current);
  int second = h2(current);
  int third = h1(final, current); 

  int maior = first;

  if(second > maior)
    maior = second;

  if(third > maior)
    maior = third;

  return maior;
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

vector<int> T = { 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15, 4, 8, 12, 0};

void init(vector<State> &A, State &S)
{
  S.setG(0);
  // S.setH(h1(T, S.getPositions()));
  // S.setH(h2(S.getPositions()));
  S.setH(h3(T, S.getPositions()));
  S.setH(h5(T, S.getPositions()));
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

    for (long unsigned int i = 0; i < K.size(); i++)
    {
      K[i].setG(v.getG() + 1);
      State m = K[i];

      int indexA = -1;
      for (long unsigned int j = 0; j < A.size(); j++)
      {
        if (A[j].getPositions() == m.getPositions() &&
            m.getG() < A[j].getG())
        {
          indexA = j;
        }
      }

      if (indexA != -1)
      {
        A.erase(A.begin() + indexA);
        pop_heap(A.begin(), A.end(), compare);
      }

      if (!belongsToAOrF(m, A, F))
      {
        // m.setH(h1(T, m.getPositions()));
        // m.setH(h2(m.getPositions()));
        // m.setH(h3(T, m.getPositions()));
        m.setH(h5(T, m.getPositions()));
        A.push_back(m);
        push_heap(A.begin(), A.end(), compare);
      }
    }
  }

  cout << v.getG() << endl;
  return 0;
}
