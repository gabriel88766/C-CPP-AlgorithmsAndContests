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
        int n, m, k;
        cin >> n >> m >> k;
        if(m % k){
            int cn = 1;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cout << cn << " ";
                    cn++;
                    if(cn > k) cn = 1;
                }
                cout << "\n";
            }
        }else{
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    int cn = (i + j) % k;
                    cn += 1;
                    cout << cn << " ";
                }
                cout << "\n";
            }
        }
    }
}
