#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+1;
const int sqrtN = 1000;
int ans[N];
int aux[230][N];

struct Query{
    int i, x, j;
    bool operator< (const Query &q) const {
        if(x != q.x) return x < q.x;
        else return i < q.i;
    }
};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    vector<ll> lv(n+1);
    for(int i=1;i<=n;i++) cin >> lv[i];
    vector<Query> vq(q);
    for(int i=0;i<q;i++){
        int j, x;
        cin >> j >> x;
        vq[i] = {j, x, i};
    }
    sort(vq.begin(), vq.end());
    int p = 0;
    for(int i=1;i<=229;i++){
        for(int j=1;j<=n;j++){
            aux[i][j] = aux[i][j-1] + (lv[j] >= i ? 1 : 0);   
        }
    }
    for(int k=1;k<=n;k++){
        int p2 = 1;
        int cl = 1;
        int ck = 0;
        if(k <= sqrtN){
            while(p < q && vq[p].x == k){
                while(p2 != vq[p].i){
                    if(cl <= lv[p2]){
                        ck++;
                    }
                    if(ck == k){
                        ck = 0;
                        cl++;
                    }
                    p2++;
                }
                if(cl <= lv[p2]){
                    ans[vq[p].j] = 1;
                }else ans[vq[p].j] = 0;
                p++;
            }
        }else{
            p2 = 0;
            while(p < q && vq[p].x == k){
                int np = p2;
                for(int jp = n/2; jp >= 1; jp /= 2){
                    while(np + jp <= n && aux[cl][np + jp] - aux[cl][p2] <= k) np += jp;
                }
                if(np < vq[p].i){
                    cl++;
                    p2 = np;
                }else{
                    while(p < q && vq[p].x == k && vq[p].i <= np){
                        if(cl <= lv[vq[p].i]){
                            ans[vq[p].j] = 1;
                        }else ans[vq[p].j] = 0;
                        p++;
                    }
                }

            }
        }
    }
    for(int i=0;i<q;i++){
        if(ans[i]) cout << "YES\n";
        else cout << "NO\n";
    }

}
