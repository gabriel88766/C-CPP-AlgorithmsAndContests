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
    //freopen("in", "r", stdin); //test input
    string s;
    cin >> s;
    int n = s.size();
    string t = s+s;
    bool ok = false;
    int cur_l = 0;
    vector<int> pos;
    for(int i=0;i<n;i++) pos.push_back(i);

    while(true){
        vector<int> newpos;
        char minl = 'z';
        for(auto x : pos){
            if(minl == t[x+cur_l]) newpos.push_back(x);
            else if(minl > t[x+cur_l]){
                newpos.clear();
                minl = t[x+cur_l];
                newpos.push_back(x);
            }
        }   
        pos = newpos;
        cur_l++;
        if(pos.size() == 1) break;
        int sz = 1, maxsz = 1;
        vector<int> mxsz = {pos[0]};
        for(int i = 1; i < 2*pos.size(); i++){
            int p1 = i % pos.size();
            int p2 = (i-1) % pos.size();
            if((n + pos[p1] - pos[p2])%n == cur_l){
                sz++;
            }else{
                sz = 1;
                if(i >= pos.size()) break;
            }
            int p = (pos[p1]+n-cur_l*(sz-1)) % n;
            if(sz > maxsz){
                maxsz = sz;
                mxsz.clear();
                mxsz.push_back(p);
            }else if(sz == maxsz){
                mxsz.push_back(p);
            }
        }
        pos = mxsz;
        cur_l = maxsz*cur_l;
        if(pos.size() == 1){
            break;
        }
    }
    cout << t.substr(pos[0], n);
}
