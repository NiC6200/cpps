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

int game=1;


int main(){

	int score=0;

	srand(time(NULL));

	char c[100][100],a,ans='y',b;
	int xmax=21,ymax=21,y[100],x[100],xt,yt,tempf=1000,temps=1000,xs,ys,xf,yf,l=1,speed=100;

	x[1]=(xmax+1)/2;
	y[1]=(ymax+1)/2;

	xt=rand()%xmax+1;
	yt=rand()%ymax+1;

	while(ans=='y'){

		if(kbhit()){

            b=getch();

			if(GetAsyncKeyState(VK_UP))a='w';
			if(GetAsyncKeyState(VK_LEFT))a='a';
			if(GetAsyncKeyState(VK_DOWN))a='s';
			if(GetAsyncKeyState(VK_RIGHT))a='d';
		}


			if(a=='w')y[1]--;
			if(a=='d')x[1]++;
			if(a=='s')y[1]++;
			if(a=='a')x[1]--;
			if(b=='n')score++;

			if(y[1]>ymax)y[1]=y[1]%ymax;
			if(x[1]>xmax)x[1]=x[1]%xmax;
			if(x[1]==0)x[1]=xmax;
			if(y[1]==0)y[1]=ymax;


			for(int i=0;i<=xmax+1;i++){

				for(int j=0;j<=ymax+1;j++){


					 if(xt==i && yt==j)c[i][j]='0';
					 else if(i==xmax+1 || i==0)c[i][j]='|';
					 else if(j==ymax+1 || j==0)c[i][j]='-';
					 else if(i==xs && j==ys && temps<50)c[i][j]=1;
					 else if(i==xf && j==yf && tempf<50)c[i][j]='^';
                    else c[i][j]=' ';

                    for(int m=1;m<=l;m++)
					{

						if(x[m]==i && y[m]==j)c[i][j]='*';
						if(x[m]==x[1] && y[m]==y[1] && m!=1)game--;

					}
				}}
					if(xt==x[1] && yt==y[1]){

						score++;
						l++;

						xt=rand()%xmax+1;
						yt=rand()%ymax+1;
					}

                        else if(xs==x[1] && ys==y[1] && temps<50){

						score=score+10;
						temps=100;

					}

					 else if(xf==x[1] && yf==y[1] && tempf<50){

						speed=20;
						tempf=100;

					}

					for(int i=l;i>1;i--){
                        x[i]=x[i-1];
                        y[i]=y[i-1];					}


                        int smile=rand()%100;



                        if(smile==0 && temps>250){

                        xs=rand()%xmax+1;
						ys=rand()%ymax+1;
						temps=1;
						c[xs][ys]=1;

                        }

                        temps++;



                        int fast=rand()%100;

                        if(fast==0 && tempf>250){

                        xf=rand()%xmax+1;
						yf=rand()%ymax+1;
						tempf=1;
						c[xf][yf]='^';


                        }

                        tempf++;

                        if(tempf>150)speed=100;



			system("cls");
			for(int i=0;i<=ymax+1;i++){
				cout<<"\n";
				for(int j=0;j<=xmax+1;j++)
				cout<<c[j][i];
			}
			cout<<"\n\nscore: "<<score<<"\nLength = "<<l;

			Sleep(speed);

			if(game<1){

                    system("cls");

                cout<<"You lost!!!\nScore is "<<score<<"\nDo you want to play again?(y/n)";
                cin>>ans;

                if(ans=='y'){game=1;
                l=1;
                score=0;

			}}



		}


	}


