#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
using namespace std;


bool validPunctuator(char ch)
{
    if (ch==' '||ch==','||ch==';'||ch=='('||ch==')'||ch=='['||ch==']'||ch=='{'||ch=='}'||ch=='<<')
        {
            return true;
        }
    return false;
}


bool validOperator(char ch)
{
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='>'||ch=='<'||ch =='='||ch=='|'||ch=='&'||ch=='%')
    {
       return true;
    }
    return false;
}


bool validIdentifier(char* str)
{
    if (str[0]=='0'||str[0]=='1'||str[0]=='2'||str[0]=='3'||str[0]=='4'||str[0]=='5'||str[0]=='6'||str[0]=='7'||str[0]=='8'||str[0]=='9'||validPunctuator(str[0]))
        {
            return false;
        }
    int len=0;
    while(str[len] !='\0') {
        if (validPunctuator(str[len])||validOperator(str[len]))
            {
            return false;
        }
        len++;
    }
    return true;
}


bool validKeyword(char *str)
{
    const char* keywords[]={"if","else","while","do","break","continue","int","double","float","return","char","case","long","short","typedef","switch","unsigned",
                               "void","static","struct","sizeof","volatile","enum","const","union","extern","bool","#include","using","namespace","std","<iostream>","main"};
    int numKeywords=sizeof(keywords)/sizeof(keywords[0]);
    for (int i=0;i<numKeywords;i++)
        {
        if(strcmp(str, keywords[i])==0)
            return true;
    }
    return false;
}


bool validDigit(char* str){
    int i,len=strlen(str),numOfDecimal=0;
    if(len==0)
    {
        return false;
    }
    for (i=0;i<len;i++)
    {
        if(numOfDecimal>1 && str[i]=='.')
        {
            return false;
        }
        else if(numOfDecimal<=1)
        {
            numOfDecimal++;
        }
        if (str[i]=='0'||str[i]=='1'||str[i]=='2'||str[i]=='3'||str[i]=='4'||str[i]=='5'||str[i]=='6'||str[i]=='7'||str[i]=='8'||str[i]=='9')
            {
                return true;
            }
    }
    return false;
}


char* subString(char* originalStr,int l,int r)
{
    int i;

    char* str=(char*) malloc(sizeof(char)*(r-l+2));

    for (i=l;i<=r;i++)
    {
        str[i-l]=originalStr[i];
        str[r-l+1]='\0';
    }
    return str;
}


void parse(char* str)
 {
    int left=0,right=0;
    int len=strlen(str);
    while(right<=len) {
        if(!validPunctuator(str[right]))
            right++;
        if(validPunctuator(str[right])&&left==right)
            {
            if(validOperator(str[right])) {
                cout<<str[right] << "             ->Is a operator"<<endl;
            }
            right++;
            left=right;
        } else if(validPunctuator(str[right])&&left!=right||(right==len&&left!=right)) {
            char* sub=subString(str,left,right-1);
            if (validKeyword(sub)) {
                cout<<sub<< "            ->Is a keyword"<<endl;
            } else if(validDigit(sub)) {
                cout<<sub<< "             ->Is a digit"<<endl;
            } else if(validIdentifier(sub)) {
                cout<<sub<< "             ->Is an identifier"<<endl;
            } else {
                if(validOperator(sub[0])) {
                    cout<<sub<< "            ->Is a operator";
                }
                else if(validDigit(sub)) {
                    cout<<sub<< "             ->Is a digit";
                }
                else if(validPunctuator(sub[0])) {
                    cout<<"               ->Is a punctuator";
                }
                cout<<endl;
            }
            left=right;
        }
    }
}


int main() {
    ifstream MyReadFile("lex_input.txt");
    if(!MyReadFile.is_open())
        {
        cerr << "Failed to open the file." << endl;
        return 1;
    }
    string line;
    while(getline(MyReadFile, line))
     {
        char* str = new char[line.length() + 1];
        strcpy(str, line.c_str());
        parse(str);
        delete[] str;
    }
    MyReadFile.close();
    return 0;
}
