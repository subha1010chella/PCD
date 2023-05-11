#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int i=0,j,k=0,m=-1,flag,l,pos,len,stlen;
	char production[10][100], str[100],input[100],stack[100],start;
	printf("\nEnter the starting symbol:");
	scanf("%c",&start);
	printf("\nUse single small character for terminals\nUse = instead of ->\nUse # instead of epsilon");
	printf("\nDon't enter spaces in between\nEnter exit to stop\nEnter the production rule 1:");
	scanf("%s",str);
	while(strcmp(str,"exit")!=0)
	{
		strcpy(production[i],str);
		i++;
		printf("Enter the production rule %d:",i+1);
		scanf("%s",str);
	}
	int prlen=i;
	printf("\nEnter the input string:");
	scanf("%s",input);
	stlen=strlen(input);
	printf("\nStack\tI/P String\tActions");
	printf("\n$%s\t%s$",stack,input);
	printf("\tShift %c",input[k]);
	stack[++m]=input[k];
	input[k]=' ';
	k++;
	while(1)
	{
		printf("\n$%s\t%s$",stack,input);
		if((input[k]=='\0' && stack[m]==start) && m==0)	//Accept condition
		{
			printf("\tAccept");
			exit(0);
		}
		else
		{
			for(j=0;j<prlen;j++)
			{
				l=strlen(production[j])-1;
				len=l;
				flag=0;
				int t=m;
				while(l!=1)
				{
					if(t==-1)
					{
						flag=0;
						break;
					}
					else 
					{
						if(stack[t]==production[j][l])
						{
							flag=1;
							t--;
						}
						else
						{	
							flag=0;
							break;
						}
						l--;
						if(l==1)
						{
							if(flag==1)
							{
								pos=j;
								break;
							}
						}
					}
				}
				if(flag==1)
				{
					printf("\tReduce by %s",production[pos]);
					for(int n=0;n<len-2;n++)
					{
						stack[m--]=' ';
					}
					stack[m]=production[pos][0];
					stack[m+1]='\0';
					break;
				}
			}
			if(flag==0)
			{
				printf("\tShift %c",input[k]);
				stack[++m]=input[k];
				stack[m+1]='\0';
				input[k]=' ';
				k++;
			}	
		}
	}
	return 0;
}
	
