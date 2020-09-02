#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< pair<int, int>, int>
#define st first
#define nd second
using namespace std;

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
vector<par> p;
vector<int> dp;
vector<int> antV;
vector<int> seq;
int acw,ach;
par temp;
int n,w,h,aux1,aux2,antI=0,maxI;
cin >> n >> w >> h;
(temp.first).first = w;
(temp.st).nd = h;
temp.nd = 0;
p.push_back(temp);
for(int i=0;i<n;i++){
    cin >> aux1 >> aux2;
    (temp.first).first = aux1;
    (temp.first).second = aux2;
    temp.second = i+1;
    p.push_back(temp);
}
sort(p.begin()+1,p.end());
dp.push_back(0);
antV.push_back(-1);
for(int i=1;i<=n;i++){
    maxI=-1;
    antI=-1;
    for(int j=0;j<i;j++){
        if((p[i].st).st>(p[j].st).st &&  (p[i].st).nd>(p[j].st).nd && dp[j]>=maxI && dp[j]!=-1){
            maxI= dp[j]+1;
            antI= j;
        }
    }
    dp.push_back(maxI);
    antV.push_back(antI);
}
maxI=0;
antI=0;
for(int i=1;i<=n;i++){
    if(dp[i]>maxI){
        maxI=dp[i];
        antI=i;
    }
}

cout << maxI<<endl;
while(antI!=0){
    seq.push_back(p[antI].nd);
    antI=antV[antI];
}
for(int i=seq.size()-1;i>=0;i--){
    cout << seq[i] << " ";
}


}
