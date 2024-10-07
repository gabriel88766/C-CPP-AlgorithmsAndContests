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
    int n;
    cin >> n;
    int xs = 0;
    vector<int> bs(30, 0);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        xs ^= x;
        while(x){
            int b = 31-__builtin_clz(x);
            if(bs[b]) x ^= bs[b];
            else{
                bs[b] = x;
                break;
            }
        }
    }   
    if(xs == 0) cout << "-1\n";
    else{
        int ans = 0;
        for(int i=0;i<30;i++) if(bs[i]) ans++;
        cout << ans << "\n";
    }
}