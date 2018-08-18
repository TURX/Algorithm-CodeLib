// LXQ AK IOI

#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

const int maxVertex = 100010;
const int maxEdge = 200010;
const long long INF = (long long)0x7FFFFFFFFFFFFFF;

struct EdgeBox
{
    struct Edge
    {
        int t;
        int l;
        Edge *next;
        Edge()
        {
            t = 0;
            next = 0;
        }
        Edge(int dest, Edge *n, int length)
        {
            t = dest;
            next = n;
            l = length;
        }
    };
    Edge e[maxEdge];
    int ec, vc;
    Edge *head[maxVertex];
    void initialize(int n)
    {
        ec = 0;
        vc = n;
        for (int i = 1; i <= n; i++)
            head[i] = 0;
    }
    void addEdge(int start, int end, int length)
    {
        e[ec] = Edge(end, head[start], length);
        head[start] = &e[ec];
        ec++;
    }
} e;

struct SPFATraceStruct
{
    long long distance[maxVertex];
    int inqueue[maxVertex];
    int trace[maxVertex];
    EdgeBox *e;
    int vc;
    queue<int> q;

    void initialize(int v, EdgeBox *edge)
    {
        memset(inqueue, 0, sizeof(inqueue));
        for (int i = 1; i <= v; i++)
            distance[i] = INF;
        vc = v;
        e = edge;
    }

    void spfa(int source)
    {
        int s = source;
        distance[s] = 0;
        inqueue[s] = true;
        q.push(s);
        while (!q.empty())
        {
            s = q.front();
            q.pop();
            inqueue[s] = false;
            for (EdgeBox::Edge *i = e->head[s]; i; i = i->next)
            {
                long long newd = distance[s] + i->l;
                if (distance[i->t] > newd)
                {
                    distance[i->t] = newd;
                    trace[i->t] = s;
                    if (!inqueue[i->t])
                    {
                        q.push(i->t);
                        inqueue[i->t] = true;
                    }
                }
            }
        }
    }

    void getTrace(int source, int sink, int *output, int &traceLength)
    {
        if (distance[sink] == INF)
        {
            traceLength = 0;
            return;
        }
        traceLength = 0;
        int s = sink;
        while (s != source)
        {
            output[traceLength++] = s;
            s = trace[s];
        }
        output[traceLength++] = s;
        for (int i = 0; i <= traceLength / 2 - 1; i++)
        {
            int tmp = output[i];
            output[i] = output[traceLength - i - 1];
            output[traceLength - i - 1] = tmp;
        }
    }
} spfa;

int n, m;
int ansc, ans[maxVertex];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    e.initialize(n);
    while (m--)
    {
        int x, y, l;
        cin >> x >> y >> l;
        e.addEdge(x, y, l);
        e.addEdge(y, x, l);
    }
    spfa.initialize(n, &e);
    spfa.spfa(1);
    spfa.getTrace(1, n, ans, ansc);
    if (ansc > 1)
    {
        cout << ans[0];
        for (int i = 1; i < ansc; i++)
            cout << ans[i];
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}