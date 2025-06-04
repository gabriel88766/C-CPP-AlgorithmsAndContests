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
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v[i] = {x, i+1};
    }
    sort(v.begin(), v.end(), greater<pair<int,int>>());
    int p = 0;
    while(p + 1 < v.size() && v[p+1].first == v[p].first) p+=1;
    bool ok = false;
    for(int j=0;j<k;j++){
        int x;
        cin >> x;
        for(int i=0;i<=p;i++){
            if(x == v[i].second) ok = true;
        }
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
