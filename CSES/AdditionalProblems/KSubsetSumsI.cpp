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
    vector<ll> v(n);
    ll aux = 0;
    for(int i=0;i<n;i++){
         cin >> v[i];
        if(v[i] < 0){
            aux += v[i];
            v[i] = -v[i];
        }
    }
    sort(v.begin(), v.end());
    multiset<pair<ll, ll>> ms;
    ms.insert({0, -1});
    while(k--){
        auto [a, b] = *ms.begin();
        ms.erase(ms.begin());
        cout << a + aux << " ";
        if(k == 0) break;
        for(int j=b+1; j < n; j++){
            while(ms.size() > k) ms.erase(prev(ms.end()));
            ll mn = ms.size() == k ? get<0>(*prev(ms.end())) - 1 : INF_LL;
            if(a + v[j] <= mn){
                ms.insert({a+v[j], j});
            }else break;
        }
    }
    cout << "\n";
}
