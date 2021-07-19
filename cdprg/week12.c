// 12.Generate the Three Address Code for a Given Expression

#include<stdio.h>
#include<string.h>

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

void pm();
void plus();
void div();
int i,ch,j,l,addr=100;
char ex[10], ex1[10] ,exp1[10],exp3[10],id1[5],op[5], id2[5];

int main()
{
    while(1)
    {
        printf("\n1.Assignment\n2.Arithmetic\n3.Relational\n4.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter the expression with assignment operator:");
                scanf("%s",ex1);
                l=strlen(ex1);
                exp3[0]='\0';
                i=0;
                while(ex1[i]!='=')
                {
                    i++;
                }
                strncat(exp3,ex1,i);
                strrev(ex1);
                exp1[0]='\0';
                strncat(exp1,ex1,l-(i+1));
                strrev(exp1);
                printf("Three address code:\ntemp=%s\n%s=temp\n",exp1,exp3);
                break;

            case 2:
                printf("\nEnter the expression with arithmetic operator:");
                scanf("%s",ex);
                strcpy(ex1,ex);
                l=strlen(ex1);
                exp1[0]='\0';

                for(i=0;i<l;i++)
                {
                    if(ex1[i]=='+'||ex1[i]=='-')
                    {
                        if(ex1[i+2]=='/'||ex1[i+2]=='*')
                        {
                            pm();
                            break;
                        }
                        else
                        {
                            plus();
                            break;
                        }
                    }
                    else if(ex1[i]=='/'||ex1[i]=='*')
                    {
                        div();
                        break;
                    }
                }
                break;

            case 3:
                printf("Enter the expression with relational operator:");
                scanf("%s%s%s",id1,op,id2);
                if(((strcmp(op,"<")==0)||(strcmp(op,">")==0)||(strcmp(op,"<=")==0)||(strcmp(op,">=")==0)||(strcmp(op,"==")==0)||(strcmp(op,"!=")==0))==0)
                    printf("Error in expression");
                else
                {
                    printf("\n%d\tif %s%s%s goto %d",addr,id1,op,id2,addr+3);
                    addr++;
                    printf("\n%d\t T:=0",addr);
                    addr++;
                    printf("\n%d\t goto %d",addr,addr+2);
                    addr++;
                    printf("\n%d\t T:=1",addr);
                }
                break;

            case 4:
                break;
        }
    }
    return 0;
}

void pm()
{
    strrev(ex1);
    j=l-i-1;
    strncat(exp1,ex1,j);
    strrev(exp1);
    printf("Three address code:\ntemp=%s\ntemp1=%c%ctemp\n",exp1,ex1[j+1],ex1[j]);
}
    
void div()
{
    strncat(exp1,ex1,i+2);
    printf("Three address code:\ntemp=%s\ntemp1=temp%c%c\n",exp1,ex1[i+2],ex1[i+3]);
}


void plus()
{
    strncat(exp1,ex1,i+2);
    printf("Three address code:\ntemp=%s\ntemp1=temp%c%c\n",exp1,ex1[i+2],ex1[i+3]);
}

