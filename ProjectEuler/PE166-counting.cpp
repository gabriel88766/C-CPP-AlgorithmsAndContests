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
    vector<vector<int>> ps[40];
    for(int i=0;i<=9999;i++){
        int sdig = 0;
        vector<int> ns;
        int cn = i;
        for(int j=0;j<4;j++){
            ns.push_back(cn % 10);
            sdig += cn % 10;
            cn /= 10;
        }
        ps[sdig].push_back(ns);
    }
    ll ans = 0;
    int v4[4];
    for(int i=0;i<=36;i++){
        for(auto &v1 : ps[i]){
            for(auto &v2 : ps[i]){
                for(auto &v3 : ps[i]){
                    v4[0] = v4[1] = v4[2] = v4[3] = i;
                    bool ok = true;
                    for(int j = 0; j < 4; j++){
                         v4[j] -= v1[j] + v2[j] + v3[j];
                         if(v4[j] < 0 || v4[j] >= 10) ok = false;
                    }
                    if(!ok) continue;
                    if(v1[0] + v2[1] + v3[2] + v4[3] != i) continue;
                    if(v1[3] + v2[2] + v3[1] + v4[0] != i) continue;
                    ans++;
                }
            }
        }
    }

    cout << ans << "\n";
}   
