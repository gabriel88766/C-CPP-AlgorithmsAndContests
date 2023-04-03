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
        ll c, d;
        cin >> n >> c >> d;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        sort(v.begin(), v.end());
        ll cost = 0;
        for(int i=1;i<n;i++){
            if(v[i] == v[i-1]) cost += c;
        }
        v.resize(unique(v.begin(), v.end()) - v.begin());
        ll mincost = INF_LL;
        for(int i=v.size()-1;i>=0;i--){
            ll curcost = v[i]-i-1;
            curcost *= d;
            curcost += cost;
            mincost = min(curcost, mincost);
            cost += c;
        }
        mincost = min(cost+d, mincost);
        cout << mincost << "\n";
    }
}
