#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll v[200005];
ll cg[16777216];
ll cnt[16777216];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    ull ans = 0;
    for(int b=0;b<=24;b++){
        int n2 = 1 << (b+1);
        int hf = 1 << b;
        for(int i=1;i<=n;i++){
            cg[v[i] % n2] += v[i];
            cnt[v[i] % n2]++;
        }
        for(int i=1;i<=n;i++){
            int cur = v[i] % n2;
            int goal = (hf >= cur ? hf - cur : n2 - cur + hf);
            ans += (v[i] * cnt[goal] + cg[goal]) / hf;
        }
        for(int i=1;i<=n;i++){
            cg[v[i] % n2] -= v[i];
            cnt[v[i] % n2]--;
        }
    }
    for(int i=1;i<=n;i++){
        ll cur = 2*v[i];
        while(!(cur & 1)) cur >>= 1;
        ans += cur;
    }
    ans /= 2;
    cout << ans << "\n";
}
