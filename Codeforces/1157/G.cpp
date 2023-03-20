#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
 
int v[201][201];
int n, m;
 
int ansi[201];
int ansj[201];

bool check(int l){
    for(int i=1;i<=n;i++) ansi[i] = -1;
    for(int j=1;j<=m;j++) ansj[j] = -1;
    if(l == n) ansi[n-1] = 0;
    else ansi[n] = 0;

    bool is1 = true;
    for(int i=n;i>=1;i--){
        if(i == l){
            is1 = false;
            continue;
        }
        for(int j=m;j>=1;j--){
            int aux = v[i][j]^(is1 ? 1 : 0);
            if(ansi[i] != -1 && ansj[j] != -1){
                if(ansi[i] ^ ansj[j] ^ aux) return false;
                else continue;
            }
            if(ansi[i] == -1){
                ansi[i] = ansj[j]^aux;
            }else ansj[j] = ansi[i]^aux;
        }
    }
    return true;
}
 
 
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> v[i][j];
        }
    }
    if(n == 1){
        cout << "YES\n";
        cout << "0\n";
        for(int i=1;i<=m;i++) cout << v[1][i]; 
        return 0;
    }
    bool ok = false;
    for(int i=n;i>=1;i--){  
        if(check(i)){
            bool bg1 = false;
            ansi[i] = ansj[1]^v[i][1];
            bool ok2 = true;
            for(int j=2;j<=m;j++){
                //line i is increasing!
                if(ansi[i] ^ ansj[j] ^ v[i][j]){
                    bg1 = true;
               }else{
                    if(bg1){
                        ok2 = false;
                        break;
                    }
                }
            }
            if(ok2){
                ok = true;
                break;
            }
        }
    }
    if(ok){
        cout << "YES\n";
        for(int i=1;i<=n;i++) cout << ansi[i];
        cout << "\n";
        for(int j=1;j<=m;j++) cout << ansj[j];
    }else cout << "NO";
}