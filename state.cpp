#include "state.h"
#include <vector>
#include <iostream>

using namespace std;
using namespace A;

void State::setH(int h)
{
  this->h = h;
}

void State::setG(int g)
{
  this->g = g;
}

void State::setNode(int node)
{
  this->node = node;
}

int State::getH()
{
  return this->h;
}

int State::getG()
{
  return this->g;
}

int State::getF()
{
  return this->h + this->g;
}

int State::getNode()
{
  return this->node;
}
