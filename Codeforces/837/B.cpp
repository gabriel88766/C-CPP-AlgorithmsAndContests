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
    bool ok = false;
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    if(!(n % 3)){
        //check i;
        bool cok = true;
        set<char> c;
        for(int u=0;u<3;u++){
            c.insert(v[(n/3)*u][0]);
            for(int i=(n/3)*u;i<(n/3)*(u+1);i++){
                for(int j=0;j<m;j++){
                    if(v[i][j] != v[(n/3)*u][0]) cok = false;
                }
            }
        }
        if(cok && c.size() == 3) ok = true;
    }
    if(!(m%3)){
        bool cok = true;
        set<char> c;
        for(int u=0;u<3;u++){
            c.insert(v[0][(m/3)*u]);
            for(int i=0;i<n;i++){
                for(int j=(m/3)*u;j<(m/3)*(u+1);j++){
                    if(v[i][j] != v[0][(m/3)*u]) cok = false;
                }
            }
        }
        if(cok && c.size() == 3) ok = true;
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
}
