#include<iostream>
#include<cstring>
using namespace std;

int main() {
    char FirstName[] = {'E','s','m','e',' '};
    char LastName[] = {'A','b','h','a'};
    int FullLength = strlen(FirstName) + strlen(LastName) + 1;
    char Fullname[FullLength];
    strcpy(Fullname, FirstName);
    strcat(Fullname, LastName);
    cout << Fullname << endl;

    return 0;
}
