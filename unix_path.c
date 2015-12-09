//very inportant unix path
/**
 * @input A : String termination by '\0'
 * 
 * @Output string. Make sure the string ends with null character
 */;
 
 typedef struct link
 {
     char data;
     struct link *next;
 }stack;
 int push(stack **head,char k);
 char top_stack(stack *head);
 char* simplifyPath(char* A) {
  stack *head;
  head = NULL;
  int len = strlen(A),i=0;
  char *arr;
  arr = (char *)malloc(sizeof(char)*len);
  while(i<len)
    {
      if(A[i] == '/')
	{
	  if(top_stack(head) == '/')
	  {
	    //pop(&head); 
	    ;
	  }
	  else
	    {
	      push(&head,A[i]);
	    }
	}
      else if(A[i] == '.')
	{
	  if(top_stack(head)=='/')
	    {
	      pop(&head);
	    }
	  else if(top_stack(head)>96 && top_stack(head)<123)
	    {
	      while(top_stack(head)>96 && top_stack(head)<123)
		{
		  pop(&head);
		}
	    }

	}
      else if(A[i]>96&&A[i]<123)
	{
	  push(&head,A[i]);
	}
      i++;
    }
    if(count(head) >1)
    {
        if(top_stack(head) == '/')
        pop(&head);
    }
    if(count(head) == 0)
    {
        push(&head,'/');
    }
  memset(arr,0,sizeof(arr));
  show(head,arr,len);
  strrev(arr);
  strcpy(A,arr);
  return A;
}
int count(stack *head)
{
    int k=0;
    if(head == NULL)
    return 0;
    else
    {
        while(head != NULL)
        {
            head = head->next;
            k++;
        }
        return k;
    }
}
int strrev(char *arr)
{
  int len = strlen(arr),i=0,j=0;
  char temp[len+1];
  memset(temp,0,sizeof(temp));
  i = len-1;
  j=0;
  while(i>=0)
    {
      temp[j] = arr[i];
      i--;
      j++;
    }
  strcpy(arr,temp);
}
int pop(stack **head)
{
  stack *start,*temp;;
  start = *head;
  if(head == NULL)
    return 0;
  else
    {
      temp = start;
      start = temp->next;
      *head = start;
      //free(temp);
      temp = NULL;
      return 0;
    }
}
int push(stack **head,char k)
{
  stack *temp,*start;
  start = *head;
  temp = (stack *)malloc(sizeof(stack));
  if(temp == NULL)
    return 0;
  else
    {
      temp->data = k;
      temp->next = NULL;
    }
  if(start == NULL)
    {
      *head = temp;
      return 0;
    }
  else
    {
      temp->next = start;
      start = temp;
      *head = start;
      return 0;
    }
}

char top_stack(stack *head)
{
  if(head == NULL)
    return '\0';
  else
    return head->data;
}

int show(stack *head,char *str,int len)
{
  int i=0;
  while(head != NULL)
    {
      //printf("%c ",head->data);
      str[i] = head->data;
      head = head->next;
      i++;
    }
}
