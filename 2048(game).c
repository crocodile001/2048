#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
void delay(void){
    clock_t start_time;	        //delay,使用CLOCK function
    start_time = clock();
    while((clock() - start_time) < 0.2 * CLOCKS_PER_SEC){}
}
void color(int c){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    switch(c){
        case 4: case 2:
            SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
            if(c==4)    printf("4");
            else    printf("2");
            SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        case 16: case 8:
            SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
            if(c==16)    printf("16");
            else    printf("8");
            SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        case 64:   case 32:
            SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
            if(c==64)    printf("64");
            else    printf("32");
            SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        case 256:  case 128:
            SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
            if(c==256)    printf("256");
            else    printf("128");
            SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        case 1024:  case 512:
            SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
            if(c==1024)    printf("1024");
            else    printf("512");
            SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        case 2048:
            SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
            printf("2048");
            SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        case 0 :
            SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            printf("0");
            break;
        default :
            SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
    }
}
int main(){

    int i,j,game[4][4]={0},temp,flag,win,a,b,times;
    char way,ch1,ch2,bug=1;
    color(999);
    while(1){

        srand(time(NULL));      //亂數產生
        temp=(rand()%2);
        if(temp==0)    temp=2;
        else    temp=4;
        for(i=0;i<10000000;i++){
            a=(rand()%4);
            b=(rand()%4);
            if(game[a][b]==0)   {game[a][b]=temp; break;}
        }
        if(i==10000000){        //防止沒有亂數產生
            for(i=0;i<4;i++){
                for(j=0;j<4;j++){
                    if(game[i][j]==0)   game[i][j]=temp;
                }
            }
        }

        start:
        flag=1;                                     //遊戲結果判斷初始化
        system("CLS");
        printf("\n2048 : \n");
        printf(" ______ ______ ______ ______\n");   //輸出矩陣
        for(i=0;i<4;i++){
            printf("|      |      |      |      |\n");
            printf("|");
            for(j=0;j<4;j++){
                if(game[i][j]>=0 && game[i][j]<=9)  {printf("   ");color(game[i][j]);printf("  |");}
                else if(game[i][j]>=10 && game[i][j]<=99) {printf("  ");color(game[i][j]);printf("  |");}
                else if(game[i][j]>=100 && game[i][j]<=999) {printf("  ");color(game[i][j]);printf(" |");}
                else    {printf(" ");color(game[i][j]);printf(" |");}
                if(j==3)    printf("\n");
            }
            printf("|______|______|______|______|\n");
        }


        for(i=0;i<4;i++){               //判斷結果
            if(flag==0 && j!=4) break;          //提早結束
            for(j=0;j<4;j++){
                if(game[i][j]==2048){
                    printf("\n完成2048\n");     //勝利
                    flag=0;
                    win=1;
                    break;                      //提早結束
                }
                if(flag==1){
                    if(game[i][j]==0)  flag=0;  //繼續遊戲
                    else if(j+1<4 && game[i][j]==game[i][j+1])  flag=0;
                    else if(j-1>=0 && game[i][j]==game[i][j-1]) flag=0;
                    else if(i+1<4 && game[i][j]==game[i+1][j])  flag=0;
                    else if(i-1>=0 && game[i][j]==game[i-1][j]) flag=0;
                }
            }
        }
        if(flag==1) printf("\n再接再厲\n");               //失敗

        if(flag==1 || win==1){                            //是否要繼續遊玩
            printf("是否要繼續遊玩(y/n) : ");
            if(bug==0)  scanf("%c",&way);
            scanf("%c",&way);
            bug=0;
            if(way=='y' || way=='Y'){
                for(i=0;i<4;i++){                        //初始化
                    for(j=0;j<4;j++)    game[i][j]=0;
                }
                win=0;                                   //遊戲結果判斷初始化
                times=999;
                srand(time(NULL));                       //亂數產生
                temp=(rand()%2);
                if(temp==0)    temp=2;
                else    temp=4;
                for(i=0;i<10000000;i++){
                    a=(rand()%4);
                    b=(rand()%4);
                    if(game[a][b]==0)   {game[a][b]=temp; break;}
                }
            }
            else if(way=='n' || way=='N')    return 0;   //  結束
            else{
                printf("因為你輸入非法字元,所以程式強制停止(我絕對不會說是因為我不太會寫防呆)\n");
                break;
            }
            goto start;
        }

        printf("\n請輸入方向鍵(上下左右) : ");
        while( ch1 = getch() ){                     //輸入方向鍵
            if(ch1 == -32){
                ch2 = getch();
                if(ch2 == 72){printf("↑\n"); way='w'; break;}
                if(ch2 == 75){printf("←\n"); way='a'; break;}
                if(ch2 == 77){printf("→\n"); way='d'; break;}
                if(ch2 == 80){printf("↓\n"); way='s'; break;}
            }
        }
        delay();

        times=0;
        if(way=='w' || way=='W'){   //向上
            for(j=0;j<4;j++){
                for(i=0;i<4;i++){
                    if(game[i][j]==0){  //數字移動
                        temp = i;
                        while(game[temp][j] == 0){
                            temp++;
                            if(temp==4){temp--; times--; break;}
                        }
                        game[i][j]=game[temp][j];
                        game[temp][j]=0;
                        times++;
                    }
                    for(temp=i+1;temp<4;temp++){    //找相同數字相加
                        if(game[i][j]==game[temp][j]){
                            game[i][j]+=game[temp][j];
                            game[temp][j]=0;
                            if(game[i][j]!=0)   times++;
                            break;
                        }
                        if(game[temp][j]!=0)    break;
                    }
                }
            }
        }
        if(way=='a' || way=='A'){   //向左
            for(i=0;i<4;i++){
                for(j=0;j<4;j++){
                    if(game[i][j]==0){  //數字移動
                        temp = j;
                        while(game[i][temp] == 0){
                            temp++;
                            if(temp==4){temp--; times--; break;}
                        }
                        game[i][j]=game[i][temp];
                        game[i][temp]=0;
                        times++;
                    }
                    for(temp=j+1;temp<4;temp++){    //找相同數字相加
                        if(game[i][j]==game[i][temp]){
                            game[i][j]+=game[i][temp];
                            game[i][temp]=0;
                            if(game[i][j]!=0)   times++;
                            break;
                        }
                        if(game[i][temp]!=0)    break;
                    }
                }
            }
        }
        if(way=='s' || way=='S'){   //向下
            for(j=0;j<4;j++){
                for(i=3;i>=0;i--){
                    if(game[i][j]==0){  //數字移動
                        temp = i;
                        while(game[temp][j] == 0){
                            temp--;
                            if(temp==-1){temp++; times--; break;}
                        }
                        game[i][j]=game[temp][j];
                        game[temp][j]=0;
                        times++;
                    }
                    for(temp=i-1;temp>=0;temp--){    //找相同數字相加
                        if(game[i][j]==game[temp][j]){
                            game[i][j]+=game[temp][j];
                            game[temp][j]=0;
                            if(game[i][j]!=0)   times++;
                            break;
                        }
                        if(game[temp][j]!=0)    break;
                    }
                }
            }
        }
        if(way=='d' || way=='D'){   //向右
            for(i=0;i<4;i++){
                for(j=3;j>=0;j--){
                    if(game[i][j]==0){  //數字移動
                        temp = j;
                        while(game[i][temp] == 0){
                            temp--;
                            if(temp==-1){temp++; times--; break;}
                        }
                        game[i][j]=game[i][temp];
                        game[i][temp]=0;
                        times++;
                    }
                    for(temp=j-1;temp>=0;temp--){    //找相同數字相加
                        if(game[i][j]==game[i][temp]){
                            game[i][j]+=game[i][temp];
                            game[i][temp]=0;
                            if(game[i][j]!=0)   times++;
                            break;
                        }
                        if(game[i][temp]!=0)    break;
                    }
                }
            }
        }

        system("CLS");
        printf("\n2048 : \n");
        printf(" ______ ______ ______ ______\n");   //輸出矩陣,這個是為了顯示最後的結果
        for(i=0;i<4;i++){
            printf("|      |      |      |      |\n");
            printf("|");
            for(j=0;j<4;j++){
                if(game[i][j]>=0 && game[i][j]<=9)  {printf("   ");color(game[i][j]);printf("  |");}
                else if(game[i][j]>=10 && game[i][j]<=99) {printf("  ");color(game[i][j]);printf("  |");}
                else if(game[i][j]>=100 && game[i][j]<=999) {printf("  ");color(game[i][j]);printf(" |");}
                else    {printf(" ");color(game[i][j]);printf(" |");}
                if(j==3)    printf("\n");
            }
            printf("|______|______|______|______|\n");
        }

        for(i=0;i<4;i++){               //判斷結果
            if(flag==0 && j!=4) break;          //提早結束
            for(j=0;j<4;j++){
                if(game[i][j]==2048){
                    printf("\n完成2048\n");        //勝利
                    flag=0;
                    win=1;
                    break;                      //提早結束
                }
                if(flag==1){
                    if(game[i][j]==0)  flag=0;  //繼續遊戲
                    else if(j+1<4 && game[i][j]==game[i][j+1])  flag=0;
                    else if(j-1>=0 && game[i][j]==game[i][j-1]) flag=0;
                    else if(i+1<4 && game[i][j]==game[i+1][j])  flag=0;
                    else if(i-1>=0 && game[i][j]==game[i-1][j]) flag=0;
                }
            }
        }
        if(flag==1) printf("\n再接再厲\n");              //失敗

        if(flag==1 || win==1){                           //是否要繼續遊玩
            printf("是否要繼續遊玩(y/n) : ");
            if(bug==0)  scanf("%c",&way);
            scanf("%c",&way);
            bug=0;
            if(way=='y' || way=='Y'){
                for(i=0;i<4;i++){                        //初始化
                    for(j=0;j<4;j++)    game[i][j]=0;
                }
                win=0;                                   //遊戲結果判斷初始化
                times=999;                               //防止進入沒移動的迴圈
            }
            else if(way=='n' || way=='N')    return 0;   //  結束
            else{
                printf("因為你輸入非法字元,所以程式強制停止(我絕對不會說是因為我不太會寫防呆)\n");
                break;
            }
        }

        if(times<=0)  goto start;                        //防止沒移動,放最後面是為了防止數字填滿會誤判
    }
}
