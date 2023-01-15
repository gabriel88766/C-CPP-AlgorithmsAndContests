#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

//mp maps current position to original index, c is the class of the prefix

int  n, c;

const int N = 400005, M = 20; // M >= log2(N)
ll sparse[N][M];

void build(vector<int> &v){
    int m = v.size();
    for(int i=0;i<m;i++) sparse[i][0] = v[i];
    for(int j = 1; j < M; j++){
        for(int i = 0; i < m; i ++){
            if((i + (1 << (j-1))) < m) sparse[i][j] = min(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]);
            else sparse[i][j] = sparse[i][j-1];
        }
    }
}

ll query(int a, int b){
    if(a > b) swap(a,b);
    b--;
    if(a == b) return sparse[a][0];
    int pot = 32 - __builtin_clz(b - a) - 1; 
    return min(sparse[a][pot], sparse[b - (1 << pot) + 1][pot]);
}


vector<int> suffix_array(string &s){
    s += " "; // '$' greater than 33
    n = s.size(), c=-1;
    vector<int> mp(n), cnt(max(n+1, 256)), mp2(256), aux(n); 
    vector<pair<int,int>> cs(n); // class,class <int,int>

    for(int i=0;i<n;i++) cnt[s[i]]++;
    for(int i=0;i<256;i++){
        if(cnt[i]) mp2[i] = ++c;
        if(i) cnt[i] += cnt[i-1];
    } 
    for(int i=0;i<n;i++) mp[--cnt[s[i]]] = i; 
    for(int i=0;i<n;i++) cs[i].first = mp2[s[i]];

    for(int i=0;(1 << i) < n;i++){
        fill(cnt.begin(), cnt.begin() + c + 2, 0);
        int offset = 1 << i;
        for(int j=0;j<n;j++){
            int mindex = (j + offset) >= n ? j + offset - n : j + offset;
            cs[j].second = cs[mindex].first;
            cnt[cs[j].second + 1]++;
        }
        //begin raddix_sort of pair
        for(int j=2; j<=(c+1); j++) cnt[j] += cnt[j-1];
        for(int j=0; j<n; j++) aux[cnt[cs[j].second]++] = j;
        fill(cnt.begin(), cnt.begin() + c + 2, 0);
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

vector<int> invmp(N, 0);

vector<int> lcp(string &s, vector<int> &sa){
    vector<int> ans(n - 1, 0);
    for(int i=0;i<n; i++) {invmp[sa[i]] = i;}
    int cnt = 0;
    for(int i=0;i < (n-1); i++){
        if(invmp[i] == (n-1)){
            cnt = 0;
            continue;
        }
        int j = sa[invmp[i] + 1];
        while (s[i+cnt] == s[j+cnt]) cnt++;
        ans[invmp[i]] = cnt;
        if (cnt) cnt--;
    }
    return ans;
}

bool comparefun(pair<int,int> &u, pair<int,int> &v){
    if(u.first != v.first){
        int k = query(invmp[u.first-1], invmp[v.first-1]);
        if(!k) return invmp[u.first-1] < invmp[v.first-1];
        else{
            int len1 = u.second - u.first + 1, len2 = v.second - v.first + 1;
            if(len1 <= k || len2 <= k ){
                if(len1 == len2) return u < v;
                else return len1 < len2;
            }else return invmp[u.first-1] < invmp[v.first-1];
        }
    }else return u.second < v.second;
}

// sorting substrings
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qnt;
    string s;
    cin >> s >> qnt;
    vector<int> sa = suffix_array(s);
    vector<int> lc = lcp(s, sa);
    build(lc);
    vector<pair<int, int>> pairs(qnt);
    for(int i=0;i<qnt;i++) cin >> pairs[i].first >> pairs[i].second;
    sort(pairs.begin(), pairs.end(), comparefun);
    cout << "\n";
    for(int i=0;i<qnt;i++) cout << pairs[i].first << " " << pairs[i].second << "\n";


}