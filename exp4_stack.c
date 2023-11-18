#include <stdio.h>

int SIZE = 0;
int TOP = -1;

void push(int item, int* stack){
    if(TOP == SIZE-1){
        printf("Stack is full\n");
    }else{
        TOP++;
        *(stack+TOP) = item;
    }
}

int pop(int* stack){
    if(TOP == -1){
        printf("Stack is empty\n");
        return -1;
    }else{
        TOP--;
        return *(stack+TOP);
    }
}

void display(int* stack){
    printf("Stack elements are ");
    for(int i=0; i<=TOP; i++){
        printf("%d ", *(stack+i));
    }
    printf("\n");
}

int main(){
    printf("Enter the size of the stack: ");
    scanf("%d", &SIZE);

    int stack[SIZE];
    while(1){
        int opt;
        printf("1)PUSH\n2)POP\n3)EXIT\n");
        scanf("%d", &opt);

        switch(opt){
            case 1:
                printf("Enter an element to push ");
                int item;
                scanf("%d", &item);

                push(item, stack);
                display(stack);
                break;
            case 2:
                printf("Popped %d\n", pop(stack));
                display(stack);
                break;
            case 3:
                return 0;
                break;
            default:
                printf("Invalid operation\n");
        }
    }
    return 0;
}