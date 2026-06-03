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
        ll s, m;
        cin >> s >> m;
        ll aux = s;
        for(int j=60;j>=0;j--){
            ll cur = 1LL << j;
            if(!(cur & m)) continue;
            if(cur <= aux) aux -= (aux / cur) * cur;
        }
        if(aux == 0){
            ll lo = 0, hi = s;
            while(lo != hi){
                ll mid = lo + (hi - lo)/2;
                ll aux = s;
                for(int j=60;j>=0;j--){
                    ll cur = 1LL << j;
                    if(!(cur & m)) continue;
                    ll md = min(aux / cur, mid);
                    aux -= md * cur;
                }
                if(aux == 0) hi = mid;
                else lo = mid + 1;
            }
            cout << lo << "\n";
        }else cout << "-1\n";
    }
}
