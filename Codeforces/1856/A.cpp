#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool checksort(vector<int> &v){
    for(int i=1;i<v.size();i++){
       if(v[i-1] > v[i]) return false; 
    }
    return true;
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
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        vector<bool> pos(n, true);
        int ans = 0;
        while(!checksort(v)){
            int mine = INF_INT; 
            for(int i=0;i<n;i++){
                if(pos[i]) mine = min(mine, v[i]);
            }
            ans += mine;
            for(int i=0;i<n;i++) if(pos[i]) v[i] -= mine;
            for(int i=0;i<n;i++){
                if(v[i] == 0) pos[i] = false;
            }
        }
        cout << ans << "\n";
    }
}
