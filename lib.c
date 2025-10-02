#include<stdio.h>
struct library{
    char title[50];
    int id;
    int freq;
};
void inputbook(struct library l[],int *p){
    int a;
    printf("enter book id\n");
    scanf("%d",&a);
    for(int i=0;i<*p;i++)
    {
        if (a==l[i].id)
        {
            printf("book already in the list\n");
            return ;
        }
        
    }
    printf("enter book title\n");
    scanf("%s",l[*p].title);
    l[*p].id=a;
    l[*p].freq=0;
    (*p)++;
    return;
}
void sort(struct library l[],int *p){
    int t=0;
    for (int i = 0; i < (*p)-1; i++)
    {
        for (int j = 0; j < (*p)-i-1; j++)
        {   t++;
            if (l[j].id>l[j+1].id)
            {
                struct library a=l[j];
                l[j]=l[j+1];
                l[j+1]=a;
            } 
        } 
    }printf("time complexity of bubble sort= %d\n",t);
}
int search(struct library l[],int *p,int sid,int *c){
    sort(l,p);int t=0;
    int low=0,high=(*p)-1;
    while (low<=high)
    {   t++;
        int mid=(low+high)/2;
        if (sid>l[mid].id)
        {   (*c)++;
            low=mid+1;
        }
        else if (sid<l[mid].id)
        {   (*c)++;
            high=mid-1;
        }else
        {   printf("time complexity of binary search= %d\n",t);
            return mid;
        }
    }
    printf("time complexity= %d\n",t);
    printf("book not found\n");
   return -1; 
}
void topfreq(struct library l[],int *p){
    struct library arr[*p];
    for (int i = 0; i < *p; i++)
    {
        arr[i]=l[i];
    }
    
    for (int i = 0; i < (*p)-1; i++)
    {
        for (int j = 0; j < (*p)-i-1; j++)
        {
            if (arr[j].freq<arr[j+1].freq)
            {
                struct library a=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=a;
            }
            
        }
        
    }
     printf("SI.NO\tID\tTITLE\tTIMES SEARCHED\n");
           for (int i = 0; i < 3; i++)
           {
                printf("%d.\t%d\t%s\t%d\n",i+1,arr[i].id,arr[i].title,arr[i].freq);
           }
}
int main(){
    int x, count=0,*p=&count;
    struct library l[100];
    printf("-------welcome to shibis library-------\n");
    while (1)
    {
        printf("enter your choice:\n1.insert new book\n2.display sorted book list\n3.find a book\n4.display trending list\n5.exit\n");
        scanf("%d",&x);
        switch (x)
        {
        case 1:
            inputbook(l,p);
            break;
        case 2:
            sort(l,p);
            printf("BOOK LIST\n");
            for (int i = 0; i < count; i++)
            {
                printf("%d. %d %s\n",i+1,l[i].id,l[i].title);
            }
            
            break;
        case 3:
            int sid,comp=0,*c=&comp;
            printf("enter id of book to be searched: ");
            scanf("%d",&sid);
            int index= search(l,p,sid,c);
            if(index>=0){
            l[index].freq++;
            printf("%s found at index %d\nno. of comparisons=%d\n",l[index].title,index,comp);}
            break;
        case 4:
        topfreq(l,p);
            break;
        case 5:
            return 0;
        default:
            break;
        }
    }
    
return 0;
}