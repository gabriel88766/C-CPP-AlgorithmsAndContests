#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int mid = 200005;
bool ok[400015];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, q;
    cin >> n >> m >> q;
    vector<ll> a(n), b(m);
    ll Sa = 0, Sb = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        Sa += a[i];
    }
    for(int i=0;i<m;i++){
        cin >> b[i];
        Sb += b[i];
    }
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    m = b.size();
    ll S = Sa * Sb;
    set<pair<ll, ll>> sx;
    for(int i=0;i<n;i++){
        ll cS = S - Sb * a[i];
        ll cSa = a[i] - Sa;
        if(!sx.count({cS, cSa})){
            sx.insert({cS, cSa}); //one time visit;
            // cS + cSa * b[j] = x
            if(cSa > 0){
                int k = 0;
                for(int j=m/2;j>=1;j>>=1){
                    while(k + j < m && cS + cSa * b[k+j] < -200000) k += j;
                }
                if(cS + cSa * b[k] < -200000) k++;
                while(k < m && cS + cSa * b[k] >= -200000 && cS + cSa * b[k] <= 200000){
                    ok[cS + cSa * b[k] + mid] = true;
                    k++;
                }
            }else if(cSa == 0){
                if(cS >= -200000 && cS <= 200000) ok[cS + mid] = true;
            }else{
                int k = m-1;
                for(int j=m/2;j>=1;j>>=1){
                    while(k - j >= 0 && cS + cSa * b[k-j] < -200000) k -= j;
                }
                if(cS + cSa * b[k] < -200000) k--;
                while(k >= 0 && cS + cSa * b[k] >= -200000 && cS + cSa * b[k] <= 200000){
                    ok[cS + cSa * b[k] + mid] = true;
                    k--;
                }
            }
        } 
        // cS += a[i] * b[j] - b[j] * Sa
    }
    for(int i=0;i<q;i++){
        int x;
        cin >> x;
        if(ok[x + mid]) cout << "YES\n";
        else cout << "NO\n";
    }
}
