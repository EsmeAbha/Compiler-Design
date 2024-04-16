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

           if(input[0]=='1'||input[0]=='2'||input[0]=='3'||input[0]=='4'||input[0]=='5'||input[0]=='6'||input[0]=='2'||input[0]=='7'||input[0]=='8'||input[0]=='9'||input[0]=='0'||input[0]=='_')
           {
                identifier=true;

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



