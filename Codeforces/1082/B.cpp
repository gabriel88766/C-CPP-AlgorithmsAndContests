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
    string s;
    cin >> n >> s;
    s = " " + s;
    vector<int> vs;
    vs.push_back(0);
    int lg = -1, hg = -1;
    for(int i=1;i<=n;i++){
        if(s[i] == 'S') vs.push_back(i);
        else{
            if(lg == -1) lg = i;
            hg = i;
        }
    }
    vs.push_back(n+1);
    if(vs.size() == 2) cout << n << "\n";
    else{
        int ans = 0;
        for(int i=1;i<vs.size()-1;i++){
            int sz = vs[i+1] - vs[i-1] - 1;
            if(lg == -1 || (lg > vs[i-1] && hg < vs[i+1])) sz--;
            ans = max(ans, sz);
        }
        cout << ans << "\n";
    }
}   
