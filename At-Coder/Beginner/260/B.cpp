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
    vector<bool> us(n+1, false);
    int x, y, z;
    cin >> x >> y >> z;
    vector<int> a(n+1), b(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=1;i<=x;i++){
        int p = 1;
        for(int j=2;j<=n;j++){
            if(a[j] > a[p]) p = j;
        }
        us[p] = true;
        a[p] = b[p] = -1; 
    }
    for(int i=1;i<=y;i++){
        int p = 1;
        for(int j=2;j<=n;j++){
            if(b[j] > b[p]) p = j;
        }
        us[p] = true;
        a[p] = b[p] = -1; 
    }
    for(int i=1;i<=z;i++){
        int p = 1;
        for(int j=2;j<=n;j++){
            if(a[j] + b[j] > a[p] + b[p]) p = j;
        }
        us[p] = true;
        a[p] = b[p] = -1; 
    }
    for(int i=1;i<=n;i++){
        if(us[i]) cout << i << "\n";
    }
}
