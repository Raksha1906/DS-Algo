//Program to add two polynomials using Linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coeff,exp;
    struct node* next;
};

struct node* insert(struct node* thead,int c,int e);
struct node* append(struct node* thead,int c,int e);
struct node* add(struct node* p1thead,struct node* p2thead);
void display(struct node* thead);

int main()
{
    int a,b,n,i;
    struct node* p1head,* p2head,* p3head;
    p1head=p2head=NULL;

    // Inputing the first polynomial

    printf("Enter the no of terms of polynomial 1: ");
    scanf("%d",&n);
    printf("\nEnter the polynomial: ");
    for(i=0;i<n;i++){
        printf("\nEnter the coeffficient and expnent of the term: ");
        scanf("%d%d",&a,&b);
        p1head=insert(p1head,a,b);
    }

    // Inputing the second polynomial

    printf("\nEnter the no of terms of polynomial 2: ");
    scanf("%d",&n);
    printf("\nEnter the polynomial: ");
    for(i=0;i<n;i++){
        printf("\nEnter the coeffficient and expnent of the term: ");
        scanf("%d%d",&a,&b);
        p2head=insert(p2head,a,b);
    }

    //Performing Addition

    p3head=add(p1head,p2head);

    //Displaying the polynomial

    printf("\nThe polynomial 1 is: ");
    display(p1head);
    printf("\nThe polynomial 2 is: ");
    display(p2head);
    printf("\nThe sum of the two polynomials is: ");
    display(p3head);
    return 0;
}

struct node* append(struct node* thead,int c,int e)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->coeff=c;
    newnode->exp=e;
    if(thead==NULL){// Corner Case to handle if the list is empty
    newnode->next=NULL;
    return newnode;
    }
    struct node* trav=thead;
    while(trav->next!=NULL) // Traversing to point to the last node
        trav=trav->next;
    trav->next=newnode;
    newnode->next=NULL;
    return thead;
}

struct node* insert(struct node* thead,int c,int e)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coeff=c;
    newnode->exp=e;
    if(thead==NULL){            // for inserting the first node..
        newnode->next=NULL;
        return newnode;
    }
    struct node* prev,* curr;
    prev=curr=thead;
    while(curr!=NULL && curr->exp>e){
        prev=curr;
        curr=curr->next;
    }
    if(curr==thead){            // for inserting before the first node
        newnode->next=curr;
        return newnode;
    }
    else if(curr==NULL){        //for inserting after the last node
        prev->next=newnode;
        newnode->next=NULL;
    }
    else{
        newnode->next=curr;
        prev->next=newnode;
    }
    return thead;
}

struct node* add(struct node* p1thead,struct node* p2thead)
{
    struct node* ans=NULL;
    struct node* t1,* t2;
    t1=p1thead;
    t2=p2thead;
    while(t1!=NULL && t2!=NULL){
        if(t1->exp > t2->exp){
            ans=append(ans,t1->coeff,t1->exp);
            t1=t1->next;
        }
        else if(t1->exp < t2->exp){
            ans=append(ans,t2->coeff,t2->exp);
            t2=t2->next;
        }
        else{
            ans=append(ans,(t1->coeff)+(t2->coeff),t1->exp);
            t1=t1->next;
            t2=t2->next;
        }
    }

    while(t1!=NULL){            //coping the remaining terms of polynomial 1...
        ans=append(ans,t1->coeff,t1->exp);
        t1=t1->next;
    }

    while(t2!=NULL){            //coping the remaining terms of polynomial 2...
        ans=append(ans,t2->coeff,t2->exp);
        t2=t2->next;
    }
    return ans;
}

void display(struct node* thead)
{
    struct node* temp=thead;
    if(temp==NULL){
        printf("\nEmpty!");
    }
    else{
        while(temp->next!=NULL){
            printf(" %dx^%d +",temp->coeff,temp->exp);
            temp=temp->next;
        }
       printf(" %dx^%d ",temp->coeff,temp->exp);
    }
}

