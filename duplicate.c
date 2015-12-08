//its also take the result of push and pop operation



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct link
{
  char data;
  struct link *next;
}stack;

char top(stack *head);
int show(stack *head);
int insert(stack **head,char data);
int pop(stack **head);

int main()
{
  stack *head;
  head = NULL;
  char str[]="careermonk";
  int index,len;
  len = strlen(str);
  for(index=0;index<len;index++)
    {
      if(str[index] == top(head))
	{
	  pop(&head);
	}
      else
	{
	  insert(&head,str[index]);
	}
    }
  show(head);
  return 0;
}

int show(stack *head)
{
  if(head == NULL)
    return 0;
  else
    {
      while(head != NULL)
	{
	  printf("%c->data);
	  head = head->next;
	}
      printf("\n");
    }
}
int insert(stack **head,char data)
{
  stack *temp,*start;
  start = *head;
  temp = (stack *)malloc(sizeof(stack));
  if(temp == NULL)
    return 0;
  else
    {
      temp->data = data;
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
  return 0;
}
char top(stack *head)
{
  if(head == NULL)
    return '\0';
  else
    {
      return head->data;
    }
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
      free(temp);
      temp = NULL;
      return 0;
    }
}
