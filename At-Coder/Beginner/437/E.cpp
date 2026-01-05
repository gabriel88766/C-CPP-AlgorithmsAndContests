#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
int cnt = 0;
int idx[N]; //idx[0] = 0
map<int, vector<int>> st[N];
vector<int> ans;
void dfs(int u){
    for(auto [y, v] : st[u]){
        for(auto x : v) ans.push_back(x);
        dfs(idx[v[0]]);
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int x, y;
        cin >> x >> y;
        if(!st[idx[x]].count(y)){
            idx[i] = ++cnt;
        }else{
            idx[i] = idx[st[idx[x]][y].back()];
        }
        st[idx[x]][y].push_back(i);
    }
    dfs(0);
    for(auto x : ans) cout << x << " ";
    cout << "\n";
}
