#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<typename T>
struct RandomHeap{
    T value;
    RandomHeap *l, *r;
    RandomHeap(){
        l = nullptr;
        r = nullptr;
    }
    RandomHeap(T value){
        this->value = value;
        l = nullptr;
        r = nullptr;
    }
};
template<typename T>
RandomHeap<T> *merger(RandomHeap<T>* t1, RandomHeap<T> *t2){
    if(!t1 || !t2) return t2 ? t2 : t1;
    if(t2->value < t1->value) swap(t1, t2);
    if(rng() % 2) swap(t1->l, t1->r);
    t1->l = merger(t1->l, t2);
    return t1;
}

//application : priority_queue
//minheap implementation with randomized heap
template<typename T>
struct PriorityQueue{
    RandomHeap<T> *rt = nullptr;
    PriorityQueue(){}
    void push(T value){
        RandomHeap<T> *nn = new RandomHeap<T>(value);
        if(rt == nullptr) rt = nn;
        else rt = merger(rt, nn);
    }
    T top(){
        return rt->value;
    }
    void pop(){
        RandomHeap<T> *nrt = merger(rt->l, rt->r);
        delete rt;
        rt = nrt;
    }
    bool empty(){
        return rt == nullptr;
    }
};

//standard task : distinct numbers, test sort related algorithms
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    PriorityQueue<int> pq;
    for(int i=0;i<v.size();i++){
        pq.push(v[i]);
    }
    int cur = 0, ans = 0;
    while(!pq.empty()){
        if(pq.top() != cur){
            ans++;
            cur = pq.top();
        }
        pq.pop();
    }
    cout << ans << "\n";
}
