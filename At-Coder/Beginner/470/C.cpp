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
    vector<int> gr1;
    int ans = 0;
    vector<int> val(n+1, 0);
    for(int i=0;i<q;i++){
        int tq;
        cin >> tq;
        if(tq == 1){
            int x;
            cin >> x;
            if(val[x] == 0) gr1.push_back(x);
            ans ^= val[x];
            val[x]++;
            ans ^= val[x];
        }else{
            vector<int> nv;
            for(auto x : gr1){
                ans ^= val[x];
                val[x]--;
                ans ^= val[x];
                if(val[x] != 0) nv.push_back(x);
            }
            gr1 = nv;
        }
        cout << ans << "\n";
    }
}
