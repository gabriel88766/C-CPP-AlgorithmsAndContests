#include<bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< pair<int, int>, int>
#define st first
#define nd second
#define mp(x,y) make_pair(x,y)
#define sti pair<string,int>
//matrix vector<vector<int>> matrix(row,vector<int>(col))

using namespace std;

long long int magicf(long long int k){
    if(k==1) return 0;
    else return (k*(k-1))/2;
}

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
long long int n,m,aux,ans;
vector<long long int> v;
map<long long int,long long int> mp;
cin >> n >> m;
for(int i=0;i<n;i++){
    cin >> aux;
    v.push_back(aux);
    mp[aux]++;
}
ans = (n*(n-1))/2;
for(int i=1;i<=m;i++){
    ans -= magicf(mp[i]);
}
cout << ans;
}


