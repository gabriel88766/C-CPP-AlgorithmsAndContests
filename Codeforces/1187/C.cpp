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
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> fc;
    vector<int> s(n+1);
    for(int i=0;i<m;i++){
        int tp, l, r;
        cin >> tp >> l >> r;
        if(tp == 1){
            for(int j=l+1;j<=r;j++) s[j] = 1;
        }else{
            fc.push_back({l, r});
        }
    }
    bool ok = true;
    for(auto [l, r] : fc){
        bool cok = false;
        for(int j=l+1;j<=r;j++) if(!s[j]) cok = true;
        if(!cok) ok = false;
    }
    if(ok){
        cout << "YES\n";
        int fn = 1001;
        cout << fn << " ";
        for(int j=2;j<=n;j++){
            if(s[j] == 0) fn--;
            cout << fn << " ";
        }
        cout << "\n";
    }else cout << "NO\n";
}
