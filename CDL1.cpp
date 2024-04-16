#include<iostream>
using namespace std;

int main()
{
    int sizeA=7;
    float arr[sizeA]={5.0,4.2,7.3,2.8,1.1,3.4,9.7};
    float sum=0;
    for(int i=0;i<sizeA;i++)
    {
        sum+=arr[i];

    }
    float avg=sum/sizeA;
    cout<<"The average sum of the array is "<<avg;
}
