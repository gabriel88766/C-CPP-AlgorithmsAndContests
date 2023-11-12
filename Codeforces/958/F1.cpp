#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
//BRUTE FORCE
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    vector<int> k(m+1);
    int len = 0;
    for(int i=1;i<=m;i++){
         cin >> k[i];
         len += k[i];
    }
    bool ok = false;
    for(int i=0;i<n;i++){
        vector<int> qt(m+1);
        for(int j=i;i + len <= n && j < i + len; j++){
            qt[v[j]]++;
        }
        bool cok = true;
        for(int j=1;j<=m;j++) if(qt[j] != k[j]) cok = false;
        if(cok){
            ok = true;
            break;
        }
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
}
