#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+1;
vector<int> pos[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        pos[v[i]].push_back(i);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    int ans = INF_INT;
    for(auto &x : v){
        for(int i=1;i<pos[x].size();i++){
            ans = min(ans, pos[x][i] - pos[x][i-1] + 1);
        }
    }
    if(ans == INF_INT) cout << "-1\n";
    else cout << ans << "\n";
}
