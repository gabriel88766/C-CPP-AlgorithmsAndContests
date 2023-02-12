//tested.
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
    freq.push_back({1,'D'});
    freq.push_back({1,'C'});
    freq.push_back({2,'B'});
    freq.push_back({5,'A'});
    build(freq);
    for(int i=0;i<4;i++){
        cout << freq[i].second << " "  << codeWord[i+1] << "\n";
    }
}
