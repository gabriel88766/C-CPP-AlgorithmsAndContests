#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    set<pair<int,int>> nums;
    map<pair<int,int>,int> mp;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    int ans = 0, alw = 0;
    for(int i=0;i<n;i++){
        if(!b[i] && !a[i]){
            alw++;
            continue;
        }
        if(!b[i] && a[i]){
            mp[{0,0}]++;
            nums.insert({0,0});
            continue;
        }
        if(!a[i] && b[i]) continue; 
        int g = __gcd(abs(a[i]), abs(b[i]));
        if(b[i] < 0){
            a[i] = -a[i];
            b[i] = -b[i];
        }
        mp[{a[i]/g, b[i]/g}]++;
        nums.insert({a[i]/g, b[i]/g});
    }
    ans = alw;
    for(auto u : nums){
        ans = max(alw + mp[u], ans);
    }
    cout << ans;
}
