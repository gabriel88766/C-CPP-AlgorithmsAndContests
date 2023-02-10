#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+3;
int cnt[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n;
    cin >> n;
    ll sum = 0;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        cnt[v[i]]++;
        sum += v[i];
    }
    vector<int> ans;
    for(int i=1;i<=n;i++){
        ll cs = sum - v[i];
        if(cs%2) continue;
        cs /= 2;
        if(cs > 1000000) continue;
        if((v[i] == cs && cnt[cs] > 1) || (v[i] != cs && cnt[cs] >= 1)) ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for(int i=0;i<ans.size();i++) cout << ans[i] << " ";


}
