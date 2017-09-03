#include<iostream>
#include<windows.h>
using namespace std;

int main(){

int a[10],t=9,game=0,b;char c[10],d[2];

d[1]='o';d[0]='x';

for(int q=1;q<=9;q++)a[q]=0;

while(game==0 && t>=0){



for(int temp=1;temp<=7;temp=temp+3)
if(a[temp]==a[temp+1] && a[temp+1]==a[temp+2] && a[temp]!=0)game=a[temp];

for(int temp=1;temp<=3;temp++)
if(a[temp]==a[temp+3] && a[temp+3]==a[temp+6] && a[temp]!=0)game=a[temp];

if(a[1]==a[5] && a[5]==a[9] || a[3]==a[5] && a[5]==a[7])game=a[5];

t--;





system("cls");



for(int j=1;j<=3;j++){

        cout<<"\t\t    ";

    for(int i=1;i<=3;i++){

        if(a[(j-1)*3+i]==0)cout<<(j-1)*3+i;
        else cout<<c[(j-1)*3+i];
        if(i<3)cout<<" | ";
    }
    cout<<"\n";

    if(j<3)cout<<"\t\t   ---+---+---\n";
}


if(game!=0 || t%2+1==0)break;


cout<<"\nplayer "<<t%2+1<<" enter your position: ";

cin>>b;
c[b]=d[t%2];
a[b]=t%2+1;

}


if(game==1)cout<<"\nplayer 1 wins";
else if(game==2)cout<<"\nplayer 2 wins";
else cout<<"Game Tied!!";
}





