#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, m, cur=0, curmax = 0;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        string s;
        cin >> s;
        char isOk = false;
        for(int j=0;j<s.size();j++){
            if(s[j] == '0') isOk = true;
        }
        if(isOk) cur++;
        else cur = 0;
        curmax = max(cur, curmax);
    }
    cout << curmax;
}
