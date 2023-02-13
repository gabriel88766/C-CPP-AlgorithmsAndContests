#include <bits/stdc++.h>

using namespace std;
#define st first
#define nd second
#define mp make_pair
const int INF = 0x3f3f3f3f;

long long int dp[200005];
long long int realend[200005];
long long int n,a,b,c,bp=0,ans;
typedef pair<long long int,pair<long long int,long long int>> plll;

int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
//freopen("test_input.txt", "r", stdin);
vector<plll> vp;
vector<long long int> auxv(200005,INF);
dp[0]=0;
cin >> n;
for(int i=0;i<n;i++){
    cin >> a >> b >> c;
    vp.push_back(mp(b,mp(c,a)));
}
sort(vp.begin(),vp.end());
auxv[0]=-INF;
for(int i=0;i<n;i++){
    auxv[i] = vp[i].st;
}
vp.push_back(mp(0x3f3f3f3f,mp(0,0)));

dp[0] = vp[0].nd.st;

for(int i=1;i<n;i++){
    auto it = lower_bound(auxv.begin(),auxv.begin()+i,vp[i].nd.nd);
    int index = it - auxv.begin();
    --index;
    if(index >= 0 && (dp[index]+vp[i].nd.st) > dp[i-1]){
        dp[i] = (dp[index]+vp[i].nd.st);
    }else if(vp[i].nd.st > dp[i-1]){
        dp[i] = vp[i].nd.st;
    }else{
        dp[i] = dp[i-1];
    }
}
cout <<  dp[n-1];

}

