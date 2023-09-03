#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 4e5+3;
vector<int> adj[N];
int dg[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, d, k;
    cin >> n >> d >> k;
    if(n <= d) cout << "NO\n";
    else if(n == 2) cout << "YES\n1 2\n";
    else if(d == 1 || k == 1) cout << "NO\n";
    else{
        //n>=3, d >= 2, k >= 2;
        stack<pair<int,int>> st;
        for(int i=1;i<=d;i++){
            adj[i].push_back(i+1);
            dg[i]++;
            dg[i+1]++;
            if(i != 1) st.push({i, min(i-1, d+1-i)});
        }
        int p = d + 1;
        while(p != n && st.size()){
            int v = st.top().first;
            int sz = st.top().second;
            if(dg[v] == k){
                st.pop();
                continue;
            }
            adj[v].push_back(++p);
            dg[v]++;
            dg[p]++;
            if(sz > 1){
                st.push({p, sz-1});
            }
        }
        if(p == n){
            cout << "YES\n";
            for(int i=1;i<=n;i++){
                for(int j=0;j<adj[i].size();j++){
                    cout << i << " " << adj[i][j] << "\n";
                }
            }
        }else{
            cout << "NO\n";
        }
    }
}
