#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<pair<int,int>> swl[4];

vector<pair<int,int>> bgop = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

map<vector<int>, int> mp;


vector<vector<int>> gen[11];

vector<int> cur;
void genall(int sz){
    if(cur.size() == sz) {gen[sz].push_back(cur); return;}
    for(int i=0;i<4;i++){
        cur.push_back(i);
        genall(sz);
        cur.pop_back();
    }
}


vector<int> transform(const vector<int> &ini, const vector<int> &transf){
    vector<int> ans(ini.begin(), ini.end());
    for(auto x : transf){
        for(auto [u, v]: swl[x]){
            swap(ans[u], ans[v]);
        }
    }
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=1;i<=10;i++) { genall(i);}
    int h, w;
    cin >> h >> w;
    for(int i=0;i<4;i++){
        int x = bgop[i].first, y = bgop[i].second;
        set<pair<int,int>> s;
        for(int u=0;u<h-1;u++){
            for(int v=0;v<w-1;v++){
                int du = h-2-u;
                int dv = w-2-v;
                int src = (u+x)*w +(v+y);
                int dst = (du+x)*w + (dv+y);
                if(src != dst) s.insert({min(src, dst), max(src, dst)});
            }
        }
        for(auto x : s) swl[i].push_back(x);
    }
    vector<int> ini;
    vector<int> bst;
    for(int i=1;i<=h*w;i++) bst.push_back(i);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            int x;
            cin >> x;
            ini.push_back(x);
        }
    }
    if(ini == bst){
        cout << "0\n";
        return 0;
    }
    int outp = INF_INT;
    for(int i=1;i<=10;i++){
        for(auto &x : gen[i]){
            auto ans = transform(ini, x);
            if(!mp.count(ans)) mp[ans] = i;
            if(ans == bst) outp = min(outp, i);
        }
    }
    for(int i=1;i<=10;i++){
        for(auto &x : gen[i]){
            auto ans = transform(bst, x);
            if(mp.count(ans)) outp = min(outp, i + mp[ans]);
            if(ans == ini) outp = min(outp, i);
        }
    }
    if(outp == INF_INT) cout << "-1\n";
    else cout << outp << "\n";

}
