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


template<typename T=int>
struct monotonic_stack
{
private:
    vector<T>vec;
    vector<T>ans;
    int size;
public:

    monotonic_stack(vector<T>&v):vec(v),size(sz(v))
    {
        ans=vector<T>(sz(v));
    }

    vector<T> next_greater_element()
    {
        stack<T>monotonic;

        for(int i=size-1;i>=0;i--)
        {
            while(!monotonic.empty()&&vec[i]>=monotonic.top())monotonic.pop();

            if(monotonic.empty())ans[i]=-1;

            else ans[i]=monotonic.top();

            monotonic.push(vec[i]);
        }

        return ans;
    }



    vector<T> prev_greater_element()
    {
        stack<T>monotonic;

        for(int i=0;i<size;i++)
        {
            while(!monotonic.empty()&&vec[i]>=monotonic.top())monotonic.pop();

            if(monotonic.empty())ans[i]=-1;

            else ans[i]=monotonic.top();

            monotonic.push(vec[i]);
        }

        return ans;
    }




    vector<T> next_smaller_element()
    {
        stack<T>monotonic;

        for(int i=size-1;i>=0;i--)
        {
            while(!monotonic.empty()&&vec[i]<=monotonic.top())monotonic.pop();

            if(monotonic.empty())ans[i]=-1;

            else ans[i]=monotonic.top();

            monotonic.push(vec[i]);
        }

        return ans;
    }



    vector<T> prev_smaller_element()
    {
        stack<T>monotonic;

        for(int i=0;i<size;i++)
        {
            while(!monotonic.empty()&&vec[i]<=monotonic.top())monotonic.pop();

            if(monotonic.empty())ans[i]=-1;

            else ans[i]=monotonic.top();

            monotonic.push(vec[i]);
        }

        return ans;
    }


    vector<T> next_greater_element_in_circular()
    {
        stack<T>monotonic;

        for(int i=(2*size)-1;i>=0;i--)
        {
            while(!monotonic.empty()&&vec[i%size]>=monotonic.top())monotonic.pop();

            if(monotonic.empty())ans[i%size]=-1;

            else ans[i%size]=monotonic.top();

            monotonic.push(vec[i%size]);
        }

        return ans;
    }



    vector<T> prev_greater_element_in_circular()
    {
        stack<T>monotonic;

        for(int i=0;i<2*size;i++)
        {
            while(!monotonic.empty()&&vec[i%size]>=monotonic.top())monotonic.pop();

            if(monotonic.empty())ans[i%size]=-1;

            else ans[i%size]=monotonic.top();

            monotonic.push(vec[i%size]);
        }

        return ans;
    }




    vector<T> next_smaller_element_in_circular()
    {
        stack<T>monotonic;

        for(int i=(2*size)-1;i>=0;i--)
        {
            while(!monotonic.empty()&&vec[i%size]<=monotonic.top())monotonic.pop();

            if(monotonic.empty())ans[i%size]=-1;

            else ans[i%size]=monotonic.top();

            monotonic.push(vec[i%size]);
        }

        return ans;
    }



    vector<T> prev_smaller_element_in_circular()
    {
        stack<T>monotonic;

        for(int i=0;i<2*size;i++)
        {
            while(!monotonic.empty()&&vec[i%size]<=monotonic.top())monotonic.pop();

            if(monotonic.empty())ans[i%size]=-1;

            else ans[i%size]=monotonic.top();

            monotonic.push(vec[i%size]);
        }

        return ans;
    }
};

void solve()
{
    vector<int>vec={3,6,2,1,8,7};
    monotonic_stack<int>monotonic(vec);
    vector<int>v=monotonic.next_greater_element_in_circular();
    cout<<v;
}
void A7med(){
    ios_base ::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
}
int main(){
    A7med();
    solve();
    return 0;
}
