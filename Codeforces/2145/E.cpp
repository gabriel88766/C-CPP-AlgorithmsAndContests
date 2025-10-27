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
    int ac, dr;
    cin >> ac >> dr;
    int n;
    cin >> n;
    vector<int> d(n+1), a(n+1), vp(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> d[i];
    vector<pair<int, int>> ins, rem;
    for(int i=1;i<=n;i++){
        vp[i] = max(d[i] - dr, 0) + max(a[i] - ac, 0);
        ins.push_back({vp[i], 0});
    }
    int q;
    cin >> q;
    for(int i=1;i<=q;i++){
        int k, na, nd;
        cin >> k >> na >> nd;
        rem.push_back({vp[k], i});
        // d[k] = nd;
        // a[k] = na;
        vp[k] = max(nd - dr, 0) + max(na - ac, 0);
        ins.push_back({vp[k], i});
        int ans = 0;
        for(int jmp = n/2;jmp>=1;jmp>>=1){
            while(ans + jmp <= n && os.find_by_order(ans + jmp - 1).first <= ans + jmp - 1) ans += jmp;
        }
    }

}
