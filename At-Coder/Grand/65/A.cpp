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
    vector<int> v(n);
    map<int,int> mp;
    int qt = 0, cnt = 0;
    for(int i=0;i<n;i++){
        cin >> v[i];
        v[i] %= k;
        mp[v[i]]++;
        if(mp[v[i]] > qt){
            qt = mp[v[i]];
            cnt = 1;
        }else if(mp[v[i]] == qt) cnt++;
    }
    ll ans = k;
    ans *= (n - qt);
    if(cnt != 1){
        vector<int> v2;
        for(int i=0;i<v.size();i++){
            if(mp[v[i]] != qt) continue;
            v2.push_back(v[i]);
            mp[v[i]]--;//only 1 time added
        }
        sort(v2.begin(), v2.end(), greater<int>());
        int minv = INF_INT;
        int xx = v2.size();
        for(int i=0;i<xx;i++){
            if(v2[(i+1)%xx] < v2[i]){
                minv = min(minv, k + v2[(i+1)%xx] - v2[i]);
            }else if(v2[(i+1)%xx] > v2[i]){
                minv = min(minv, v2[(i+1)%xx] - v2[i]);
            }else assert(1 == 0);
        }
        ans -= minv;
    }
    cout << ans << "\n";
    
}
