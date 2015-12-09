//this is also interview problem in this problem i stuck for the given poin twheree one place i use == in the malloc for this the 
//memory is not located by me but its also very good quesion

///**
 * @input A : String termination by '\0'
 * 
 * @Output Integer
 */
typedef struct link
{
    char data;
    struct link *next;
}list;
char top_stack(list *head);

int isValid(char* A) {
  list *head;
  head = NULL;
  int len = strlen(A),i=0;
  while(i<len)
    {
      if(A[i] == '(' || A[i] == '[' || A[i] == '{')
	{
	  push(&head,A[i]);
	}
      else if(A[i] == ')')
	{
	  if(top_stack(head) == '(')
	    pop(&head);
	  else
	    return 0;
	}
      else if(A[i] =='}')
	{
	  if(top_stack(head) == '{')
	    {
	      pop(&head);
	    }
	  else
	    {
	      return 0;
	    }
	}
      else if(A[i] == ']')
	{
	  if(top_stack(head) == '[')
	    {
	      pop(&head);
	    }
	  else
	    {
	      return 0;
	    }
	}
      i++;
    }
  if(check_stack(head) == 0)
    return 1;
  else
    return 0;
}


int push(list **head,int value)
{
  list *start,*temp;
  start = *head;
  temp = (list *)malloc(sizeof(list));
  if(temp == NULL)
    return 0;
  else
    {
      temp->data = value;
      temp->next = NULL;
      if(start == NULL)
	{
	  *head = temp;
	  return 0;
	}
      else
	{
	  temp->next = start;
	  *head = temp;
	  return 0;
	}
    }
}

char top_stack(list *head)
{
  if(head == NULL)
    return '\0';
  else
    return head->data;
}

int check_stack(list *head)
{
  if(head == NULL)
    return 0;
  else
    return 1;
}
int pop(list **head)
{
  list *start,*temp;;
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
