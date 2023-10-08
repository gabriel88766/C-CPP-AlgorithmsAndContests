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
    freopen("in", "r", stdin); //test input
    freopen("out", "w", stdout);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        cout << "Case #" << i << ": ";
        ll n;
        cin >> n;
        vector<ll> v(2*n-1);
        for(int i=0;i<2*n-1;i++) cin >> v[i];
        if(n == 1){
            cout << "1\n";
            continue;
        }
        sort(v.begin(), v.end());
        bool ok = false;
        vector<int> pos;
        for(int i=0;i<3;i++){
            vector<ll> va;
            ll cur = -1;
            ll sum = 0;
            if(i == 0){
                sum = v[2*n-2] + v[1];
                cur = v[2*n-2] + v[1] - v[0];
            }else if(i == 1){
                sum = v[2*n-3] + v[0];
                cur = v[2*n-3] + v[0] - v[2*n-2];
            }else{
                ll S = 0;
                for(auto x : v) S += x;
                sum = v[0] + v[2*n-2];
                cur = n*(v[0]+v[2*n-2]) - S;
            }
            if(cur <= 0) continue;
            va = v;
            va.push_back(cur);
            sort(va.begin(), va.end());
            bool curok = true;
            for(int j = 0; j < n; j++){
                if(sum != va[0+j] + va[2*n-1-j]) curok = false;
            }
            if(curok){
                ok = true;
                pos.push_back(cur);
            }
        }
        if(!ok) cout << "-1\n";
        else{
            sort(pos.begin(), pos.end());
            cout << pos[0] << "\n";
        }
    }


}
