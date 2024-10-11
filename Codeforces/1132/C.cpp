#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5005;
int cnt[N];
int ps[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //unoptimally
    int n, q;
    cin >> n >> q;
    vector<pair<int,int>> vq(q);
    for(int i=0;i<q;i++){
        int l, r;
        cin >> l >> r;
        vq[i] = {l, r};
        for(int j=l;j<=r;j++) cnt[j]++;
    }
    int ans = 0;
    for(int i=0;i<q;i++){
        auto [l, r] = vq[i];
        for(int j=l;j<=r;j++) cnt[j]--;
        int ansc = 0;
        for(int j=1;j<=n;j++) if(cnt[j]) ansc++;
        for(int j=1;j<=n;j++){
            ps[j] = ps[j-1];
            if(cnt[j] == 1) ps[j]++;
        }
        for(int j=i+1;j<q;j++){
            auto [l, r] = vq[j];
            int cur = ansc - ps[r] + ps[l-1];
            ans = max(ans, cur);
        }
        for(int j=l;j<=r;j++) cnt[j]++;
    }
    cout << ans << "\n";
}
