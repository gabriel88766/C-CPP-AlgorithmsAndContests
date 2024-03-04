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
    int v1, v2, v3;
    cin >> v1 >> v2 >> v3;
    bool ok = false;
    for(int i=0;i<4096;i++){
        if(ok) break;
        for(int j=0;j<4096;j++){
            if(ok) break;
            int x1, y1, z1, x2, y2, z2;
            int aux = i;
            x1 = aux % 16;
            aux /= 16;
            y1 = aux % 16;
            aux /= 16;
            z1 = aux % 16;
            aux = j;
            x2 = aux % 16;
            aux /= 16;
            y2 = aux % 16;
            aux /= 16;
            z2 = aux % 16;
            int v3c = 0, v2c = 0, v1c = 0;
            v3c = max(min(14, min(x1+7, x2+7)) - max(max(x1,7), x2), 0)*max(min(14, min(y1+7, y2+7)) - max(max(y1, 7), y2), 0)*max(min(14, min(z1+7, z2+7)) - max(max(z1, 7), z2), 0);
            v2c = max(min(x1+7,x2+7) - max(x1, x2), 0)*max(min(y1+7,y2+7) - max(y1, y2), 0)*max(min(z1+7,z2+7) - max(z1, z2), 0) + max(min(14, x1+7) - max(7, x1), 0)*max(min(14, y1+7) - max(7, y1), 0)*max(min(14, z1+7) - max(7, z1), 0) + max(min(14, x2+7) - max(7, x2), 0)*max(min(14, y2+7) - max(7, y2), 0)*max(min(14, z2+7) - max(7, z2), 0);
            v2c -= 3*v3c;
            v1c = 343*3 - 2*v2c - 3*v3c;
            if(v3c == v3 && v2c == v2 && v1c == v1){
                ok = true;
                cout << "Yes\n";
                cout << "7 7 7 " << x1 << " " << y1 << " " << z1 << " " << x2 << " " << y2 << " " << z2 << "\n"; 
            }
        }
    }
    if(!ok) cout << "No\n";
}
