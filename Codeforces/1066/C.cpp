#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int t[N], vt[N], pos[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int q;
    cin >> q;
    int sz = 0, cnt = 0;

    for(int i=1;i<=q;i++){
        char c; int v;
        cin >> c >> v;
        if(c == 'L' || c == 'R') vt[v] = i;
        if(c == 'L'){
            pos[v] = 0;
            sz++;
            cnt++;
        }else if(c == 'R'){
            pos[v] = sz;
            sz++;
        }else{
            int l = pos[v] + cnt - t[vt[v]];
            cout << min(sz-l-1, l) << "\n";;
        }
        t[i] = cnt; //total left;
    }
}
