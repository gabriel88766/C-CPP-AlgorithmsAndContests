#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool pos[1001];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int a=1;a<=333;a++){
        for(int b=1;b<=333;b++){
            int S = 4*a*b + 3*a + 3*b;
            if(S <= 1000) pos[S] = true;
        }
    }
    int n, ans = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        if(!pos[aux]) ans++;
    }
    cout << ans << "\n";
}
