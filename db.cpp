//x for single or double player...
//count for no of wrong guesses...
//g for entering guesses....
//f is for breaking the loop if player wins...
//flag is for checking the entered choice is wrong or not...
//k is the length of word entered by the player...
//p is for score of players...
#include<iostream>
#include<fstream>
#include<math.h>
#include<cstdlib>
#include<string.h>
#include<time.h>
#include<conio.h>
#include <vector>
using namespace std;
int main (void)
{
    char ab[20],ch;
    int b=0;
string str,name1,name2;
int s,i,k=0,count=5,flag=0,p,p1,p2,f,z,t,x,o;
char g,a,choice;

pk:cout<<"WELCOME TO HANGMAN \n";
cout<<"\n1.Play Game.\n";
cout<<"2.Help.\n";
cout<<"3.Exit.\n";
cin>>o;

if(o==1)
goto pk1;

else if(o==2)
{
    system("cls");
    cout<<"\nYou have to guess the word. Enter your guess one by one. You have been given 5 chances.\n";
    cout<<"\n\nPress 1 to go back.\n";
    cin>>o;
    system("cls");
    if (o==1)
        goto pk;

}
else if(o==3)
    exit(0);
else
{
    cout<<"\nError..\n";
    system("pause");
    system("cls");
    goto pk;
}

pk1:cout<<"Press 1 for single player or 2 for double player \n";
cin>>x;
if(x==1)
{
    //string words[5]={"apple","orange","guava","banana","mango"};
    cout<<"enter your name \n";
    cin>>name1;
//srand(time(NULL));
//s=rand()%5;
//str=words[s];
vector<string> words;
      ifstream file("afile.txt");
      string line,str;
      while (getline(file, line)) words.push_back(line);
       srand(time(NULL));
       str=words[rand() % words.size()];



int z=0;

    k=str.length();
    char ans[k];
    for(i=0;i<k;i++)        //For initializing an array to blank spaces....
    {
        ans[i]='_';
    }
    system("cls");
    cout<<name1<<" your word is :"<<endl;
    //hcout<<str<<endl;
     for(i=0;i<k;i++)       //For displaying an array of blank spaces....
    {
        cout<<" "<<ans[i];
    }
    while(count!=0)
    {
    flag=0;
    int f=0;
     cout<<endl<<"Enter your guess\n";
        g=getche();
        cout<<endl;
        system("cls");
    for(i=0;i<k;i++)        //checking the entered word is correct or not...
    {
        if(g==str[i])
        {
           ans[i]=g;
           flag=1;
        }

    }

    if(flag==0)
    {
      cout<<"sorry wrong guess..!\a\n";
        count--;

        if(count!=0)
        cout<<"You have "<<count<<" chances left.\n";
    }
     for(i=0;i<k;i++)       //display word after guess is entered...
    {
        cout<<" "<<ans[i];
    }

    for(i=0;i<k;i++)        //check whether there is any blank is left?...
    {
        if(ans[i]=='_')
            f=1;
    }
    if(f==0)
    {
        count=0;
        z=1;
        cout<<endl<<"CONGO ..... right guess";
    }
   }                        //while loop ends...

   if(z!=1)
   {
       system("cls");
    cout<<endl<<"SORRY..... game over";
    cout<<"\nThe word was: "<<str;
   }

}


else if(x==2)
{
 cout<<"Player 1 enter name\n";
        cin>>name1;
        cout<<"Player 2 enter name\n";
        cin>>name2;
do
{   system("cls");
            for(t=0;t<2;t++)        //for loop to give chance to both players...
            {
                if(t==0)            //condition for first player...
                {
                    cout<<name1<<" enter a word \n";
                    //cin>>str;

                    xy:ch=getche();
                     while(ch!=13)
                     {
                      str[b]=ch;
                    system("cls");
                      for(int j=0;j<=b;j++)
                        cout<<"*";
                        b++;
                     goto xy;
                     }
                     k=b;
                }

                else        //condition for second player...
                {
                    int h=0;
                    system("cls");
                    cout<<name2<<" enter a word \n";
                    //cin>>str;
                    ab:ch=getche();
                     while(ch!=13)
                     {
                      str[h]=ch;
                    system("cls");
                      for(int j=0;j<=h;j++)
                        cout<<"*";
                        h++;
                     goto ab;
                     }
                     k=h;
                }

z=0;
count=5;
p=500;
    //k=str.length();
     char ans[k];
    for(i=0;i<k;i++)
    {
        ans[i]='_';
    }
      //  cout<<"your word is :"<<endl;
    //cout<<str<<endl;
     for(i=0;i<k;i++)
    {
        cout<<" "<<ans[i];
    }
    while(count!=0)
    {
    flag=0;
     f=0;
     if(t==0)
     cout<<endl<<name2<<" Enter your guess\n";
     else
     cout<<endl<<name1<<" Enter your guess\n";
        g=getche();
        cout<<endl;
        system("cls");
    for(i=0;i<k;i++)
    {
        if(g==str[i])
        {
           ans[i]=g;
           flag=1;
        }
    }
    if(flag==0)
    {
        cout<<"\nSorry wrong guess..!\n\a";
        count--;
        p=p-100;

        if(count!=0)
        cout<<"You have "<<count<<" chances left.\n";
    }
     for(i=0;i<k;i++)
    {
        cout<<" "<<ans[i];
    }
    for(i=0;i<k;i++)
    {
        if(ans[i]=='_')
            f=1;
    }
    if(f==0)
    {
        count=0;
        z=1;
        cout<<endl<<"Congo ..... right guess";
    }
   }        //while loop ends...
   if(z!=1)
   {
    cout<<endl<<"Sorry..... turn over";
   }

   cout<<endl<<"You scored: "<<p<<endl;
   system("pause");
   if(t==0)
    p2=p;
   else
    p1=p;
}       //for loop ends...


    if(p1>p2 && p1>0 && p2>0)
        cout<<endl<<name1<<" Won ";
    else if(p1==p2 && p1>0 && p2>0)
        cout<<endl<<"Its a tie ";
    else if(p1==0 && p2==0)
        cout<<endl<<"Both lost ";
    else
        cout<<endl<<name2<<" Won";

         cout<<"\n Press y to play again and e to exit\n";
       cin>>choice;
    }
    while(choice=='y');

}
else
    cout<<"\nNot a valid choice";
    getch();
return 0;
}
