#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<int> v(m+1);
    vector<int> pos(m+1);
    for(int i=1;i<=m;i++) cin >> v[i];
    pos[0] = 1;
    for(int i=1;i<=m;i++){
        if(v[i] == pos[i-1]) pos[i] = pos[i-1] + 1;
        else if(v[i] == pos[i-1] - 1) pos[i] = pos[i-1] - 1;
        else pos[i] = pos[i-1];
    }
    vector<int> aux(n+1), inv(n+1);
    for(int i=1;i<=n;i++){
        aux[i] = inv[i] = i;
    }
    vector<int> ans(m+1);
    for(int i=m;i>=1;i--){
        ans[i] = inv[pos[i-1]];
        int p1 = inv[v[i]];
        int p2 = inv[v[i] + 1];
        swap(aux[p1], aux[p2]);
        swap(inv[v[i]], inv[v[i] + 1]);
    }
    for(int i=1;i<=m;i++) cout << ans[i] << "\n";
}   
