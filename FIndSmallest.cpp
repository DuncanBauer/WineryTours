
#include <vector>
#include "Winery.h"
using namespace std;

int FindClosest(vector<float> myV, int& wineryNum)
{
    float smallest =0;
    smallest = myV[0];
    for(unsigned int index=1;index<myV.size();index++)
    {
        if(smallest>myV[index]&&myV[index]!=0.0)
        {
            smallest = myV[index];
            wineryNum =index+1;
        }
    }
    return smallest;
}

void ResetAll(vector<Winery> wineryVector)
{
    for(unsigned int index = 0; index < wineryVector.size(); index++)
    {
        wineryVector.operator [](index).setVisitable(true);
    }
}
