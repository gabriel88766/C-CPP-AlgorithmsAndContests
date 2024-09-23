#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
ll ans[2][N][2];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    vector<int> pos, neg;
    int n, k;
    cin >> n >> k;
    memset(ans, 63, sizeof(ans));
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(x >= 0) pos.push_back(x);
        else neg.push_back(abs(x));
    }
    reverse(neg.begin(), neg.end());
    ans[0][0][0] = ans[0][0][1] = ans[1][0][0] = ans[1][0][1] = 0;
    for(int i=1;i<=pos.size();i++){
        ans[0][i][0] = pos[i-1];
        ans[0][i][1] = 2*pos[i-1];
    }
    for(int i=1;i<=neg.size();i++){
        ans[1][i][0] = neg[i-1];
        ans[1][i][1] = 2*neg[i-1];
    }
    ll rans = INF_LL;
    for(int i=0;i<=k;i++){
        rans = min(rans, ans[0][i][0] + ans[1][k-i][1]);
        rans = min(rans, ans[0][i][1] + ans[1][k-i][0]);
    }
    cout << rans << "\n";
}
