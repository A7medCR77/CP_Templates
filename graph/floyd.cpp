#include <bits/stdc++.h>
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

// ______________________________________________CODE________________________________________________________________________________________________________________________________________

template <typename T = int, int base = 1>
struct floyd
{
    struct Graph
    {
        T u, v, w;
        Graph(T _u = 0, T _v = 0, T _w = 0) : u(_u), v(_v), w(_w){};
        bool operator<(const T &rhs)
        {
            return w < rhs.w;
        }
    };

    T n;
    vector<Graph> graph;
    vector<vector<T>> dis;

    floyd(T n, T e)
    {
        this->n = n;
        graph.resize(e);
        dis.assign(n + 5, vector<T>(n + 5, OO));
    }

    floyd(T n, T e, vector<vector<int>> &vec)
    {
        this->n = n;
        graph.resize(e);
        dis.assign(n + 5, vector<T>(n + 5, OO));
        for (int i = 0; i < e; ++i)
        {
            graph[i].u = vec[i][0];
            graph[i].v = vec[i][1];
            graph[i].w = vec[i][2];
            dis[graph[i].u][graph[i].u] = dis[graph[i].v][graph[i].v] = 0;
            dis[graph[i].u][graph[i].v] = dis[graph[i].v][graph[i].u] = min({dis[graph[i].u][graph[i].v], dis[graph[i].v][graph[i].u], graph[i].w});
        }
    }

    vector<vector<T>> put_input()
    {
        for (auto &i : graph)
        {
            cin >> i.u >> i.v >> i.w;
            dis[i.u][i.u] = dis[i.v][i.v] = 0;
            dis[i.u][i.v] = dis[i.v][i.u] = min({dis[i.u][i.v], dis[i.v][i.u], i.w});
        }
        return Floyd();
    }

    T operation(T a, T b, T c)
    {
        return min(a, b + c);
    }

    vector<vector<T>> Floyd()
    {
        for (int node = base; node < n + base; ++node)
            for (int u = base; u < n + base; ++u)
                for (int v = base; v < n + base; ++v)
                    dis[u][v] = operation(dis[u][v], dis[u][node], dis[node][v]);

        return dis;
    }
};

void solve(){
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
