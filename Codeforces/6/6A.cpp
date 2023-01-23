#include <bits/stdc++.h>
 
using namespace std;
const int N = 1e5+3, INF = 0x3f3f3f3f;
int suf[N], v[N], p[N];
 
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    vector<int> v(4);
    cin >> v[0] >> v[1] >> v[2] >> v[3];
    sort(v.begin(),v.end());
    bool deg = false, tri = false;
    if(v[2] < (v[1]+v[0])) tri = true;
    if(v[3] < (v[2]+v[1])) tri = true;
    if(v[2] == (v[1]+v[0])) deg = true;
    if(v[3] == (v[2]+v[1])) deg = true;
    if(tri) cout << "TRIANGLE";
    else if(deg) cout << "SEGMENT";
    else cout << "IMPOSSIBLE";
}