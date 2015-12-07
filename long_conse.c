//Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//link---https://www.interviewbit.com/courses/programming/topics/hashing/problems/conseq/
//without hashing
/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
 int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int longestConsecutive(const int* A, int n1) {
    int len,max=1,k=1,i=0,arr[n1];
    if(n1 == 0 || n1==1)
    return 1;
    for(i=0;i<n1;i++)
    {
        arr[i] = A[i];
    }
    qsort(arr,n1,sizeof(int),cmpfunc);
    for(i=0;i<n1;i++)
    {
        if(arr[i] != arr[i+1])
        if(arr[i+1]-arr[i] == 1)
        {
            k++;
        }
        else
        {
            if(k>max)
            {
                max = k;
                k=1;
            }
            k=1;
            
        }
    }
    return max;
}
