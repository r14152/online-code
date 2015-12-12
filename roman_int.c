this program also from interview .com where change the roman letter in the integer ....

/**
 * @input A : String termination by '\0'
 * 
 * @Output Integer
 */
 int str(char c);
int romanToInt(char* A) {
    int len = strlen(A),i=0,sum=0,max=0,min=0;
    while(i<len)
    {
        if(A[i] == ' ')
        {
            if(sum != 0)
            return sum;
        }
        if(A[i] == A[i+1])
        {
            sum += str(A[i])+str(A[i+1]);
            i++;
        }
        else if(A[i] != A[i+1])
        {
             max = str(A[i+1]);
             min = str(A[i]);
             if(max>min)
             {
                 sum +=(max-min);
                 i++;
             }
             else
                 sum += str(A[i]);
             
        }
        else if(A[i+1] == '\0')
        {
            sum +=str(A[i]);
            i++;
        }
        i++;
    }
    return sum;
}

int str(char c)
{
    switch(c)
    {
        case 'I':
            return 1;
            break;
        case 'V':
            return 5;
            break;
        case 'X':
            return 10;
            break;
        case 'L':
            return 50;
            break;
        case 'C':
            return 100;
            break;
        case 'D':
            return 500;
            break;
        case 'M':
            return 1000;
        default:
            return 0;
        
    }
}
