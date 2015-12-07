//Given an array, find the next greater element G[i] for every element A[i] in the array.
//The Next greater Element for an element A[i] is the first greater element on the right side of A[i] in array. 
//More formally,
//https://www.interviewbit.com/courses/programming/topics/stacks-and-queues/problems/nextgreater/
//Solution:
/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
 
 typedef struct link
 {
     int data;
     struct link *next;
 }list;
int* nextGreater(int* A, int n1, int *len1) {
    int i=0,max=0,*arr,j=0,k=0,flag = 1;
    list *head;
    arr = (int *)malloc(sizeof(int)*n1);
    for(i=0;i<n1;i++)
    {
        flag = 1;
        for(j=i;j<n1;j++)
        {
            if(A[j]>A[i])
            {
                arr[k] = A[j];
                //insert(&head,A[j]);
                k++;
                flag = 0;
                break;
            }
        }
            if(flag !=0)
            {
                arr[k] = -1;
                k++;
                
            }
        }
    //size = size_of_stack(head);
    //for(i=0;i<=k;i++)
    //{
      //  arr[j] = top(head);
        //pop(&head);
        //j++;
    //}
    *len1 = k;
    return arr;
}

int insert(list **head,int k)
{
    list *temp,*start;
    start = *head;
    temp = (list *)malloc(sizeof(list));
    if(temp == NULL)
    return 0;
    else
    {
        temp->data = k;
        temp->next = NULL;
    }
    if(start == NULL)
    {
        start = head;
        return 0;
    }
    else
    {
        temp->next = start;
        start = temp;
        return 0;
    }
}

int pop(list **head)
{
    int k;
    list *start,*temp;
    start = *head;
    if(start == NULL)
        return 0;
    else
    {
        k = start->data;
        temp = start;
        start = start->next;
        temp->next = NULL;
        free(temp);
    }
    
}

int top(list *head)
{
    if(head == NULL)
    return 0;
    else
    return head->data;
}

int size_of_stack(list *head)
{
    int k=0;
    while(head != NULL)
    {
        head = head->next;
        k++;
    }
    return k;
}
