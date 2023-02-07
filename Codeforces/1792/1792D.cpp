#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct vec{
    vector<int> v;
    int ind;
};

bool compare(vec &u, vec &v){
    int n = u.v.size();
    int x[n+1], y[n+1];
    for(int i=0;i<u.v.size(); i++){
        x[u.v[i]] = i;
        y[v.v[i]] = i;
    }
    for(int i=1;i<=u.v.size(); i++){
        if(x[i] < y[i]) return true;
        else if(x[i] > y[i]) return false;
    }
    return u.ind < v.ind;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vec> v;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            vec aux2;
            for(int j=0;j<m;j++){
                int aux;
                cin >> aux;
                aux2.v.push_back(aux);
            }
            aux2.ind = i;
            v.push_back(aux2);
        }
        sort(v.begin(), v.end(), compare);
        for(int i=0;i<n;i++){
            int lo = 0, hi = n-1, cans = 0;
            for(int j=1;j<=m;j++){
                int posj = v[i].v[j-1]-1; //0indexed
                int clo = lo, chi = hi;
                for(int k = (hi-lo)/2; k >= 1; k /= 2){
                    while(clo + k <= hi){
                        int posjh;
                        for(int w = 0; w < m; w++){
                            if(v[clo+k].v[w] == j) posjh = w;
                        }
                        if(posjh < posj) clo+=k;
                        else break;
                    }
                }
                if(v[clo].v[posj] != j) clo++;

                for(int k = (hi-lo)/2; k >= 1; k /= 2){
                    while(chi - k >= lo){
                        int posjh;
                        for(int w = 0; w < m; w++){
                            if(v[chi-k].v[w] == j) posjh = w;
                        }
                        if(posjh > posj) chi -=k;
                        else break;
                    }
                }
                if(v[chi].v[posj] != j) chi--;
                if(chi >= clo) {cans++; lo = clo; hi = chi;}
                else break;
            }
            ans[v[i].ind] = cans;
        }
        for(int i=0;i<ans.size();i++) cout << ans[i] << " ";
        cout << "\n";
    }
}
