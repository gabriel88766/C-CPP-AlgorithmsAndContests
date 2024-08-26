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
    int n, m, q;
    cin >> n >> m >> q;
    string s;
    cin >> s;
    s = " " + s;
    string t;
    cin >> t;
    vector<int> v;
    for(int i=0;i<s.size();i++){
        bool ok = true;
        for(int j=0;j<t.size();j++){
            if(i+j >= s.size() || s[i+j] != t[j]) ok = false;
        }
        if(ok)v.push_back(i);
    }
    for(int i=0;i<q;i++){
        int l, r;
        cin >> l >> r;
        if(r - m + 1 >= l){
            // 1 3 4 5... 2=> 1, 4 -> 3
            cout << lower_bound(v.begin(), v.end(), r-m+2) - lower_bound(v.begin(), v.end(), l) << "\n";
        }else cout << "0\n";
    }
}
