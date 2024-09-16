#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 200005, M = 20; // M >= log2(N)
ll sparse[N][M];
ll v[N], ps[N];
int n;

void build(){
    for(int i=1;i<=n;i++) sparse[i][0] = v[i];
    for(int j = 1; j < M; j++){
        for(int i = 1; i <= n; i++){
            if((i + (1 << (j-1))) <= n) sparse[i][j] = max(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]);
            else sparse[i][j] = sparse[i][j-1];
        }
    }
}

ll query(int a, int b){
    if(a == b) return sparse[a][0]; //bug
    int pot = 32 - __builtin_clz(b - a) - 1; 
    return max(sparse[a][pot], sparse[b - (1 << pot) + 1][pot]);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> n >> x;
        for(int i=1;i<=n;i++){
            cin >> v[i];
            ps[i] = ps[i-1] + v[i];
        }
        build();
        vector<int> ans(n+2, 0);
        for(int i=1;i<=n;i++){
            int l = i, r = i;
            while(l > 1){
                ll curs = ps[r] - ps[l-1];
                int nl = l, nr = r;
                for(int j = n/2;j>=1;j>>=1){
                    while(nl - j >= 1 && query(nl-j, r) <= curs) nl -= j;
                }
                if(nl != l){
                    l = nl;
                }else{
                    ll dif = v[l-1] - curs;
                    for(int j = n/2;j>=1;j>>=1){
                        while(nr + j <= n && ps[nr + j] - ps[r] < dif && query(l, nr+j) <= curs) nr += j;
                    }
                    if(nr == n) break;
                    ll xs = ps[nr] - ps[r];
                    if(xs+curs >= query(nr+1,nr+1)) nr++;
                    if(r == nr) break;
                    r = nr;
                }
            }
            if(l == 1){
                //what should i do now?
                //try to expand the most
                int lr = r;
                int hr = r;
                while(hr < n){
                    ll curs = ps[hr];
                    int ov = hr;
                    for(int j = n/2;j>=1;j>>=1){
                        while(hr + j <= n && query(1, hr+j) <= curs) hr += j;
                    }
                    if(ov == hr) break;
                }
                ans[lr]++;
                ans[hr+1]--;
            }
        }
        for(int i=1;i<=n;i++){
            ans[i] += ans[i-1];
            if(i >= x) cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
