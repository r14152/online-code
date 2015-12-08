//this problem is very much pretty becouse in this problem if the number alreaddy in the list then send the index of the
//data otherwise return the index where er indsert the given data in the array
// so for this problem i used binary search for solving this problem

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer
 */
int searchInsert(int* A, int n1, int B) {
    int mid,min = 0,max=n1;
    
    while(1)
    {
        mid = (min +max)/2;
        if(min>max||min==max)
        {
            return min;
        }
        else if(A[mid] == B)
        {
            return mid;
        }
        else if(B>A[mid-1] && B <A[mid])
        {
            return mid;
        }
        else if(A[mid] > B)
        {
            max = mid-1;
        }
        else if(A[mid] < B)
        {
            min = mid+1;
        }
        
    }
}
