#include<stdio.h>
#define size 5
int queue[size],cqueue[size];
int front=-1,cfront=-1;
int rear=-1,crear=-1;
void enqueue(){
    int n;
    printf("enter element to enqueue\n");
    scanf("%d",&n);
    if (rear==size-1)
        printf("queue overflow\n");
    else if(front==-1){
        front++;
        queue[++rear]=n;
        printf("%d enqueued\n",n);
    }else{
        queue[++rear]=n;
        printf("%d enqueued\n",n);}
} 
void cenqueue(){
    int n;
    printf("enter element to enqueue\n");
    scanf("%d",&n);
    if (cfront==(crear+1)%size)
        printf("queue overflow\n");
    else if(cfront==-1){
        cfront++;
        cqueue[++crear]=n;
        printf("%d enqueued\n",n);
    }else{
        crear=(crear+1)%size;
        cqueue[crear]=n;
        printf("%d enqueued\n",n);}
}
void dequeue(){
    if(front==-1)
        printf("queue underflow\n");
    else{
        int n=queue[front];
        if(front==rear)
            front=rear= -1;
        else
            front++;
     printf("%d dequeued\n",n);   
    }}
void cdequeue(){
    if(cfront==-1)
        printf("queue underflow\n");
    else{
        int n=cqueue[cfront];
        if(cfront==crear)
            cfront=crear= -1;
        else
            cfront=(cfront+1)%size;
     printf("%d dequeued\n",n);   
    }

}
int main(){
    int c,c2;
    printf("BUFFER MANAGEMENT SYSTEM\n");
    while (1)
    {
        printf("enter your choice\n1. QUEUE\n2. CIRCULAR QUEUE\n3. DEQUE\n4. EXIT\n");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            printf("enter your choice\n1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY QUEUE\n");
             scanf("%d",&c2);
            switch (c2)
            {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                for (int i = front; i <= rear; i++)
                {
                    printf("%d ",queue[i]);
                }
                
                break;
            default:
                break;
            }
            break;
        case 2:
            printf("enter your choice\n1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY CIRCULAR QUEUE\n");
             scanf("%d",&c2);
            switch (c2)
            {
            case 1:
                cenqueue();
                break;
            case 2:
                cdequeue();
                break;
            case 3:
                for (int i = 0; i < size; i++)
                {
                    printf("%d ",cqueue[i]);
                }
                
                break;
            default:
                break;
            }
           
            break;
        case 3:
           
            break;
        case 4:
            return 0;
        default:
            break;
        }
    }
    

return 0;
}