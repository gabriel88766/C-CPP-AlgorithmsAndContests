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
    ll n, t;
    cin >> n >> t;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    vector<ll> v1, v2;
    for(int i=0;i<n;i++){
        if(i % 2) v2.push_back(v[i]);
        else v1.push_back(v[i]);
    }
    int n1 = v1.size(), n2 = v2.size();
    vector<ll> s1, s2;
    for(int i=0;i<(1 << n1); i++){
        ll cs = 0;
        for(int j=0;j<n1;j++){
            if(i & (1 << j)) cs += v1[j];
        }
        s1.push_back(cs);
    }
    
    for(int i=0;i<(1<<n2);i++){
        ll cs = 0;
        for(int j=0;j<n2;j++){
            if(i & (1 << j)) cs += v2[j];
        }
        s2.push_back(cs);
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    int p = s2.size() - 1;
    ll ans = 0;
    for(int i=0;i<s1.size();i++){
        while(p >= 0 && s1[i] + s2[p] > t) p--;
        if(p >= 0) ans = max(ans, s1[i] + s2[p]);
    }
    cout << ans << "\n";
}
