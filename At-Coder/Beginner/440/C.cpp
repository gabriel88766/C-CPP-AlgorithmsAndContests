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
        int n, w;
        cin >> n >> w;
        vector<ll> c(n);
        for(int j=0;j<n;j++) cin >> c[j];
        vector<ll> ttc(2*w);
        for(int i=0;i<2*w;i++){
            for(int j=i;j<n;j+=2*w){
                ttc[i] += c[j];
            }
        }
        for(int i=1;i<2*w;i++) ttc[i] += ttc[i-1];
        ll mn = INF_LL;
        for(int i=0;i<2*w;i++){
            ll cur = ttc[i];
            if(i >= w) cur -= ttc[i-w];
            else if(i != w-1){
                int nd = w - 1 - i;
                cur += ttc[2*w-1];
                cur -= ttc[2*w-1-nd];
            }
            mn = min(mn, cur);
        }
        cout << mn << "\n";
    }
}   
