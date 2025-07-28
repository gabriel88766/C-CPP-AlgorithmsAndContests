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
    vector<int> a(n), b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];
    int p = 0;
    vector<int> us(n, -1);
    for(int i=0;i<n;i++){
        if(p < m && a[i] == b[p]){
            us[i] = p++;
        }
    }
    if(p != m){
        cout << "No\n";
        return 0;
    }
    bool ok = false;
    p = m-1;
    for(int i=n-1;i>=0;i--){
        if(p >= 0 && a[i] == b[p]){
            if(us[i] != p){
                ok = true;
            }
            p--;
        }
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
