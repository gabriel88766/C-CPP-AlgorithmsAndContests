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
        vector<bool> used(1 << n, false);
        for(int x=n;x>=0;x--){
            int cn = (1 << x) - 1;
            for(int j=0;j<(1<<n);j++){
                if((cn & j) == cn && used[j] == false){
                    used[j] = true;
                    cout << j << " ";
                }
            }
        }
        cout << "\n";
    }
}
