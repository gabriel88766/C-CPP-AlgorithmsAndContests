#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


//int p[] = {1, 3, 9, 27, 81, 243, 729, ...}

ll ps[200005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    ps[0] = 0;
    for(int i=1;i<=200000;i++){
        int aux = i;
        ps[i] = ps[i-1];
        while(aux){
            aux /= 3;
            ps[i]++;
        }
    }
    cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        int ans = 0;
        int aux = l;
        while(aux){
            aux /= 3;
            ans += 2;
        }
        ans += ps[r] - ps[l];
        cout << ans << "\n";
    }
}
