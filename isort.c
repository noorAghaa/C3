
#include <stdio.h>
#include"isort.h"



void shift_element(int* arr, int i){
	if(i < 0){
		printf("negative number");
		return;
	}
	int tmp = *(arr + i);
	for(int y = i - 1; y >= 0; y--){
		*(arr + y + 1) = *(arr + y);
	}
	*arr = tmp;
}

void insertion_sort(int* arr, int len){
	int i, temp;
int j;
    for (i = 1; i < len; i++) { 
        temp= *(arr + i); 
        j = i - 1;
        while (*(arr + j) > temp&&j >= 0 ) { 
			shift_element((arr + j), 1);
			j--;
        } 
        *(arr + j + 1) = temp; 
    } 
}

int main(){
    int num = 50;
    int arr[50] = {0};
    for (int i = 0; i < 50; i++){
        scanf("%d", arr + i);
    }
    insertion_sort(arr, num);
    for (int i = 0; i < 50; i++){
        if (i == 49){
            printf("%d", *(arr+i)); 
        }
        else{
            printf("%d,", *(arr+i));
        }
    }
    return 0;
}