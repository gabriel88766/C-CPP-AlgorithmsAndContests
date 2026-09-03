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
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    string s;
    cin >> s;
    s = " " + s;
    int cur = 0;
    vector<int> vs;
    for(int i=1; i <= n; i++){
        if(s[i] == '0'){
            cur++;
        }else cur = 0;
        if(cur == b){
            vs.push_back(i);
            cur = 0;
        }
    }
    assert(a <= vs.size());
    int ans = vs.size() - a + 1;
    cout << ans << "\n";
    for(int i=0;i<ans;i++) cout << vs[i] << " ";
    cout << "\n";
}
