//
//  t4.c
//  
//
//  Created by tyougenni on 2020/01/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int Bool;
#define TRUE 1
#define FALSE 0

typedef struct{
  int m;
  int n;
} Result;

Result abs_(Bool p1, Bool p2, int b1, int b2){
    int res1,res2;
    p1 = TRUE;
    Bool t1 = p1 && b1 >= 0;
    Bool f1 = p1 && !(b1 >= 0);
    if(t1) {res1 = b1;}
    if(f1) {res1 = -b1;}
    
    p2 = TRUE;
    Bool t2 = p2 && (b2 >= 0);
    Bool f2 = p2 && !(b2 >= 0);
    if(t2) {res2 = b2;}
    if(f2) {res2 = -b2;}
    
    return (Result){res1, res2};
}

int main(){
    int i1 = 0, i2 = 0, b1 = 0, b2 = 0;
    int a1 = 0, a2 = 0, N1 = 0, N2 = 0;
    Bool p1 = TRUE;
    Bool p2 = TRUE;
    srand((unsigned)time(NULL));
    b1 = rand()%5;
    if(p1){
        i1 = 0;
        a1 = 0;
    }
    b2 = rand()%5;
    if(p2){
        i2 = 0;
        a2 = 0;
    }
    if(p1 || p2){
        Result temp = abs_(p1, p2, b1, b2);
        a1 = temp.m;
        a2 = temp.n;
    }
    while((p1 && i1 < N1) || (p2 && i2 < N2)){
        Bool l1 = p1 && i1 < N1;
        Bool l2 = p2 && i2 < N2;
        if(l1){
            a1+=a1;
            i1++;
        }
        if(l2){
            a2+=a2;
            i2++;
        }
    }
    if(p1){
        if(a1>=0) {
            printf("yes\n");
        }else{
            printf("no\n");
        }
    }
    if(p2){
        if(a2>=0) {
            printf("yes\n");
        }else{
            printf("no\n");
        }
    }
    return 0;
}
