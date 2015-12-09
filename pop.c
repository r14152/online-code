//pop the header element from the stack

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
