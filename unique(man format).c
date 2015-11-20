#include<stdio.h>
#include<string.h>
char wordcap[10000][50];
void UniqueFile(char*iname,char*oname)
{
    FILE*input,*output;
    int i,j,count=0;
    char word[50];
    input=fopen(iname,"r");
    output=fopen(oname,"a");
    while(fscanf(input,"%[a-z],",word)!=EOF)
    {
        for(i=0;i<count;i++)
        {
            if(strcmp(word,wordcap[i])==0)
            break;
            else if(strcmp(word,wordcap[i])<0)
            {
                for(j=count;j>=i;j--)
                    strcpy(wordcap[j+1],wordcap[j]);
                strcpy(wordcap[i],word);
                count++;
                break;
            }

        }
          if(i==count)
            strcpy(wordcap[count++],word);
    }
    for(i=1;i<=count;i++)
    {
        fprintf(output,"%s,",wordcap[i-1]);
        if(i%10==0)
        fprintf(output,"\n");
    }

}
int main(int argc,char*argv[])
{
UniqueFile(argv[1],argv[2]);
}
