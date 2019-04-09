#include <iostream>
#include <vector>
#include <algorithm>
//using namespace std;
bool checkPrime(int n);
void print(int elem);

void main()
{
    int value;
    std::vector<int> primeVec;
    std::cout<<"Enter number: ";
    std::cin>>value;
    for(int i = 2;i<=value;i++)
    {
        if(checkPrime(i))
        {
            primeVec.push_back(i);
        }
    }
    std::cout<<"Prime Numbers: ";
    for_each(primeVec.begin(),primeVec.end(),print);
}
bool checkPrime(int n)
{
    for(int i = 2;i<=n/2;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
void print (int elem)
{
    std::cout << elem << ' ';
}
