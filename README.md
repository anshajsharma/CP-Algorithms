| No. | Topics |
| --- | --------- |
|    | [*Special Notes*](#special-notes-) |
|    | **Dyamic Programming** |
|15  | [Weighted Job Scheduling](#weighted-job-scheduling) |
|16  | [Namespaces](#namespaces) |
|17  | [Namespaces](#namespaces) |
|18  | [Namespaces](#namespaces) |
|19  | [Namespaces](#namespaces) |
|20  | [Namespaces](#namespaces) |
|21  | [Namespaces](#namespaces) |
|22  | [Namespaces](#namespaces) |


##  Weighted Job Scheduling
Given N jobs where every job is represented by following three elements of it.

1.  Start Time
2.  Finish Time
3.  Profit or Value Associated (>= 0)  

Find the maximum profit subset of jobs such that no two jobs in the subset overlap.

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


