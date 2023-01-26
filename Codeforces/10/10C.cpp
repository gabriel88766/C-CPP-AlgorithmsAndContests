#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dr[100];
ll total[100];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    for(int i=1;i<=81;i++){
        if(i < 10) dr[i] = i;
        else{
            int sumd = 0, aux = i;
            while(aux){
                sumd += aux % 10;
                aux /= 10;
            }
            dr[i] = dr[sumd];
        }
    }
    vector<vector<pair<ll,ll>>> abisc(10);
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            int res = dr[dr[i]*dr[j]];
            abisc[res].push_back({i, j});
        }
    }
    int n;
    cin >> n;
    ll ans = 0;
    for(int i=1;i<=9;i++){
        total[i] = n % 9 >= i ? 1 : 0;
        total[i] += n/9;
    }
    for(int i=1;i<=9;i++){
        for(auto u : abisc[i]){
            ans += total[u.first] * total[u.second] * total[i];
        }
    }
    for(int i=1;i<=n;i++){
        ans--;
        for(int j=(2*i);j<=n;j+=i){
            ans --;
        }
    }
    cout << ans;
}
