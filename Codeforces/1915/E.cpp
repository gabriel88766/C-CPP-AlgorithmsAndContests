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
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        vector<ll> ps(n+1, 0);
        for(int i=1;i<=n;i++){
            if(i % 2) ps[i] = ps[i-1] + v[i];
            else ps[i] = ps[i-1] - v[i];
        }
        set<ll> s;
        bool ok = false;
        s.insert(0);
        for(int i=1;i<=n;i++){
            if(s.count(ps[i])) ok = true;
            s.insert(ps[i]);
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}   
