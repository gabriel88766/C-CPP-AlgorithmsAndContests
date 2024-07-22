#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<ll> cmad(vector<ll> &v){
    map<int,int> mp;
    vector<ll> ans(v.size());
    ll mad = 0;
    for(int i=0;i<v.size();i++){
        mp[v[i]]++;
        if(mp[v[i]] >= 2) mad = max(mad, v[i]);
        ans[i] = mad;
    }
    return ans;
}
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
        vector<ll> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        ll sum = 0;
        for(int i=0;i<n;i++) sum += v[i];
        v = cmad(v);
        for(int i=0;i<n;i++) sum += v[i];
        v = cmad(v);
        reverse(v.begin(), v.end());
        ll ln = 0;
        ll fa = 0;
        for(int i=0;i<v.size();i++){
            if(v[i] != ln){
                ll qt = i - fa;
                sum += (fa+1) * qt * ln;
                sum += ((qt*(qt-1))/2) * ln;
                ln = v[i];
                fa = i;
            }
        }
        cout << sum << "\n";
    }
}
