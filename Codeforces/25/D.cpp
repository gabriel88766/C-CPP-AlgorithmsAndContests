#include <bits/stdc++.h>
 
using namespace std;
typedef vector<int> vi;
const int N = 1005;
 
int par[N], sz[N];
int n;
 
int find(int a) { return par[a] == a ? a : par[a] = find(par[a]); }
 
void unite(int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a; sz[a] += sz[b];
}
 
void init(){
    for(int i=0;i<N;i++){
        par[i]=i,sz[i]=1;
    }
}
 
 
 
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    init();
    vector<pair<int,int>> v1,v2;
    int a,b,bp=0;
    cin >> n;
    for(int i=1;i<n;i++){
        cin >> a >> b;
        if(find(a)!=find(b)) unite(a,b);
        else v1.push_back(make_pair(a,b));
    }
    cout << v1.size() << endl;
    while(bp<v1.size()){
        int k = v1[bp].first;
        int dest = 1;
        cout <<  v1[bp].first << " " << v1[bp].second << " ";
        while(find(k)==find(dest)) dest++;
        cout << k << " " << dest << endl;
        unite(k,dest);
        bp++;
    }
 
 
 
}
