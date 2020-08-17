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


