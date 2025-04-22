#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5 + 3;
int v[N];
vector<int> pl[N];
vector<int> dv[N];
ll ans[N];
void init(){
    for(int i=2;i<N;i++){
        for(int j=i;j<N;j+=i){
            dv[j].push_back(i);
        }
    }
}
vector<tuple<int, int, int>> qr[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        for(int i=1;i<=n;i++){
            cin >> v[i];
        }
        for(int i=n;i>=1;i--){
            pl[v[i]].push_back(i);
        }
        
        //weird code, whatever!
        for(int i=1;i<=q;i++) ans[i] = 0;

        for(int i=1;i<=q;i++){
            int k, l, r;
            cin >> k >> l >> r;
            qr[l].push_back({i, k, r});
        }
        for(int i=1;i<=n;i++){
            while(qr[i].size()){
                auto [j, k, r] = qr[i].back();
                qr[i].pop_back();
                int mn = INF_INT;
                for(auto &x : dv[k]){
                    if(pl[x].size()){
                        mn = min(mn, pl[x].back());
                    }
                }
                if(mn > r){
                    ans[j] += ((ll)(r - i + 1)) * k; 
                }else{
                    ans[j] += ((ll)(mn - i)) * k;
                    while(!(k % v[mn])) k /= v[mn];
                    ans[j] += k;
                    if(mn != r){
                        qr[mn+1].push_back({j, k, r});
                    } 
                }
            }
            pl[v[i]].pop_back();
        }
        for(int i=1;i<=q;i++){
            cout << ans[i] << "\n";
        }
    }
}
