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
    ll p, a, b;
    cin >> p >> a >> b;
    vector<bool> vis(p, false);
    ll x = 1;
    int sz = 0;
    vector<vector<int>> av;
    while(!vis[x]){
        ll cur = x;
        vector<int> cv;
        while(!vis[cur]){
            cv.push_back(cur);
            vis[cur] = true;
            cur = (cur * a) % p;
        }
        av.push_back(cv);
        sz += cv.size();
        x = (x * b) % p;
    }
    if(sz == p - 1){
        cout << "Yes\n";
        for(int i=0;i<av.size();i++){
            cout << av[i][0] << " ";
        }
        int inv = 0;
        for(int i=av.size() - 1; i >= 0; i--){
            if(inv){
                for(int j=av[i].size()-1;j>=1;j--) cout << av[i][j] << " ";
            }else{
                for(int j=1;j<av[i].size();j++) cout << av[i][j] << " ";
            }
            inv ^= 1;
        }
        cout << 1 << "\n";
    }else cout << "No\n";
}
