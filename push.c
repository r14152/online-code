//this is the similar to stack for push

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
