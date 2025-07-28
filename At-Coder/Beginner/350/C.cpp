#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int pos[N], v[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<pair<int, int>> ans;
    for(int i=1;i<=n;i++){
        cin >> v[i];
        pos[v[i]] = i;
    }
    for(int i=1;i<n;i++){
        if(pos[i] != i){
            ans.push_back({i, pos[i]});
            int x = v[i];
            swap(v[i], v[pos[i]]);
            swap(pos[x], pos[i]);
        }
    }
    cout << ans.size() << "\n";
    for(auto [a, b] : ans) cout << a << " " << b << "\n";
}
