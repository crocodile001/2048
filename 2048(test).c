#include <stdio.h>

int main(){

    //freopen("test_in.txt","r",stdin);
    int ncase,i,j,game[4][4],temp,flag;
    char way,c;

    scanf("%d",&ncase);
    while(ncase--){
        flag=1;
        for(i=0;i<4;i++){
            for(j=0;j<4;j++)    scanf("%d",&(game[i][j]));
        }
        scanf("%c",&c);
        scanf("%c",&way);

        if(way=='w' || way=='W'){   //向上
            for(j=0;j<4;j++){
                for(i=0;i<4;i++){
                    if(game[i][j]==0){  //數字移動
                        temp = i;
                        while(game[temp][j] == 0){
                            temp++;
                            if(temp==4){temp--; break;}
                        }
                        game[i][j]=game[temp][j];
                        game[temp][j]=0;
                    }
                    for(temp=i+1;temp<4;temp++){    //找相同數字相加
                        if(game[i][j]==game[temp][j]){
                            game[i][j]+=game[temp][j];
                            game[temp][j]=0;
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
                            if(temp==4){temp--; break;}
                        }
                        game[i][j]=game[i][temp];
                        game[i][temp]=0;
                    }
                    for(temp=j+1;temp<4;temp++){    //找相同數字相加
                        if(game[i][j]==game[i][temp]){
                            game[i][j]+=game[i][temp];
                            game[i][temp]=0;
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
                            if(temp==-1){temp++; break;}
                        }
                        game[i][j]=game[temp][j];
                        game[temp][j]=0;
                    }
                    for(temp=i-1;temp>=0;temp--){    //找相同數字相加
                        if(game[i][j]==game[temp][j]){
                            game[i][j]+=game[temp][j];
                            game[temp][j]=0;
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
                            if(temp==-1){temp++; break;}
                        }
                        game[i][j]=game[i][temp];
                        game[i][temp]=0;
                    }
                    for(temp=j-1;temp>=0;temp--){    //找相同數字相加
                        if(game[i][j]==game[i][temp]){
                            game[i][j]+=game[i][temp];
                            game[i][temp]=0;
                            break;
                        }
                        if(game[i][temp]!=0)    break;
                    }
                }
            }
        }
        for(i=0;i<4;i++){   //輸出矩陣
            for(j=0;j<3;j++)    printf("%d ",game[i][j]);
            printf("%d",game[i][3]);
            if(i!=3)    printf("\n");
        }
        for(i=0;i<4;i++){   //判斷結果
            if(flag==0 && j!=4) break;  //提早結束
            for(j=0;j<4;j++){
                if(game[i][j]==64){
                    printf("\nYou win");    //勝利
                    flag=0;
                    break;  //提早結束
                }
                if(flag==1){
                    if(game[i][j]==0)  flag=0; //繼續遊戲
                    else if(j+1<4 && game[i][j]==game[i][j+1])  flag=0;
                    else if(j-1>=0 && game[i][j]==game[i][j-1]) flag=0;
                    else if(i+1<4 && game[i][j]==game[i+1][j])  flag=0;
                    else if(i-1>=0 && game[i][j]==game[i-1][j]) flag=0;
                }
            }
        }
        if(flag==1) printf("\nGame over");  //失敗
        if(ncase)   printf("\n\n");
    }
    return 0;
}
