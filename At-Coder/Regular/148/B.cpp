#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5005; 
int n, c;
// n log n
int cnt[N], aux[N], mp2[256];
pair<int, int> cs[N];
vector<int> suffix_array(string s){
    s += "$";
    n = s.size(), c=-1;
    vector<int> mp(n);

    for(int i=0;i<n;i++) cnt[s[i]]++;
    for(int i=0;i<256;i++){
        if(cnt[i]) mp2[i] = ++c;
        if(i) cnt[i] += cnt[i-1];
    } 
    for(int i=0;i<n;i++) mp[--cnt[s[i]]] = i; 
    for(int i=0;i<n;i++) cs[i].first = mp2[s[i]];

    for(int i=0;(1 << i) < n;i++){
        fill(cnt, cnt + c + 2, 0);
        int offset = 1 << i;
        for(int j=0;j<n;j++){
            int mindex = (j + offset) >= n ? j + offset - n : j + offset;
            cs[j].second = cs[mindex].first;
            cnt[cs[j].second + 1]++;
        }
        //begin raddix_sort of pair O(n)
        for(int j=2; j<=(c+1); j++) cnt[j] += cnt[j-1];
        for(int j=0; j<n; j++) aux[cnt[cs[j].second]++] = j;
        fill(cnt, cnt + c + 2, 0);
        for(int j=0; j<n; j++) cnt[cs[j].first+1]++; 
        for(int j=2; j<=(c+1); j++) cnt[j] += cnt[j-1];
        for(int j=0; j<n;j++) mp[cnt[cs[aux[j]].first]++] = aux[j]; 
        //end raddix_sort
        aux[mp[0]] = c = 0;
        for(int j=1;j<n;j++){
            if(cs[mp[j]] == cs[mp[j-1]]) aux[mp[j]] = c;
            else aux[mp[j]] = ++c;
        }
        for(int j=0;j<n;j++) cs[j].first = aux[j];
    }
    return mp;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    string s;
    cin >> n >> s;
    int fp = -1;
    for(int i=0;i<n;i++){
        if(s[i] == 'p'){
            fp = i;
            break;
        }
    }
    if(fp == -1) cout << s << "\n";
    else{
        int xd = fp;
        while(xd + 1 < s.size() && s[xd + 1] == 'p') xd++;
        while(xd + 1 < s.size() && s[xd + 1] == 'd') xd++;
        string os = s;
        for(int i=fp;i<=xd;i++){
            os[i] = 'd';
        }
        reverse(s.begin(), s.end());
        auto sa = suffix_array(s);
        int ls = n - sa.back() - 1;
        reverse(s.begin(), s.end());
        assert(ls >= fp);
        reverse(s.begin() + fp, s.begin() + ls + 1);
        for(int i=fp;i<=ls;i++){
            if(s[i] == 'd') s[i] = 'p';
            else s[i] = 'd';
        }
        cout << min(s, os) << "\n";
        
    }
}
