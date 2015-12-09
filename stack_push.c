//this is the code for put in the stack

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
