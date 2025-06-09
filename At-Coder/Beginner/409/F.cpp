#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3005;
pair<int, int> pt[N];

int p[N], sz[N];

void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n, q;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        pt[i] = {a, b};
    }
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int d = abs(pt[i].first - pt[j].first) + abs(pt[i].second - pt[j].second);
            pq.push({d, i, j});
        }
    }
    for(int i=1;i<=q;i++){
        int tq, a, b;
        cin >> tq;
        if(tq == 1){
            cin >> a >> b;
            for(int j=1;j<=n;j++){
                pq.push({abs(pt[j].first - a) + abs(pt[j].second - b), j, n+1});
            }
            pt[++n] = {a, b};
        }else if(tq == 2){
            while(pq.size() && get(get<1>(pq.top())) == get(get<2>(pq.top()))) pq.pop();
            int d;
            if(pq.size()) d = get<0>(pq.top());
            else d = -1;
            cout << d << "\n";
            while(pq.size() && get<0>(pq.top()) == d){
                unite(get<1>(pq.top()), get<2>(pq.top()));
                pq.pop();
            }
        }else{
            cin >> a >> b;
            if(get(a) == get(b)) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}
