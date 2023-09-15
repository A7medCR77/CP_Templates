#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define debug(x) cout << #x << ": " << (x) << "\n";
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

// Time complexity (v^2)
template <typename T = int>
struct prim
{
    int sz;
    vector<vector<T>> graph; // adj matrix
    vector<int> vis, par;
    vector<T> val;

    prim(vector<vector<T>> &_graph, int n) : graph(_graph)
    {
        sz = n;
        vis.assign(n, 0);
        par.assign(n, 0);
        val.assign(n, OO);
    }

    int min_val()
    {
        T mn = OO;
        int v;
        for (int i = 0; i < sz; ++i)
        {
            if (!vis[i] && val[i] < mn)
            {
                mn = val[i];
                v = i;
            }
        }

        return v;
    }

    vector<T> Prim()
    {
        val[0] = 0;
        par[0] = -1;

        for (int i = 0; i < sz - 1; ++i)
        {
            int v = min_val();
            vis[v] = 1;

            for (int l = 0; l < sz; ++l)
            {
                if (!vis[l] && graph[v][l] && val[l] > graph[v][l])
                {
                    val[l] = graph[v][l];
                    par[l] = v;
                }
            }
        }

        return val;
    }
};

void siu()
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
