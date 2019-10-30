#include<iostream>
#include <stdlib.h>
using namespace std;

typedef struct{
    double value;
    double weight;
} Item;

typedef struct{
    int bagweight;
    Item * list;
} Example;

int compare (const void *a ,const void *b){
    return ((((Item *)b)->value / ((Item *)b)->weight) - (((Item *)a)->value / ((Item *)a)->weight));
}
void FractionalVersion (){    
    Item objectlist[3]={
        [0]={
             .value = 10,
             .weight = 2},
        [1]={
            .value = 6,
            .weight = 1},
        [2]={
            .value = 12,
            .weight = 3}
    };
    Example a = {
        .bagweight = 5,
        .list = objectlist
    };
    qsort(a.list,3,sizeof(a.list[0]),compare);
    double profit = 0;
    int counter = 0;
    while (a.bagweight>0){
        if(a.bagweight >= a.list[counter].weight ){
            a.bagweight -= a.list[counter].weight;
            profit += a.list[counter].value;
        }
        else {
            profit += (a.list[counter].value/a.list[counter].weight*a.bagweight);
            a.bagweight = 0;
        }
        counter ++;                  
    }
    printf("FractionalVersion: %d\n", (int)profit);    
}

void ZeroOneVersion (){
    Item objectlist[3]={
        [0]={
             .value = 10,
             .weight = 2},
        [1]={
            .value = 6,
            .weight = 1},
        [2]={
            .value = 12,
            .weight = 3}
    };
    Example a = {
        .bagweight = 5,
        .list = objectlist
    };
    int profit [4][6];
    for(int i = 0; i < 4 ; i++){
        for (int j = 0; j< 6 ; j++){
            profit[i][j] = 0;
        }
        
    }
    for(int i = 1; i < 4 ; i++){
        for (int j = 1; j< 6 ; j++){
            if(j>= a.list[i-1].weight){
                profit[i][j] = (a.list[i-1].value + profit[i-1][j - (int)a.list[i-1].weight]) >= profit[i-1][j] ? (a.list[i-1].value + profit[i-1][j - (int)a.list[i-1].weight]):(profit[i-1][j]);
            }
            else{              
                profit[i][j]= profit[i-1][j];
            }

        }
        
    }
    printf("ZeroOneVersion: %d\n", profit[3][5]);
}

int main(){
    FractionalVersion();
    ZeroOneVersion();
    system("pause");
    return 0;
}