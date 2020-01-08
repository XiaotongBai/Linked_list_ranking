#ifndef __LIST_GEN_H__
#define __LIST_GEN_H__

int list_gen(int* list, const int n){
    int valid[n];
    int i, j;
    int head = 2;    // head node
    int curr = head; // current node
    int next;        // next node

    for(i=0; i < n; i++){
        valid[i] = 1;  // the entire list is valid
    }

    for(i = 0; i < n; i++){  // in each iteration, insert a number
        if(i != n-1){        // not the final one
            srand(i);
            next = rand() % n;     // generate random position
            #if DEBUG
            printf("next = %d\n", next);
            #endif
            if((valid[next] == 1) && (next != curr)){  // no loop!!
                list[curr] = next;

                // if(list[curr] == -1){
                //     printf("find -1~~~!\n");
                // }

                valid[curr] = 0;
                #if DEBUG
                printf("list[%d] = %d\n", curr, next);
                #endif
                curr = next;
            }
            else{
                #if DEBUG
                printf("position %d is not valid\n", next);
                #endif
                j = next;
                while(valid[j] == 0 || j == curr){ // not && j!= curr
                    j++;
                    j = j % n;
                }
                #if DEBUG
                printf("find valid position %d\n", j);
                #endif
                list[curr] = j;
                // if(list[curr] == -1){
                //     printf("hhhhhh find -1\n");
                // }
                valid[curr] = 0; // forgot this
                curr = j;
            }
        }
        else{ // final stage, whenever valid, list = -1
            j = 0;
            while(valid[j] == 0){j++;}
            #if DEBUG
            printf("find valid position %d\n", j);
            #endif
            list[j] = -1;
            // printf("find -1 at j = %d\n", j);
            valid[j]= 0;
        }
    }
}
#endif