#include<stdio.h>
#include<stdlib.h>
struct Q {
    int size;
    int f;
    int r;
    int *A;
    
};
void create(struct Q *q)
{
    printf("Enter the size\n");
    scanf("%d",&q->size);
    q->A=malloc(sizeof(int)*q->size);
     q->f = 0;
    q->r = -1;
}
void insert(struct Q *q, int data) {
    if (q->r == q->size - 1) {
        printf("Q Overflow\n");
        return;
    }
    int i;
    for (i = q->r; i >= q->f; i--)
    {
        
        if(q->A[i]>data)
        {
             q->A[i+1]=q->A[i];
            q->A[i]=data;
        }
           
       else
          break;
    }
    if(q->r==-1)
         q->A[++q->r]=data;
    else
       {
           q->A[i+1]=data;
           q->r++;
       }
   
}
int delete(struct Q *q) {
    if (q->f > q->r) {
        printf("Q Underflow\n");
        return 0;
    }
    return q->A[q->f++];
}

void display(struct Q *q) {
    int i;
    for (i = q->f; i <= q->r; i++) {
        printf("%d ", q->A[i]);
    }
    printf("\n");
}
int main() {
    struct Q *q=malloc(sizeof(struct Q));
   
    int x,choice, data;
    while(1) {
        printf("0.Create\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 0:create(q);
                   break;
            case 1: printf("\nEnter data  ");
                    scanf("%d", &data);
                    insert(q, data);
                    break;
            case 2: printf("Deleted data: %d\n", delete(q));
                    break;
            case 3: display(q);
                    break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
                     break;
        }
    }
    return 0;
}
