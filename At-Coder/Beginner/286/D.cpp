#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bitset<10001> bs;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    bs[0] = 1;
    int n, x;
    cin >> n >> x;
    for(int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        for(int j=0;j<b;j++) bs |= bs << a;
    }
    if(bs[x]) cout << "Yes\n";
    else cout << "No\n";
}
