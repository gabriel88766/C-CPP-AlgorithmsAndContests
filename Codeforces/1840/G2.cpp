#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int cur, maxv = 1;
    cin >> maxv;
    for(int i=0;i<300;i++){
        ll x = uniform_int_distribution<ll>(1, 1000000)(rng);
        cout << "+ " << x << "\n";
        cout.flush();
        cin >> cur;
        maxv = max(maxv, cur);
    }
    map<int,int> ans;
    ans[cur] = 1;
    for(int i = 1; i< 300; i++){
        cout << "+ " << 1 << "\n";
        cout.flush();
        cin >> cur;
        if(ans.count(cur)){
            cout << "! " << i << "\n";
            cout.flush();
            return 0;
        }
        ans[cur] = i+1;
    }
    int dif = maxv + ans[cur];
    cout << "+ " << maxv << "\n";
    cout.flush();
    cin >> cur;
    if(ans.count(cur)){
        cout << "! " << dif-ans[cur] << "\n";
        cout.flush();
    }
    do{
        ans[cur] = dif;
        cout << "+ " << 300 << "\n";
        cout.flush();
        cin >> cur;
        dif += 300;
    } while(!ans.count(cur)); 
    cout << "! " << dif-ans[cur] << "\n";
    cout.flush();
}