#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//This code creates a linked list and fills it with random numbers. Then, it prompts the user to enter a number and finds the position of that number in the list.

void scan();
void insert();
void print();
void insertAfter(int newData, int afterData);
void insertAtBeginning(int data);
void insertAtEnd(int data);

struct node;
struct node* Start;
struct node* createNewNode(int data);

int main()
{
    insert();
    print();
    scan();

    return 0;
}

struct node {
    int data;
    struct node* next;
};

struct node* createNewNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(int data){
    struct node* newNode = createNewNode(data);
    if(Start == NULL){
        Start = newNode;
    }
    else{
        struct node* temp = Start;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtBeginning(int data){
    struct node* newNode = createNewNode(data);
    if(Start == NULL){
        Start = newNode;
    }
    else{
        struct node* temp = Start;
        Start = newNode;
        Start->next = temp;
    }
}

void insertAfter(int newData, int afterData){
    struct node* newNode = createNewNode(newData);
    if(Start == NULL)
        insertAtBeginning(newData);
    else{
        struct node* temp = Start;
        while(temp->data != afterData){
            temp = temp->next;
        }
        if(temp->next == NULL)
            insertAtEnd(newData);
        else{
            struct node* nextNode = temp->next;
            temp->next = newNode;
            newNode->next = nextNode;
        }
    }
}

void print(){
    struct node* temp = Start;
    while(temp != NULL){
        printf(" %d ", temp->data);
        temp = temp->next;
    }
}

void insert(){
    srand(time(NULL));
    for(int i = 0; i < 98; i++){
        insertAtBeginning(rand() % 1000);
    }
}

void scan(){
    printf("\nPlease enter the element you are looking for:\n");
    int searchedElement;
    int counter = 0;
    scanf("%d", &searchedElement);
    struct node* temp = Start;
    while(temp->data != searchedElement){
        temp = temp->next;
        counter++;
    }
    if(temp->data == searchedElement){
        printf("\nThe searched element is the %dth element.", counter + 1);
    }
}
