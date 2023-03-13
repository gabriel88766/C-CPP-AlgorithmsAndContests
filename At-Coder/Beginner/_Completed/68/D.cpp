#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll K, aux, v;
    cin >> K;
    if(!K){
        cout << "2\n0 0";
        return 0;
    }else{
        if(K < 50){
            //safety
            cout << "2\n";
            cout << 2+(K-1)/2 << " ";
            if(K > 1) cout << K/2;
            else cout << "0";
        }else{
            cout << "50\n";
            vector<ll> ans(50);
            K-=50;
            for(int i=0;i<50;i++) ans[i] = 50-i + K/50;
            for(int i=0;i<(K%50);i++) ans[i]++;
            for(int i=0;i<50;i++) cout << ans[i] << " ";
        }
    }
}
