#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 105;
const int M = 15;
int hi[N][1 << M], lo[N][1 << M]; 
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<(1 << 15);j++){
            for(int k=0;k<15;k++){
                int b = ((v[i] & (1 << k)) >> k);
                if(j & (1 << k)) b ^= 1;
                assert(b == 0 || b == 1);
                lo[i][j] += b;
            }
            for(int k=0;k<15;k++){
                int b = ((v[i] & (1 << (k + 15))) >> (k + 15));
                if(j & (1 << k)) b ^= 1;
                assert(b == 0 || b == 1);
                hi[i][j] += b;
            }
        }
    }
    map<vector<int>, int> mp;
    for(int i=0;i<(1 << 15);i++){
        vector<int> cur;
        for(int j=0;j<n;j++) cur.push_back(lo[j][i]);
        mp[cur] = i;
    }
    bool ok = false;
    for(int i=0;i<(1 << 15);i++){
        vector<int> aux;
        for(int j=0;j<n;j++) aux.push_back(hi[j][i]);
        vector<int> cur(n);
        for(int val = 0;val<=30;val++){
            
            bool okh = true;
            for(int j=0;j<n;j++){
                if(val < aux[j]) okh = false;
                if(val - aux[j] > 15) okh = false;
                if(!okh) break;
                cur[j] = val - aux[j];
            }
            if(okh){
                if(mp.count(cur)){
                    ok = true;
                    int ans = i << 15;
                    ans += mp[cur];
                    cout << ans << "\n";
                }
            }
            if(ok) break;
        }
        if(ok) break;
    }
    if(!ok) cout << "-1\n";
}