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
    vector<int> cnt(14, 0);
    for(int i=0;i<5;i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    bool ok3 = false, ok2 = false;
    for(int i=1;i<=13;i++){
        if(cnt[i] == 2) ok2 = true;
        if(cnt[i] == 3) ok3 = true;
    }
    if(ok2 && ok3) cout << "Yes\n";
    else cout << "No\n";
}
