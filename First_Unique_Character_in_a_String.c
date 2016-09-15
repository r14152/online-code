/* Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.

*/
//solution
int removeD(int *arr,int *ptr,int k,int size);
int firstUniqChar(char* s) {
    int arr[256]={0};
    int str[256]={0};
    int ptr[256]={0};
    int i=0,j=0;
    while(i<strlen(s))
    {
        int k = s[i]-'a';
        k = k+1;
        if(arr[k] == -1)
        {
            i++;
        }
        else if(arr[k] == 1)
        {
            arr[k] = -1;
            removeD(str,ptr,k,28);
            i++;
        }
        if(arr[k] ==0)
        {
            str[j]= i;
            ptr[j]=k;
            j++;
            arr[k] = 1;
            i++;
        }
    }
    for(i=0;i<27;i++)
    {
        if((ptr[i] !=0))
        {
            j = str[i];
            return j;
        }
        else
        {
            if(str[i] != 0)
                return str[i];
        }
    }
    return -1;
}
int removeD(int *ptr,int *arr,int k,int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(arr[i] == k)
        {
            arr[i] = 0;
            ptr[i] = 0;
            break;
        }
    }
    return 0;
}
