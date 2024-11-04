#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 505;
vector<int> r[N];
int cnt[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, q;
    cin >> n >> m >> q;
    for(int i=1;i<=m;i++){
        int l, rr;
        cin >> l >> rr;
        r[l].push_back(rr);
        cnt[rr]++;
    }
    vector<tuple<int,int,int>> qr;
    vector<int> ans(q+1);
    for(int i=1;i<=q;i++){
        int l, r;
        cin >> l >> r;
        qr.push_back({l, r, i});
    }
    sort(qr.begin(), qr.end());
    int p = 1;
    for(auto [l, rr, j] : qr){
        while(p != l){
            for(auto x : r[p]) cnt[x]--;
            p++;
        }
        int cur = 0;
        for(int i=l;i<=rr;i++) cur += cnt[i];
        ans[j] = cur;
    }
    for(int i=1;i<=q;i++) cout << ans[i] << "\n";
}
