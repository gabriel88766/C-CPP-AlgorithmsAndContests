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
    int n;
    cin >> n;
    vector<int> p(n+1), pos;
    for(int i=1;i<=n;i++){
        cin >> p[i];
        if(p[i] == i) pos.push_back(i);
    }
    int ans = 0;
    for(int i=0;i<pos.size();i++){
        if(i+1 < pos.size() && pos[i] == (pos[i+1]-1)) i++;
        ans++;
    }
    cout << ans;
}
