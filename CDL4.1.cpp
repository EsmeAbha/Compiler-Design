#include<iostream>
using namespace std;


bool isIdentifier(string input)
{
    bool identifier=true;
    for(int a=0;a<input.length();a++)
    {
        if(input[a]=='!'||input[a]=='@'||input[a]=='#'||input[a]=='$'||input[a]=='%'||input[a]=='^'||input[a]=='&'||input[a]=='*'||input[a]=='+'||input[a]=='='||input[a]=='-'||input[a]=='/'||input[a]=='<'||input[a]=='>'||input[a]=='?')
           {
               identifier=false;
           }
    }
    return identifier;

}

int main()
{
    string i;
    cin>>i;
    if(isIdentifier(i)==true)
    {
        cout<<"Valid Variable Name";
    }
    else
    {
        cout<<"Invalid Variable Name";
    }

}


