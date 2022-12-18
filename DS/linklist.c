#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* root = NULL;
int len;

void append(void);
int length(void);
void display(void);
void insertion(void);
void update(void);
void deletion(void);
int search(void);

void main()
{

    int ch, loc=-1;
    while(1){
        printf("Single linked list operation: \n");
        printf("1.Append\n");
        printf("2.Length\n");
        printf("3.Display\n");
        printf("4.Insertion\n");
        printf("5.Update\n");
        printf("6.Deletion\n");
        printf("7.Search\n");
        printf("8.Quit\n");

        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 : append();
                    break;
            case 2: len = length();
                    printf("\nlength: %d\n",len);
                    break;
            case 3: display();
                    break;
            case 4: insertion();
                    break;
            case 5: update();
                    break;
            case 6: deletion();
                    break;
            case 7: loc = search();
                    if(loc==-1){
                        printf("Data not found\n");
                    }
                    else{
                        printf("Data found and its location is %d\n",loc);
                    }
                    break;
            case 8: exit(1);

            default : printf("Invalid Input\n\n");

        }
    }
}
void append(){
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter node data: ");
    scanf("%d",&temp->data);
    temp->link = NULL;

    if(root == NULL){
        root = temp;
    }
    else{
        struct node* p;
        p = root;

        while(p->link != NULL){
           p =  p->link;
        }
        p->link = temp;
    }

}

int length(){
    int count = 0;
    struct node* temp;
    temp = root;

    while(temp != NULL){
        count++ ;
        temp = temp->link;
    }
    return count;

}

void display(){
    struct node* temp;
    temp = root;
    if(temp == NULL){
        printf(" List is empty\n");
    }
    else{
        while(temp != NULL){
            printf("%d-->",temp->data);
            temp = temp->link;
        }
        printf("\n\n");
    }
}

void insertion(){
    struct node* temp;
    struct node* p = root;
    int loc, i = 0;
    printf("\nEnter the location: ");
    scanf("%d",&loc);
    len = length();
    if(loc>len){
        printf("Invalid location\n");
    }
    else{
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter node data: ");
        scanf("%d",&temp->data);
        if(loc==0){
            root = temp;
            temp->link = p;
        }
        else{
            while(i < loc-1){
                p = p->link;
                i++;
            }
            temp->link = p->link;
            p->link = temp;
        }
    }
}

void update(){
    struct node* p = root;
    int loc, i = 0;
    printf("\nEnter the location: ");
    scanf("%d",&loc);
    len = length();
    if(loc>len){
        printf("Invalid location\n");
    }
    else{
        while(i < loc){
            p = p->link;
            i++;
        }
        printf("Enter node data: ");
        scanf("%d",&p->data);
    }
}
void deletion(){
    struct node* temp;
    int loc;

    printf("Enter location to delete: ");
    scanf("%d",&loc);

    if(loc > length()){
        printf("Invalid location\n");
    }
    else if(loc==0){
        temp = root;
        root = temp->link;
        temp->link = NULL;
        free(temp);
    }
    else{
      struct node* p = root, *q;
      int i = 0;
      while(i < loc - 1){
        p = p->link;
        i++;
      }
      q = p->link;
      p->link = q->link;
      free(q);

    }
}
int search(){
    struct node* p = root;
    int data,loc = -1,i = 0;

    printf("\nEnter the data: ");
    scanf("%d",&data);

    while(p!=NULL){
        if(data==p->data)
            return i+1;
        p=p->link;
        i++;
    }
    return loc;
}
