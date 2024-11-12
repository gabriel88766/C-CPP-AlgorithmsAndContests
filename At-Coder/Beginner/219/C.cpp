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
    string x;
    cin >> x;
    vector<int> ord(26);
    for(int i=0;i<26;i++) ord[x[i]-'a'] = i;
    auto str_cmp = [&](string a, string b){
        for(int i=0;i<a.size();i++){
            if(i < b.size()){
                if(a[i] != b[i]) return ord[a[i]-'a'] < ord[b[i]-'a'];
            }else return false; // b < a, 
        }
        if(a.size() < b.size()) return true;
        else return false; //a = b
    };
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end(), str_cmp);
    for(auto x : v) cout << x << "\n";
}
