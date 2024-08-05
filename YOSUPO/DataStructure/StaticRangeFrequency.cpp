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
    map<int, vector<int>> mp;
    int n, q;
    cin >> n >> q;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        mp[x].push_back(i);
    }
    for(int i=0;i<q;i++){
        int l, r, x;
        cin >> l >> r >> x;
        if(mp.count(x)){
            cout << lower_bound(mp[x].begin(), mp[x].end(), r) - lower_bound(mp[x].begin(), mp[x].end(), l) << "\n";
        }else cout << "0\n";
    }
}
