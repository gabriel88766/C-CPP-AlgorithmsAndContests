//Was solving 2009G3 and got many TLEs, so I made this struct to fix the issue.
template<typename T>
struct Deque{
    T *dq = new T[1000005];
    int l_ptr = 500002, r_ptr = 500001;
    int szdq = 0;
    inline void push_back(const T& p){
        dq[++r_ptr] = p;
        szdq++;
    }

    inline void pop_back(){
        r_ptr--;
        szdq--;
    }

    inline void push_front(const T& p){
        dq[--l_ptr] = p;
        szdq++;
    }

    inline void pop_front(){
        l_ptr++;
        szdq--;
    }

    inline T at(int pos) const {
        return dq[l_ptr+pos];
    }

    T operator [](int i) const {
        return dq[l_ptr+i];
    }

    T front() const {
        return dq[l_ptr];
    }

    T back() const {
        return dq[r_ptr];
    }

    int size() const {
        return szdq;
    }

    void clear(){
        l_ptr = 500002;
        r_ptr = 500001;
        szdq = 0;
    }
};