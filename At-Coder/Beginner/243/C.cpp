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
    vector<pair<int,int>> vp(n);
    vector<int> ytc;
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        vp[i] = {a, b};
        ytc.push_back(b);
    }
    string s;
    cin >> s;
    map<int, int> ml, mr;
    for(int i=0;i<n;i++){
        auto [x, y] = vp[i];
        if(s[i] == 'L'){
            if(ml.count(y)) ml[y] = max(ml[y], x);
            else ml[y] = x;
        }else{
            if(mr.count(y)) mr[y] = min(mr[y], x);
            else mr[y] = x;
        }
    }
    bool ok = false;
    for(auto y : ytc){
        if(ml.count(y) && mr.count(y) && ml[y] > mr[y]) ok = true;
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";


}
