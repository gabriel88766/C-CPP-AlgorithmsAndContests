#include <bits/stdc++.h>
 
using namespace std;
const int INF = 0x3f3f3f3f;
vector<int> adj[400000];
int d[400000];
 
long long int fac[] = { 1,1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
 
int value(vector<int> &v){
    int ans = 0;
    vector<char> used(10,false);
    for(int i=1;i<=9;i++ ){
        int cont = 1;
        for(int j=1;j<v[i-1];j++) if(used[j]) cont++;
        ans += fac[9-i] * (v[i-1] - cont );
        used[v[i-1]] = true;
    }
    return ans;
}
 
void bfs(int src){
 
    memset(d,63,sizeof d);
 
    queue<int> q;
    q.push(src);
    d[src] = 0;
 
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (int v : adj[u]) if (d[v] == INF)
        d[v] = d[u]+1, q.push(v);
    }
}
int main(){
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    vector<int> s;
    for(int i = 0;i<9;i++){
        int aux;
        cin >> aux;
        s.push_back(aux);
    }
    int src = value(s);
    int dest = value(v);
    do{
        int k = value(v);
        swap(v[0],v[1]);
        adj[k].push_back(value(v));
        swap(v[1],v[0]);
 
        swap(v[1],v[2]);
        adj[k].push_back(value(v));
        swap(v[2],v[1]);
 
        swap(v[3],v[4]);
        adj[k].push_back(value(v));
        swap(v[4],v[3]);
 
        swap(v[4],v[5]);
        adj[k].push_back(value(v));
        swap(v[5],v[4]);
 
        swap(v[6],v[7]);
        adj[k].push_back(value(v));
        swap(v[7],v[6]);
 
        swap(v[7],v[8]);
        adj[k].push_back(value(v));
        swap(v[8],v[7]);
 
        swap(v[0],v[3]);
        adj[k].push_back(value(v));
        swap(v[3],v[0]);
 
        swap(v[3],v[6]);
        adj[k].push_back(value(v));
        swap(v[6],v[3]);
 
        swap(v[1],v[4]);
        adj[k].push_back(value(v));
        swap(v[4],v[1]);
 
        swap(v[4],v[7]);
        adj[k].push_back(value(v));
        swap(v[7],v[4]);
 
        swap(v[2],v[5]);
        adj[k].push_back(value(v));
        swap(v[5],v[2]);
 
        swap(v[5],v[8]);
        adj[k].push_back(value(v));
        swap(v[8],v[5]);
 
    }while(next_permutation(v.begin(),v.end()));
    bfs(src);
    cout << d[dest];
}