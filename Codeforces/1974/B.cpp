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
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        auto r = s;
        sort(r.begin(), r.end());
        r.resize(unique(r.begin(), r.end()) - r.begin());
        vector<int> p(26, 0);
        int sz = r.size();
        for(int i=0;i<sz;i++) p[r[i]-'a'] = i;
        for(int i=0;i<s.size();i++){
            s[i] = r[sz - p[s[i]-'a'] - 1];
        }
        cout << s << "\n";
    }

}
