INPUT 1 2 3 4 5 
OUTPUT 3 2 4 1 5
INPUT 1 2 3 4 5 6
OUTPUT 3 4 2 5 1 6


code:
#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;//pointing head to null
void append(int x)
{
    struct node *temp,*r;
    temp=(struct node *)malloc(sizeof(struct node));//creating temp node
    temp->data=x;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL)// for 1st element to insert
    {
        head=temp;//pointing head to temp
    }
    else//other than 1st element
    {
        r=head;//pointing r to head
        while(r->next!=NULL)//travesing till the last node
        r=r->next;
        r->next=temp;//making forward connection between last node and newly created temp node
        temp->prev=r;//making backward connection between last node and newly created temp node
        
    }
    
}
void display(int n)
{
    struct node *f,*s,*temp;
    f=head;
    s=head;
    while(f->next!=NULL && f->next->next!=NULL)//to find mid location we use this loop
    {
        f=f->next->next;//making fast to travese two node a head
        s=s->next;//making slow to travese one node a head
    }
    temp=s;//pointing temp to mid node
    if(n%2!=0)//if list is odd
    {
    while(s->next!=NULL )
    {
        
        printf("%d ",s->data);//printing mid value
        temp=temp->prev;//travesing left
        s=s->next;//travesing right
        printf("%d ",temp->data);//printing left data
        
        
        
    }
    printf("%d",s->data);//printing last data
    }
    else//if list is even
    {
        printf("%d ",s->data);//printing mid value
        s=s->next;//travesing right
        while(s->next!=NULL )//same as above while loop
    {
        
        printf("%d ",s->data);
        temp=temp->prev;
        s=s->next;
        
        printf("%d ",temp->data);
        
        
        
    }
    printf("%d",s->data);
        
    }
}

int main()
{
    
    int n,i,x;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        append(x);
    }
    display(n);

    return 0;
}
