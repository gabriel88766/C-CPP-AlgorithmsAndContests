#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5005;
int r[N], v[N], ans[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        r[i] = 1e9;
    }
    vector<tuple<int,int,int,int>> qr;
    for(int i=1;i<=m;i++){
        int t, ll, rr, d;
        cin >> t >> ll >> rr >> d;
        qr.push_back({t, ll, rr, d});
        if(t == 1){
            for(int j=ll;j<=rr;j++) v[j] += d;
        }else{
            for(int j=ll;j<=rr;j++){
                r[j] = min(r[j], d - v[j]);
            }
        }
    }
    for(int i=1;i<=n;i++) ans[i] = r[i];
    bool ok = true;
    for(int i=1;i<=n;i++) v[i] = 0;
    for(auto [t, ll, rr, d] : qr){
        if(t == 1){
            for(int j=ll;j<=rr;j++) v[j] += d;
        }else{
            int mv = -INF_INT;
            for(int j=ll;j<=rr;j++){
                mv = max(mv, ans[j] + v[j]);
            }
            if(mv != d) ok = false;
        }
    }
    if(ok){
        cout << "YES\n";
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << "\n";
    }else cout << "NO\n";
}
