#include "state.h"
#include "utils.h"
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace A;

bool Utils::compare(State a1, State a2)
{
  return a1.getF() < a2.getF();
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

    firstChild.getPositions()[pos0] = v.getPositions()[pos0 + 1];
    firstChild.getPositions()[pos0 + 1] = 0;
    firstChild.setG(v.getG() + 1);

    secondChild.getPositions()[pos0] = v.getPositions()[pos0 + 4];
    secondChild.getPositions()[pos0 + 4] = 0;
    secondChild.setG(v.getG() + 1);

    K.push_back(firstChild);
    K.push_back(secondChild);
    push_heap(K.begin(), K.end(), Utils::compare);
    return K;
  }

  if (pos0 == 3)
  {
    State firstChild = v, secondChild = v;

    firstChild.getPositions()[pos0] = v.getPositions()[pos0 - 1];
    firstChild.getPositions()[pos0 - 1] = 0;
    firstChild.setG(v.getG() + 1);

    secondChild.getPositions()[pos0] = v.getPositions()[pos0 + 4];
    secondChild.getPositions()[pos0 + 4] = 0;
    secondChild.setG(v.getG() + 1);

    K.push_back(firstChild);
    K.push_back(secondChild);
    push_heap(K.begin(), K.end(), Utils::compare);
    return K;
  }

  if (pos0 == 12)
  {
    State firstChild = v, secondChild = v;

    firstChild.getPositions()[pos0] = v.getPositions()[pos0 + 1];
    firstChild.getPositions()[pos0 + 1] = 0;
    firstChild.setG(v.getG() + 1);

    secondChild.getPositions()[pos0] = v.getPositions()[pos0 - 4];
    secondChild.getPositions()[pos0 - 4] = 0;
    secondChild.setG(v.getG() + 1);

    K.push_back(firstChild);
    K.push_back(secondChild);
    push_heap(K.begin(), K.end(), Utils::compare);
    return K;
  }

  //Laterais sem os cantos
  if (pos0 == 1 || pos0 == 2)
  {

    State firstChild = v, secondChild = v, thirdChild = v;

    firstChild.getPositions()[pos0] = v.getPositions()[pos0 - 1];
    firstChild.getPositions()[pos0 - 1] = 0;
    firstChild.setG(v.getG() + 1);

    secondChild.getPositions()[pos0] = v.getPositions()[pos0 + 1];
    secondChild.getPositions()[pos0 + 1] = 0;
    secondChild.setG(v.getG() + 1);

    thirdChild.getPositions()[pos0] = v.getPositions()[pos0 + 4];
    thirdChild.getPositions()[pos0 + 4] = 0;
    thirdChild.setG(v.getG() + 1);

    K.push_back(firstChild);
    K.push_back(secondChild);
    K.push_back(thirdChild);
    push_heap(K.begin(), K.end(), Utils::compare);
    return K;
  }

  if (pos0 == 4 || pos0 == 8)
  {
    State firstChild = v, secondChild = v, thirdChild = v;

    firstChild.getPositions()[pos0] = v.getPositions()[pos0 + 1];
    firstChild.getPositions()[pos0 + 1] = 0;
    firstChild.setG(v.getG() + 1);

    secondChild.getPositions()[pos0] = v.getPositions()[pos0 - 4];
    secondChild.getPositions()[pos0 - 4] = 0;
    secondChild.setG(v.getG() + 1);

    thirdChild.getPositions()[pos0] = v.getPositions()[pos0 + 4];
    thirdChild.getPositions()[pos0 + 4] = 0;
    thirdChild.setG(v.getG() + 1);

    K.push_back(firstChild);
    K.push_back(secondChild);
    K.push_back(thirdChild);
    push_heap(K.begin(), K.end(), Utils::compare);
    return K;
  }

  if (pos0 == 7 || pos0 == 11)
  {
    State firstChild = v, secondChild = v, thirdChild = v;

    firstChild.getPositions()[pos0] = v.getPositions()[pos0 - 1];
    firstChild.getPositions()[pos0 - 1] = 0;
    firstChild.setG(v.getG() + 1);

    secondChild.getPositions()[pos0] = v.getPositions()[pos0 - 4];
    secondChild.getPositions()[pos0 - 4] = 0;
    secondChild.setG(v.getG() + 1);

    thirdChild.getPositions()[pos0] = v.getPositions()[pos0 + 4];
    thirdChild.getPositions()[pos0 + 4] = 0;
    thirdChild.setG(v.getG() + 1);

    K.push_back(firstChild);
    K.push_back(secondChild);
    K.push_back(thirdChild);
    push_heap(K.begin(), K.end(), Utils::compare);
    return K;
  }

  if (pos0 == 13 || pos0 == 14)
  {
    State firstChild = v, secondChild = v, thirdChild = v;

    firstChild.getPositions()[pos0] = v.getPositions()[pos0 + 1];
    firstChild.getPositions()[pos0 + 1] = 0;
    firstChild.setG(v.getG() + 1);

    secondChild.getPositions()[pos0] = v.getPositions()[pos0 - 1];
    secondChild.getPositions()[pos0 - 1] = 0;
    secondChild.setG(v.getG() + 1);

    thirdChild.getPositions()[pos0] = v.getPositions()[pos0 - 4];
    thirdChild.getPositions()[pos0 - 4] = 0;
    thirdChild.setG(v.getG() + 1);

    K.push_back(firstChild);
    K.push_back(secondChild);
    K.push_back(thirdChild);
    push_heap(K.begin(), K.end(), Utils::compare);
    return K;
  }

  //Centro
  State firstChild = v, secondChild = v, thirdChild = v, fourthChild = v;

  firstChild.getPositions()[pos0] = v.getPositions()[pos0 + 1];
  firstChild.getPositions()[pos0 + 1] = 0;
  firstChild.setG(v.getG() + 1);

  secondChild.getPositions()[pos0] = v.getPositions()[pos0 - 1];
  secondChild.getPositions()[pos0 - 1] = 0;
  secondChild.setG(v.getG() + 1);

  thirdChild.getPositions()[pos0] = v.getPositions()[pos0 - 4];
  thirdChild.getPositions()[pos0 - 4] = 0;
  thirdChild.setG(v.getG() + 1);

  fourthChild.getPositions()[pos0] = v.getPositions()[pos0 + 4];
  fourthChild.getPositions()[pos0 + 4] = 0;
  fourthChild.setG(v.getG() + 1);

  K.push_back(firstChild);
  K.push_back(secondChild);
  K.push_back(thirdChild);
  K.push_back(fourthChild);
  push_heap(K.begin(), K.end(), Utils::compare);
  return K;
}
