#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void reversewords( char *s , char *t)
{
    int ls=strlen(s);
    int word=1;

    for(int i=0;i<ls;i++)
    {
        *(t+i)=*(s+ls-1-i);
        if(*(s+i)==' ') word++; //counting word
    } //full sentence reversed * hello world-> dlrow olleh
    *(t + ls) = '\0'; 

    int z=0;
    for(int i=0;i<word;i++)
    {
        int letter=0;
        for(int j=z;*(t+j)!=' ' &&*(t+j)!='\0';j++)
        {
            letter++; //letter count for each word
        }
        for(int j=0;j<(letter/2);j++) 
        {
            char x=*(t+j+z); 
            *(t+j+z)=*(t+letter-j+z-1); //reversinf each word from ulta string 
            *(t+letter+z-j-1)=x;      
        }
        z=z+letter+1;
    }
    
    puts(t);
    
}

int main()
{
    char *s =(char*)malloc(100*sizeof(char));
    char *t =(char*)malloc(100*sizeof(char));
    gets(s);
    reversewords(s,t);
    free(s);
    free(t);
}