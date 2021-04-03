#include "state.h"
#include "utils.h"
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace A;

void Utils::logTree(vector<State> tree, string treeName)
{
  cout << "Printing: " << treeName << endl;
  for (int i = 0; i < tree.size(); i++)
  {
    cout << "Node: " << i << " ";
    logPositions(tree[i].getPositions());
  }
  cout << endl;
}

void Utils::logPositions(vector<int> positions)
{
  cout << "POSITIONS: ";
  for (int i = 0; i < positions.size(); i++)
  {
    cout << positions[i] << " ";
  }
  cout << endl;
}

bool Utils::compare(State a1, State a2)
{
  return a1.getF() < a2.getF();
}

int Utils::findMinIndex(vector<State> tree, State &state)
{
  State min = tree[0];
  int index = 0;
  for (int i = 1; i < tree.size(); i++)
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
  for (int i = 0; i < node.getPositions().size(); i++)
  {
    if (node.getPositions()[i] == 0)
    {
      pos = i;
      break;
    }
  }
  return pos;
}

vector<State> Utils::calculateK(State v)
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
    push_heap(K.begin(), K.end(), Utils::compare);
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
    push_heap(K.begin(), K.end(), Utils::compare);
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
    push_heap(K.begin(), K.end(), Utils::compare);
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
    push_heap(K.begin(), K.end(), Utils::compare);
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
    push_heap(K.begin(), K.end(), Utils::compare);
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
    push_heap(K.begin(), K.end(), Utils::compare);
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
    push_heap(K.begin(), K.end(), Utils::compare);
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
    push_heap(K.begin(), K.end(), Utils::compare);
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
    push_heap(K.begin(), K.end(), Utils::compare);
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
  push_heap(K.begin(), K.end(), Utils::compare);
  return K;
}

bool Utils::belongsToAOrF(State m, vector<State> A, vector<State> F)
{
  for (int i = 0; i < A.size(); i++)
  {
    if (m.getPositions() == A[i].getPositions())
      return true;
  }

  for (int i = 0; i < F.size(); i++)
  {
    if (m.getPositions() == F[i].getPositions())
      return true;
  }
  return false;
}
