#include<bits/stdc++.h>
using namespace std;
void E();
void T();
void F();
void Eds();
void Tds();
 
char input[100];
int i,error;
 
int main()
{
    printf("\nTop Down parsing for the following grammar\n");
    printf("\nE->TE'\nE'->+TE'/@\nT->FT'\nT'->*FT'/@\nF->(E)/ID\nHere ID is a \n");
    cout<<"Enter the input string : ";
    cin>>input;
    E();
    if(i==strlen(input) && error==0)
    {
         printf("String is Accepted");
    }
    else{
        printf("String rejected");
    }
 
}
void E()
{
    T();
    Eds();
 
}
void T()
{
    F();
    Tds();
}
void Eds()
{
    if(input[i]=='+')
    {
        i++;
        T();
        Eds();
    }
}
void Tds()
{
    if(input[i]=='*')
    {
        i++;
        F();
        Tds();
    }
}
void F()
{
    if(input[i]=='a')
    {
        i++;
    }
    else if(input[i]=='(')
    {
        i++;
        E();
        if(input[i]==')')
        {
            i++;
        }
        else
        {
            error=1;
        }
    }
    else{
        error=1;
 
    }
}
