#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

const int N = 3e5+3;
int p[N], sz[N];
ll sum1[N], sum2[N];
vector<int> lst[N];

void init(){
    for(int i=1;i<N;i++) {
        p[i] = i; sz[i] = 1; lst[i].push_back(i);
    }
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    for(auto i : lst[b]){
        sum2[i] += (sum1[b] - sum1[a]);
        lst[a].push_back(i);
    }
    p[b] = a;
    sz[a] += sz[b];
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    init();
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        string s;
        int a, b;
        cin >> s;
        if(s == "add"){
            cin >> a >> b;
            a = get(a);
            sum1[a] += b;
        }else if(s == "get"){
            cin >> a;
            b = get(a);
            cout << sum1[b] + sum2[a] << "\n";
        }else{
            cin >> a >> b;
            unite(a, b);
        }
    }
}
