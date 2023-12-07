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
    int n, q;
    cin >> n >> q;
    vector<int> v(n+1);
    int c1 = 0;
    for(int i=1;i<=n;i++){
        cin >> v[i];
        if(v[i] == 1) c1++;
    }
    for(int i=0;i<q;i++){
        int t, x;
        cin >> t >> x;
        if(t == 1){
            if(v[x] == 1) c1--;
            else c1++;
            v[x] ^= 1;
        }else{
            if(c1 >= x) cout << "1\n";
            else cout << "0\n";
        }
    }
}
