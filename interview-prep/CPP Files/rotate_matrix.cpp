#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = pow(10,9)+7;

vector<vector<int>> rotateRight( int n, int m, vector< vector<int> > &v )
{
    vector<vector<int>> ans( m, vector<int>(n,0) );

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            ans[i][j] = v[n-1-j][i];
        }
    }

    return ans;

}
vector<vector<int>> rotateLeft( int n, int m, vector< vector<int> > &v )
{
    vector<vector<int>> ans( m, vector<int>(n,0) );

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            ans[i][j] = v[j][m-1-i];
        }
    }

    return ans;

}
void solve()
{

   ll n,m;

   cin>>n>>m;

   vector<vector<int>> v( n, vector<int>(m,0) );

   for(int i=0;i<n;i++)
   {
        for(int j=0;j<m;j++)
        {
            cin>>v[i][j];
        }
   }

   v = rotateRight(n,m,v);

   for(int i=0;i<n;i++)
   {
        for(int j=0;j<m;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
   }
   cout<<endl;
   v = rotateLeft(n,m,v);

   for(int i=0;i<n;i++)
   {
        for(int j=0;j<m;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
   }


}
 
int main() {
    // fast;   // Always use fast
    #ifndef ONLINE_JUDGE
        freopen("inp.txt" , "r" , stdin);
        freopen("opi.txt" , "w" , stdout);
    #endif
    clock_t tv1, tv2;
    double time;
    tv1 = clock();
    

    solve();
 
    tv2 = clock();
    time = (tv2 - tv1)/(CLOCKS_PER_SEC / (double) 1000.0);
    #ifndef ONLINE_JUDGE
       cout<<"Time Elasped: "<< time <<" ms"<<endl; 
    #endif
}
