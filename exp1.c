#include <stdio.h>

int linearComplexity = 0;
int binaryComplexity = 0;

int linearSearch(int search, int* array, int n){
    for(int i=0; i<n; i++){
        linearComplexity++;
        if(search == *(array+i)){
            return i;
        }
    }
    linearComplexity++;
    return -1;
}

int binarySearch(int search, int* array, int n){
    int high = n-1;
    binaryComplexity++;
    int low = 0;
    binaryComplexity++;

    while(high>=low){
        int mid = (high+low)/2;
        binaryComplexity++;
        if(*(array+mid) < search){
            low = mid;
            binaryComplexity++;
        }else if(*(array+mid) > search){
            high = mid - 1;
            binaryComplexity++;
        }else{
            return mid;
        }
    }

    return -1;
}


int main(){
    printf("Enter size of array: ");

    int n = 0;
    scanf("%d", &n);
    
    int array[n];
    for(int i=0; i<n; i++){
        printf("Element %d: ", i);
        scanf("%d", &array[i]);
    }

    int search = 0;
    printf("Enter search element: ");
    scanf("%d", &search);

    printf("Linear search result: %d\n", linearSearch(search, array, n));
    printf("Linear search time complexity: %d\n", linearComplexity);
    printf("Linear search space complexity: %d bytes\n\n", (3+n)*sizeof(int));
    printf("Binary search result: %d\n", binarySearch(search, array, n));
    printf("Binary search time complexity: %d\n", binaryComplexity);
    printf("Binary search space complexity: %d bytes\n", (5+n)*sizeof(int));

    return 0;
}