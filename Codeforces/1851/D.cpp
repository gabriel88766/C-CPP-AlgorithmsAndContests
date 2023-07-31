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
        vector<ll> ps(n,0);
        for(int i=1;i<n;i++) cin >> ps[i];

        ll sum = n;
        sum *= (n+1);
        sum /= 2;
        if(ps[n-1] == sum){
            vector<int> cnt(n+1,0);
            bool ok = true;
            ll gr = -1;
            ll rep = -1;
            for(int i=1;i<n;i++){
                ll dif = ps[i] - ps[i-1];
                if(dif > n){
                    if(gr == -1) gr = dif;
                    else ok = false;
                }else{
                    cnt[dif]++;
                    if(cnt[dif] > 1){
                        if(rep != -1) ok = false;
                        else{
                            rep = dif;
                        }
                    }
                }
            }
            if(rep != -1 && gr != -1) ok = false;
            else{
                int st=-1, nd=-1;
                for(int i=1;i<=n;i++){
                    if(cnt[i] == 0){
                        if(st == -1) st = i;
                        else nd = i;
                    }
                }
                if(rep != -1){
                    if(rep != st + nd) ok = false;
                }else{
                    if(gr != st + nd) ok = false;
                }
            }
            if(ok) cout << "YES\n";
            else cout << "NO\n";
        }else{
            vector<int> cnt(n+1,0);
            bool ok = true;
            for(int i=1;i<n;i++){
                ll dif = ps[i] - ps[i-1];
                if(dif <= n){
                    if(cnt[dif]) ok = false;
                    else cnt[dif]++;
                }else ok = false;
            }
            if(ok) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
