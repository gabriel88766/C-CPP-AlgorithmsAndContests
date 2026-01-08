#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int f[1 << 20];
ll g[1 << 20];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        int msk = 0;
        for(auto c : s){
            msk <<= 1;
            if(c == '1') msk |= 1;
        }
        f[msk] += 1;
    }
    //subset zeta
    for(int j = 1; j < (1 << k); j <<= 1){
        for(int i = 0; i < (1 << k);i++){
            if(i & j){
                f[i] += f[i^j];
            }
        }
    }
    for(int i = 0; i < (1 << k); i++){
        ll cf = f[i];
        g[i] = (cf * (cf - 1) * (cf - 2))/6;
    }
    //subset mobius
    for(int j = 1; j < (1 << k); j <<= 1){
        for(int i = 0; i < (1 << k);i++){
            if(i & j){
                g[i] -= g[i^j];
            }
        }
    }
    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        string s;
        cin >> s;
        int msk = 0;
        for(auto c : s){
            msk <<= 1;
            if(c == '1') msk |= 1;
        }
        cout << g[msk] << "\n";
    }
}
