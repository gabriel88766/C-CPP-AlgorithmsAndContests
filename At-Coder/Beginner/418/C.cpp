#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+1;
ll sum[N];
ll cnt[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        int a;
        cin >> a;
        sum[a] += a;
        cnt[a] += 1;
    }
    for(int i=1;i<N;i++){
        cnt[i] += cnt[i-1];
        sum[i] += sum[i-1];
    }
    for(int i=1;i<=q;i++){
        ll b;
        cin >> b;
        ll mn = sum[b-1] + (n - cnt[b-1]) * (b-1);
        if(cnt[b-1] == n) cout << "-1\n";
        else cout << mn+1 << "\n";
    }

}
