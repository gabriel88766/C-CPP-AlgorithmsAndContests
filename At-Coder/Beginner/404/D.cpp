#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 11, M = 101;
ll cost[N];
vector<int> zoo[M];

int p3[11];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    p3[0] = 1;
    for(int i=1;i<=10;i++){
        p3[i] = 3 * p3[i-1];
    }
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> cost[i];
    for(int i=1;i<=m;i++){
        int k;
        cin >> k;
        for(int j=0;j<k;j++){
            int x;
            cin >> x;
            zoo[i].push_back(x-1);
        }
    }
    ll ans = INF_LL;
    for(int i=0;i<p3[n];i++){
        vector<int> cv(n);
        int aux = i;
        int p = 0;
        while(aux){
            cv[p++] = aux % 3;
            aux /= 3;
        }
        ll fee = 0;
        for(int j=0;j<n;j++){
            fee += cv[j] * cost[j];
        }
        bool ok = true;
        for(int j=1;j<=m;j++){
            int ttv = 0;
            for(auto &x : zoo[j]) ttv += cv[x];
            if(ttv < 2) ok = false;
        }
        if(ok) ans = min(ans, fee);
    }
    cout << ans << "\n";
}
