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
    int n, T;
    cin >> n >> T;
    vector<ll> v(n), tmp(n);
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<n;i++) cin >> tmp[i];
    int mine = *min_element(tmp.begin(), tmp.end());
    int maxe = *max_element(tmp.begin(), tmp.end());
    cout << fixed << setprecision(15);
    if(mine > T || maxe < T){
        cout << 0.0 << "\n";
        return 0;
    }
    //solve...
    vector<int> v1, v2;
    ll ans = 0;
    for(int i=0;i<n;i++){
        if(tmp[i] > T) v1.push_back(i);
        else if(tmp[i] < T) v2.push_back(i);
        else ans += v[i];
    }
    sort(v1.begin(), v1.end(), [&](int u, int v){
        return (tmp[u] - T) < (tmp[v] - T);
    });
    sort(v2.begin(), v2.end(), [&](int u, int v){
        return (T - tmp[u]) < (T - tmp[v]);
    });
    ll sum1 = 0, sum2 = 0;
    for(auto x : v1){
        sum1 += (tmp[x] - T) * v[x];
    }
    for(auto x : v2){
        sum2 += (T - tmp[x]) * v[x];
    }
    double ansd = 0;
    if(sum1 > sum2){
        for(auto x : v2) ans += v[x];
        ll csum = 0;
        for(auto x : v1){
            if(csum + (tmp[x] - T) * v[x] <= sum2){
                csum += (tmp[x] - T) * v[x];
                ans += v[x];
            }else{
                ansd = sum2 - csum;
                ansd /= (tmp[x] - T);
                break;
            }
        }
    }else if(sum1 < sum2){
        for(auto x : v1) ans += v[x];
        ll csum = 0;
        for(auto x : v2){
            if(csum + (T - tmp[x]) * v[x] <= sum1){
                csum += (T - tmp[x]) * v[x];
                ans += v[x];
            }else{
                ansd = sum1 - csum;
                ansd /= (T - tmp[x]);
                break;
            }
        }
    }else{
        for(auto x : v1) ans += v[x];
        for(auto x : v2) ans += v[x];
        
    }
    cout << ans + ansd << "\n";
}
