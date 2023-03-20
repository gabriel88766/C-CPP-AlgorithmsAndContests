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
    vector<int> ps(n+1);
    ps[1] = 0;
    for(int i=2;i<=n;i++) {
        cin >> ps[i];
        ps[i] += ps[i-1];
    }
    int a,b;
    cin >> a >> b;
    cout << ps[b] - ps[a];
}
