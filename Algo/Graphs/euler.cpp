//Hierholzer’s algorithm
const int N = 2e5+3;
vector<int> adj[N];
int ind[N];
vector<int> path;
//no multiedges?! not tested
void euler(int u){
    for(int &j = ind[u];j < adj[u].size();){
        euler(adj[u][j++]);
    }
    path.push_back(u); //reverse path
}
reverse(path.begin(), path.end());