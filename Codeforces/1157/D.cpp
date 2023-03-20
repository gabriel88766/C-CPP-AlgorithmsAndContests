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
    ll n, k;
    cin >> n >> k;
    vector<int> v(k+1), dif(k+1);
    ll lo = 0, hi = 1e9+1, mid;
    while(lo != hi){
        mid = (lo+hi+1)/2;
        ll val = (mid-1)*k + (k*(k+1))/2;
        if(val > n) hi = mid-1;
        else lo = mid;
    }
    if(lo == 0) cout << "NO\n";
    else{
        for(int i=1;i<=k;i++) v[i] = lo+i-1;
        n -= ((lo-1)*k + (k*(k+1))/2);
        while(n){
            bool ok = false;
            ll ind;
            for(int i=2;i<=k;i++){
                if(n && (2*v[i-1] > v[i])){
                    ok = true;
                    ind = i;
                    break;
                }
            }
            if(ok){
                for(int i=max(ind,k-n+1);i<=k;i++){
                    n--;
                    v[i]++;
                }
            }else break;
        }
        if(n) cout << "NO\n";
        else{
            cout << "YES\n";
            for(int i=1;i<=k;i++) cout << v[i] << " ";
        }
    }
}
