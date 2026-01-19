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
    string s, t;
    cin >> n >> m >> s >> t >> q;
    vector<int> a(26, 0), b(26, 0);
    for(auto c : s) a[c-'a']++;
    for(auto c : t) b[c-'a']++;
    for(int i=1;i<=q;i++){
        string x;
        cin >> x;
        bool ok1 = true, ok2 = true;
        for(auto c : x){
            if(a[c-'a']==0) ok1 = false;
            if(b[c-'a']==0) ok2 = false;
        }
        if(ok1 && ok2) cout << "Unknown\n";
        else if(ok1) cout << "Takahashi\n";
        else if(ok2) cout << "Aoki\n";
        else cout << "WTF!!!\n";
    }
}
