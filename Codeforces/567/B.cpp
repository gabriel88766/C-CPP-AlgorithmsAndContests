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
    int n;
    cin >> n;
    vector<pair<char, int>> vp;
    map<int, bool> vis;
    set<int> s;
    for(int i=1;i<=n;i++){
        char c;
        int x;
        cin >> c >> x;
        vp.push_back({c, x});
        if(!vis.count(x)){
            if(c == '-'){
                s.insert(x);
            }
        }
        vis[x] = true;
    }
    size_t ans = s.size();
    for(auto [a, b] : vp){
        if(a == '-') s.erase(b);
        else s.insert(b);
        ans = max(ans, s.size());
    }
    cout << ans << "\n";
}
