//TOOLS TO GENERATE input file
//new functions will be added soon
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

string gen_rbs(int n){ //()((()))(((())))
    int tt = 2*n;
    string ans = "";
    int sum = 0;
    for(int i=0;i<tt;i++){
        if(sum == 0){
            sum = 1;
            ans += '(';
        }else if(sum == tt - i){
            sum--;
            ans += ')';
        }else{
            if(uniform_int_distribution<int>(1,100000000)(rng) % 2){
                sum++;
                ans += '(';
            }else{
                sum--;
                ans += ')';
            }
        }
    }
    return ans;
}

string gen_str(int n){
    string ans = "";
    for(int i=0;i<n;i++){
        char c = uniform_int_distribution<int>(0,25)(rng) + 'a';
        ans += c;
    }
    return ans;
}

vector<int> gen_vec(int n, int M){
    vector<int> v;
    for(int i=0;i<n;i++){
        int c = uniform_int_distribution<int>(1,M)(rng);
        v.push_back(c);
    }
    return v;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in", "w", stdout); //test output;
    
    // shuffle(permutation.begin(), permutation.end(), rng);
    // pVal = uniform_int_distribution<int>(257, 1000000000)(rng);    
    const int n = 300000;
    string rbs = gen_rbs(n);
    stack<int> st;
    vector<pair<int, int>> vp;
    for(int i=0;i<rbs.size();i++){
        if(rbs[i] == '(') st.push(i);
        else{
            vp.push_back({st.top() + 1, i+1});
            st.pop();
        }
    }
    shuffle(vp.begin(), vp.end(), rng);
    //testcase <<
    cout << "1\n";
    cout << n << "\n";
    for(int i=1;i<=n;i++){
        cout << vp[i-1].first << " " << vp[i-1].second << "\n";
    }
}
