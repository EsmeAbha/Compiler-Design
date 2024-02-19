#include<iostream>
using namespace std;

int main() {
    int sizeA=7;
    float arr[sizeA]={5.0,4.2,7.3,2.8,1.1,3.4,9.7};

    float mini= arr[0];
    float maxi= arr[0];

    for (int i=0; i<sizeA; i++) {
        if (arr[i]<mini) {
            mini = arr[i];
        }
        if(arr[i]>maxi){
            maxi=arr[i];
        }

    }

    cout<<"The minimum value of this array is "<<mini<<endl;
    cout<<"The maximum value of this array is "<<maxi<<endl;
    return 0;
}
