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
    vector<int> inds;
    string s;
    cin >> s;
    for(int i=0;i<s.size();i++){
        if(s[i] == '|') inds.push_back(i);
    }
    assert(inds.size() == 2);
    string ans = s.substr(0, inds[0]) + s.substr(inds[1]+1, s.size()-inds[1]-1);
    cout << ans << "\n";
}
