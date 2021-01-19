
#include <graphics.h>
#include<dos.h>
#include <stdlib.h>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
int system();
void over();
void lose();
void win();
void grid();
void grid_lvl2();
void grid_lvl1();
void grid_lvl3();
int mat[6][6],k=0,l=0;
// int i=192,j=138;
char y;
 void boundaryfill(int x,int y,int f_color,int b_color)
{
	if(getpixel(x,y)!=b_color && getpixel(x,y)!=f_color)
	{
		putpixel(x,y,f_color);
		boundaryfill(x+1,y,f_color,b_color);
		boundaryfill(x,y+1,f_color,b_color);
		boundaryfill(x-1,y,f_color,b_color);
		boundaryfill(x,y-1,f_color,b_color);
	}
}

int main()
{

    int gd=DETECT,gm;
    char y;
    initgraph(&gd,&gm,"");
   settextstyle(10,0,5);
   outtextxy(120,200,"THE  MEMOMRY  GAME");
   delay(1500);
   cleardevice();
   settextstyle(8,0,5);
   outtextxy(200,200,"LEVEL 1");
   delay(1500);
   cleardevice();
   grid_lvl1();
    cleardevice();
    system();
    cleardevice();
    settextstyle(8,0,5);
   outtextxy(200,200,"LEVEL 2");
   delay(1500);
   cleardevice();
    over();
    grid_lvl2();
    cleardevice();
    system();
    cleardevice();
    settextstyle(8, 0, 3);
    outtextxy(130,200,"YOU ARE NOW IN FINAL LEVEL ");
    delay(1500);
     over();
    cleardevice();
    grid_lvl3();
    cleardevice();
    system();
    cleardevice();
    win();
    cleardevice();
    settextstyle(10,0,4);
    outtextxy(190,200,"YOU FINISHED THE GAME");
    delay(1500);
    getch();
    closegraph();
    return 0;
}
void grid()
{
     rectangle(170,120,440,380);
    line(215,120,215,380);
    floodfill(161,121,WHITE);
    line(260,120,260,380);
    line(305,120,305,380);
    line(345,120,345,380);
    line(390,120,390,380);
    line(170,160,440,160);
    line(170,205,440,205);
    line(170,250,440,250);
    line(170,290,440,290);
    line(170,335,440,335);
     // STARTING POINT
    boundaryfill(180,151,BLUE,WHITE);
    // ENDING POINT
    boundaryfill(435,337,BLUE,WHITE);

}
void grid_lvl1()
{
     grid();
    //LEVEL 1 POINTS
    boundaryfill(429,320,RED,WHITE);
    boundaryfill(304,121,RED,WHITE);
    boundaryfill(171,206,RED,WHITE);
    boundaryfill(320,220,RED,WHITE);
    boundaryfill(300,320,RED,WHITE);
    boundaryfill(300,320,RED,WHITE);
    boundaryfill(174,375,RED,WHITE);
    boundaryfill(235,270,RED,WHITE);
    boundaryfill(370,121,RED,WHITE);
    mat[0][2]=1;
    mat[2][0]=1;
    mat[2][3]=1;
    mat[4][2]=1;
    mat[4][5]=1;
    mat[5][5]=2;
    mat[0][5]=1;
    mat[5][0]=1;
    mat[3][1]=1;
     mat[0][4]=1;
    delay(4000);

}
void win()
{
    settextstyle(8, 0, 6);
    outtextxy(200, 200, "YOU WON");
    delay(1500);
}
 void grid_lvl2()
{
    grid();
    // boundaryfill(340,320,RED,WHITE);
    boundaryfill(300,230,RED,WHITE);
    boundaryfill(400,240,RED,WHITE);
    boundaryfill(320,300,RED,WHITE);
    boundaryfill(350,125,RED,WHITE);
    boundaryfill(200,280,RED,WHITE);
    boundaryfill(360,280,RED,WHITE);
    boundaryfill(175,170,RED,WHITE);
    boundaryfill(220,375,RED,WHITE);
    mat[0][4]=1;
    mat[1][0]=1;
    mat[2][2]=1;
    mat[3][0]=1;
    mat[2][5]=1;
    mat[3][4]=1;
    mat[4][3]=1;
    mat[5][5]=2;
    mat[5][1]=1;
    delay(4000);
}
int system()
{
    int i=192,j=138;
    while(1)
    {
end_:


        grid();
        circle(i,j,15);
        floodfill(i,j,WHITE);
        y=getche();
        system("CLS");


        if(y=='d')
        {
            i+=45;
            l++;
        }
        else if(y=='a')
         {
            i-=45;
            l--;
         }
        else if(y=='w')
          {
            j-=45;
            k--;
          }
        else if(y=='s')
           {
               j+=45;
               k++;
           }
            if(j>380)
         {
             j-=45;
             k--;

            goto end_;
         }
         if(j<120)
         {
             j+=45;
             k++;
             goto end_;
         }
         if(i<170)
         {
             i+=45;
             l++;
             goto end_;
         }
          if(i>440)
          {
              i-=45;
              l--;
              goto end_;
          }
          if (mat[k][l]==1)
          {
              cleardevice();
              lose();
              exit(0);
            break;
          }

            if(mat[k][l]==2)
            {
                cleardevice();
                win();
                break;
            }
            delay(100);
            cleardevice();

    }
}
void over()
{
    for(k=0;k<5;k++)
    {
        for(l=0;l<5;l++)
        {
            mat[k][l]=0;
        }
    }
    k=0;
    l=0;
}
void lose()
{
    settextstyle(8, 0, 5);
    outtextxy(200, 200, "YOU LOST");
    delay(1000);

}
void grid_lvl3()
{
    grid();
    over();
     boundaryfill(340,225,RED,WHITE);
    boundaryfill(340,300,RED,WHITE);
    boundaryfill(385,265,RED,WHITE);
    boundaryfill(225,170,RED,WHITE);
    boundaryfill(175,230,RED,WHITE);
    boundaryfill(300,265,RED,WHITE);
    boundaryfill(175,320,RED,WHITE);
    boundaryfill(225,365,RED,WHITE);
    boundaryfill(340,125,RED,WHITE);
    boundaryfill(365,125,RED,WHITE);
    boundaryfill(435,165,RED,WHITE);
    mat[0][3]=1;
    mat[2][5]=0;
    mat[4][5]=0;
    mat[0][4]=1;
    mat[1][1]=1;
    mat[1][5]=1;
    mat[2][0]=1;
    mat[2][3]=1;
    mat[3][2]=1;
    mat[3][4]=1;
    mat[4][0]=1;
    mat[4][3]=1;
    mat[5][1]=1;
    mat[5][5]=2;
    delay(4000);

}
