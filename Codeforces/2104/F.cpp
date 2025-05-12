#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//BEGIN PREPROCESSING
vector<vector<int>> prp;
vector<int> cur;
int sum = 0;
void init(){
    if(cur.size() == 9){
        cur.push_back(9-sum);
        prp.push_back(cur);
        cur.pop_back();
        return;
    }
    for(int i=0;i<=9-sum;i++){
        cur.push_back(i);
        sum += i;
        init();
        sum -= i;
        cur.pop_back();
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("out", "w", stdout); //test input
    init();
    map<string, int> mp;
    for(int i=1;i<=8;i++){
        string cn = string('9', i);
        string key = cn + to_string(stoi(cn) + 1);
        sort(key.begin(), key.end());
        mp[key] = stoi(cn);
    }
    for(auto &v : prp){
        for(int i=1;i<=8;i++){
            if(v[i] != 0){
                int on;
                for(int x=1;x<=9;x++){
                    
                }
                for(int c=0;c<=v[0];c++){
                    for(int j=0;j<=v[9];j++){
                        string cn;
                        int on;
                        for(int x=1;x<=9;x++){
                            if()
                        }


                        string cn = num;
                        for(int k=0;k<v[9]-j;k++) cn += ('0' + 9);
                        cn += ('0' + i);
                        for(int k=0;k<j;k++) cn += ('0' + 9);
                        string app = to_string(stoi(cn) + 1);
                        reverse(app.begin(), app.end());
                        while(app.size() != 9) app += '0';
                        reverse(app.begin(), app.end());
                        assert(cn.size() == app.size());
                        string key = cn + app;
                        sort(key.begin(), key.end());
                        if(stoi(cn) == 99) cout << key << "\n";
                        if(mp.count(key)){
                            mp[key] = min(mp[key], stoi(cn));
                        }
                        else mp[key] = stoi(cn);
                }
            }
        }
    }
    vector<int> v;
    for(auto &[x, y] : mp){
        if(y != 0) v.push_back(y);
    }
    sort(v.begin(), v.end());
    // for(auto &x : v) cout << x << " ";
    // v.resize(unique(v.begin(), v.end()) - v.begin());
    //END PREPROCESSING
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        cout << upper_bound(v.begin(), v.end(), n) - v.begin() << "\n";
    }
}
