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
    cin >> n;
    n--;
    vector<int> c(n+1), b(n+1), m(n+1);
    for(int i=1;i<=n;i++) cin >> c[i] >> b[i] >> m[i];
    for(int i=1;i<=n;i++){
        int cur = 0;
        for(int j=i;j<=n;j++){
            cur = max(cur, b[j]);
            while((cur-b[j])%m[j]) cur++;
            cur += c[j];
        }
        cout << cur << "\n";
    }
    cout << 0;
}
