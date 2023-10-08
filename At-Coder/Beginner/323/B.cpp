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
    vector<pair<int,int>> vp(n, {0, 0});
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        vp[i].second = i;
        for(int j=0;j<n;j++){
            if(i == j) continue;
            if(s[j] == 'o') vp[i].first++;
            else vp[j].first++;
        }
    }
    sort(vp.begin(), vp.end(), [&](pair<int,int> u, pair<int,int> v){
        if(u.first != v.first) return u.first > v.first;
        else return u.second < v.second;
    });
    for(int i=0;i<n;i++) cout << vp[i].second + 1 << " ";

}
