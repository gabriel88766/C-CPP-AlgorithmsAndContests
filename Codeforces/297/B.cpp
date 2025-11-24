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
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    if(n > m) cout << "YES\n";
    else{
        bool ok = false;
        for(int i=0;i<n;i++){
            if(a[i] > b[i]) ok = true;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
