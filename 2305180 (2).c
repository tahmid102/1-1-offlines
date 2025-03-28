#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

char a_1[]="listen";
char a_2[]="binary";
char a_3[]="earth";
char b_1[]="stilen";
char b_2[]="narybi";
char b_3[]="herta";

char p_1[]="there is a secret code";
char p_2[]="attack at dawn";
char p_3[]="meet me at the park";


char word1[]="program";
char word2[]="network";
char word3[]="science";

char hint1[]="pro";
char hint2[]="net";
char hint3[]="sci";

int score=0;
int success=0;

int show_menu();
int len(char a[]);
void strCpy(char a[],char b[]);
int equal(char t[],char v[]);
void decrypt(char a[], int n);
void encrypt(char a[], int n);
int substr(char a[], char b[]);
void anargram();
void cypher();
void wordgame();
int scorefunc(int a);




int main()
{
   //menu
   if(show_menu()==2)return 1;

   //game01
    printf("Starting Anargram Challenge...\n");
    Sleep(500);
    printf("Scrambled word: ");
    anargram();

    //end of game 01

    //game 02
    
    printf("Starting Caesar Cipher Challenge...\n");
    Sleep(500);
    cypher();

    //end of game02

    //game 03
    printf("Starting word guess challenge\n");
    Sleep(500);
    wordgame();
    
    //bonus
    if(success==3)
    {
        score+=5;
    }


    printf("\nGAME OVER!!\n");
    printf("Your total score: %d points",score);
    
}




int show_menu()
{
 printf("Welcome to the Game World!\n");
    printf("1. Start Game\n2.Exit\n");
    printf("Enter your choice");
    int choice;
    scanf("%d",&choice);
    return choice;
}
int len(char a[])
{
    for(int i=0;1;i++)
    {
        if(a[i]=='\0')
        return i;
    }
}
int equal(char t[],char v[]){
   
    int c=1;
    for(int i=0;t[i]!='\0' && v[i]!='\0';i++)
    {
        if(t[i]==v[i])
        {
            continue;

        }
        else {
            c=0;
            break;
        }
    }
    if(len(t)!=len(v)) c=0;
    if(c)return 1;
    else return 0;
}
void strCpy(char a[],char b[])
{
    for(int i=0;i<=len(b);i++)
    {
        a[i]=b[i];
    }
    a[len(b)]='\0';
}
int scorefunc(int a)
{
    
    score+=(2-a)*10;
    if(a<=2) score+=10; 
}
void encrypt(char a[], int n)
{
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]>=97 && a[i]<=122)
        {
            a[i] = 'a' + (a[i] - 'a' + n) % 26;
        }
    }
    return;
}
void decrypt(char a[], int n)
{
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]>=97 && a[i]<=122)
        {
            a[i] = 'a' + (a[i] - 'a' - n + 26) % 26;
        }
    }
    return;

}
int substr(char a[], char b[])
{
    for(int i=0;i<=len(b)-len(a);i++)
    {
        int j;
        for( j=0;j<len(a);j++)
        {
            if(a[j]!=b[i+j]) break;
        }
        if(j==len(a))
        {
            return 1;
        }
    }
    return 0;
}

void anargram()
{
    
    int argm;
    srand(time(0));
    int ub=3,lb=1;
    argm=rand()%(ub-lb+1)+lb;
    char original[100],scrambled[100];
    if(argm==1)
    {
        strCpy(original,a_1);
        strCpy(scrambled,b_1);
    }
     if(argm==2)
    {
        strCpy(original,a_2);
        strCpy(scrambled,b_2);
    }
     if(argm==3)
    {
        strCpy(original,a_3);
        strCpy(scrambled,b_3);
    }
    puts(scrambled);
    int i;
    for(i=0;i<3;i++)
    {
        printf("Your Guess :");
        char input[100];
        scanf("%s",input);
        if(equal(original,input))
        {
            printf("Correct! You solved it in %d attempts\n",i+1);
            success++;
            scorefunc(i);
            break;
        }
        else printf("Incorrect! Try again\n");
    }
    
}
void cypher(){
    char phrase[100];

    int ccc=rand()%(3-1+1)+1;
    if(ccc==1) strCpy(phrase,p_1);
    if(ccc==2) strCpy(phrase,p_2);
    if(ccc==3) strCpy(phrase,p_3);
    encrypt(phrase,3);
    puts(phrase);
    decrypt(phrase,3);
   
    int j;
    for(j=0;j<3;j++)
    {
        printf("Your Guess :");
        char ges[100];
        getchar();
        scanf("%[^\n]s",ges);
    if(equal(phrase,ges))
    { 
        printf("Correct answer in attempt %d\n",j+1);
        success++;
        scorefunc(j);
        break;
    }
    else printf("Incorrect! Try again\n");
    }
    
}


void wordgame()
{
    int ranword=rand()%(3-1+1)+1;
    char word[100],hint[100];
    if(ranword==1)
    {
        strCpy(word,word1);
        strCpy(hint,hint1);
    }
    if(ranword==2)
    {
        strCpy(word,word2);
        strCpy(hint,hint2);
    }
    if(ranword==3)
    {
        strCpy(word,word3);
        strCpy(hint,hint3);
    }
    printf("Hint : %s \n",hint);

    
    printf("Select an option: 1. Write Answer 2. Check Substring 3. Check Length\n");
    
    int n;

    int m=0;
    for(n=0;n<3 && m==0;n++)
    {
    int x1=0,x2=0,x3=0;
    for(int k=0;1;)
    {
    int option;
    scanf("%d",&option);
    
    if(option==1)
    {
    {
        if(x1>0) {
            printf("Error: Utility function already used.\n");
            continue;
        }
        printf("Enter your guess: ");
        x1++;
        k++;
    }
    char guess[100];
    scanf("%s",guess);
    if(equal(guess,word))
    {
        printf("Correct answer in attemp %d",n+1);
        success++;
        scorefunc(n);
        m++;
        break;

    }
    else printf("No");
    k++;
    score+=-2;
    }

    else if(option==3)
    {
         if(x2>0) {
            printf("Error: Utility function already used.\n");
            continue;
        }
        
        printf("Enter Length: ");
        int length;
        scanf("%d",&length);
        if(len(word)==length)
        {
            printf("Yes\n");
        }
        else printf("No\n");
        printf("Select another option ");
        k++;
        x2++;
        score+=-2;
    }
    else if(option==2)
    {
        if(x3>0) {
            printf("Error: Utility function already used.\n");
            continue;
        }
        printf("Enter substring:");
        char sub[100];
        scanf("%s",sub);
        if(substr(sub,word)) printf("Yes\n");
        else printf("No\n");
        printf("Select another option ");
        x3++;
        k++;
        score+=-2;
    }
     if(k>=3) {
        printf("Next attempt\n");
        break;
     }
    }
    }

}