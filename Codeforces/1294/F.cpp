#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
tuple<int, int> dp1[N];
tuple<int, int, int> dp2[N];
tuple<int, int, int, int> ans;

void dfs(int u, int p){
    tuple<int, int> bs1;
    tuple<int, int, int> bs2 = {-INF_INT, -INF_INT, -INF_INT};
    tuple<int, int, int, int> bs3 = {-INF_INT, -INF_INT, -INF_INT, -INF_INT};
    //own leaf:
    dp1[u] = bs1 = {0, u};
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            //3 = 2 from cur + 1 from anywhere else
            if(get<0>(bs3) < get<0>(dp2[v]) + 1 + get<0>(bs1)){
                bs3 = {get<0>(dp2[v]) + 1 + get<0>(bs1), get<1>(dp2[v]), get<2>(dp2[v]), get<1>(bs1)};
            }
            //3 = 1 from cur + 2 from anywhere else
            if(get<0>(bs3) < get<0>(dp1[v]) + 1 + get<0>(bs2)){
                bs3 = {get<0>(dp1[v]) + 1 + get<0>(bs2), get<1>(dp1[v]), get<1>(bs2), get<2>(bs2)};
            }
            //2 = 2 from cur
            if(get<0>(bs2) < get<0>(dp2[v]) + 1){
                bs2 = {get<0>(dp2[v]) + 1, get<1>(dp2[v]), get<2>(dp2[v])};
            }
            //2 = 1 from cur + 1 from anywhere else
            if(get<0>(bs2) < get<0>(dp1[v]) + 1 + get<0>(bs1)){
                bs2 = {get<0>(dp1[v]) + 1 + get<0>(bs1), get<1>(dp1[v]), get<1>(bs1)};
            }
            //1 = from cur
            if(get<0>(bs1) < get<0>(dp1[v]) + 1){
                bs1 = {get<0>(dp1[v]) + 1, get<1>(dp1[v])};
            }
        }
    }
    // cout << u << " : " << get<0>(bs1) << " " << get<1>(bs1) << ", " << get<0>(bs2) << " " << get<1>(bs2) << " " << get<2>(bs2);
    // cout << ", " << get<0>(bs3) << " " << get<1>(bs3) << " " << get<2>(bs3) << " " << get<3>(bs3) << "\n";
    dp1[u] = bs1;
    dp2[u] = bs2;
    ans = max(ans, bs3);
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
    cout << get<0>(ans) << "\n";
    cout << get<1>(ans) << " " << get<2>(ans) << " " << get<3>(ans) << "\n";
}
