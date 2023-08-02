#include <bits/stdc++.h>
#define ll long long
#define sz(s) s.size()
#define eb emplace_back
#define pb push_back
#define nl '\n'
#define all(s) s.begin(), s.end()
using namespace std;

struct Isomorphism
{

private:
    string dfs(int node, vector<vector<string>> &can)
    {
        string ans = "(";

        sort(all(can[node]));

        for (auto &i : can[node])
            ans += i;
        ans += ')';
        return ans;
    }

public:
    Isomorphism() {}

    // when compare between two trees with given the root
    string dfs(int node, int par, vector<vector<int>> &graph)
    {
        vector<string> ans;
        for (auto &ch : graph[node])
            if (ch != par)
                ans.pb(dfs(ch, node, graph));

        string s = "(";
        sort(all(ans));
        for (auto &l : ans)
            s += l;
        s += ')';

        return s;
    }

    // when compare between two trees without given the root

    string bfs(ll n, vector<vector<int>> &graph)
    {
        queue<int> leaf;
        vector<int> deg(n + 5, 0);
        vector<vector<string>> can(n + 5);
        for (int i = 1; i <= n; ++i)
        {
            if (sz(graph[i]) <= 1)
                leaf.push(i);
            else
                deg[i] = sz(graph[i]);
        }

        int cnt_node = n;

        while (cnt_node > 2)
        {
            int sz = sz(leaf);
            while (sz--)
            {
                int x = leaf.front();
                leaf.pop();

                string s = dfs(x, can);

                for (auto &par : graph[x])
                {
                    can[par].push_back(s);
                    if (--deg[par] == 1)
                        leaf.push(par);
                }
                cnt_node--;
            }
        }

        int node1 = leaf.front();
        leaf.pop();
        string ans1 = dfs(node1, can);

        if (leaf.empty())
            return ans1;

        int node2 = leaf.front();
        leaf.pop();
        string ans2 = dfs(node2, can);

        can[node1].push_back(ans2);
        can[node2].push_back(ans1);

        return min(dfs(node1, can), dfs(node2, can));
    }
};

void solve()
{
}

int main()
{
    ll t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
