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
    vector<ll> a(n+1), b(n+1);
    for(int i=1;i<=n;i++) cin >> a[i] >> b[i];
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 1);
    sort(ord.begin(), ord.end(), [&](int &x, int &y){
        ll n1 = a[x];
        ll d1 = a[x] + b[x];
        ll n2 = a[y];
        ll d2 = a[y] + b[y];
        if(n1 * d2 == n2 * d1) return x < y;
        else return n1*d2 > n2*d1;
    });
    for(auto &x : ord) cout << x << " ";
    cout << "\n";
}
