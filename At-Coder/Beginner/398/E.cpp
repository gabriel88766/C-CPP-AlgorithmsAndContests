#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3, M = 20; 
vector<int> adj[N];
int rt = 1, h[N], p[N];

void dfs(int u, int par){ 
    p[u] = par;
    h[u] = h[par] + 1;
    for(auto x : adj[u]){
        if(x != par){
            dfs(x, u);
        }
    } 
}



//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    set<pair<int, int>> st;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(p[i] == j || p[j] == i) continue;
            if(h[i] % 2 != h[j] % 2){
                st.insert({i, j});
            }
        }
    }
    if(st.size() % 2){
        cout << "First\n";
        cout.flush();
        while(st.size()){
            auto p = *st.begin();
            st.erase(st.begin());
            cout << p.first << " " << p.second << "\n";
            cout.flush();
            int a, b;
            cin >> a >> b;
            if(a == -1) break;
            if(a > b) swap(a, b);
            assert(st.count({a, b}));
            st.erase({a, b});
        }
    }else{
        cout << "Second\n";
        cout.flush();
        while(st.size()){
            int a, b;
            cin >> a >> b;
            if(a == -1) break;
            if(a > b) swap(a, b);
            assert(st.count({a, b}));
            st.erase({a, b});
            auto p = *st.begin();
            st.erase(st.begin());
            cout << p.first << " " << p.second << "\n";
            cout.flush();
        }
    }
}
