// linked list ranking
// Serial version
// c version
// input: a linked list with N elements
// output:a vector of rank

#include <stdio.h>
#include <stdlib.h>
#define DEBUG 0    // 1 is debugging mode
#define GENERATE 1 // 1 let program generate list automatically
#include "generate/list_gen.h"
#define N 10     // note: N must > head in list_gen()

void show_vec(const int* vec, int n);
int find_head(const int* vec, int n);
void sequential(const int* vec, int n, int* result);

int main(){
    int resu[N]; // list rank

    #if GENERATE
    int list[N];
    // int* list = (int*)malloc(N * sizeof(int)); // this doesn't work, why???
    list_gen(list, N);
    #else
    // int list[N] = {4,-1,7,6,3,2,5,9,1,8}; // get a linked list, head at 0
    int list[N] = {-1,2,9,4,6,8,1,5,3,0}; // get a linked list, head at 7
    #endif

    show_vec(list, N);
    sequential(list, N, resu);
    show_vec(resu, N);

    return 0;
}

void sequential(const int* vec, int n, int* result){
    int pointer = 0;
    int temp;
    int i;
    temp = find_head(vec, N);
    result[temp] = N-1;
    for(i = 1; i < N; i++){
        temp = vec[temp]; // temp is next pointer
        pointer ++;
        result[temp] = N - pointer - 1;
    }
}

void show_vec(const int* vec, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%3d ", vec[i]);
    }
    printf("\n");
}

int find_head(const int* vec, int n){
    int head;
    int i;
    int total = (N-1) * N / 2;
    for(i = 0; i < N; i++){
        total -= vec[i];
    }
    head = total -1;
    printf("head is %d\n", head);
    return head;
}