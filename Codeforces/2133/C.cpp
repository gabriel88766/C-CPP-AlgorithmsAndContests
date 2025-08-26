#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int askn(int x, int n){
    cout << "? " << x << " " << n << " ";
    for(int i=1;i<=n;i++) cout << i << " ";
    cout << "\n";
    cout.flush();
    int nx;
    cin >> nx;
    return nx;
}
vector<bool> isin;
int ask2(int x, int n){
    vector<int> av;
    for(int i=1;i<=n;i++) if(isin[i]) av.push_back(i);
    cout << "? " << x << " " << av.size() << " ";
    for(auto x : av) cout << x << " ";
    cout << "\n";
    cout.flush();
    int nx;
    cin >> nx;
    return nx;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> ans(n+1);
        isin.resize(n+1);
        fill(isin.begin(), isin.end(), true);
        int mx = 1;
        for(int i=1;i<=n;i++){
            ans[i] = askn(i, n);
            if(ans[i] > ans[mx]) mx = i;
        }
        for(int i=1;i<=n;i++){
            if(i == mx) continue;
            isin[i] = false;
            int cx = ask2(mx, n);
            if(cx != ans[mx]) isin[i] = true;
        }
        vector<pair<int, int>> vxx;
        for(int i=1;i<=n;i++){
            if(isin[i]){
                vxx.push_back({ans[i], i});
            }
        }
        sort(vxx.begin(), vxx.end(), greater<pair<int, int>>());
        cout << "! " << vxx.size() << " ";
        for(auto [a,b] : vxx) cout << b << " ";
        cout << "\n";
        cout.flush();


    }
}
