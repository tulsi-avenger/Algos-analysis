#include<bits/stdc++.h>

using namespace std;
int n,m;
typedef vector<int> vi;
#define rep(i,k,n) for(int i=k;i<=n;i++)
typedef vector<vi> vvi;
typedef pair<int,int>  pii;
typedef vector<pii> vpi;
void warshell(vvi & g)
{
	vvi dist(n,vi(n));

	rep(i,0,n-1)
	{
		rep(j,0,n-1)
		{
			dist[i][j]=g[i][j];
		}
	}

	rep(k,0,n-1)
	{
		rep(i,0,n-1)
		{
			rep(j,0,n-1)
			{
				if(dist[i][j]>dist[i][k]+dist[k][j])
				{
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
	rep(i,0,n-1)
	{
		rep(j,0,n-1)
		{
			printf("%4d",dist[i][j]);
		}
		cout<<endl;
	}



}
void dij(vvi & g,vi & temp,int s)
{
	rep(i,0,n-1)
	temp[i]=20000000;
	temp[s]=0;

	priority_queue<pii,vector<pii>,greater<pii> > pq;
	pq.push({0,s});
	while(!pq.empty())
	{
		int u=pq.top().second;
		pq.pop();
		rep(i,0,n-1)
		{
			if(g[u][i]!=20000000)
			{

				if(temp[i]>temp[u]+g[u][i])
				{
					temp[i]=temp[u]+g[u][i];
					pq.push({temp[i],i});
				}

			}
		}


	}
}
void dijkestra(vvi & g)
{
	vvi dist(n,vi(n));
	vi temp(n);
	rep(i,0,n-1)
	{
		dij(g,temp,i);
		rep(j,0,n-1)
		{
			dist[i][j]=temp[j];
		}
	}
	rep(i,0,n-1)
	{
		rep(j,0,n-1)
		{
			printf("%4d",dist[i][j]);
		}
		cout<<endl;
	}
}
int main()
{
	int u,v,w;
	cin>>n>>m;
	vvi g(n,vi(n)) ;
	rep(i,0,n-1)
	{
		rep(j,0,n-1)
		g[i][j]=10000000;
	}
	rep(i,0,n-1)
	g[i][i]=0;
	
	rep(i,0,m-1)
	{
		cin>>u>>v>>w;
		g[u][v]=w;
		g[v][u]=w;

	}
	warshell(g);
	cout<<endl;
	dijkestra(g);

}