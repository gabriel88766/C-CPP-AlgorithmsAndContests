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
    string s, t;
    cin >> s >> t;
    bool ok = false;
    int n = s.size();
    for(int w=1;w<n;w++){
        for(int c=1;c<=w;c++){
            string cur = "";
            for(int k=0;k*w+c-1 <n;k++){
                cur += s[k*w+c-1];
            }
            if(cur == t){
                ok = true;
            }
        }
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
