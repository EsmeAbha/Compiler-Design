#include <iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    string myText;
    ifstream MyReadFile("ReadFile.txt");

    while (getline(MyReadFile,myText))
    {
        cout<<myText;
    }
    MyReadFile.close();
}
