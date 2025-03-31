#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int cnt[14];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=1;i<=7;i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    vector<int> v;
    for(int i=1;i<=13;i++){
        v.push_back(cnt[i]);
    }
    sort(v.begin(), v.end(), greater<int>());
    if(v[0] >= 3 && v[1] >= 2) cout << "Yes\n";
    else cout << "No\n";
}
