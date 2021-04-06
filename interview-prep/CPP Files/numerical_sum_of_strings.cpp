#include<bits/stdc++.h>
using namespace std;

string addStrings(string num1, string num2) {
        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());
        int n=num1.size(),m=num2.size();
        int carry=0;
        int n1=0,n2=0;
        string ans="";
        int i=0,j=0;
        while(i<n || j<m)
        {
            if(i<n) { n1 = num1[i]-'0' ; i++;}
            if(j<m) { n2 = num2[j]-'0' ; j++;}
            ans = char( (n1+n2+carry)%10  + '0' ) + ans;
            carry = (n1+n2+carry)/10;
            if(i<n || j<m) {
                 
            }else if(carry>0){
                ans =  char( (carry)%10  + '0' ) + ans;
            }
            n1=0,n2=0;
        }
        return ans;
}