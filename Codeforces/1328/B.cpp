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
        int n, k;
        cin >> n >> k;
        int p = n - 1;
        k--;
        while(k){
            int nxt = n - p;
            if(k >= nxt){
                p--;
                k -= nxt;
            }else break;
        }
        int p2 = n;
        while(k){
            k--;
            p2--;
        }
        for(int i=1;i<=n;i++){
            if(i == p || i == p2) cout << "b";
            else cout << "a";
        }
        cout << "\n";

    }
}
