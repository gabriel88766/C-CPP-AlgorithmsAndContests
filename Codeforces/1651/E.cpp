//UNSOLVED
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<int> adj[1505];

ll sum(ll n){
    return (n * (n+1))/2;
}

ll n;
ll calc(ll v1, ll v2){
    if(v1 > v2) swap(v1, v2); //v1 < v2
    return v1 * (n-v1+1) + v2 * (n-v2 + 1) - v1 * (n-v2+1);
}
ll calc(ll v1){
    return v1 * (n - v1 + 1);
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n;
    for(int i=1;i<=2*n;i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y-n);
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        vector<int> cnt(n+1);
        vector<int> op(n+1), opmx(n+1), opmn(n+1);
        ll sc = 0;
        for(int j=i;j<=n;j++){
            int v1 = adj[j][0];
            int v2 = adj[j][1];
            //4 possibilities
            if(cnt[v1] == 0 && cnt[v2] == 0){
                opmx[v1] = opmx[v2] = max(v1, v2);
                opmn[v1] = opmn[v2] = min(v1, v2);
                op[v1] = v2;
                op[v2] = v1;
                //if L <= v1 <= R || L <= v2 <= R, sum 1
                sc += calc(v1, v2);
            }
            if(cnt[v1] == 0 && cnt[v2] == 1){
                swap(v1, v2);
            }
            if(cnt[v1] == 1 && cnt[v2] == 0){
                sc -= calc(v1, op[v1]);
                sc += calc(v1);
                sc += calc(v2, op[v1]);
                opmn[op[v1]] = opmn[v2] = min(opmn[op[v1]], v2);
                opmx[op[v1]] = opmax[v2] = max(opmx[op[v1]], v2);
                if(min(v2, op[v1]) < opmx[v2] || max(v2, op[v1]) > opmn[v2]) sc +=  
                op[v2] = op[v1];
                op[op[v1]] = v2;
            }
            if(cnt[v1] == 1 && cnt[v2] == 1){
                if(op[v1] != v2){
                    sc -= calc(v1, op[v1]);
                    sc -= calc(v2, op[v2]);
                    sc += calc(v1);
                    sc += calc(v2);
                    sc -= calc(op[v1], op[v2]);
                    op[op[v1]] = op[v2];
                    op[op[v2]] = op[v1];

                }else{
                    
                    //looping
                    sc -= calc(v1, v2);
                    sc += calc(v1);
                    sc += calc(v2);
                }
            }
            cnt[v1]++;
            cnt[v2]++;
            ans += sc;
        }
    }
    cout << ans << "\n";
}
