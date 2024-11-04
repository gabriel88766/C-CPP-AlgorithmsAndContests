#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2505;
char gr[N][N];
int jmx[N], jmn[N], imn[N];
int h1[N][N];  
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        int n, k;
        cin >> n >> k;
        int mni = n+1, mxi = 0, mnj = n+1, mxj = 0; // for 1
        int mxii = 0, mxjj = 0; // for '?'
        int mnii = n+1, mnjj = n+1;
        for(int i=1;i<=n;i++){
            imn[i] = jmn[i] = n+1;
            jmx[i] = 0;
        }
        vector<pair<int,int>> opt;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin >> gr[i][j];
                if(gr[i][j] == '1'){
                    mni = min(mni, i);
                    mxi = max(mxi, i);
                    mnj = min(mnj, j);
                    mxj = max(mxj, j);
                }
                if(gr[i][j] == '?'){
                    opt.push_back({i, j});
                    jmx[i] = max(jmx[i], j);
                    imn[j] = min(imn[j], i);
                    jmn[i] = min(jmn[i], j);
                    h1[i][j] = 1;
                    mxii = max(mxii, i);
                    mxjj = max(mxjj, j);
                    mnii = min(mnii, i);
                    mnjj = min(mnjj, j);
                }else{
                    h1[i][j] = 0;
                }
            }
        }
        int Ans;
        if(k >= 4){
            for(auto [a, b] : opt){
                mni = min(mni, a);
                mxi = max(mxi, a);
                mnj = min(mnj, b);
                mxj = max(mxj, b);
            }
            Ans = (mxi-mni+1) * (mxj-mnj+1);
        }else{
            if(mxi >= mni) Ans = (mxi-mni+1) * (mxj-mnj+1);
            else Ans = 0;
            for(int i=1;i<=mni;i++){
                for(int j=1;j<=mnj;j++){
                    int mq = 0;
                    if(h1[i][j]){
                        mq = 1;
                    }else if(gr[i][j] == '1'){
                        mq = 0;
                    }else if(i == mni){
                        if(j != jmn[i]) continue;
                        mq = 1;
                    }else if(j == mnj){
                        if(i != imn[j]) continue;
                        mq = 1;
                    }else{
                        if(i != mnii && j != mnjj) continue;
                        mq = 2;
                    }
                    //only O(n)
                    if(mq == k){
                        Ans = max((mxi - i + 1) * (mxj - j + 1), Ans);
                    }else if(mq == k-1){
                        for(int k=i;k<=n;k++){
                            if(jmx[k] != 0 && jmx[k] > mxj) Ans = max((k - i + 1) * (jmx[k] - j + 1), Ans);
                            else Ans = max((k - i + 1) * (mxj - j + 1), Ans);
                        }
                    }else if(mq >= k-2){
                        Ans = max(Ans, (max(mxii, mxi) - i + 1) * (max(mxjj, mxj) - j + 1));
                    }
                }
            }
        }
        cout << "Case #" << i << ": "; 
        cout << Ans << "\n";
    }
}
