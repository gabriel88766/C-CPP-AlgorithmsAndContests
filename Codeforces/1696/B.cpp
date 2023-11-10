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
        int l = -1, r = -1;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
            if(v[i] != 0){
                if(l == -1) l = i;
                r = i;
            }
        }
        if(l == -1) cout << "0\n";
        else{
            bool ok = true;
            for(int i=l;i<=r;i++) if(v[i] == 0) ok = false;
            if(ok) cout << "1\n";
            else cout << "2\n";
        }
    }
}
