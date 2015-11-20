#include<stdio.h>
#include<string.h>
char wordcap[10000][50];
void SortFile(char *iname,char*oname)
{
    FILE*input,*output;
    char word[50];
    int count=0,i,j;
    input=fopen(iname,"r");
    output=fopen(oname,"a");
   while( fscanf(input,"%[a-z],",word)!=EOF)
    {
        for(i=0;i<count;i++)
            if(strcmp(word,wordcap[i])<0)
            {
                for(j=count;j>=i;j--)
                    strcpy(wordcap[j+1],wordcap[j]);
                strcpy(wordcap[i],word);
                count++;
                break;
            }

        if(count==0||i==count&&strcmp(word,wordcap[count-1])>0 )//&&strcmp(word,wordcap[count-1])>0  if use sort twice,then unique;
           strcpy(wordcap[count++],word);
    }
    for(i=1;i<=count;i++)
    {
         fprintf(output,"%s,",wordcap[i-1]);
          if(i%10==0) fprintf(output,"\n");
    }


}
int main(int argc,char *argv[])
{
SortFile(argv[1],argv[2]);
}
