//https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_15_D
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N = 257; //alphabet size
bool isLeaf[2*N], isRightChild[2*N];
int p[2*N];
string codeWord[N];
int cn = 0; 

void build(vector<pair<ll,char>> freq){ // sum of all freq < 1e18
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    for(auto u : freq){
        int node = ++cn;
        isLeaf[node] = true;
        pq.push({u.first, node});
    }
    while(pq.size() >= 2){
        auto r = pq.top();
        pq.pop();
        auto l = pq.top();
        pq.pop();
        int node = ++cn;
        p[l.second] = p[r.second] = cn;
        isRightChild[r.second] = true;
        pq.push({l.first + r.first, cn});
    }
    for(int i=1;i<=freq.size();i++){
        int cur = i;
        string cw;
        while(p[cur]){
            if(isRightChild[cur]) cw += '1';
            else cw += '0';
            cur = p[cur]; 
        }
        reverse(cw.begin(), cw.end());
        codeWord[i] = cw; 
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    vector<pair<ll,char>> freq;
    string s;
    cin >> s;
    vector<int> mp(26,0), mp2(26,0);
    //counting frequences
    for(int i=0;i<s.size();i++){
        mp[s[i]-'a']++;
    }
    int cnt = 0;
    //mapping letters to node ans inserting in frequence vector
    for(int i=0;i<26;i++){
        if(mp[i]){
            mp2[i] = ++cnt;
            freq.push_back({mp[i], 'a'+i});
        }
    }
    // if 1 symbol, then special case.
    if(cnt == 1){
        cout << s.size() << "\n";
        return 0;
    }
    build(freq);
    int ans = 0;
    for(int i=0;i<26;i++){
        ans += codeWord[mp2[i]].size() * mp[i];
    }
    cout << ans << "\n";
}
