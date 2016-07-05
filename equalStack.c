//this program is solution of hackerank 
//i solve this program in linear and in c++
//link of file is : https://www.hackerrank.com/challenges/equal-stacks

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int summatIon(vector <int>data)
{
    int sum=0,i=0;
    while(i != data.size())
    {
        sum += data[i];
        i++;
    }
    return sum;
}

int main(){
    int n1;
    int n2;
    int n3;
    cin >> n1 >> n2 >> n3;
    vector<int> h1(n1);
    for(int h1_i = 0;h1_i < n1;h1_i++){
       cin >> h1[h1_i];
       // cout  << h1[h1_i] << endl;
    }
    vector<int> h2(n2);
    for(int h2_i = 0;h2_i < n2;h2_i++){
       cin >> h2[h2_i];
    }
    vector<int> h3(n3);
    for(int h3_i = 0;h3_i < n3;h3_i++){
       cin >> h3[h3_i];
    }
    
   
    
    while(!h1.empty() && !h2.empty() && !h3.empty())
        {
             int sum1 = summatIon(h1);
             int sum2 = summatIon(h2);    //this function is use to add the vector element and return the value in the sum1;
             int sum3 = summatIon(h3);
             if(sum1==0 || sum2==0 ||sum3==0)
                {
                   cout  << 0 << endl;
                    return 0;
                 }
        if(sum1 == sum2 && sum1 == sum3 && sum2 == sum3)
            {
            //cout <<"is it u" << sum1 << "   " << sum2 << "  "<< sum3 << endl;
            cout << sum1<<endl;
            return 0;
        }
                if(sum1>sum2 && sum1 > sum3 )
                    {
                    if(sum2 > sum3)
                        {
                            h1.erase(h1.begin());
                            h2.erase(h2.begin());
                        }
                    else if(sum2 == sum3)
                        {
                            h1.erase(h1.begin());
                        }
                    else{
                        h1.erase(h1.begin());
                        h3.erase(h3.begin());
                    }
                    
                }
            else if(sum2>sum1 && sum2>sum3)
                {
                if(sum1>sum3)
                {
                    h2.erase(h2.begin());
                    h1.erase(h1.begin());
                }
                else if(sum1 == sum3)
                    {
                    h2.erase(h2.begin());
                }
                else{
                    h2.erase(h2.begin());
                    h3.erase(h3.begin());
                }
            }
        else {
            if(sum1>sum2)
                {
                h3.erase(h3.begin());
                h1.erase(h1.begin());
            }
            else if(sum1 == sum2)
                {
                h3.erase(h3.begin());
            }
            else{
                h3.erase(h3.begin());
                h2.erase(h2.begin());
            }
        }
        }
    if(h1.empty() || h2.empty() || h3.empty())
        cout << 0 <<endl;
    return 0;
}
