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
    int n;
    cin >> n;
    multiset<ll> s1, s2;
    vector<ll> v(n);
    ll sum1 = 0, sum2 = 0;
    for(int i=0;i<n;i++){
        cin >> v[i];
        sum2 += v[i];
        s2.insert(v[i]);
    }
    bool ok = false;
    for(int i=0;i<n;i++){
        ll dif = sum2 - sum1;
        if(!(dif % 2)){
            dif /= 2;
            if(dif > 0){
                auto it = s2.lower_bound(dif);
                if(it != s2.end() && *it == dif) ok = true;
            }else if(dif < 0){
                dif = -dif;
                auto it = s1.lower_bound(dif);
                if(it != s1.end() && *it == dif) ok = true;
            }else{
                ok = true;
            }
        }
        
        sum2 -= v[i];
        sum1 += v[i];
        s2.erase(s2.lower_bound(v[i]));
        s1.insert(v[i]);
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
}
