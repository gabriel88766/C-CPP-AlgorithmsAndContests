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
    string s;
    cin >> s;
    vector<pair<int,int>> vx;
    int x = 0;
    for(int i=0;i<s.size();i++){
        vx.push_back({x, i});
        if(s[i] == '(') x++;
        else x--;
    }
    sort(vx.begin(), vx.end(), [&](pair<int,int> u, pair<int,int> v){
        if(u.first != v.first) return u.first < v.first;
        else return u.second > v.second;
    });
    for(auto [a, b] : vx) cout << s[b];
    cout << "\n";
}
