#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int ask(int a, int b){
    cout << "? " << a << " " << b << "\n";
    cout.flush();
    string ans;
    cin >> ans;
    return ans == "YES";
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v;
    for(int i=1;i<=n;i++) v.push_back(i);
    stable_sort(v.begin(), v.end(), [&](int a, int b){
        return ask(a, b);
    });
    vector<int> ans(n);
    for(int i=0;i<n;i++) ans[v[i]-1] = i+1;
    cout << "! ";
    for(auto &x : ans) cout << x << " ";
    cout << "\n";
    cout.flush();
}
