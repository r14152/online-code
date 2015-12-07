#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
          unsigned int t,f_len,s_len,hash[26],f_index,s_index,k,i=0,j=0,flag=0;
            char str[100000],ptr[100000],f_str[100000],s_str[100000];
            scanf("%u",&t);
      while(j<t)
    {
        scanf("%s %s",str,ptr);
        f_len = strlen(str);
        s_len =strlen(ptr);
        if(f_len>s_len)
        {
            strcpy(f_str,str);
            strcpy(s_str,ptr);
            f_index = f_len;
            s_index = s_len;
        }
        else
        {
         strcpy(f_str,ptr);
        strcpy(s_str,str);
        f_index =s_len;
        s_index =f_len;   
        }
        memset(hash,0,sizeof(hash));
        for(i=0;i<f_index;i++)
        {
            k = f_str[i];
            if(k<97)
            k = k-65;
            else
            k = k-97;
            if(hash[k] == 0)
            {
             hash[k] = 1;   
            }
        }
        for(i=0;i<s_index;i++)
        {
            k = s_str[i];
            if(k<97)
            k = k-65;
            else
             k = k-97;
            if(hash[k] == 1)
            {
                flag = 1;
                printf("YES\n");
                break;
            }
      }
        if(flag != 1)
        printf("NO\n");
        j++;
        flag = 0;
      }  
                    
    return 0;
}
