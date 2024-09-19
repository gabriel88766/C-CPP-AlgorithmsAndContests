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
    int x =0;
    int n;
    cin >> n;
    map<int,bool> mp;
    for(int i=0;i<n;i++){
        int cur;
        cin >> cur;
        x ^= cur;
        mp[cur] = true;
    }
    if(mp.count(x)) cout << "Win\n";
    else if(n % 2) cout << "Win\n";
    else cout << "Lose\n";
}
