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
    int a, b, c;
    cin >> a >> b >> c;
    int m;
    cin >> m;
    vector<int> ta, tb;
    for(int i=0;i<m;i++){
        int a;
        string s;
        cin >> a >> s;
        if(s == "USB") ta.push_back(a);
        else tb.push_back(a);
    }
    sort(ta.begin(), ta.end());
    sort(tb.begin(), tb.end());
    a = min(a, (int)ta.size());
    b = min(b, (int)tb.size());
    int ans = a + b;
    c = min(m - ans, c);
    ans += c;
    cout << ans << " ";
    ll ttc = 0;
    //equip a and b first, then equip c with remainder
    for(int i = 0; i < a; i++) ttc += ta[i];
    for(int i = 0; i < b; i++) ttc += tb[i];
    vector<int> v3;
    for(int i = a; i < ta.size(); i++) v3.push_back(ta[i]);
    for(int i = b; i < tb.size(); i++) v3.push_back(tb[i]);
    sort(v3.begin(), v3.end());
    for(int i = 0; i < c; i++) ttc += v3[i];
    cout << ttc << "\n";
}
