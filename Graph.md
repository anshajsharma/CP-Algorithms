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
|    | **Graph Related Topics** |
|1   | [Disjoint Set Data Structure](#disjoint-set-data-structure) |
|2   | [Kruskal's Algorithm MST](#kruskals-algorithm-mst) |
|3   | [Cycle Detection Using DS](#cycle-detection-using-ds) |
|1   | [Namespace](#namespace) |
|1   | [Namespace](#namespace) |
|1   | [Namespace](#namespace) |
|1   | [Namespace](#namespace) |




##  Disjoint Set Data Structure

Consider a situation with a number of persons and following tasks to be performed on them.  

1.  Add a new friendship relation, i.e., a person x becomes friend of another person y.  
2.  Find whether individual x is a friend of individual y (direct or indirect friend)  

```c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(i,j,n)    for(ll i=j;i<n;i++)
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
#define srt(v)       sort(v.begin(),v.end())
#define srte(v)      sort(v.rbegin(),v.rend())
#define maxx         1000005
#define lb(v,n)      lower_bound(v.begin(),v.end(),n)-v.begin()
#define ub(v,n)      upper_bound(v.begin(),v.end(),n)-v.begin()
#define inf          LONG_MAX
#define zer          LONG_MIN
const long           mod=pow(10,9)+7;

class DisjSet { 
    int *rank, *parent, n; 
  
public: 
    // Constructor to create and initialize sets of n items 
    DisjSet(int n) 
    { 
        rank = new int[n]; 
        parent = new int[n]; 
        this->n = n; 
        makeSet(); 
    } 
  
    // Creates n single item sets 
    void makeSet() 
    { 
        for (int i = 0; i < n; i++) { 
            parent[i] = i; 
        } 
    } 
  
    // Finds set of given item x 
    int find(int x) 
    { 
        // Finds the representative of the set that x is an element of 
        if (parent[x] != x) { 
  
            // if x is not the parent of itself Then x is not the representative of his set, 
            parent[x] = find(parent[x]);    // Known as path compression
  
        } 
  
        return parent[x]; 
    } 
  
    // Do union of two sets represented by x and y. 
    void Union(int x, int y) 
    { 
        // Find current sets of x and y 
        int xset = find(x); 
        int yset = find(y); 
  
        // If they are already in same set 
        if (xset == yset) 
            return; 
  
        // Put smaller ranked item under  bigger ranked item if ranks are different 
        if (rank[xset] < rank[yset]) { 
            parent[xset] = yset; 
        } 
        else if (rank[xset] > rank[yset]) { 
            parent[yset] = xset; 
        } 
  
        // If ranks are same, then increment 
        // rank. (Here xset or yset anyone can be treated as parent.)
        // In my case xset is treated as
        else { 
            parent[yset] = xset; 
            rank[xset] = rank[xset] + 1; 
        } 
    } 
}; 
void solve()
{
    DisjSet obj(5);  // creates disjoint set of size 5
    obj.Union(0, 2);         
    obj.Union(4, 2); 
    obj.Union(3, 1); 

              //     0
              //       \
              //   1     2
              //  /       \
              // 3         4

    // check if 4 and 0 belongs to same set or not (YES)
    if (obj.find(4) == obj.find(0)) 
        cout << "Yes\n"; 
    else
        cout << "No\n"; 

    // check if 4 and 0 belongs to same set or not (NO)
    if (obj.find(1) == obj.find(0)) 
        cout << "Yes\n"; 
    else
        cout << "No\n"; 
}
int main()
{
    // fast;
    #ifndef ONLINE_JUDGE
    freopen("inputf.in" , "r" , stdin);
    freopen("outputf.in" , "w" , stdout);
    #endif
    
      solve();  

    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
    return 0;
}


```

**[⬆ Back to Top](#----cp-algorithms-)** 


##  Kruskal's Algorithm MST
<h5 align="center">
   Image Src: HackerEarth
 </h5>   
 
![](https://github.com/anshajsharma/CP-Algorithms/blob/master/Data/6322896.jpg)  
 
```c++  

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(i,j,n)    for(ll i=j;i<n;i++)
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
#define srt(v)       sort(v.begin(),v.end())
#define srte(v)      sort(v.rbegin(),v.rend())
#define maxx         1000005
#define lb(v,n)      lower_bound(v.begin(),v.end(),n)-v.begin()
#define ub(v,n)      upper_bound(v.begin(),v.end(),n)-v.begin()
#define inf          LONG_MAX
#define zer          LONG_MIN
const long           mod=pow(10,9)+7;

class DisjSet { 
    int *rank, *parent, n; 
  
public: 
    DisjSet(int n) 
    { 
        rank = new int[n]; 
        parent = new int[n]; 
        this->n = n; 
        makeSet(); 
    } 
    void makeSet() 
    { 
        for (int i = 0; i < n; i++) { 
            parent[i] = i; 
            rank[i]=0;
        } 
    } 
    int find(int x) 
    { 
        if (parent[x] != x) { 
            parent[x] = find(parent[x]);    // Known as path compression
        } 
        return parent[x]; 
    } 
    void Union(int x, int y) 
    { 
        int xset = find(x); 
        int yset = find(y); 
  
        // If they are already in same set 
        if (xset == yset) 
            return; 
  
        if (rank[xset] < rank[yset]) { 
            parent[xset] = yset; 
        } 
        else if (rank[xset] > rank[yset]) { 
            parent[yset] = xset; 
        } 
        else { 
            parent[yset] = xset; 
            rank[xset] = rank[xset] + 1; 
        } 
    } 
}; 

struct edge
{
  ll x,y,weight;
};

bool comp(edge a,edge b)
{
  return a.weight<b.weight;
}

void kruskalAlgoMST()
{
    ll n,e;
    cin>>n>>e;
    edge edges[e];

    fr(i,0,e) cin>>edges[i].x>>edges[i].y>>edges[i].weight;

    sort(edges,edges+e,comp);

    std::vector<edge> v;

    // DisjSet ds(n+1);  // for 1 based indexing
    DisjSet ds(n);      // for 0 based indexing

    fr(i,0,e){
      int parentX = ds.find(edges[i].x);
      int parentY = ds.find(edges[i].y);
      if(parentX==parentY) ;
      else {
        ds.Union(edges[i].x,edges[i].y);
        v.pb(edges[i]);
      }
    }
    int l = v.size();
    fr(i,0,l) cout<<v[i].x<<" "<<v[i].y<<" "<<v[i].weight<<endl;

}
int main()
{
    // fast;
    #ifndef ONLINE_JUDGE
    freopen("inputf.in" , "r" , stdin);
    freopen("outputf.in" , "w" , stdout);
    #endif

      kruskalAlgoMST();  

    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
    return 0;
}

// input                 Output
// 5 7                    0 1 1
// 0 1 1                  3 4 2
// 0 2 7                  1 4 3
// 1 2 5                  1 2 5
// 1 3 4
// 1 4 3
// 3 4 2
// 2 4 6

```

**[⬆ Back to Top](#----cp-algorithms-)** 

##  Cycle Detection Using DS
**Concept Used:** For each edge, make subsets using both the vertices of the edge. If both the vertices are in the same subset, a cycle is found.  
```c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(i,j,n)    for(ll i=j;i<n;i++)
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
#define srt(v)       sort(v.begin(),v.end())
#define srte(v)      sort(v.rbegin(),v.rend())
#define maxx         1000005
#define lb(v,n)      lower_bound(v.begin(),v.end(),n)-v.begin()
#define ub(v,n)      upper_bound(v.begin(),v.end(),n)-v.begin()
#define inf          LONG_MAX
#define zer          LONG_MIN
const long           mod=pow(10,9)+7;

class DisjSet { 
    int *rank, *parent, n; 
  
public: 
    DisjSet(int n) 
    { 
        rank = new int[n]; 
        parent = new int[n]; 
        this->n = n; 
        makeSet(); 
    } 
    void makeSet() 
    { 
        for (int i = 0; i < n; i++) { 
            parent[i] = i; 
            rank[i]=0;
        } 
    } 
    int find(int x) 
    { 
        if (parent[x] != x) { 
            parent[x] = find(parent[x]);    // Known as path compression
        } 
        return parent[x]; 
    } 
    void Union(int x, int y) 
    { 
        int xset = find(x); 
        int yset = find(y); 
  
        // If they are already in same set 
        if (xset == yset) 
            return; 
  
        if (rank[xset] < rank[yset]) { 
            parent[xset] = yset; 
        } 
        else if (rank[xset] > rank[yset]) { 
            parent[yset] = xset; 
        } 
        else { 
            parent[yset] = xset; 
            rank[xset] = rank[xset] + 1; 
        } 
    } 
}; 

// Time Complexicity: O(n)
void solve()
{
    ll n,e;
    cin>>n>>e;
    DisjSet graph(n);  // creates disjoint set of size 5
    int f=0;
    fr(i,0,e){
        ll x,y;
        cin>>x>>y;
        if (graph.find(x) == graph.find(y)) f=1;
        graph.Union(x,y);
    }

    if (f) 
        cout << "Yes\n"; 
    else
        cout << "No\n"; 
}
int main()
{
    // fast;
    #ifndef ONLINE_JUDGE
    freopen("inputf.in" , "r" , stdin);
    freopen("outputf.in" , "w" , stdout);
    #endif
    
      solve();  

    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
    return 0;
}

// input                 Output
// 5 7                    
// 0 1 1                  Yes
// 0 2 7                  
// 1 2 5                  
// 1 3 4
// 1 4 3
// 3 4 2
// 2 4 6

// 5 3                    No
// 0 2
// 2 4
// 4 1

```

**[⬆ Back to Top](#----cp-algorithms-)** 

##  Disjoin

```c++

```

**[⬆ Back to Top](#----cp-algorithms-)** 

##  Disjoin

```c++

```

**[⬆ Back to Top](#----cp-algorithms-)** 

