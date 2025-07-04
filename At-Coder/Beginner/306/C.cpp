#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
int cnt[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freop en("in", "r", stdin); //test input
    vector<int> ans;
    int n;
    cin >> n;
    for(int i=1;i<=3*n;i++){
        int x;
        cin >> x;
        if(cnt[x] == 1) ans.push_back(x);
        cnt[x]++;
    }
    for(auto x : ans) cout << x << " ";
    cout << "\n";
}
