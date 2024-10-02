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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> v(n);
        for(int i=0;i<n;i++){
            vector<int> cur(5);
            for(int j=0;j<5;j++) cin >> cur[j];
            v[i] = cur;
        }
        bool ok = false;
        for(int i=0;i<5;i++){
            for(int j=i+1;j<5;j++){
                int ai = 0, aj = 0, aij = 0, nok = 0;
                for(int k=0;k<n;k++){
                    if(v[k][i] == 1 && v[k][j] == 1) aij++;
                    if(v[k][i] == 1 && v[k][j] == 0) ai++;
                    if(v[k][i] == 0 && v[k][j] == 1) aj++;
                    if(v[k][i] == 0 && v[k][j] == 0) nok++;
                }
                if(nok) continue;
                if(ai <= n/2 && aj <= n/2) ok = true;
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
