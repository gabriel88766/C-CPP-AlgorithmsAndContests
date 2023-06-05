#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e7+5;
int p[N]; // 0 if prime, 1 if not prime
vector<ll> primes;
void sieve(){
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i*i; j < N; j += i){
                p[j] = 1; //marking all multiples of i as not prime
            }
            primes.push_back(i);
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> facts;
        for(int i=0;i<n;i++){
            int num;
            cin >> num;
            int aux = num;
            for(ll i = 2; i*i <= num; i++){
                ll fat = 1, cnt = 0;
                while(!(aux%(fat*i))) fat *= i, cnt++;
                if(cnt){
                    facts.push_back({i, cnt});
                }
                aux /= fat;
            }
            if(aux != 1) facts.push_back({aux,1});
        }
        sort(facts.begin(), facts.end());
        vector<pair<int,int>> rf;
        rf.push_back(facts[0]);
        for(int i=1;i<facts.size();i++){
            if(rf.back().first == facts[i].first) rf.back().second += facts[i].second;
            else rf.push_back(facts[i]);
        }
        int cntodd = 0;
        int ans = 0;
        for(int i=0;i<rf.size();i++){
            ans += rf[i].second / 2;
            if(rf[i].second % 2) cntodd++;
        }
        ans += cntodd / 3;
        cout << ans << "\n";
    }
}
