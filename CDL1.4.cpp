#include<iostream>
using namespace std;

int main() {
    int f = 1;
    int value;

    cout << "Enter the value for factorial: " << endl;
    cin >> value;

    for (int a = value; a > 0; a--) {
        f *= a;
    }

    cout << "The value for factorial is: " << f << endl;

    return 0;
}
