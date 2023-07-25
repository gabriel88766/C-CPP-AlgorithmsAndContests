#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
bool vis[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    deque<int> ans;
    int cur = 1;
    do{
        ans.push_back(cur);
        vis[cur] = true;
        cur = v[cur];
    }while(!vis[cur]);
    while(ans.front() != cur) ans.pop_front();
    cout << ans.size() << "\n";
    for(auto x : ans) cout << x << " ";
}
