
/*Floyd's Cycle-Finding Algorithm*/
/*  Time Complexity = O(n)
    Space Complexity = O(n) ----->

    dist covered by fast pointer =2*(x+y)
    dist covered by slow pointer = x+y
            where x = dist from head to start node of a cycle and  y = dist from start node and the node where they meet in cycle

    2(x+y) = x+ kL + y
    => x+y = kL + (L -L)
    => x = (k-1)*L +(L-y)
       */
/*using 2 pointers*/
#include <bits/stdc++.h>
using namespace std;

/*dynamic allocation of node*/
typedef struct node
{
    int data;
    struct node *next;
}List;

/*insert function*/

List* insert(List* head)
{
    printf("\nEnter data to be inserted\n");
    int key;
    scanf("%d",&key);
    List* new_node = (List*)malloc(sizeof(List));
    /*allocating new_node tpo insert new node to insert
    abd tmp pointer to use it as transvering*/

    new_node->data = key;/*assigning data value in node*/
    new_node->next = NULL;/*assigning next of new_node to null*/

    if(head==NULL){
        head = new_node;
    } else
    {
        List *tmp = head;/*initially tmp points to head*/
        while(tmp->next!=NULL){
            tmp=tmp->next;
        }
        tmp->next=new_node;

    }
return head;
}

bool detectLoop(List* head)
{
    List *s,*f;/*s = slow pointer, f = fast pointer*/;
    s=head,f=head;
    if(head->next==NULL) return 0;
    /*assume there are more than 3 nodes*/
    while(s&&f&&f->next)
    {
        s = s->next;
        f = f->next->next;
        if(s==f) {
            cout<<"Loop at node"<<s<<endl;
            return 1;
        }
    }
    return 0;
}

List* startnode(List* head)
{
     List *s,*f;/*s = slow pointer, f = fast pointer*/;
    s=head,f=head;

    int flag =0;
    for(s =head,f = head;s&&f&&f->next; s=s->next,f = f->next->next)
    {

        if(s==f){
            flag = 1;
            break;
        }
    }
    s = head;
    for(s=head;s!=f; s=s->next,f=f->next)
    {
        if(s==f)
            return s;
    }
}

/*printing linked List*/
void display(List* t)
{
    /*t as head here is transversed so that we can print all the data*/
    while(t!=NULL){
        printf("%d\t",(t->data));
        t=t->next;
    }
}

int main()
{
     List *head = NULL;

    cout<<"Enter no of elements in SLL\n";
    int n,k;
    cin>>n;
    while(n>0)
    {
        head = insert(head);
        n--;
    }
    /*MAKE A LOOP FOR TESTING*/
    head->next->next = head->next;
    /*Find start node of cycle if it exists*/
    int b = detectLoop(head);
    if (b)
        {cout << "\tLoop found\n";
        cout << startnode(head)<<" is the start node of cycle\n";}
    else
        cout << "No Loop";

    return 0;
}
