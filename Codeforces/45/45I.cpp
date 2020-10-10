#include<bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< pair<int, int>, int>
#define st first
#define nd second
#define mp(x,y) make_pair(x,y)
#define sti pair<string,int>
//matrix vector<vector<int>> matrix(row,vector<int>(col))

using namespace std;

bool func(int a,int b){
    if(a>b) return true;
    else return false;
}

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
bool hasZ=false;
vector<int> pos,neg;
int aux,n;
cin >> n;
for(int i=0;i<n;i++){
    cin >> aux;
    if(aux>0) pos.push_back(aux);
    else if(aux<0) neg.push_back(aux);
    else hasZ=true;
}
// 1 negative 0 positive and hasZ or !hasZ
int ps,ns;
ps = pos.size();
ns = neg.size();
if(ps==0 && ns==1){
    if(hasZ) cout << "0";
    else cout << neg[0];
}else if (ps==0 && ns==0){
    cout << 0;
}
else
{
    while(!pos.empty()){
        cout << *(--pos.end()) << " ";
        pos.pop_back();
    }
    sort(neg.begin(),neg.end(),func);
    while(!(neg.size()==1 || neg.size()==0)){
        cout << *(--neg.end()) << " ";
        neg.pop_back();
        cout << *(--neg.end()) << " ";
        neg.pop_back();
    }
}



}
