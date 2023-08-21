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
    int n, k;
    cin >> n >> k;
    if(k == 1){
        vector<int> ans(n+1);
        for(int i=1;i<=n;i++){
            cout << "? " << i << "\n";
            cout.flush();
            cin >> ans[i];
        }
        cout << "! ";
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << "\n";
        cout.flush();
    }else {
        //g1 = {1,2,...,k-1} g2 = {k, ... n}
        vector<int> ans(n+1); //suppose 1^2^3^..^k-1 = 0
        for(int i=k;i<=n;i++){
            cout << "? ";
            for(int j=1;j<k;j++) cout << j << " ";
            cout << i << "\n";
            cout.flush();
            cin >> ans[i];
        }
        int xx = ans[k]^ans[k+1];
        for(int i=1;i<k;i++){
            cout << "? ";
            for(int j=1;j<k;j++){
                if(i != j) cout << j << " ";
            }
            cout << k << " " << k+1 << "\n";
            cout.flush();
            cin >> ans[i];
            ans[i] ^= xx;
        }
        int p = 0;
        for(int i=1;i<k;i++) p^= ans[i];
        if(p == 1){
            for(int i=1;i<=n;i++) ans[i] ^= 1;
        }
        cout << "! ";
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << "\n";
        cout.flush();
    }
}
