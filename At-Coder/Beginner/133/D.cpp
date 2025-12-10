#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
ll a[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    ll sum = 0;
    for(int i=1;i<n;i++){
        if(i % 2) sum += a[i];
        else sum -= a[i];
    }
    ll lx = sum + a[n];
    cout << lx << " ";
    for(int i=2;i<=n;i++){
        ll nx = 2*a[i-1] - lx;
        cout << nx << " ";
        lx = nx;
    }
    cout << "\n";
}
