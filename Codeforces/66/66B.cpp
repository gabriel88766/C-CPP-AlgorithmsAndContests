#include<bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< pair<int, int>, int>
#define st first
#define nd second
#define mp(x,y) make_pair(x,y)
#define sti pair<string,int>

using namespace std;

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
int linc=0,ginc=0,maxt=1;
int n, aux, pointer,old;
bool isinc;
cin >> n;
vector <int> v;
for(int i=0;i<n;i++){
    cin >> aux;
    v.push_back(aux);
}
for (int i=0;i<n;i++){
    linc=0;
    ginc=0;
    pointer=i-1;
    old = v[i];
    while(pointer >=0){
        if(v[pointer] > old) break;
        old=v[pointer];
        linc ++;
        pointer--;
    }
    pointer=i+1;
    old = v[i];
    while(pointer < n){
        if(v[pointer] > old) break;
        old=v[pointer];
        ginc ++;
        pointer++;
    }
    if(maxt<(ginc+linc+1)) maxt=ginc+linc+1;
}
cout << maxt;
}


