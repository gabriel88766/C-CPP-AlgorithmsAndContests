#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll ask(int l, int r){
    cout << "? " << l << " " << r << "\n";
    cout.flush();
    ll ans;
    cin >> ans;
    return ans;
}
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
        vector<ll> ans(n+1);
        for(int i=1;i<n;i++){
            ans[i] = ask(i, n);
        }
        if(ans[1] == 0){
            cout << "! IMPOSSIBLE\n";
            cout.flush();
        }else{
            //possible, I think
            int f0;
            for(int i=n-1;i>=1;i--){
                if(ans[i] != 0){
                    f0 = i;
                    break;
                }
            }
            string rans = "";
            int aux = 0;
            for(int i=f0+1;i<=n;i++){
                if(aux < ans[f0]){
                    aux++;
                    rans += '1';
                }else{
                    rans += '0';
                }
            }
            reverse(rans.begin(), rans.end());
            for(int i=f0;i>=1;i--){
                if(ans[i] != ans[i+1]) rans += '0';
                else rans += '1';
            }
            reverse(rans.begin(), rans.end());
            cout << "! " << rans << "\n";
            cout.flush();

        }
    }
}
