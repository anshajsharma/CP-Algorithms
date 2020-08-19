<h1 align="center">
    CP Algorithms
 </h1>
 <h5 align="center">
   Author: Anshaj Kumar
 </h5>
 
 
 ### Contents  
 
| No. | Topics |
| --- | --------- |
|    | [*Special Notes*](#special-notes-) |
|    | **Dyamic Programming** |
|1   | [Matrix Chain Multiplication](#matrix-chain-multiplication) |
|2   | [Longest Palindromic Subsequence](#longest-palindromic-subsequence) |
|3   | [Longest Common Subsequence](#longest-common-subsequence) |
|4   | [Longest Common Substring](#longest-common-substring) |
|5   | [Edit Operations](#edit-operations) |
|6   | [Longest Increasing Subsequence](#longest-increasing-subsequence) |
|7   | [Subsequence and Subarray Sum](#subsequence-and-subarray-sum) |
|8   | [Coin Change Problem](#coin-change-problem) |


##  Matrix Chain Multiplication

```C++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define loop(i,n)    for(int i = 0; x < n; i++)
#define fr(i,j,n)   for(ll i=j;i<n;i++)
#define tc           ll t1; cin>>t1; while(t1--)
#define inp          ll n; cin>>n; ll a[n]; fr(i,0,n) cin>>a[i];
#define inp1         ll n1; cin>>n1; ll a[n1]; fr(i,0,n1) cin>>a[i];
#define vec          vector<ll>
#define pb           push_back
#define pii          pair<ll,ll>
#define mp           make_pair
#define F            first
#define S            second
#define fast         ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define scn(n)       scanf("%lld",&n)
#define lscn(n)      scanf("%lld",&n)
#define lpri(n)      printf("%lld",n)
#define pri(n)       printf("%d",n)
#define pln()        printf("\n")
#define priln(n)     printf("%d\n",n)
#define lpriln(n)    printf("%lld\n",n)
#define srt(v)       sort(v.begin(),v.end())
#define srte(v)      sort(v.rbegin(),v.rend())
#define maxx         1000005
#define lb(v,n)        lower_bound(v.begin(),v.end(),n)-v.begin()
#define ub(v,n)        upper_bound(v.begin(),v.end(),n)-v.begin()
#define inf          LONG_MAX
#define zer          LONG_MIN
const long mod=pow(10,9)+7;

ll matrixMultiplication()
{
  ll n;
  cin>>n;
  std::vector<pii> v;

  fr(i,0,n)
  {
    ll a,b; cin>>a>>b;
    v.pb(mp(a,b));
  }

  ll dp[n][n];

  fr(i,0,n) fr(j,0,n) dp[i][j]=INT_MAX;

  fr(i,0,n) dp[i][i]=0;

  fr(i,0,n)
  fr(j,i+1,n)
  fr(k,i,j)
  {
    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+v[i].F*v[k].S*v[j].S);
  }

  return dp[0][n-1];


}

int main()
{
    // fast;
    #ifndef ONLINE_JUDGE
    freopen("inputf.in" , "r" , stdin);
    freopen("outputf.in" , "w" , stdout);
    #endif

    cout<<matrixMultiplication();

    
   
    

    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
    return 0;
}

// Time Complexicity : O(n^3)
// Space Complexicity : O(n^2)

//Example
// Input         Output
// 5             70
// 1 2 
// 2 4
// 4 5
// 5 6
// 6 2
```
**[⬆ Back to Top](#----cp-algorithms-)** 


##  Longest Palindromic Subsequence

```C++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define loop(i,n)    for(int i = 0; x < n; i++)
#define fr(i,j,n)   for(ll i=j;i<n;i++)
#define tc           ll t1; cin>>t1; while(t1--)
#define inp          ll n; cin>>n; ll a[n]; fr(i,0,n) cin>>a[i];
#define inp1         ll n1; cin>>n1; ll a[n1]; fr(i,0,n1) cin>>a[i];
#define vec          vector<ll>
#define pb           push_back
#define pii          pair<ll,ll>
#define mp           make_pair
#define F            first
#define S            second
#define fast         ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define scn(n)       scanf("%lld",&n)
#define lscn(n)      scanf("%lld",&n)
#define lpri(n)      printf("%lld",n)
#define pri(n)       printf("%d",n)
#define pln()        printf("\n")
#define priln(n)     printf("%d\n",n)
#define lpriln(n)    printf("%lld\n",n)
#define srt(v)       sort(v.begin(),v.end())
#define srte(v)      sort(v.rbegin(),v.rend())
#define maxx         1000005
#define lb(v,n)        lower_bound(v.begin(),v.end(),n)-v.begin()
#define ub(v,n)        upper_bound(v.begin(),v.end(),n)-v.begin()
#define inf          LONG_MAX
#define zer          LONG_MIN
const long mod=pow(10,9)+7;

int longestPalindromicSubsequence(string s){
    int dp[s.size()][s.size()];
    for(int i = 0 ; i < s.size(); i++){
        dp[i][i] = 1;
    }
    for(int l = 1 ; l < s.size() ; l++){
        int i = 0, j = l;
        while(j != s.size()){
            if(s[i] == s[j]){
                dp[i][j] = 2 + dp[i+1][j-1];
            }
            else{
                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
            i++;j++;
        }
    }
    return dp[0][s.size()-1];
}

int main()
{
    // fast;
    #ifndef ONLINE_JUDGE
    freopen("inputf.in" , "r" , stdin);
    freopen("outputf.in" , "w" , stdout);
    #endif

    string s;
    cin>>s;

    cout<<longestPalindromicSubsequence(s);

    

    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
    return 0;
}
// Time Complexicity : O(n^2)
// Space Complexicity : O(n^2)
//Example
// Input         Output
// asdfa           3
// iuabtsucsyftg   5
```

**[⬆ Back to Top](#----cp-algorithms-)** 

##  Longest Common Subsequence

```C++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define loop(i,n)    for(int i = 0; x < n; i++)
#define fr(i,j,n)   for(ll i=j;i<n;i++)
#define tc           ll t1; cin>>t1; while(t1--)
#define inp          ll n; cin>>n; ll a[n]; fr(i,0,n) cin>>a[i];
#define inp1         ll n1; cin>>n1; ll a[n1]; fr(i,0,n1) cin>>a[i];
#define vec          vector<ll>
#define pb           push_back
#define pii          pair<ll,ll>
#define mp           make_pair
#define F            first
#define S            second
#define fast         ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define scn(n)       scanf("%lld",&n)
#define lscn(n)      scanf("%lld",&n)
#define lpri(n)      printf("%lld",n)
#define pri(n)       printf("%d",n)
#define pln()        printf("\n")
#define priln(n)     printf("%d\n",n)
#define lpriln(n)    printf("%lld\n",n)
#define srt(v)       sort(v.begin(),v.end())
#define srte(v)      sort(v.rbegin(),v.rend())
#define maxx         1000005
#define lb(v,n)        lower_bound(v.begin(),v.end(),n)-v.begin()
#define ub(v,n)        upper_bound(v.begin(),v.end(),n)-v.begin()
#define inf          LONG_MAX
#define zer          LONG_MIN
const long mod=pow(10,9)+7;

int longestCommonSubsequence(string x,string y){
    int m = x.size(),n = y.size();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        dp[i][0] = 0;
    }
    for(int j=0;j<=m;j++){
        dp[0][j] = 0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[m][n];
}

int main()
{
    // fast;
    #ifndef ONLINE_JUDGE
    freopen("inputf.in" , "r" , stdin);
    freopen("outputf.in" , "w" , stdout);
    #endif

    string s1,s2;
    cin>>s1>>s2;

    cout<<longestCommonSubsequence(s1,s2);

    

    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
    return 0;
}
// Time Complexicity : O(n*m)
// Space Complexicity : O(n*m)
// Example
// Input            Output
// anshaj anuj        3
```

**[⬆ Back to Top](#----cp-algorithms-)** 


##  Longest Common Substring

```C++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define loop(i,n)    for(int i = 0; x < n; i++)
#define fr(i,j,n)   for(ll i=j;i<n;i++)
#define tc           ll t1; cin>>t1; while(t1--)
#define inp          ll n; cin>>n; ll a[n]; fr(i,0,n) cin>>a[i];
#define inp1         ll n1; cin>>n1; ll a[n1]; fr(i,0,n1) cin>>a[i];
#define vec          vector<ll>
#define pb           push_back
#define pii          pair<ll,ll>
#define mp           make_pair
#define F            first
#define S            second
#define fast         ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define scn(n)       scanf("%lld",&n)
#define lscn(n)      scanf("%lld",&n)
#define lpri(n)      printf("%lld",n)
#define pri(n)       printf("%d",n)
#define pln()        printf("\n")
#define priln(n)     printf("%d\n",n)
#define lpriln(n)    printf("%lld\n",n)
#define srt(v)       sort(v.begin(),v.end())
#define srte(v)      sort(v.rbegin(),v.rend())
#define maxx         1000005
#define lb(v,n)        lower_bound(v.begin(),v.end(),n)-v.begin()
#define ub(v,n)        upper_bound(v.begin(),v.end(),n)-v.begin()
#define inf          LONG_MAX
#define zer          LONG_MIN
const long mod=pow(10,9)+7;

int longestCommonSubstring(string x,string y){
    int m =  x.size();
    int n =  y.size();
    int dp[m+1][n+1];
    for(int i = 0 ; i < m; i++){
        dp[i][0] = 0;
    }
    for(int j = 0; j < n; j++){
        dp[0][j] = 0;
    }
    int ans=0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <=n; j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = 0;
            }
            ans=max(dp[i][j],ans);
        }
    }
    return ans;
}

int main()
{
    // fast;
    #ifndef ONLINE_JUDGE
    freopen("inputf.in" , "r" , stdin);
    freopen("outputf.in" , "w" , stdout);
    #endif

    string s1,s2;
    cin>>s1>>s2;

    cout<<longestCommonSubstring(s1,s2);


    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
    return 0;
}
// Time Complexicity : O(n*m)
// Space Complexicity : O(n*m)
// Example
// Input            Output
// anshaj anuj        2

```

**[⬆ Back to Top](#----cp-algorithms-)** 

##  Edit Operations

```C++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define loop(i,n)    for(int i = 0; x < n; i++)
#define fr(i,j,n)   for(ll i=j;i<n;i++)
#define tc           ll t1; cin>>t1; while(t1--)
#define inp          ll n; cin>>n; ll a[n]; fr(i,0,n) cin>>a[i];
#define inp1         ll n1; cin>>n1; ll a[n1]; fr(i,0,n1) cin>>a[i];
#define vec          vector<ll>
#define pb           push_back
#define pii          pair<ll,ll>
#define mp           make_pair
#define F            first
#define S            second
#define fast         ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define scn(n)       scanf("%lld",&n)
#define lscn(n)      scanf("%lld",&n)
#define lpri(n)      printf("%lld",n)
#define pri(n)       printf("%d",n)
#define pln()        printf("\n")
#define priln(n)     printf("%d\n",n)
#define lpriln(n)    printf("%lld\n",n)
#define srt(v)       sort(v.begin(),v.end())
#define srte(v)      sort(v.rbegin(),v.rend())
#define maxx         1000005
#define lb(v,n)        lower_bound(v.begin(),v.end(),n)-v.begin()
#define ub(v,n)        upper_bound(v.begin(),v.end(),n)-v.begin()
#define inf          LONG_MAX
#define zer          LONG_MIN
const long mod=pow(10,9)+7;

int editOperations(string s1, string s2){
    int m = s1.length();
    int n = s2.length();
    int dp[m+1][n+1];
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
        if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
        else dp[i][j] = 1 + min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1]);
        }
    }
    return dp[m][n];
}

int main()
{
    // fast;
    #ifndef ONLINE_JUDGE
    freopen("inputf.in" , "r" , stdin);
    freopen("outputf.in" , "w" , stdout);
    #endif

    string s1,s2;
    cin>>s1>>s2;

    cout<<editOperations(s1,s2);


    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
    return 0;
}
// Time Complexicity : O(n*m)
// Space Complexicity : O(n*m)
// Example
// Input            Output
// anshaj anuj        3

```

**[⬆ Back to Top](#----cp-algorithms-)** 

##  Longest Increasing Subsequence

```C++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define loop(i,n)    for(int i = 0; x < n; i++)
#define fr(i,j,n)   for(ll i=j;i<n;i++)
#define tc           ll t1; cin>>t1; while(t1--)
#define inp          ll n; cin>>n; ll a[n]; fr(i,0,n) cin>>a[i];
#define inp1         ll n1; cin>>n1; ll a[n1]; fr(i,0,n1) cin>>a[i];
#define vec          vector<ll>
#define pb           push_back
#define pii          pair<ll,ll>
#define mp           make_pair
#define F            first
#define S            second
#define fast         ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define scn(n)       scanf("%lld",&n)
#define lscn(n)      scanf("%lld",&n)
#define lpri(n)      printf("%lld",n)
#define pri(n)       printf("%d",n)
#define pln()        printf("\n")
#define priln(n)     printf("%d\n",n)
#define lpriln(n)    printf("%lld\n",n)
#define srt(v)       sort(v.begin(),v.end())
#define srte(v)      sort(v.rbegin(),v.rend())
#define maxx         1000005
#define lb(v,n)        lower_bound(v.begin(),v.end(),n)-v.begin()
#define ub(v,n)        upper_bound(v.begin(),v.end(),n)-v.begin()
#define inf          LONG_MAX
#define zer          LONG_MIN
const long mod=pow(10,9)+7;

// Time complexicity: O(n^2) 
int longestIncreasingSubsequence(std::vector<ll> a,ll n){
     ll dp[n];
    for(int i=0;i<n;i++)
    dp[i]=1;
    ll ans=zer;
    for(int i=1;i<n;i++)
     for(int j=0;j<i;j++)
      {
      if(a[j]<a[i]) dp[i]=max(dp[i],dp[j]+1);
      ans=max(ans,dp[i]);
      }
      return ans;

}
// Time complexicity: O(nlogn) 
int longestIncreasingSubsequence2(std::vector<ll> v){
    if (v.size() == 0) 
        return 0; 
    std::vector<ll> a;
    a.pb(v[0]);
    ll length=1;
    fr(i,1,v.size())
    {
        if(a[length-1]<v[i])
            a.pb(v[i]);
        else 
        {
            int ind=lb(v,v[i]);
            a[ind]=v[i];
        }

            length=a.size();
    }
    return length; 
}
int main()
{
    // fast;
    #ifndef ONLINE_JUDGE
    freopen("inputf.in" , "r" , stdin);
    freopen("outputf.in" , "w" , stdout);
    #endif

    int n;
    cin>>n;
    std::vector<ll> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    
      cout<<longestIncreasingSubsequence(a,n)<<endl;
      cout<<longestIncreasingSubsequence2(a)<<endl;


    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
    return 0;
}
// Space Complexicity : O(n)
// Example
// Input            Output
// 7                    4
// 1 4 1 3 4 2 5        4

```
**[⬆ Back to Top](#----cp-algorithms-)** 


##  Subsequence and Subarray Sum

```C++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define loop(i,n)    for(int i = 0; x < n; i++)
#define fr(i,j,n)   for(ll i=j;i<n;i++)
#define tc           ll t1; cin>>t1; while(t1--)
#define inp          ll n; cin>>n; ll a[n]; fr(i,0,n) cin>>a[i];
#define inp1         ll n1; cin>>n1; ll a[n1]; fr(i,0,n1) cin>>a[i];
#define vec          vector<ll>
#define pb           push_back
#define pii          pair<ll,ll>
#define mp           make_pair
#define F            first
#define S            second
#define fast         ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define scn(n)       scanf("%lld",&n)
#define lscn(n)      scanf("%lld",&n)
#define lpri(n)      printf("%lld",n)
#define pri(n)       printf("%d",n)
#define pln()        printf("\n")
#define priln(n)     printf("%d\n",n)
#define lpriln(n)    printf("%lld\n",n)
#define srt(v)       sort(v.begin(),v.end())
#define srte(v)      sort(v.rbegin(),v.rend())
#define maxx         1000005
#define lb(v,n)        lower_bound(v.begin(),v.end(),n)-v.begin()
#define ub(v,n)        upper_bound(v.begin(),v.end(),n)-v.begin()
#define inf          LONG_MAX
#define zer          LONG_MIN
const long mod=pow(10,9)+7;

// Time Complexicity : O(n^2)
// Space Complexicity : O(n*k) 
// returns 1 if any subsequence having sum equal to k
int subsequenceSumProblem(std::vector<ll> a,ll k){
    int n=a.size();
     ll dp[n+1][k+1];
     memset(dp,0,sizeof(dp));
     fr(i,0,n+1) dp[i][0]=1;
     
     fr(i,1,n+1)
     {
        ll temp=a[i-1];
        fr(j,temp,k+1)
        {
            if(dp[i-1][j-temp]) dp[i][j]=1;
        }
     }
    
     return dp[n][k];

}
// Time complexicity: O(n) 
// Space Complexicity : O(n)
// returns no of subarray sum equals k (not subsequence)
int subarraySumProblem(std::vector<ll> v,ll k){
    int n=v.size();
    unordered_map<ll, ll> count; 
  
    int res = 0; 
    ll sum = 0; 
    fr(i,0,n) { 
        sum += v[i]; 
        if (sum == k)  
            res++;         
        if (count.find(sum - k) !=  
                                  count.end())  
            res += (count[sum - k]); 
        count[sum]++; 
    } 
  
    return res;
}
int main()
{
    // fast;
    #ifndef ONLINE_JUDGE
    freopen("inputf.in" , "r" , stdin);
    freopen("outputf.in" , "w" , stdout);
    #endif

    int n;
    cin>>n;
    std::vector<ll> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    
      cout<<subsequenceSumProblem(a,5)<<endl;
      cout<<subarraySumProblem(a,5)<<endl;


    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
    return 0;
}
// Example
// Input            Output
// 7                    1
// 1 4 1 3 4 2 5        3

```
**[⬆ Back to Top](#----cp-algorithms-)** 

##  Coin Change Problem

```C++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define loop(i,n)    for(int i = 0; x < n; i++)
#define fr(i,j,n)   for(ll i=j;i<n;i++)
#define tc           ll t1; cin>>t1; while(t1--)
#define inp          ll n; cin>>n; ll a[n]; fr(i,0,n) cin>>a[i];
#define inp1         ll n1; cin>>n1; ll a[n1]; fr(i,0,n1) cin>>a[i];
#define vec          vector<ll>
#define pb           push_back
#define pii          pair<ll,ll>
#define mp           make_pair
#define F            first
#define S            second
#define fast         ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define scn(n)       scanf("%lld",&n)
#define lscn(n)      scanf("%lld",&n)
#define lpri(n)      printf("%lld",n)
#define pri(n)       printf("%d",n)
#define pln()        printf("\n")
#define priln(n)     printf("%d\n",n)
#define lpriln(n)    printf("%lld\n",n)
#define srt(v)       sort(v.begin(),v.end())
#define srte(v)      sort(v.rbegin(),v.rend())
#define maxx         1000005
#define lb(v,n)        lower_bound(v.begin(),v.end(),n)-v.begin()
#define ub(v,n)        upper_bound(v.begin(),v.end(),n)-v.begin()
#define inf          LONG_MAX
#define zer          LONG_MIN
const long mod=pow(10,9)+7;

// Time Complexicity : O(n*k)
// Space Complexicity : O(n*k) 
// returns minimum no of coin needed for sum=k (infinite coins of each denomination)
int coinChangeProblem(std::vector<ll> a,ll k){
    int n=a.size();
     ll dp[n+1][k+1];
     memset(dp,0,sizeof(dp));
     fr(i,1,k+1) dp[0][i]=inf;

     
     fr(i,1,n+1)
     {
        ll temp=a[i-1];
        fr(j,1,k+1)
        {
            if(j<temp) dp[i][j]=dp[i-1][j];
            else
            {
            dp[i][j] = min(min(dp[i-1][j-temp],dp[i][j-temp])+1, dp[i-1][j]);
            }
        
        }
     }

     return dp[n][k];

}
int main()
{
    // fast;
    #ifndef ONLINE_JUDGE
    freopen("inputf.in" , "r" , stdin);
    freopen("outputf.in" , "w" , stdout);
    #endif

    int n;
    cin>>n;
    std::vector<ll> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    
      cout<<coinChangeProblem(a,4)<<endl;
      cout<<coinChangeProblem(a,11)<<endl;

    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
    return 0;
}
// Example
// Input            Output
// 7                    4
// 1 5 6 8              2


```
**[⬆ Back to Top](#----cp-algorithms-)** 
