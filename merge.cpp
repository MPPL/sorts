#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 5000

void merge(int array[], int start, int mid, int end){

    int left = start;
    int right = mid+1;
    int i = start;
    int arr[N];
    while((left<= mid)&&(right <= end)){
        if(array[left]<array[right]){
            arr[i] = array[left];
            left++;
        }
        else{
            arr[i] = array[right];
            right++;
        }
        i++;
    }
    while(left<= mid){
        arr[i] = array[left];
        left++;
        i++;
    }
    while(right<=end){
        arr[i] = array[right];
        right++;
        i++;
    }
    for(int j = start; j <= end; j++){
        array[j] = arr[j];
    }
    
}

void mergesort(int array[], int start, int end){
    if(start<end){
        int mid = start + (end - start)/2;
        mergesort(array,start,mid);
        mergesort(array,mid+1,end);
        merge(array, start, mid, end);
    }
}

int main(int argn, char** args){
    srand((int)time(NULL));
    int array[N];
    for(int i = 0; i < N; i++){
        array[i] = rand()%100;
        printf("%d ", array[i]);
    }
    printf("\n\n");
    mergesort(array,0,N-1);
    for(int i = 0; i < N; i++){
        printf("%d ", array[i]);
    }
    return(0);
}
