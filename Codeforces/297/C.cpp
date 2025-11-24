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
    vector<pair<int, int>> vp;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        vp.push_back({x, i});
    }
    sort(vp.begin(), vp.end());
    if(n == 1){
        cout << "YES\n" << vp[0].first << "\n" << "0\n";
    }else{
        cout << "YES\n";
        vector<int> a(n), b(n);
        int h3 = (n + 2) / 3;
        for(int i=0;i<h3;i++){
            a[i] = 0;
            b[i] = vp[i].first;
        }
        for(int i=h3;i<2*h3;i++){
            a[i] = vp[i].first;
            b[i] = 0;
        }
        int px = 0;
        for(int i=n-1;i>=2*h3;i--){
            a[i] = px++;
            b[i] = vp[i].first - a[i];
        }
        vector<int> ra(n), rb(n);
        for(int i=0;i<n;i++){
            ra[vp[i].second] = a[i];
            rb[vp[i].second] = b[i];
        }
        for(auto x : ra) cout << x << " ";
        cout << "\n";
        for(auto x : rb) cout << x << " ";
        cout << "\n";
    }
}
