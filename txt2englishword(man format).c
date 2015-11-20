#include<stdio.h>
#include<string.h>
#include<ctype.h>
void Text2Word(char*iname,char*oname)
{
    FILE*input,*output;
    char fch,ch;
     input=fopen(iname,"r");
    output=fopen(oname,"a");
    int sletter;
   int count=0;
while((fch=fgetc(input))!=EOF)
 {

    if(fch>='a'&&fch<='z'||fch>='A'&&fch<='Z')
    {
         sletter=1;
        while((ch=fgetc(input))!=EOF&&ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')
         {
             if(sletter)
             {
                 fputc(tolower(fch),output);sletter=0;
             }
             fputc(tolower(ch),output);
         }
     if(!sletter)
     {
           fputc(',',output);
           if(++count%10==0)
            fputc('\n',output);
     }

    }
 }
}
int main(int argc,char *argv[])
{
Text2Word(argv[1],argv[2]);
}
