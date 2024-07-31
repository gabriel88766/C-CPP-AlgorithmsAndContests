#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

map<int, vector<int>> mp;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        mp[x].push_back(i);
    }
    for(int i=0;i<q;i++){
        int x, k;
        cin >> x >> k;
        if(mp.count(x)){
            if(mp[x].size() >= k) cout << mp[x][k-1] << "\n";
            else cout << "-1\n";
        }else cout << "-1\n";
    }
}
