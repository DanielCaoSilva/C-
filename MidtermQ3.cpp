#include <iostream>
#include <array>

using namespace std;

class ArrayFloatNum
{
private:
    int sz;
    float array[1];
public:
    ArrayFloatNum(int n)
    {
        array[n];
        sz = n;
    }
    ~ArrayFloatNum()
    {
       delete []array;
    }
    void storeNum(float num,int pos)
    {
        array[pos]=num;
    }
    float getNum(int pos)
    {
        return array[pos];
    }
    float getHighest()
    {
        float temp = array[0];
        for(int i=0;i<sz;i++)
        {
            if(array[i]>temp)
            temp=array[i];
        }
        return temp;
    }
    float getLowest()
    {
        float temp = array[0];
        for(int i=0;i<sz;i++)
        {
            if(array[i]<temp)
            temp=array[i];
        }
        return temp;
    }
};

int main()
{
    ArrayFloatNum a(2);
    a.storeNum(1,0);
    a.storeNum(-2,1);
    cout<<a.getNum(1);
    cout<<a.getHighest();
    cout<<a.getLowest();

    return 0;
}
