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
    vector<ll> cnt(n+1, n-1);
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        cnt[a]--, cnt[b]--;
    }
    for(int i=1;i<=n;i++){
        if(cnt[i] >= 3) cout << (cnt[i] * (cnt[i] - 1) * (cnt[i]-2))/6 << " ";
        else cout << "0 ";
    }
    cout << "\n";
}
