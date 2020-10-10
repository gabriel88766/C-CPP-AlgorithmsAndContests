
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define st first
#define nd second

const int N = 1e6+3;

vector<int> starting,ending;

int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
int n,k,a,b,stp=0,edp=0,cont=1,start,finish;
vector<pair<int,int>> p;
cin >> n >> k;

for(int i=0;i<n;i++){
    cin >> a >> b;
    starting.push_back(a);
    ending.push_back(b);
}
sort(starting.begin(),starting.end());
sort(ending.begin(),ending.end());
while(true){
    while(cont!=k && stp<(n-1)){
        if(starting[stp+1] <= ending[edp]){
            cont++;
            stp++;
        }else{
            edp++;
            cont--;
        }
    }
    if(cont == k) start = starting[stp];
    else break;
    while(cont>=k && stp<(n-1)){
        if(starting[stp+1] <= ending[edp]){
            cont++;
            stp++;
        }else{
            edp++;
            cont--;
        }
    }
    if(stp!=(n-1)) finish = ending[edp-1];
    else{
        while(cont>=k){
            edp++;
            cont--;
        }
        finish = ending[edp-1];
    }
    p.push_back(mp(start,finish));
}
cout << p.size() << endl;
for(int i=0;i<p.size();i++){
    cout << p[i].st << " " << p[i].nd << endl;
}


}
