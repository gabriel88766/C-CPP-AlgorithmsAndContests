#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

pair<ll, ll> ans[18][18][18];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int tt = 0;
    for(int i=1;i<=17;i++){
        for(int j=i;j<=17;j++){
            for(int k=j;k<=i+j && k <= 17;k++){
                ll a = 1, b = 1, c = 1;
                ll p2 = 0;
                while(to_string(2*a).size() <= i){
                    a *= 2;
                    c *= 2;
                    p2++;
                }
                while(to_string(3*c).size() <= k){
                    c *= 3;
                    b *= 3;
                }
                while(to_string(b).size() < j && p2){
                    b *= 2;
                    p2--;
                }
                assert(c == lcm(a, b));
                if(to_string(a).size() != i || to_string(b).size() != j || to_string(c).size() != k){
                    assert(i + j == k); //checked by brute force
                    string an = "8" + string(i-1, '0');
                    string bn = string(j, '9');
                    a = stol(an);
                    b = stol(bn);
                    assert(an.size() == i);
                    assert(bn.size() == j);
                    c = lcm(a, b);
                    assert(to_string(c).size() == k);
                    ans[i][j][k] = {a, b};
                }else{
                    ans[i][j][k] = {a, b};
                }
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        bool swp = false;
        if(a > b) swp = true;
        if(c >= max(a, b) && c <= a + b){
            cout << "Yes\n";
            if(swp) cout << ans[b][a][c].second << " " << ans[b][a][c].first << "\n";
            else cout << ans[a][b][c].first << " " << ans[a][b][c].second << "\n";
        }else{
            cout << "No\n";
        }
    }
}   
