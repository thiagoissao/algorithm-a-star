#ifndef STATE_H
#define STATE_H
#include <vector>

using namespace std;

namespace A
{
  class State
  {
  private:
    int h;
    int g;
    int node;
    vector<int> positions;

  public:
    void setH(int h);
    void setG(int g);
    void setNode(int node);
    void setPositions(vector<int> p);

    int getH();
    int getG();
    int getF();
    int getNode();
    vector<int> getPositions();
    };
}
#endif
