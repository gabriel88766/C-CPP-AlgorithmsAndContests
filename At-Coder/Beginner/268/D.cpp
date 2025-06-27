#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<vector<int>> cur;
vector<int> cv;
void getp(int ms, int sz, int cs = 0){
    if(cv.size() == sz){
        cur.push_back(cv);
        return;
    }
    for(int j=1;j<=ms-cs;j++){
        cv.push_back(j);
        getp(ms, sz, cs + j);
        cv.pop_back();
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<string> vs;
    int sx = 0;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        sx += s.size();
        vs.push_back(s);
    }
    map<string, bool> mp;
    for(int j=0;j<m;j++){
        string s;
        cin >> s;
        mp[s] = true;
    }
    if(vs.size() == 1){
        if(mp[vs[0]] || vs[0].size() < 3) cout << "-1\n";
        else cout << vs[0] << "\n";
        return 0;
    }
    int sm = 16 - sx;
    getp(sm, n-1);
    sort(vs.begin(), vs.end());
    do{ 
        for(auto &v : cur){
            string curs = vs[0];
            for(int i=1;i<n;i++){
                curs += string(v[i-1], '_');
                curs += vs[i];
            }
            if(curs.size() < 3) continue;
            if(!mp.count(curs)){
                cout << curs << "\n";
                return 0;
            }
        }
    }while(next_permutation(vs.begin(), vs.end()));
    cout << "-1\n";
}
