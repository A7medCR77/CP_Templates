#include <bits/stdc++.h>
#define ll long long
#define sz(s) s.size()
#define all(s)  s.begin(),s.end()
#define nl '\n'


using namespace std;

template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x;
    return in;
}

template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) {
    for (const T &x : v) out << x << ' ';
    return out;
}

template<typename T>struct Coordinate_Compression
{
    vector<T>vec;
    
    bool is_bulid;

    Coordinate_Compression(vector<T>&v)
    {
        vec=v;
        bulid();
    }
    
    Coordinate_Compression(): is_bulid(false) {}
    
    void add(T val)
    {
        vec.emplace_back(val);
        is_bulid=false;
    }

    void bulid()
    {
        sort(all(vec));
        
        vec.resize(unique(all(vec))-vec.begin());
        
        is_bulid=true;
    }


    T get_val(T value)
    {
        if(!is_bulid)bulid();

        return upper_bound(all(vec),value)-vec.begin();
    }

    vector<T> get_compressed_element()
    {
        if(!is_bulid)bulid();

        vector<T>ans;
        for(auto&i:vec)
            ans.emplace_back(get_val(i));

        return ans;
    }

    vector<T> get_mapping()
    {
        if(!is_bulid)bulid();
        
        vector<T>ans(sz(vec)+1);
        for(auto&i:vec)
            ans[get_val(i)]=i;

        return ans;
    }

};

void solve()
{
    vector<ll>vec={1,5,9,10,100,2};

    Coordinate_Compression c(vec);
    c.add(4);
    cout<<c.get_compressed_element()<<nl;
    cout<<c.get_mapping()<<nl;
    cout<<c.get_val(100);
}

int main(){
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}
