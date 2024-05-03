#include <stdio.h>

void setspace(char w,int k,char arr[k][k]){
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            arr[i][j]=w;
        }
    }
}
void print(int k,char arr[k][k]){
    printf("____________\n");
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            if(j==0){
                printf("|");
                printf("%c",arr[i][j]);

            }
            else if(j==k-1){
                printf("%c",arr[i][j]);
                printf("|");
            }
            else printf("%c",arr[i][j]);

        }
        
        printf("\n");
    } 
    printf("============\n");   
}
int main(){

    char w='#';
    char s=' ';
    int k=10;
    char move;
    int total;
    char arr[k][k];
    char* p1=&arr[9][8];
    int cr=9,cc=8;
    
    setspace(w,k,arr);
    #include "maze.c"
    *p1='X';
    print(k,arr);
    
    int check=1;
    arr[0][0]='0';
    
    printf("Are you ready?press s to start q to quit.");
    scanf("%c",&move);
    total=0;
    if(move=='q') return 0;
    else{
        printf("rules\n 1. dont hit a wall \n 2. press q if you want to quit at anytime \n 3. reach the M to finish\n 4. reach the 0 at top left corner\n 5.use w,a,s,d to move our player X.\n");

        while(check){
            scanf(" %c",&move);
            
            if(move=='w'){
                if(arr[cr-1][cc]=='#'){printf("i said don't hit a wall \n"); continue;}
                *p1=' ';
                p1=&arr[--cr][cc];
                *p1='X';    
            }
            else if(move=='a'){
                if(arr[cr][cc-1]=='#'){printf("i said don't hit a wall \n"); continue;}
                *p1=' ';
                p1=&arr[cr][--cc];
                *p1='X';
            }
            else if(move=='s'){
                if(arr[cr+1][cc]=='#'){printf("i said don't hit a wall \n"); continue;}
                *p1=' ';
                p1=&arr[++cr][cc];
                *p1='X';
            }
            else if(move=='d'){
                if(arr[cr][cc+1]=='#'){printf("i said don't hit a wall \n"); continue;}
                *p1=' ';
                p1=&arr[cr][++cc];
                *p1='X';
            }
            if(p1==&arr[0][0]) check=0;

            total++;
            
            print(k,arr);
            
        }

    }
    printf("you win with a total of %d moves",total);

return 0;
}