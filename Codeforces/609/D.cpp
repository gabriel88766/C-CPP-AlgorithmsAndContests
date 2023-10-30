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
    int n, m, k;
    ll s;
    cin >> n >> m >> k >> s;
    vector<ll> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    vector<pair<ll,ll>> g1, g2;
    int c1 = 0, c2 = 0;
    for(int i=0;i<m;i++){
        int t, c;
        cin >> t >> c;
        if(t == 1){
             g1.push_back({c, i+1});
             c1++;
        }else{
             g2.push_back({c, i+1});
             c2++;
        }
    }   
    sort(g1.begin(), g1.end());
    sort(g2.begin(), g2.end());
    vector<ll> ps1(c1+1, 0);
    vector<ll> ps2(c2+1, 0);
    for(int i=0;i<g1.size();i++){
        ps1[i+1] = ps1[i] + g1[i].first;
    }
    for(int i=0;i<g2.size();i++){
        ps2[i+1] = ps2[i] + g2[i].first;
    }
    vector<pair<ll,ll>> mina(n), minb(n);
    for(int i=0;i<n;i++){
        if(i){
            mina[i] = min(mina[i-1], make_pair(a[i], (ll)i+1));
            minb[i] = min(minb[i-1], make_pair(b[i], (ll)i+1));
        }else{
            mina[i] = {a[i], i+1};
            minb[i] = {b[i], i+1};
        }
    }
    int lp = max(0, k-c2), hp = min(c1, k);
    ll minv = INF_LL;
    for(int j=lp;j<=hp;j++){
        minv = min(minv, ps1[j]*mina[n-1].first + ps2[k-j]*minb[n-1].first);
    }
    if(minv <= s){
        int lo = 0, hi = n-1;
        while(lo != hi){
            int mid = lo + (hi - lo) / 2;
            minv = INF_LL;
            for(int j=lp;j<=hp;j++){
                minv = min(minv, ps1[j]*mina[mid].first + ps2[k-j]*minb[mid].first);
            }
            if(minv <= s) hi = mid;
            else lo = mid + 1; 
        }
        cout << lo+1 << "\n";
        minv = INF_LL;
        int ind;
        for(int j=lp;j<=hp;j++){
            if(minv > ps1[j]*mina[lo].first + ps2[k-j]*minb[lo].first){
                minv = ps1[j]*mina[lo].first + ps2[k-j]*minb[lo].first;
                ind = j;
            }
        }
        for(int i=0;i<ind;i++){
            cout << g1[i].second << " " << mina[lo].second << "\n";
        }
        for(int i=0;i<k-ind;i++){
            cout << g2[i].second << " " << minb[lo].second << "\n";
        }
    }else cout << "-1\n";
        
}
