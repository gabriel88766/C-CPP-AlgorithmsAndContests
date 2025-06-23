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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> s1, s2;
    int xx;
    cin >> xx;
    x -= xx; //A1
    x = abs(x);
    y = abs(y); //<=10^4;
    for(int i = 2;i<=n;i++){
        cin >> xx;
        if(i % 2 == 0) s2.push_back(xx);
        else s1.push_back(xx);
    }
    bitset<20001> bs;
    bool ok = true;
    bs[10000] = 1;
    //solve x;
    for(auto x : s1){
        bitset<20001> nbs;
        nbs |= bs >> x;
        nbs |= bs << x;
        bs = nbs;
    }
    if(!bs[10000 + x]) ok = false;
    bs.reset();
    bs[10000] = 1;
    //solve y;
    for(auto x : s2){
        bitset<20001> nbs;
        nbs |= bs >> x;
        nbs |= bs << x;
        bs = nbs;
    }
    if(!bs[10000 + y]) ok = false;
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
