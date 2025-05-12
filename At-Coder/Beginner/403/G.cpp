#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
ll sum[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int x = 0;
    int q;
    cin >> q;
    vector<pair<int, int>> an;
    for(int i=1;i<=q;i++){
        int y;
        cin >> y;
        int nx = ((x + y) % 1'000'000'000) + 1;
        x = nx;
        an.push_back({x, i});
        sum[i] = sum[i-1] + x;
    }
    sort(an.begin(), an.end());

}
