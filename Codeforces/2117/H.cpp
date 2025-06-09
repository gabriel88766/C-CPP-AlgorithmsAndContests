#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 300005;
int pr[4*N], su[4*N], st[4*N], sum[4*N];
int v[N];
int n;

int val[N];
int cnt[N];

void build(int l = 1, int r = n, int p = 1){
    if(l == r){ pr[p] = su[p] = st[p] = sum[p] = v[l]; return; }
    build(l, (l+r)/2, 2 * p);
    build((l+r)/2 + 1, r, 2 * p + 1);
    pr[p] = max(pr[2*p], sum[2*p] + pr[2*p+1]);
    su[p] = max(su[2*p+1], su[2*p] + sum[2*p+1]);
    st[p] = max(st[2*p], max(st[2*p+1], su[2*p] + pr[2*p+1]));
    sum[p] = sum[2*p] + sum[2*p+1];
}
 
void update(int i, int value, int l = 1, int r = n, int p = 1){
    if(i < l || i > r) return;
    if(l == r) {pr[p] = su[p] = st[p] = sum[p] = value; return;}
    update(i, value, l, (l + r)/2, 2 * p);
    update(i, value, (l + r)/2 + 1, r, 2 * p + 1);
    pr[p] = max(pr[2*p], sum[2*p] + pr[2*p+1]);
    su[p] = max(su[2*p+1], su[2*p] + sum[2*p+1]);
    st[p] = max(st[2*p], max(st[2*p+1], su[2*p] + pr[2*p+1]));
    sum[p] = sum[2*p] + sum[2*p+1];
}


int u[N];
vector<pair<int, int>> ins[N];
vector<pair<int, int>> rem[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int q;
        cin >> n >> q;
        for(int i=1;i<=n;i++) v[i] = -1;
        build();
        for(int i=1;i<=n;i++){
            cin >> u[i];
            ins[u[i]].push_back({i, 0});
        }
        for(int i=1;i<=q;i++){
            int j, x;
            cin >> j >> x;
            if(x != u[j]){
                rem[u[j]].push_back({j, i});
                u[j] = x;
                ins[u[j]].push_back({j, i});
            }
        }
        for(int i=1;i<=n;i++){
            rem[u[i]].push_back({i, q+1});
        }
        for(int i=1;i<=n;i++){
            reverse(ins[i].begin(), ins[i].end());
            reverse(rem[i].begin(), rem[i].end());
        }
        vector<vector<pair<int, int>>> upd(q+1);
        for(int i=1;i<=n;i++){
            while(ins[i].size() || rem[i].size()){
                int inst = INF_INT;
                if(ins[i].size()) inst = ins[i].back().second;
                if(rem[i].size()) inst = min(rem[i].back().second, inst);
                while(ins[i].size() && ins[i].back().second == inst){
                    update(ins[i].back().first, 1);
                    ins[i].pop_back();
                }
                while(rem[i].size() && rem[i].back().second == inst){
                    update(rem[i].back().first, -1);
                    rem[i].pop_back();
                }
                if(inst != q+1) upd[inst].push_back({i, st[1] >= 0 ? st[1] : 0});
            }
        }
        int ans = 0;
        for(auto &[a, b] : upd[0]){
            val[a] = b; 
            cnt[val[a]]++;
        }
        for(int i=n;i>=1;i--){
            if(cnt[i] > 0){
                ans = i;
                break;
            }
        }
        cnt[0] = 1000000;
        for(int i=1;i<=q;i++){
            for(auto &[a, b] : upd[i]){
                cnt[val[a]]--;
                val[a] = b;
                cnt[val[a]]++;
            }
            if(cnt[ans + 2]) ans+=2;
            else if(cnt[ans + 1]) ans += 1;
            else if(!cnt[ans]){
                if(ans >= 1 && cnt[ans - 1]) ans -= 1;
                else if(ans >= 2 && cnt[ans - 2]) ans -= 2;
                else assert(false);
            }
            cout << ans/2 << " ";
        }
        for(int i=0;i<=n;i++){
            cnt[i] = 0;
            val[i] = 0;
        }
        cout << "\n";
    }
}
