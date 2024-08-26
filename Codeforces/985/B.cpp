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
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    vector<int> cnt(m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j] == '1') cnt[j]++;
        }
    }
    bool ok = false;
    for(int i=0;i<n;i++){
        bool cok = true;
        for(int j=0;j<m;j++){
            if(v[i][j] == '1' && cnt[j] == 1) cok = false;
        }
        if(cok) ok = true;
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
}
