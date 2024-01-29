#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Query{
    int s, d, k, i;
};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        int sqt = sqrt(n);
        vector<Query> vq(q);
        vector<ll> ans(q);
        vector<int> num(n+1);
        for(int i=1;i<=n;i++) cin >> num[i];
        for(int i=0;i<q;i++){
            cin >> vq[i].s >> vq[i].d >> vq[i].k;
            vq[i].i = i;
        }     
        sort(vq.begin(), vq.end(), [&](Query &u, Query &v){
            return u.d < v.d;
        });
        int cd = 0;
        vector<ll> ps1(n+1), ps2(n+1);
        for(auto [s, d, k, i] : vq){
            if(cd != d && d < sqt){
                for(int j=n;j>=1;j--){
                    if(j + d <= n){
                        ps1[j] = num[j] + ps1[j + d];
                        ps2[j] = ps2[j + d] + ps1[j];
                    }else{
                        ps2[j] = ps1[j] = num[j];
                    }
                }
                cd = d;
            }
            if(d < sqt){
                ll ansc = ps2[s];
                if(s + d*k <= n){
                    ansc -= ps2[s+d*k] + ps1[s+d*k] * k;
                }
                ans[i] = ansc;
            }else{
                ll ansc = 0;
                for(ll j=1; j<= k; j++){
                    ansc += j * num[s + (j-1)*d];
                }
                ans[i] = ansc;
            }
        }
        for(int i=0;i<q;i++) cout << ans[i] << " ";
        cout << "\n";
    }
}
