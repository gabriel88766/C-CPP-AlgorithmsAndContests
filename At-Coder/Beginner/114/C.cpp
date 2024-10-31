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
    int n;
    cin >> n;
    int aux3[] = {3, 5, 7};
    int aux = 1;
    int ans = 0;
    for(int d=1;d<=9;d++){
        aux *= 3;
        for(int j=0;j<aux;j++){
            int aux2 = j;
            int num = 0;
            bool used[] = {false, false, false};
            for(int k=1;k<=d;k++){
                num *= 10;
                num += aux3[aux2 % 3];
                used[aux2 % 3] = true;
                aux2 /= 3;
            }
            if(num <= n && used[0] && used[1] && used[2]) ans++;
        }
    }
    cout << ans << "\n";
}
