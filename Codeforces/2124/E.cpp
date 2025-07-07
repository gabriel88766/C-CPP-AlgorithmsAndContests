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
        ll s = 0;
        vector<ll> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
            s += v[i];
        }
        if(*max_element(v.begin(), v.end()) * 2 > s || s % 2 == 1) cout << "-1\n";
        else{
            ll cs = 0;
            bool ok = false;
            for(int i=0;i<n;i++){
                cs += v[i];
                if(2*cs == s) ok = true;
            }
            if(ok){
                cout << "1\n";
                for(auto x : v) cout << x << " ";
                cout << "\n";
            }else{
                cout << "2\n";
                int p = 0;
                ll cs = 0;
                while(cs + v[p] <= s/2){
                    cs += v[p++];
                }
                ll x1 = cs;
                ll x2 = v[p];
                ll x3 = s - cs - v[p];
                assert(max(x1,x3) - min(x1,x3) <= x2 && x2 <= x1 + x3);//then we can :)
                ll dif = x3 - x1; //x1 + l1 = x3 + l2, l1 = l2 + dif, 2*l2 + dif = x2
                ll l2 = (x2 - dif) / 2;
                ll l1 = l2 + dif;
                assert(l1 + l2 == v[p]);
                assert(l1 >= 0 && l2 >= 0);
                ll a1 = x3 - l1;
                assert(a1 <= x1);
                for(int i=0;i<p;i++){
                    if(a1 >= v[i]){
                        cout << v[i] << " ";
                        a1 -= v[i];
                        v[i] = 0;
                    }else{
                        cout << a1 << " ";
                        v[i] -= a1;
                        a1 = 0;
                    }
                }
                cout << l1 << " ";
                v[p] -= l1;
                for(int i=p+1;i<n;i++){
                    cout << v[i] << " ";
                    v[i] = 0;
                }
                cout << "\n";
                for(auto x : v) cout << x << " ";
                cout << "\n";

            }
        }
    }
}
