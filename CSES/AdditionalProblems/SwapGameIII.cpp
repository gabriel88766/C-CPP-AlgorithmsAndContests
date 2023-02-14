#include <bits/stdc++.h>
 
using namespace std;
const int INF = 0x3f3f3f3f;

const int N = 2e6;//idk bounds..
int cntn = 0;
int cntl = 0;
int trie[N][10];
int ln[N], p1[N], p2[N], val[N];
int d[N];

int add(int node, int c){
    if(trie[node][c]) return trie[node][c];
    else {
        p1[++cntn] = node;
        p2[cntn] = c;
        return trie[node][c] = cntn;
    }
}

int addv(vector<int> &v){
    int curn = 0;
    for(auto c : v) curn = add(curn, c);
    if(!val[curn]){
        ln[++cntl] = curn;
        val[curn] = cntl;
    }
    return val[curn]; //leaf value
}
 
void recv(vector<int> &v, int l){
    int cur = ln[l];
    for(int i=8;i>=0;i--){
        v[i] = p2[cur];
        cur = p1[cur];
    }
}

int swx[] = {0,1,3,4,6,7,0,3,1,4,2,5};
int swy[] = {1,2,4,5,7,8,3,6,4,7,5,8};

void bfs(int src){
    memset(d,63,sizeof d);
    queue<int> q;
    q.push(src);
    d[src] = 0;
    vector<int> cur(9);
    while (!q.empty()) {
      int u = q.front(); q.pop();
      if(u == 1) return;
      recv(cur, u);
      for (int i=0;i<12;i++){
        swap(cur[swx[i]], cur[swy[i]]);
        int v = addv(cur);
        swap(cur[swx[i]], cur[swy[i]]);
        if (d[v] == INF)
            d[v] = d[u]+1, q.push(v);
      }
        
    }
}
int main(){
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    addv(v);
    vector<int> s(9);
    vector<int> ds;
    
    for(int i = 0;i<9;i++) cin >> s[i];
    int src = addv(s);
    
    bfs(src);
    cout << d[1];
}