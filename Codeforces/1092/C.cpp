#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n;
    cin >> n;
    vector<string> v[101], x;
    vector<int> ind[101];
    for(int i=0;i<(2*n-2);i++){
        string s;
        cin >> s;
        v[s.size()].push_back(s);
        ind[s.size()].push_back(i);
        x.push_back(s);
    }
    string pos[4];
    pos[0] = v[n-1][0] + v[1][0];
    pos[1] = v[n-1][0] + v[1][1];
    pos[2] = v[1][0] + v[n-1][0];
    pos[3] = v[1][1] + v[n-1][0];
    string ans;
    int p;
    for(int i=0;i<4;i++){
        //check all possibilities;
        bool ok = true;
        for(int j=1;j<=(n-1);j++){
            if((pos[i].substr(0, j) != v[j][0]) && (pos[i].substr(n-j, j) != v[j][0])) ok = false;
            if((pos[i].substr(0, j) != v[j][1]) && (pos[i].substr(n-j, j) != v[j][1])) ok = false;
        }
        if(ok) p = i;
    }
    for(int j=0;j<x.size();j++){
        int aux = x[j].size();
        if((pos[p].substr(0, aux) == x[j])) ans += 'P';
        else ans += 'S';
        if(v[aux][0] == v[aux][1]){
            if(j == ind[aux][1]) ans[ans.size()-1] = 'S';
        }
    }
    cout << ans;
}
