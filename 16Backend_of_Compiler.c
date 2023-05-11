#include<stdio.h>
#include<conio.h>
struct regis
{
char var;
}reg[10];
int noreg;
char st[10][10];
char *opcode[10]={"add","sub","mul","div","assign"};
char oper[10]={'+','-','*','/','='};
char *toopcode(char opert)
{
int i;
for(i=0;i<5;i++)
{
if(oper[i]==opert)
{
return(opcode[i]);
}}
return(0);
}
int isinregister(char var)
{
int i;
for(i=1;i<=noreg;i++)
{
if(var==reg[i].var)
{
return(i);
}}
return(0);
}
void main()
{
int i,regno2=0,regno1=1,nost;
//clrscr();
printf("\nCODE GENERATION");
printf("\n");
printf("Enter the no of statements:");
scanf("%d",&nost);
printf("Enter the statements:");
printf("\n");
for(i=0;i<nost;i++)
{
scanf("%s",st[i]);
}
printf("\n\tStatements\tTarget code");
for(i=0;i<nost;i++)
{
printf("\n\n\t%s",st[i]);
if(!regno1==isinregister(st[i][2]))
{
printf("\n\t\t\t mov %c,R%d",st[i][2],++noreg);
reg[noreg].var=st[i][2];
regno1=noreg;
}
if(regno2!=isinregister(st[i][4]))
{
printf("\n\t\t\t%s R%d,R%d",toopcode(st[i][3]),regno2,regno1);
reg[regno1].var=st[i][0];
}
else
{
printf("\n\t\t\t%s %c,R%d",toopcode(st[i][3]),st[i][4],regno1);
reg[regno1].var=st[i][0];
}
if(i==nost-1)
{
printf("\n\t\t\t mov R%d,%c",regno1,st[i][0]);
}}
getch();
}
