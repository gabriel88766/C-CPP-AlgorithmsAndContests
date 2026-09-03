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
    set<int> s;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        s.insert(x);
    }
    int cur = 0;
    ll ans = 0;
    while(s.size()){
        auto it = s.lower_bound(cur);
        if(it == s.end()){
            it = prev(s.end());
        }else if(it != s.begin()){
            auto v1 = *it;
            auto v2 = *prev(it);
            if(abs(cur - v2) <= abs(cur - v1)){
                it = prev(it);
            }
        }
        ans += abs(*it - cur);
        cur = *it;
        s.erase(it);
    }
    cout << ans << "\n";
}
