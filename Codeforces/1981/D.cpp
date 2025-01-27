#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+1;
int p[N]; // 0 if prime, 1 if not prime
vector<ll> pr;
void sieve(){
    pr.push_back(0);
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i*i; j < N; j += i){
                p[j] = 1; //marking all multiples of i as not prime
            }
            pr.push_back(i);
        }
    }
}


const int M = 2000;
bool us[M][M];

int ind[M];
vector<int> path;
//no multiedges?! not tested
void euler(int u, int &n){
    for(int &j = ind[u];j <= n;){
        if(us[u][j]){j++; continue;}
        us[u][j] = us[j][u] = 1;
        euler(j++, n);
    }
    path.push_back(u); //reverse path
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    int t;
    cin >> t;
    for(int i=1;i<M;i++) ind[i] = 1;
    while(t--){
        int n;
        cin >> n;
        for(int i=1;;i++){
            int tt = i + 1;
            if(i % 2) tt += (i * (i-1))/2;
            else tt += (i * (i-1))/2 - i/2 + 1;
            if(tt >= n){
                for(int j=1;j<=i;j++){
                    for(int k=j+1;k<=i;k++){
                        if(!(i % 2)){
                            if(j != 1 && k != 2){
                                if(j % 2 && k == j + 1){
                                    us[j][k] = us[k][j] = 1;
                                }
                            }
                        }
                    }
                }
                vector<int> ans;
                if(i != 1){
                    euler(1, i);
                    reverse(path.begin(), path.end());
                }else{
                    path.push_back(1);
                    path.push_back(1);
                }
                for(int j=0;j<n;j++) cout << pr[path[j]] << " ";
                cout << "\n";


                for(int j=1;j<=i;j++){
                    for(int k=1;k<=i;k++){
                        us[j][k] = 0;
                    }
                    ind[j] = 1;
                }
                path.clear();
                break;
            }
            
        }
    }
}   
