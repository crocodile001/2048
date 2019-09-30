#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
void delay(void){
    clock_t start_time;	        //delay,�ϥ�CLOCK function
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

        srand(time(NULL));      //�üƲ���
        temp=(rand()%2);
        if(temp==0)    temp=2;
        else    temp=4;
        for(i=0;i<10000000;i++){
            a=(rand()%4);
            b=(rand()%4);
            if(game[a][b]==0)   {game[a][b]=temp; break;}
        }
        if(i==10000000){        //����S���üƲ���
            for(i=0;i<4;i++){
                for(j=0;j<4;j++){
                    if(game[i][j]==0)   game[i][j]=temp;
                }
            }
        }

        start:
        flag=1;                                     //�C�����G�P�_��l��
        system("CLS");
        printf("\n2048 : \n");
        printf(" ______ ______ ______ ______\n");   //��X�x�}
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


        for(i=0;i<4;i++){               //�P�_���G
            if(flag==0 && j!=4) break;          //��������
            for(j=0;j<4;j++){
                if(game[i][j]==2048){
                    printf("\n����2048\n");     //�ӧQ
                    flag=0;
                    win=1;
                    break;                      //��������
                }
                if(flag==1){
                    if(game[i][j]==0)  flag=0;  //�~��C��
                    else if(j+1<4 && game[i][j]==game[i][j+1])  flag=0;
                    else if(j-1>=0 && game[i][j]==game[i][j-1]) flag=0;
                    else if(i+1<4 && game[i][j]==game[i+1][j])  flag=0;
                    else if(i-1>=0 && game[i][j]==game[i-1][j]) flag=0;
                }
            }
        }
        if(flag==1) printf("\n�A���A�F\n");               //����

        if(flag==1 || win==1){                            //�O�_�n�~��C��
            printf("�O�_�n�~��C��(y/n) : ");
            if(bug==0)  scanf("%c",&way);
            scanf("%c",&way);
            bug=0;
            if(way=='y' || way=='Y'){
                for(i=0;i<4;i++){                        //��l��
                    for(j=0;j<4;j++)    game[i][j]=0;
                }
                win=0;                                   //�C�����G�P�_��l��
                times=999;
                srand(time(NULL));                       //�üƲ���
                temp=(rand()%2);
                if(temp==0)    temp=2;
                else    temp=4;
                for(i=0;i<10000000;i++){
                    a=(rand()%4);
                    b=(rand()%4);
                    if(game[a][b]==0)   {game[a][b]=temp; break;}
                }
            }
            else if(way=='n' || way=='N')    return 0;   //  ����
            else{
                printf("�]���A��J�D�k�r��,�ҥH�{���j���(�ڵ��藍�|���O�]���ڤ��ӷ|�g���b)\n");
                break;
            }
            goto start;
        }

        printf("\n�п�J��V��(�W�U���k) : ");
        while( ch1 = getch() ){                     //��J��V��
            if(ch1 == -32){
                ch2 = getch();
                if(ch2 == 72){printf("��\n"); way='w'; break;}
                if(ch2 == 75){printf("��\n"); way='a'; break;}
                if(ch2 == 77){printf("��\n"); way='d'; break;}
                if(ch2 == 80){printf("��\n"); way='s'; break;}
            }
        }
        delay();

        times=0;
        if(way=='w' || way=='W'){   //�V�W
            for(j=0;j<4;j++){
                for(i=0;i<4;i++){
                    if(game[i][j]==0){  //�Ʀr����
                        temp = i;
                        while(game[temp][j] == 0){
                            temp++;
                            if(temp==4){temp--; times--; break;}
                        }
                        game[i][j]=game[temp][j];
                        game[temp][j]=0;
                        times++;
                    }
                    for(temp=i+1;temp<4;temp++){    //��ۦP�Ʀr�ۥ[
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
        if(way=='a' || way=='A'){   //�V��
            for(i=0;i<4;i++){
                for(j=0;j<4;j++){
                    if(game[i][j]==0){  //�Ʀr����
                        temp = j;
                        while(game[i][temp] == 0){
                            temp++;
                            if(temp==4){temp--; times--; break;}
                        }
                        game[i][j]=game[i][temp];
                        game[i][temp]=0;
                        times++;
                    }
                    for(temp=j+1;temp<4;temp++){    //��ۦP�Ʀr�ۥ[
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
        if(way=='s' || way=='S'){   //�V�U
            for(j=0;j<4;j++){
                for(i=3;i>=0;i--){
                    if(game[i][j]==0){  //�Ʀr����
                        temp = i;
                        while(game[temp][j] == 0){
                            temp--;
                            if(temp==-1){temp++; times--; break;}
                        }
                        game[i][j]=game[temp][j];
                        game[temp][j]=0;
                        times++;
                    }
                    for(temp=i-1;temp>=0;temp--){    //��ۦP�Ʀr�ۥ[
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
        if(way=='d' || way=='D'){   //�V�k
            for(i=0;i<4;i++){
                for(j=3;j>=0;j--){
                    if(game[i][j]==0){  //�Ʀr����
                        temp = j;
                        while(game[i][temp] == 0){
                            temp--;
                            if(temp==-1){temp++; times--; break;}
                        }
                        game[i][j]=game[i][temp];
                        game[i][temp]=0;
                        times++;
                    }
                    for(temp=j-1;temp>=0;temp--){    //��ۦP�Ʀr�ۥ[
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
        printf(" ______ ______ ______ ______\n");   //��X�x�},�o�ӬO���F��̫᪺ܳ���G
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

        for(i=0;i<4;i++){               //�P�_���G
            if(flag==0 && j!=4) break;          //��������
            for(j=0;j<4;j++){
                if(game[i][j]==2048){
                    printf("\n����2048\n");        //�ӧQ
                    flag=0;
                    win=1;
                    break;                      //��������
                }
                if(flag==1){
                    if(game[i][j]==0)  flag=0;  //�~��C��
                    else if(j+1<4 && game[i][j]==game[i][j+1])  flag=0;
                    else if(j-1>=0 && game[i][j]==game[i][j-1]) flag=0;
                    else if(i+1<4 && game[i][j]==game[i+1][j])  flag=0;
                    else if(i-1>=0 && game[i][j]==game[i-1][j]) flag=0;
                }
            }
        }
        if(flag==1) printf("\n�A���A�F\n");              //����

        if(flag==1 || win==1){                           //�O�_�n�~��C��
            printf("�O�_�n�~��C��(y/n) : ");
            if(bug==0)  scanf("%c",&way);
            scanf("%c",&way);
            bug=0;
            if(way=='y' || way=='Y'){
                for(i=0;i<4;i++){                        //��l��
                    for(j=0;j<4;j++)    game[i][j]=0;
                }
                win=0;                                   //�C�����G�P�_��l��
                times=999;                               //����i�J�S���ʪ��j��
            }
            else if(way=='n' || way=='N')    return 0;   //  ����
            else{
                printf("�]���A��J�D�k�r��,�ҥH�{���j���(�ڵ��藍�|���O�]���ڤ��ӷ|�g���b)\n");
                break;
            }
        }

        if(times<=0)  goto start;                        //����S����,��̫᭱�O���F����Ʀr�񺡷|�~�P
    }
}
