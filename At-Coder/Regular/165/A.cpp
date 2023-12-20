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
        vector<pair<int,int>> vp;
        auto aux = n;
        for(int i=2;i*i<=n;i++){
            if(!(aux % i)){
                int cnt = 0;
                while(!(aux % i)){
                    cnt++;
                    aux /= i;
                }
                vp.push_back({i, cnt});
            }
        }
        if(aux != 1){
            vp.push_back({aux, 1});
        }
        ll num = 0;
        for(auto [x, y] : vp){
            ll cur = 1;
            while(y--) cur *= x;
            num += cur;
        }
        if(vp.size() == 1) num++;
        if(num <= n) cout << "Yes\n";
        else cout << "No\n";
    }
}
