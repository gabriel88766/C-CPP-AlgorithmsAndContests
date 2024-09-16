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
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        vector<int> dif;
        for(int i=1;i<n;i++) dif.push_back(v[i] - v[i-1]);
        auto x = max_element(dif.begin(), dif.end()) - dif.begin();
        //dif[x] = v[x+1] - v[x];
        dif.erase(max_element(dif.begin(), dif.end()));
        vector<int> d(m), f(k);
        for(int i=0;i<m;i++) cin >> d[i];
        for(int i=0;i<k;i++) cin >> f[i];
        sort(d.begin(), d.end());
        sort(f.begin(), f.end());
        int lws = v[x+1] - v[x];
        for(int i=0;i<d.size();i++){
            int tgt = v[x] + (v[x+1] - v[x])/2 - d[i];
            auto it = lower_bound(f.begin(), f.end(), tgt);
            if(it != f.end() && *it + d[i] < v[x+1]){
                lws = min(lws, max(*it+d[i] - v[x], v[x+1] - *it - d[i]));
            }
            if(it != f.begin() && *prev(it) + d[i] > v[x]){
                it = prev(it);
                lws = min(lws, max(*it+d[i] - v[x], v[x+1] - *it - d[i]));
            }
        }
        dif.push_back(lws);
        cout << *max_element(dif.begin(), dif.end()) << "\n";
    }
}
