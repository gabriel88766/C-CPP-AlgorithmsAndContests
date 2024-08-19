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
        cin >> n;
        vector<int> v(n);
        string s;
        for(int i=0;i<n;i++) cin >> v[i];
        cin >> s;
        vector<int> bl, rd;
        for(int i=0;i<n;i++){
            if(s[i] == 'B') bl.push_back(v[i]);
            else rd.push_back(v[i]);
        }
        bool ok = true;
        sort(bl.begin(), bl.end());
        int cur = 1;
        for(auto x : bl){
            if(x < cur) ok = false;
            cur++;
        }
        sort(rd.begin(), rd.end(), greater<int>());
        cur = n;
        for(auto x: rd){
            if(x > cur) ok = false;
            cur--;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
