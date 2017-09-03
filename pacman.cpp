#include<iostream>
#include<time.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<cstdlib>
using namespace std;

int main(){

    srand(time(NULL));


   int game=1,xmax=17,ymax=17,xp=(xmax+1)/2,yp=(ymax+1)/2,xpp,ypp,score=0,n=5,xm[20],ym[20],temp,temp2=rand()%4,anti=4,advantage=0,xa[10],ya[10],advremain[10];

    char c[20][20],ctemp[20];

    string direction,md[20];

for(int i=1;i<=anti;i++)advremain[i]=0;


for(int i=1;i<=ymax;i++){

    for(int j=1;j<=xmax;j++){

    c[j][i]='.';

    }

}


for(int i=1;i<=anti;i++){

    xa[i]=rand()%xmax+1;
    ya[i]=rand()%ymax+1;

    c[xa[i]][ya[i]]='*';
}



for(int i=1;i<=n;i++){

    xm[i]=1;
    ym[i]=1;

}


while(game>0){

        if(advantage>=0)
    advantage--;

    for(int i=1;i<=anti;i++){
        if(xp==xa[i] && yp==ya[i] && advremain[i]==0){

        advantage=20;
        advremain[i]=-1;

    }}



if(GetAsyncKeyState(VK_UP))direction="up";
if(GetAsyncKeyState(VK_DOWN))direction="down";
if(GetAsyncKeyState(VK_RIGHT))direction="right";
if(GetAsyncKeyState(VK_LEFT))direction="left";


if(direction=="up"){

    xpp=xp;ypp=yp;

    c[xp][yp]=' ';

    if(yp==1)yp=ymax;

       else yp--;
        if(c[xp][yp]=='.')
            score++;

        c[xp][yp]='v';

}
if(direction=="down"){

    xpp=xp;ypp=yp;

    c[xp][yp]=' ';

    if(yp==ymax)yp=1;

       else yp++;
        if(c[xp][yp]=='.')
            score++;
        c[xp][yp]='^';

}
if(direction=="right"){

    xpp=xp;ypp=yp;

    c[xp][yp]=' ';

    if(xp==xmax)xp=1;

      else  xp++;
        if(c[xp][yp]=='.')
            score++;
        c[xp][yp]='<';

}
if(direction=="left"){

    xpp=xp;ypp=yp;

    c[xp][yp]=' ';

    if(xp==1)xp=xmax;

      else  xp--;
        if(c[xp][yp]=='.')
            score++;
        c[xp][yp]='>';

}

for(int i=1;i<=n;i++){

temp=rand()%5;

if(temp==4){

        temp2=rand()%4;


    if(temp2==0)
        md[i]="right";


    else if(temp2==1)
        md[i]="down"; //down

    else if(temp2==2)
            md[i]="up"; //up

    else md[i]="left"; //left

}

int temp=0;

if(xm[i]==xp && ym[i]==yp)temp++;

if(md[i]=="right"){

    if(ctemp[i]=='.' || ctemp[i]==' ')
    c[xm[i]][ym[i]]=ctemp[i];

    else c[xm[i]][ym[i]]=' ';

    if(xm[i]==xmax)xm[i]=1;

    else xm[i]++;

    if(c[xm[i]][ym[i]]!='#')
    ctemp[i]=c[xm[i]][ym[i]];

    c[xm[i]][ym[i]]='#';
}


if(md[i]=="left"){

    if(ctemp[i]=='.' || ctemp[i]==' ')
    c[xm[i]][ym[i]]=ctemp[i];

    else c[xm[i]][ym[i]]=' ';

    if(xm[i]==1)xm[i]=xmax;

    else xm[i]--;

    if(c[xm[i]][ym[i]]!='#')
    ctemp[i]=c[xm[i]][ym[i]];

    c[xm[i]][ym[i]]='#';
}


if(md[i]=="up"){

    if(ctemp[i]=='.' || ctemp[i]==' ' || ctemp[i]=='*')
    c[xm[i]][ym[i]]=ctemp[i];

    else c[xm[i]][ym[i]]=' ';

    if(ym[i]==1)ym[i]=ymax;

    else ym[i]--;

    if(c[xm[i]][ym[i]]!='#')
    ctemp[i]=c[xm[i]][ym[i]];

    c[xm[i]][ym[i]]='#';
}


if(md[i]=="down"){

    if(ctemp[i]=='.' || ctemp[i]==' ')
    c[xm[i]][ym[i]]=ctemp[i];

    else c[xm[i]][ym[i]]=' ';

    if(ym[i]==ymax)ym[i]=1;

    else ym[i]++;

    if(c[xm[i]][ym[i]]!='#')
    ctemp[i]=c[xm[i]][ym[i]];

    c[xm[i]][ym[i]]='#';
}


if(xm[i]==xpp && ym[i]==ypp && temp==1){
        if(advantage<=0)
        game=0;

        else score=score+20;}


if(xm[i]==xp && ym[i]==yp){

        if(advantage<0)
        game=0;

        else score=score+20;
}




}

   Sleep(200);

    system("cls");

for(int i=1;i<=ymax;i++){


    for(int j=1;j<=xmax;j++){

        cout<<c[j][i];

    }

        cout<<"\n";

}

cout<<"\n\nScore= "<<score;
if(advantage>=0)cout<<"\nadvantage="<<advantage;


}

cout<<"\nyour score is "<<score;
char tp;
tp=getchar();


}
