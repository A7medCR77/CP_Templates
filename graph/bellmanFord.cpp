#include <bits/stdc++.h>\
#define ll long long
#define ull unsigned long long
#define EPS 1e-9
#define MOD 1000000007
#define ceil(n, m) (n + m - 1) / m
#define round(n, m) (n + m / 2) / m
#define sz(s) s.size()
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define sum_of_first_n_odd_number(n) ((n % MOD) * (n % MOD)) % MOD;
#define all(s) s.begin(), s.end()
#define OO INT_MAX
#define ld long double
#define pi 3.141592653589793
#define rall(s) s.rbegin(), s.rend()
#define fixed(n) cout << fixed << setprecision(n)
#define mod_combine(a, b, m) (((a % m) * (b % m)) % m)
#define se second
#define fi first
#define eb emplace_back
#define pb push_back
#define pf push_front
#define nl '\n'
#define PI acos(-1.0)
#define EPS 1e-9
#define dot_prod(a, b) real(conj(a) * (b))
#define cross_prod(a, b) imag(conj(a) * (b))
#define rotateO(p, theta) (p) * polar(1.0, theta)
#define rotateA(p, a, theta) rotateO((p) - (a), theta) + (a)
#define reflectO(p, m) conj((p) / (m)) * (m)
#define reflectA(p, a, m) reflectO((p) - (a), m) + (a)
#define INF 9223372036854775807
#define E 2.71828182846
#define tolower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)

using namespace std;
template <typename T = int>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
        in >> x;
    return in;
}

template <typename T = int>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (const T &x : v)
        out << x << " ";
    return out;
}

struct edge
{
    int src, dst, w;
    edge(int _src, int _dst, int _w) : src(_src), dst(_dst), w(_w) {}
    bool operator<(const edge &rhs) const
    {
        return w > rhs.w;
    }
};

struct bellmanFord
{
    vector<int> par, val;
    vector<edge> graph;
    int v, e, start, end;
    bool n_cycle, bulid;
    bellmanFord(int n, vector<edge> &vec, int start, int end = -1) : start(start), end(end)
    {
        bulid = 1;
        n_cycle = false;
        v = n;
        e = sz(vec);
        graph = vec;
        par.assign(v + 5, -1);
        val.assign(v + 5, OO);
    }

    vector<int> bellman()
    {
        bulid = 1;

        par[start] = -1;
        val[start] = 0;

        for (int i = 0; i < v - 1; ++i)
        {
            bool update = false;
            for (int l = 0; l < e; ++l)
            {
                int a, b, wt;
                a = graph[l].src;
                b = graph[l].dst;
                wt = graph[l].w;

                if (val[a] != OO && val[a] + wt < val[b])
                {
                    update = true;
                    val[b] = val[a] + wt;
                    par[b] = a;
                }
            }
            if (!update)
                break;
        }

        for (int l = 0; l < e; ++l)
        {
            int a, b, wt;
            a = graph[l].src;
            b = graph[l].dst;
            wt = graph[l].w;

            if (val[a] != OO && val[a] + wt < val[b])
            {
                // -N cycle
                n_cycle = 1;
                return {-1};
            }
        }

        return val;
    }

    vector<int> get_path(int src, int dst)
    {

        start = src;
        end = dst;

        if (!bulid)
            bellman();

        if (n_cycle)
            return {-1};

        vector<int> ans;

        for (int i = end; i != -1; i = par[i])
            ans.eb(i);

        reverse(all(ans));

        return ans;
    }
};

void solve()
{
}

int main()
{
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
