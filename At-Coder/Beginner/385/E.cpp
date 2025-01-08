#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
vector<int> adj[N];
int getsz(int x, int y){
    return x*y + x + 1;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int hsz = 0;
    int n;
    cin >> n;
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        vector<int> chs;
        for(auto v : adj[i]){
            chs.push_back(adj[v].size() - 1);
        }
        sort(chs.begin(), chs.end());
        for(int j=0;j<chs.size();j++){
            hsz = max(hsz, getsz(chs.size() - j, chs[j]));
        }
    }
    cout << n - hsz << "\n";
}
