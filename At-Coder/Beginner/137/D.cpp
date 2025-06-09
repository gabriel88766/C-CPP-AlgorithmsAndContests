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
    set<int> al;
    for(int i=0;i<=m;i++) al.insert(i);
    int ans = 0;
    vector<pair<int, int>> vp;
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        vp.push_back({b, a});
    }
    sort(vp.begin(), vp.end(), greater<pair<int, int>>());
    for(auto &[b, a] : vp){
        auto it = al.lower_bound(a);
        if(it != al.end()){
            ans += b;
            al.erase(it);
        }
    }
    cout << ans << "\n";
}
