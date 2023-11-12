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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = " " + s;
    vector<int> v;
    for(int i=1;i<n;i++){
        if(s[i] == s[i+1]) v.push_back(i);
    }
    for(int i=0;i<q;i++){
        int l, r;
        cin >> l >> r;
        int ind1 = lower_bound(v.begin(), v.end(), l) - v.begin();
        int ind2 = lower_bound(v.begin(), v.end(), r) - v.begin();
        cout << ind2 - ind1 << "\n"; 
    }
}
