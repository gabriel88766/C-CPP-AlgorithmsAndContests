#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
using namespace std;

//cout << fixed << setprecision(6)

const int N = 2e6;

int nodeOfvaluetree[N][10];
int orderleaf[N];
vector<int> adj[400000];

int cntnodes = 0;
int cntOrder = 0;
int h = 0;
vector<char> isUsed(10, false);


void make_tree(){
    if(h == 9){
        orderleaf[cntnodes] = cntOrder++;
        return;
    }
    int cur = cntnodes;
    for(int i=1;i<=9;i++){
        if(!isUsed[i]){
            isUsed[i] = true;
            nodeOfvaluetree[cur][i] = ++cntnodes;
            h++;
            make_tree();
            h--;
            isUsed[i] = false;
        }
    }
}

int findOrder(vector<int> &v){
    int node = 0;
    for(int i=0;i<=8;i++){
        node = nodeOfvaluetree[node][v[i]];
    }
    return orderleaf[node];
}

int d[400000];

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    make_tree();
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    vector<int> s;
    for(int i = 0;i<9;i++){
        int aux;
        cin >> aux;
        s.push_back(aux);
    }
    int src = findOrder(s);
    int dest = findOrder(v);
    do{
        int k = findOrder(v);
        swap(v[0],v[1]);
        adj[k].push_back(findOrder(v));
        swap(v[1],v[0]);
 
        swap(v[1],v[2]);
        adj[k].push_back(findOrder(v));
        swap(v[2],v[1]);
 
        swap(v[3],v[4]);
        adj[k].push_back(findOrder(v));
        swap(v[4],v[3]);
 
        swap(v[4],v[5]);
        adj[k].push_back(findOrder(v));
        swap(v[5],v[4]);
 
        swap(v[6],v[7]);
        adj[k].push_back(findOrder(v));
        swap(v[7],v[6]);
 
        swap(v[7],v[8]);
        adj[k].push_back(findOrder(v));
        swap(v[8],v[7]);
 
        swap(v[0],v[3]);
        adj[k].push_back(findOrder(v));
        swap(v[3],v[0]);
 
        swap(v[3],v[6]);
        adj[k].push_back(findOrder(v));
        swap(v[6],v[3]);
 
        swap(v[1],v[4]);
        adj[k].push_back(findOrder(v));
        swap(v[4],v[1]);
 
        swap(v[4],v[7]);
        adj[k].push_back(findOrder(v));
        swap(v[7],v[4]);
 
        swap(v[2],v[5]);
        adj[k].push_back(findOrder(v));
        swap(v[5],v[2]);
 
        swap(v[5],v[8]);
        adj[k].push_back(findOrder(v));
        swap(v[8],v[5]);
 
    }while(next_permutation(v.begin(),v.end()));
    bfs(src);
    cout << d[dest];
}
