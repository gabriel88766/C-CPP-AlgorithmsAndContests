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
    int n;
    string t;
    cin >> n >> t;
    vector<int> b(n, 0), e(n, 0);
    int m = t.size();
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        int p = 0;
        for(int i=0;i<s.size();i++){
            if(p < m && s[i] == t[p]){
                p++;
            }
        }
        b[i] = p;
        p = m-1;
        for(int i=s.size()-1;i>= 0;i--){
            if(p >= 0 && s[i] == t[p]){
                p--;
            }
        }
        e[i] = m-1-p;
    }
    vector<int> ce(m+1, 0), cb(m+1, 0);
    for(int i=0;i<n;i++){
        ce[e[i]]++;
        cb[b[i]]++;
    }
    for(int i=1;i<=m;i++){
        ce[i] += ce[i-1];
        cb[i] += cb[i-1];
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        int qt = m-b[i]-1;
        if(qt < 0) ans += n;
        else ans += n - ce[m-b[i]-1];
    }
    cout << ans << "\n";

}
