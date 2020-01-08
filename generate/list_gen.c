// linked list gen 
#include <stdio.h>
#include <stdlib.h>

#define DEBUG 1
#include "list_gen.h"
#define N 100

int main(){
    int* list = (int*) malloc(N * sizeof(int));
    if(list == NULL){
        printf("malloc failed, exit\n");
        return -1;
    }

    list_gen(list, N);
    
    int i;
    for(i = 0; i < N; i++){
        printf("%2d ", list[i]);
    }
    printf("\n");
    return 0;
}