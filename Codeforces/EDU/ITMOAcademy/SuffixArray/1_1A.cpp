#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

const int N = 2e5+3; // 2 * MAX_SIZE + 1
int ind[N], mp[N];

void suffix_array(string s){
    s += "$";
    int n = s.size(), c=-1;
    vector<pair<char, int>> v(n);
    vector<pair<pair<int,int>, int>> cs(n); // class of string <int,int> and pos 
    vector<int> newv(n);
    for(int i=0;i<n;i++) v[i] = {s[i], i};
    sort(v.begin(), v.end());


    for(int i=0;i<n; i++){ 
        cs[i].second = v[i].second;
        mp[cs[i].second] = i;
        if(i && v[i].first == v[i-1].first){
            cs[i].first.first = c;
        }else{
            cs[i].first.first = ++c;
        }
    }
    
    int pot = 32 - __builtin_clz(s.size());
    for(int i=0;i<pot;i++){
        int offset = 1 << i;
        for(int j=0;j<n;j++){
            int mindex = cs[j].second + offset;
            mindex = mindex >= n ? mindex - n : mindex;
            cs[j].first.second = cs[mp[mindex]].first.first;
        }
        sort(cs.begin(), cs.end());
        for(int j=0;j<n;j++) mp[cs[j].second] = j;
        c = -1;
        for(int j=0;j<n;j++){
            if(j && cs[j].first == cs[j-1].first){
                newv[j] = c;
            }else{
                newv[j] = ++c;
            }
        }
        for(int j=0;j<n;j++) cs[j].first.first = newv[j];
    }
    for(int i=0;i<n;i++) ind[i] = cs[i].second;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    string s;
    cin >> s;
    suffix_array(s);
    for(int i=0;i<=s.size();i++){
        cout << ind[i] << " ";
    }
}
