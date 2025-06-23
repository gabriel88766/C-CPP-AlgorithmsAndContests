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
    int h, w;
    cin >> h >> w;
    vector<string> v1(h), v2(h);
    for(int i=0;i<h;i++) cin >> v1[i];
    for(int i=0;i<h;i++) cin >> v2[i];
    vector<string> s1(w), s2(w);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            s1[j] += v1[i][j];
            s2[j] += v2[i][j];
        }
    }
    vector<string> vv1, vv2;
    for(int j=0;j<w;j++){
        vv1.push_back(s1[j]);
        vv2.push_back(s2[j]);
    }
    sort(vv1.begin(), vv1.end());
    sort(vv2.begin(), vv2.end());
    if(vv1 == vv2) cout << "Yes\n";
    else cout << "No\n";
}
