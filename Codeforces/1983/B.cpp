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
        int n, m;
        cin >> n >> m;
        vector<string> g1(n), g2(n);
        for(int i=0;i<n;i++) cin >> g1[i];
        for(int i=0;i<n;i++) cin >> g2[i];
        bool ok = true;
        for(int i=0;i<n;i++){
            //line sum
            int s1 = 0, s2 = 0;
            for(int j=0;j<m;j++){
                s1 += g1[i][j] - '0';
                s2 += g2[i][j] - '0';
            }
            if(s1 % 3 != s2 % 3) ok = false;
        }
        for(int j=0;j<m;j++){
            //collumn sum
            int s1 = 0, s2 = 0;
            for(int i=0;i<n;i++){
                s1 += g1[i][j] - '0';
                s2 += g2[i][j] - '0';
            }
            if(s1 % 3 != s2 % 3) ok = false;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }

}
