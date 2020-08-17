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
|2   | [Namespaces](#namespaces) |
|3   | [Namespaces](#namespaces) |
|4   | [Namespaces](#namespaces) |
|5   | [Namespaces](#namespaces) |

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
