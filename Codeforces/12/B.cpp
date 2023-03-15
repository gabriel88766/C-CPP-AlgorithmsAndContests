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
    string n, m;
    cin >> n >> m;
    if(n.size() == 1){
        if(n == m) cout << "OK";
        else cout << "WRONG_ANSWER";
        return 0;
    }
    string ans = n;
    char minv = '9'+1;
    for(int i=0;i<ans.size();i++) if(ans[i] != '0') minv=min(minv,ans[i]);
    for(int i=0;i<ans.size();i++){
        if(minv == ans[i] && i){
            swap(ans[0], ans[i]);
            break;
        }
    }
    sort(ans.begin()+1, ans.end());
    if(ans == m) cout << "OK";
    else cout << "WRONG_ANSWER";
}
