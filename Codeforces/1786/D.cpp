#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

map<vector<int>, int> mp;
map<int,vector<int>> invmp;
vector<char> let = {'w', 'i', 'n'};
stack<int> v[10];
vector<pair<int,int>> ansi;
vector<pair<char,char>> ansc;

void init(){
    vector<int> v;
    v = {1,1,1}; mp[v] = 0; invmp[0] = v;
    v = {0,0,3}; mp[v] = 1; invmp[1] = v;
    v = {0,3,0}; mp[v] = 2; invmp[2] = v;
    v = {3,0,0}; mp[v] = 3; invmp[3] = v;
    v = {0,1,2}; mp[v] = 4; invmp[4] = v;
    v = {0,2,1}; mp[v] = 5; invmp[5] = v;
    v = {1,0,2}; mp[v] = 6; invmp[6] = v;
    v = {2,0,1}; mp[v] = 7; invmp[7] = v;
    v = {1,2,0}; mp[v] = 8; invmp[8] = v;
    v = {2,1,0}; mp[v] = 9; invmp[9] = v;
}

void change(int iia, int iib){
    int a = v[iia].top(); v[iia].pop();
    int b = v[iib].top(); v[iib].pop();
    vector<int> av = invmp[iia];
    vector<int> bv = invmp[iib];
    int ia, ib;
    for(int i=0;i<3;i++){
        if(av[i] > 1) ia = i;
        if(bv[i] > 1) ib = i;
    }
    av[ia]--;
    av[ib]++;
    bv[ib]--;
    bv[ia]++;
    ansi.push_back({a, b});
    ansc.push_back({let[ia], let[ib]});
    v[mp[av]].push(a);
    v[mp[bv]].push(b);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    init();
    cin >> t;
    while(t--){
        int m;
        cin >> m;
        //omg
        for(int i=0;i<10;i++) while(!v[i].empty()) v[i].pop();
        if(!ansi.empty()) ansi.clear();
        if(!ansc.empty()) ansc.clear();

        for(int i=1;i<=m;i++){
            vector<int> aux(3, 0);
            string s;
            cin >> s;
            for(int j=0;j<3;j++){
                if(s[j] == 'w') aux[0]++;
                if(s[j] == 'i') aux[1]++;
                if(s[j] == 'n') aux[2]++;
            }
            v[mp[aux]].push(i);
        }
        int cnt = 0;

        while(!(v[0].size() == m)){
            //verify optimals
            if(v[4].size() > 0 && v[9].size() > 0){
                change(4, 9);
                continue;
            }
            if(v[5].size() > 0 && v[7].size() > 0){
                change(5,7);
                continue;
            }
            if(v[6].size() > 0 && v[8].size() > 0){
                change(6,8);
                continue;
            }
            //suboptimal
            if(v[1].size() > 0){
                if(v[8].size()){
                    change(1,8);
                    continue;
                }else if(v[9].size()){
                    change(1,9);
                    continue;
                }
            }
            if(v[2].size() > 0){
                if(v[6].size()){
                    change(2,6);
                    continue;
                }else if(v[7].size()){
                    change(2,7);
                    continue;
                }
            }
            if(v[3].size() > 0){
                if(v[4].size()){
                    change(3,4);
                    continue;
                }else if(v[5].size()){
                    change(3,5);
                    continue;
                }
            }
            //so...
            if(v[4].size() && v[8].size()){
                change(4,8);
                continue;
            }
            if(v[5].size() && v[6].size()){
                change(5,6);
                continue;
            }
            if(v[6].size() && v[9].size()){
                change(6,9);
                continue;
            }
            if(v[7].size() && v[4].size()){
                change(7,4);
                continue;
            }
            if(v[8].size() && v[7].size()){
                change(8,7);
                continue;
            }
            if(v[9].size() && v[5].size()){
                change(9,5);
                continue;
            }
            if(v[1].size() && v[2].size()){
                change(1, 2);
                continue;
            }
            if(v[1].size() && v[3].size()){
                change(1,3);
                continue;
            }
            if(v[2].size() && v[3].size()){
                change(2,3);
                continue;
            }
        }
        cout << ansi.size() << "\n";
        for(int i=0;i<ansi.size();i++){
            cout << ansi[i].first << " " << ansc[i].first << " " << ansi[i].second << " " << ansc[i].second << "\n";
        }
    }
}
