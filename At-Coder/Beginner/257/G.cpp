#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int z[1000005]; //Lenght of greatest prefix(sz) equals substr (i, i+sz-1) 
//Z-function
void zfunc(string s){
    int lm = 0, rm = 0;
    for(int i=0;i<s.size();i++) z[i] = 0;
    for(int i=1;i<s.size();i++){
        if(i < rm){
            z[i] = min(z[i-lm], rm-i);
        }
        while(i+z[i] < s.size() && s[i+z[i]] == s[z[i]]) z[i]++;
        if(i + z[i] > rm){
            rm = i + z[i];
            lm = i;
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s, t;
    cin >> s >> t;
    string cat = s + "#" + t;
    zfunc(cat);
    vector<int> aux;
    for(int i=s.size();i<cat.size();i++) aux.push_back(z[i]);
    int n = t.size();
    vector<int> d(n+1, INF_INT);
    d[0] = 0;
    int mv = 0;
    for(int i=1;i<=n;i++){
        int val = d[i-1];
        if(val != INF_INT){ //means I can reach i-1 state
            if(aux[i] > 0){
                //means I can go further
                int r = i + aux[i] - 1;
                //set "j : [i, r]" = min(a[j], val + 1)
                if(mv+1 <= r){
                    for(int j=mv+1;j<=r;j++) d[j] = val + 1;
                    mv = r;
                }
            }
        }
    }
    int ans = d[n];
    if(ans == INF_INT) cout << -1 << "\n";
    else cout << ans << "\n";
}
