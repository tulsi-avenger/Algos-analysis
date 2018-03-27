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
	cout<<"Floyd-Warshall\n";
	rep(i,0,n-1)
	{
		rep(j,0,n-1)
		{
			printf("%10d",dist[i][j]);
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
			printf("%10d",dist[i][j]);
		}
		cout<<endl;
	}
}
int main()
{
	cin>>n;
	float p;
	cin>>p;
	m=0;
	vvi g(n,vi(n));
	rep(i,0,n-1)
	{
		rep(j,0,n-1)
		g[i][j]=10000000;
	}
	rep(i,0,n-1)
	g[i][i]=0;
	rep(i,0,n-1)
	{
		rep(j,0,n-1)
		g[i][j]=10000000;
	}
	rep(i,0,n-1)
	g[i][i]=0;
	srand(time(0));
	rep(i,0,n-1)
	{
		rep(j,0,n-1)
		{
			//srand(time(0));
			float r = (rand() / (float)RAND_MAX * 1) ;
			//
			r=r*p;
			if(r>0.3)
			{
				m++;

				g[i][j]=rand()%100;
				cout<<"edge is "<<i<<" "<<j<<" :->"<<g[i][j]<<endl;
			}

	

		}
	}
	cout<<"johnson with n="<<n<<" "<<"m= "<<m<<" p="<<p<<endl;
	dijkestra(g);
	warshell(g);

}