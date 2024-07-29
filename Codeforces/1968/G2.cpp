#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int z[200005]; //Lenght of greatest prefix(sz) equals substr (i, i+sz-1) 
int n;
int ans[200005];
//Z-function
void zfunc(string s){
    int lm = 0, rm = 0;
    for(int i=0;i<n;i++) z[i] = 0;
    for(int i=1;i<s.size();i++){
        if(i < rm){
            z[i] = min(z[i-lm], rm-i);
        }
        while(i+z[i] < n && s[i+z[i]] == s[z[i]]) z[i]++;
        if(i + z[i] > rm){
            rm = i + z[i];
            lm = i;
        }
    }
}

ll calc(ll lo, ll hi, ll sz){
    while(lo != hi){
        int cnt = 1;
        int mid = lo + (hi - lo + 1)/2;
        int p = mid;
        while(p < n){
            if(z[p] >= mid){
                p += mid;
                cnt++;
            }else p++;
        }
        if(cnt >= sz) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}

//for l, m-1 => ans to hi. for m+1, r => lo to ans
void solve(ll l, ll r, ll lo = 0, ll hi = n){
    if(l > r) return;
    int m = (l + r) / 2;
    int ansc = calc(lo, hi, m);
    ans[m] = ansc;
    solve(l, m-1, ansc, hi);
    solve(m+1, r, lo, ansc);
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int l, r;
        cin >> n >> l >> r;
        string s;
        cin >> s;
        zfunc(s);
        solve(l, r);
        for(int i=l;i<=r;i++) cout << ans[i] << " ";
        cout << "\n";
    }
}
