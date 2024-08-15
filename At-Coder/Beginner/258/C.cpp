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
    string s;
    int n, q;
    cin >> n >> q;
    cin >> s;
    int off = 0;
    for(int i=0;i<q;i++){
        int t, x;
        cin >> t >> x;
        if(t == 1){
            off += x;
            off %= n;
        }else{
            int p = (x-off-1)%n;
            if(p < 0) p += n;
            cout << s[p] << "\n";
        }
    }
}
