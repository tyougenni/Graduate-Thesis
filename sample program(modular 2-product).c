#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX_LENGTH 60000 // メモリ容量を制限するため
typedef int Bool;
typedef struct {
  int a;
  int b;
} Result;

Result is_female(Bool p1, Bool p2, int person1, int person2) {
  int res1, res2;
  int gender1, gender2;
  if(p1){
      gender1 = person1 % 2;
  }
  Bool t1 = p1 && gender1 == 0;
  Bool f1 = p1 && !(gender1 == 0);
  if (t1) {res1 = 1;}
  if (f1) {res1 = 0;}

  if(p2){
      gender2 = person2 % 2;
  }
  Bool t2 = p2 && gender2 == 0;
  Bool f2 = p2 && !(gender2 == 0);
  if (t2) {res2 = 1;}
  if (f2) {res2 = 0;}

  return (Result){res1, res2};
}

int main() {
    int i1 = 0, count1 = 0, i2 = 0, count2 = 0;
    int current1, current2;
    int t1, t2;
    int f1, f2;
    Bool p1 = TRUE;
    Bool p2 = TRUE;
    int length1 = (int)rand()%MAX_LENGTH;
    int people1[length1];
    srand((unsigned)time(NULL));
    if(p1){
        i1 = 0, count1 = 0;
    }
    int length2 = (int)rand()%MAX_LENGTH;
    int people2[length2];
    for (int i = 0; i < length1; i++) {
        people1[i] = rand()%2;
    }
    for (int i = 0; i < length2; i++) {
      people2[i] = rand()%2;
    }

    if(p2){
        i2 = 0, count2 = 0;
    }

    while ((p1 && i1 < length1) || (p2 && i2 < length2)) {
        Bool l1 = p1 && i1 < length1;
        Bool l2 = p2 && i2 < length2;
        if(l1){
            current1 = people1[i1];
        }
        if(l2){
            current2 = people2[i2];
        }
        if(l1 || l2){
            Result temp = is_female(l1, l2, current1, current2);
            t1 = temp.a;
            t2 = temp.b;
        }
        if(l1){
            f1 = t1;
            count1 += f1;
            i1 += 1;
        }
        if(l2){
            f2 = t2;
            count2 += f2;
            i2 += 1;
        }
    }
    if (count1 != count2) {
      //@ assert count1 != count2;
    } else {
      //@ assert count1 == count2;
    }
    return 0;
}
