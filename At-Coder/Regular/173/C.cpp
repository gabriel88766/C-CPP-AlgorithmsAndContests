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
    int n;
    cin >> n;
    vector<int> p(n+1);
    vector<pair<int, int>> vx;
    for(int i=1;i<=n;i++){
        cin >> p[i];
        vx.push_back({p[i], i});
    }
    vector<bool> st(n+1, true); //true means it's greater
    sort(vx.begin(), vx.end());
    set<int> st2;
    for(int i=1;i<n;i++) st2.insert(i);
    vector<int> ans(n+1);

    for(auto [pv, j] : vx){
        st2.erase(j);
        st2.erase(j-1);
        if(j != 1 && j != n){
            if(st[j-1] == st[j+1]) ans[j] = 3;
            else{
                auto it = st2.lower_bound(j);
                int mn1 = INF_INT, mn2 = INF_INT;
                if(it != st2.end()){
                    mn1 = *it - j + 2;
                    if(mn1 % 2 == 0) mn1++;
                }
                if(it != st2.begin()){
                    it = prev(it);
                    mn2 = j - *it + 1;
                    if(mn2 % 2 == 0) mn2++;
                }
                int cans = min(mn1, mn2);
                if(cans > n) ans[j] = -1;
                else ans[j] = cans;
            }
                
        }
        st[j] = false;
        if(j != 1 && st[j-1] == st[j]) st2.insert(j-1);
        if(j != n && st[j] == st[j+1]) st2.insert(j);
    }
    //treat 1 and n as independent
    int cur = 0, qnt = 1;
    ans[1] = ans[n] = -1;
    for(int i=2;i<=n;i++){
        if(p[i] > p[1]) cur++;
        else cur--;
        if(i % 2 == 1 && cur != 0){
            ans[1] = i;
            break;
        }
    }
    cur = 0;
    for(int i=n-1;i>=1;i--){
        qnt++;
        if(p[i] > p[n]) cur++;
        else cur--;
        if(qnt % 2 == 1 && cur != 0){
            ans[n] = qnt;
            break;
        }
    }
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    cout << "\n";
}
