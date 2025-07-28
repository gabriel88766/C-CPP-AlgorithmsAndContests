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
        int n;
        cin >> n;
        vector<pair<int, int>> vp(n);
        for(int i=0;i<n;i++){
            cin >> vp[i].first >> vp[i].second;
        }
        map<int, int> mp;
        for(int i=0;i<n;i++){
            mp[vp[i].first]++;
        }
        int cx = -1;
        for(auto [k, v] : mp){
            if(v % 2){
                assert(cx == -1);
                cx = k;
            }
        }
        assert(cx != -1);
        mp.clear();
        for(int i=0;i<n;i++){
            mp[vp[i].second + vp[i].first - cx]++;
        }
        int cy = -1;
        for(auto [k, v] : mp){
            if(v % 2){
                assert(cy == -1);
                // cout << k << " " << v << "\n";
                cy = k;
            }
        }
        assert(cy != -1);
        cout << cx << " " << cy << "\n";
    }
}
