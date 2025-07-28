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
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> vp;//beauty leng
    for(int i=1;i<=n;i++){
        ll tm, b;
        cin >> tm >> b;
        vp.push_back({b, tm});
    }
    sort(vp.begin(), vp.end(), greater<pair<int, int>>());
    multiset<int> ms;
    ll sum = 0;
    ll ans = 0;
    for(auto [b, tt] : vp){
        ms.insert(tt);
        sum += tt;
        if(ms.size() > k){
            sum -= *ms.begin();
            ms.erase(ms.begin());
        }
        ans = max(ans, sum * b);
    }   
    cout << ans << "\n";
}
