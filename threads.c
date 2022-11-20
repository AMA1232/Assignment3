#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include <time.h>

int* array;
int length = 1000000;
int arr[1000000];
int count;
int* arr_builder(){
    int *arr = (int*)malloc(sizeof(int) * length);
    for(int i = 0 ; i < length ; i++){
        if(i % 4 != 0){
            arr[i] = 1;
        }
        else{
            arr[i] = 2;
        }
    }
    return arr;
}

int count1s(){
    int i;
    array = arr_builder();
    count = 0 ; 
    for(i = 0 ; i < length/64 ; i++){
        if(array[i] == 1){
            count++;
        }
    }
    return count;
} 
int main(int argc , char* argv[]){
    pthread_t thread;
        pthread_create(&thread , NULL , &count1s , NULL);
        pthread_join(thread , NULL);

    clock_t t;
    t = clock();
    count1s();
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
     printf("count1s took %f seconds to execute \n", time_taken);

    printf("NUMBER of 1's : %d \n" , count);
    return 0;
}