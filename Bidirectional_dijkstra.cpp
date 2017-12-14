#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< ii > vii;
#define INF 1e9

int V,E,res(INT_MAX);
vector< vii > g;
vector< vii > gr;

vi df;
vi db;

void dijkstra(int s, int t)
{
	df[s]=0;
	db[t]=0;
	set<int> p;

	priority_queue< ii, vector< ii >, greater<ii> > pqf; pqf.push(ii(0,s));
	//Backward graph priority queue
	priority_queue< ii, vector< ii >, greater<ii> > pqb; pqb.push(ii(0,t));
	
	while(1)
	{
		//dijkstra on forward graph
		ii ff = pqf.top(); pqf.pop();
		int d(ff.first), u(ff.second);
		for(int j=0; j<g[u].size(); j++)
		{
			ii v = g[u][j];
			if(df[u] + v.second < df[v.first])
			{
				df[v.first] = df[u] + v.second;
				pqf.push(ii(df[v.first],v.first));
			}
		}

		//updating the result
		if(res > df[u]+db[u])
			res = df[u]+db[u];

		//inserting the node in the list of processed nodes
		if(p.insert(u).second == false)
			break;


		//dijkstra on reverse graph
		ii fb = pqb.top(); pqb.pop();
		d = fb.first;u = fb.second;
		for(int j=0; j<gr[u].size(); j++)
		{
			ii v = gr[u][j];
			if(db[u] + v.second < db[v.first])
			{
				db[v.first] = db[u] + v.second;
				pqb.push(ii(db[v.first],v.first));
			}
		}

		//updating the result
		if(res > df[u]+db[u])
			res = df[u]+db[u];

		//inserting the nodes in the list of processed nondes
		if(p.insert(u).second == false)
			break;
		
		if(pqf.empty() || pqb.empty())
			break;
	}
	return;	
}

int main(void)
{
	int x,y,wt;
	cin >> V >> E;
	g.assign(V, vii());
	gr.assign(V, vii());
	df.assign(V,INF);
	db.assign(V,INF);
	for(int i=0; i<E; i++)
	{
		cin >> x >> y >> wt;
		x--;y--;
		g[x].push_back(ii(y,wt));
		gr[y].push_back(ii(x,wt));
	}
	int s,t,q;
	cin >> q;
	while(q--)
	{
		res = INT_MAX;
		cin >> s >> t;
		s--; t--;
		dijkstra(s,t);
		if(res == INF)
			cout << "-1\n";
		else
			cout << res << "\n";
		fill(df.begin(),df.end(),INF);
		fill(db.begin(),db.end(),INF);
	}
	return 0;
}