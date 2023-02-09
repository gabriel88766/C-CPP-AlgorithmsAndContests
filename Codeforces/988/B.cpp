#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool cmp(string a, string b){
    return a.size() < b.size();
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n;
    cin >> n;
    vector<string> v;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);
    bool ok = true;
    for(int i=0;i<(n-1);i++){
        //check if i subtr i+1
        bool ok2 = false;
        for(int j=0;j<=v[i+1].size() - v[i].size(); j++){
            if(v[i+1].substr(j, v[i].size()) == v[i]) ok2 = true;
        }
        if(!ok2) ok = false;
    }
    if(ok){
        cout << "YES\n";
        for(int i=0;i<v.size();i++) cout << v[i] << "\n";
    }else cout << "NO";
}
