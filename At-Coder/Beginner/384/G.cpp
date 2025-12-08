#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int sqrtM = 50;
const int M = 100005;
const int sqrtN = 500;
const int N = 200005;

ll va[M], vb[M];
ll pa[M], pb[M];
ll rans[M];

struct SqrDec{
    array<ll, N> v;
    array<ll, N> blk;
    int n;
    SqrDec(int n){
        this->n = n;
    }
    void clear(){
        for(int i=0;i<n;i++){
            blk[i] = v[i] = 0;
        }
    }

    ll query(int a, int b){
        int l = (a/sqrtN+1)*sqrtN;
        int r = (b/sqrtN)*sqrtN;
        ll ans = 0;
        if(r <= l){
            for(int i=a;i<=b;i++) ans += v[i];
        }else{
            for(int i=a;i<l;i++) ans += v[i];
            for(int i=r;i<=b;i++) ans += v[i];
            l /= sqrtN, r /= sqrtN;
            for(int i=l;i<r;i++){
                ans += blk[i];
            }
        }
        return ans;
    }

    void update(ll pos, ll val){ //PURS
        blk[pos/sqrtN] += val;
        v[pos] += val;
    }
};

ll ps1[N], ps2[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    //let a[0] = b[0] = 0;
    vector<int> cds;
    for(int i=0;i<n;i++){
        cin >> va[i];
        cds.push_back(va[i]);
    }
    for(int i=0;i<n;i++) {
        cin >> vb[i];
        cds.push_back(vb[i]);
    }
    sort(cds.begin(), cds.end());
    cds.resize(unique(cds.begin(), cds.end()) - cds.begin());
    for(int i=0;i<n;i++){
        pa[i] = lower_bound(cds.begin(), cds.end(), va[i]) - cds.begin();
        pb[i] = lower_bound(cds.begin(), cds.end(), vb[i]) - cds.begin();
    }
    int k;
    cin >> k;
    vector<tuple<int, int, int>> qr;
    for(int i=1;i<=k;i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        qr.push_back({x, y, i});
    }
    sort(qr.begin(), qr.end(), [&](tuple<int, int, int> a, tuple<int, int, int> b){
        auto [a1, b1, c1] = a;
        auto [a2, b2, c2] = b;
        if(a1 / sqrtM == a2 / sqrtM){
            return b1 < b2;
        }else{
            return a1 < a2;
        }
    });
    int px = 0;
    SqrDec sq1(cds.size()), sq2(cds.size());
    int mx = cds.size() - 1;
    for(int b = 0; ;b++){
        if(px == qr.size()) break;
        if(get<0>(qr[px])/sqrtM != b) continue;
        for(int i=0;i<=mx;i++){
            ps1[i] = ps2[i] = 0;
        }
        for(int i=0;i<b*sqrtM;i++){
            ps1[pa[i]] += va[i];
            ps2[pa[i]] += 1;
        }
        for(int i=1;i<=mx;i++){
            ps1[i] += ps1[i-1];
            ps2[i] += ps2[i-1];
        }
        ll ans = 0;
        sq1.clear();
        sq2.clear();
        for(int j=0;j<n;j++){
            if(px == qr.size()) break;
            if(get<0>(qr[px])/sqrtM != b) break;
            ans += ps1[mx] - 2 * ps1[pb[j]] + (2 * ps2[pb[j]] - ps2[mx]) * vb[j];
            sq1.update(pb[j], vb[j]);
            sq2.update(pb[j], 1);
            while(px < qr.size() && get<1>(qr[px]) == j && get<0>(qr[px])/sqrtM == b){
                ll cans = ans;
                // cout << cans << "\n";
                for(int u=b*sqrtM; u <= get<0>(qr[px]); u++){
                    cans += sq1.query(0, mx) - 2 * sq1.query(0, pa[u]);
                    cans += (2 * sq2.query(0, pa[u]) - sq2.query(0, mx)) * va[u];
                }
                rans[get<2>(qr[px])] = cans;
                px++;
            }
        }
    }
    for(int i=1;i<=k;i++){
        cout << rans[i] << "\n";
    }
}
