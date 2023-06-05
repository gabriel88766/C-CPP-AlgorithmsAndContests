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
        bool ok = false;
        for(int i=0;i<=n;i++){
            int pos = i;
            int neg = n-i;
            int tt = (pos*(pos-1))/2 + (neg*(neg-1))/2;
            if(tt == k){
                cout << "YES\n";
                for(int i=0;i<pos;i++) cout << "1 ";
                for(int i=0;i<neg;i++) cout << "-1 ";
                cout << "\n";
                ok = true;
            }
            if(ok) break;
        }
        if(!ok) cout << "NO\n";
    }
}
