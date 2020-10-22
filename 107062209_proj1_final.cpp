#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<string.h>
#include<map>

using namespace std;

void generate_new_block(string block, int pos,int dis);
void move_(int temp[4][4],int pos,int dis);
void eliminate();
int row,column;
int **board;

int T1[4][4] = {{0,0,0,0},
                {0,0,0,0},
                {1,1,1,0},
                {0,1,0,0}
                };

int T2[4][4] = {{0,0,0,0},
                {0,1,0,0},
                {1,1,0,0},
                {0,1,0,0}
                };

int T3[4][4] = {{0,0,0,0},
                {0,0,0,0},
                {0,1,0,0},
                {1,1,1,0}
                };

int T4[4][4] = {{0,0,0,0},
                {1,0,0,0},
                {1,1,0,0},
                {1,0,0,0}
                };

int L1[4][4] = {{0,0,0,0},
                {1,0,0,0},
                {1,0,0,0},
                {1,1,0,0}
                };

int L2[4][4] = {{0,0,0,0},
                {0,0,0,0},
                {1,1,1,0},
                {1,0,0,0}
                };

int L3[4][4] = {{0,0,0,0},
                {1,1,0,0},
                {0,1,0,0},
                {0,1,0,0}
                };

int L4[4][4] = {{0,0,0,0},
                {0,0,0,0},
                {0,0,1,0},
                {1,1,1,0}
                };

int J1[4][4] = {{0,0,0,0},
                {0,1,0,0},
                {0,1,0,0},
                {1,1,0,0}
                };

int J2[4][4] = {{0,0,0,0},
                {0,0,0,0},
                {1,0,0,0},
                {1,1,1,0}
                };

int J3[4][4] = {{0,0,0,0},
                {1,1,0,0},
                {1,0,0,0},
                {1,0,0,0}
                };

int J4[4][4] = {{0,0,0,0},
                {0,0,0,0},
                {1,1,1,0},
                {0,0,1,0}
                };

int S1[4][4] = {{0,0,0,0},
                {0,0,0,0},
                {0,1,1,0},
                {1,1,0,0}
                };

int S2[4][4] = {{0,0,0,0},
                {1,0,0,0},
                {1,1,0,0},
                {0,1,0,0}
                };

int Z1[4][4] = {{0,0,0,0},
                {0,0,0,0},
                {1,1,0,0},
                {0,1,1,0}
                };

int Z2[4][4] = {{0,0,0,0},
                {0,1,0,0},
                {1,1,0,0},
                {1,0,0,0}
                };

int I1[4][4] = {{1,0,0,0},
                {1,0,0,0},
                {1,0,0,0},
                {1,0,0,0}
                };

int I2[4][4] = {{0,0,0,0},
                {0,0,0,0},
                {0,0,0,0},
                {1,1,1,1}
                };

int O[4][4] = { {0,0,0,0},
                {0,0,0,0},
                {1,1,0,0},
                {1,1,0,0}
                };


int main(int argc,char* argv[]){
    ifstream file;
    ofstream file_out;
    string s;
    file_out.open("107062209_proj1.final");
    file.open(argv[1]);

    file>>row;
    file>>column;

    board = new int*[row+1];

    for(int i = 0;i < row;i++){
        board[i]= new int[column+2];
        memset(board[i],0,(column+2)*sizeof(int));
        board[i][0] = board[i][column+1] =1;
    }
    board[row] = new int[column+2];
    for(int j = 0;j<column+2;j++)
        board[row][j]=1;

    while(1){
        string block;
        int pos,dis;
        file>>block;
        if(block=="End"){
            block = "";
            break;
        }
        file>>pos;
        pos;
        file>>dis;
        generate_new_block(block,pos,dis);
        eliminate();
        //cout<<block<<" "<<pos<<" "<<dis<<endl;
    }

    /*for(int i=0;i<row+1;i++){
        for(int j=0;j<column+2;j++)
            cout<<board[i][j];
        cout<<endl;
    }*/

    for(int i = 0;i < row;i++){
        for(int j = 1;j<column+1;j++)
            file_out<<board[i][j]<<" ";
        file_out<<endl;
    }

    for(int i = 0;i < row;i++){
        delete[]board[i];
        board[i] = NULL;
    }
    delete[] board;
    board = NULL;

    file.close();
    file_out.close();
    return 0;
}

void generate_new_block(string block, int pos,int dis){
    int temp[4][4];
    if(block=="T1"){
        memcpy(temp,T1,sizeof(T1));
        /*for(int i = 0;i<4;i++){
            for(int j = 0;j<4;j++){
                cout<<temp[i][j];
            }
            cout<<endl;
        }
        for(int i =0;i<row+1;i++){
        for(int j = 0;j<column+2;j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }*/
    }
    else if(block=="T2"){
        memcpy(temp,T2,sizeof(T2));

    }else if(block=="T3"){
        memcpy(temp,T3,sizeof(T3));

    }else if(block=="T4"){
        memcpy(temp,T4,sizeof(T4));

    }else if(block=="L1"){
        memcpy(temp,L1,sizeof(L1));

    }else if(block=="L2"){
        memcpy(temp,L2,sizeof(L2));

    }else if(block=="L3"){
        memcpy(temp,L3,sizeof(L3));

    }else if(block=="L4"){
        memcpy(temp,L4,sizeof(L4));

    }else if(block=="J1"){
        memcpy(temp,J1,sizeof(J1));

    }else if(block=="J2"){
        memcpy(temp,J2,sizeof(J2));

    }else if(block=="J3"){
        memcpy(temp,J3,sizeof(J3));

    }else if(block=="J4"){
        memcpy(temp,J4,sizeof(J4));

    }else if(block=="S1"){
        memcpy(temp,S1,sizeof(S1));

    }else if(block=="S2"){
        memcpy(temp,S2,sizeof(S2));

    }else if(block=="Z1"){
        memcpy(temp,Z1,sizeof(Z1));

    }
    else if(block=="Z2"){
        memcpy(temp,Z2,sizeof(Z2));

    }
    else if(block=="I1"){
        memcpy(temp,I1,sizeof(I1));

    }
    else if(block=="I2"){
        memcpy(temp,I2,sizeof(I2));
    }
    else if(block=="O"){
        memcpy(temp,O,sizeof(O));

    }
    move_(temp,pos,dis);
}
void move_(int temp[4][4],int pos,int dis){
    int finish=0;
    int x = pos;
    int touch_bottom = 0;
    int touch_boundary = 0;
    int y = 0;
    /*for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<temp[i][j];
        }
        cout<<endl;
    }
    for(int i =0;i<row+1;i++){
        for(int j = 0;j<column+2;j++){
            cout<<board[i][j];
        }
        cout<<endl;*/
    //}

    while(!finish){
        while(!touch_bottom){
            if(((board[y+1][x]==1)&&(temp[3][0]==1))||
               ((board[y+1][x+1]==1)&&(temp[3][1]==1))||
               ((board[y+1][x+2]==1)&&(temp[3][2]==1))||
               ((board[y+1][x+3]==1)&&(temp[3][3]==1))){
                touch_bottom = 1;
            }
            else{
                y++;
            }
        }
        if(touch_bottom){
            if(dis>0){
                if((board[y][x+1]==1&&temp[y][3]==1)||
                   (board[y-1][x+1]==1&&temp[y-1][3]==1)
                   ||(board[y-2][x+1]==1&&temp[y-2][3]==1)
                   ||(board[y-3][x+1]==1&&temp[y-3][3]==1))
                    touch_boundary = 1;
                else{
                    dis--;
                    x++;
                    touch_bottom = 0;
                }
            }
            else if(dis<0){
                if((board[y][x-1]==1&&temp[y][0]==1)
                   ||(board[y-1][x-1]==1&&temp[y-1][0]==1)
                   ||(board[y-2][x-1]==1&&temp[y-2][0]==1)
                   ||(board[y-3][x-1]==1&&temp[y-3][0]==1))
                    touch_boundary = 1;
                else{
                    dis++;
                    x--;
                    touch_bottom = 0;
                }
            }
        }
        if(touch_bottom){
            finish = 1;
            for(int i = y-3;i<=y;i++){
                for(int j = x;j<x+4&&j<=column;j++){
                    board[i][j] = temp[i+3-y][j-x]||board[i][j];
                }
            }
        }
    }
}
void eliminate(){
    int *all_1 = new int[column+2];
    int index = 0;
    int same = 1;
    int flag = 1;
    for(int i=0;i<column+2;i++){
        all_1[i] = 1;
    }
    while(flag){
        flag=0;
        for(int i=0;i<row;i++){
            same = 1;
            for(int j = 0;j<column+2;j++){
                if(board[i][j]!=all_1[j]){
                    same = 0;
                }
            }
            if(same){
                index = i;
                flag = 1;
                break;
            }
        }
        //cout<<"index"<<index<<endl;
        //cout<<"flag"<<flag<<endl;
        if(flag){
            for(int i = index;i>0;i--){
                for(int j=0;j<column+2;j++){
                    board[i][j]=board[i-1][j];
                }
            }
            for(int i = 1;i<column+1;i++){
                board[0][i] = 0;
            }
        }
        /*for(int i=0;i<row+1;i++){
        for(int j=0;j<column+2;j++)
            cout<<board[i][j];
        cout<<endl;
    }
    cout<<endl;*/
    }
    free(all_1);
}
/*int collision(int **temp,int x,int y){

}*/
