#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int k;
    cin >> k;
    vector<ll> qt(k);
    for(int i=0;i<k;i++) cin >> qt[i];
    int n;
    cin >> n;
    vector<vector<ll>> v(n, vector<ll>(k));
    vector<ll> sum(k);
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin >> v[i][j];
            sum[j] += v[i][j];
        }
    }
    ll mn = INF_LL;
    for(int j=0;j<k;j++){
        if(sum[j] != 0) mn = min(mn, qt[j] / sum[j]);
    }
    cout << mn + 1 << " ";
    for(int j=0;j<k;j++){
        qt[j] -= mn * sum[j];
    }
    for(int i=0;i<n;i++){
        bool ok = true;
        for(int j=0;j<k;j++){
            qt[j] -= v[i][j];
            if(qt[j] < 0){
                ok = false;
            }
        }
        if(!ok){
            cout << i+1 << "\n";
            break;
        }
    }
}
