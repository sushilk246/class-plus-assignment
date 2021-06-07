#include <bits/stdc++.h>
using namespace std;


int bfsWithDistance(vector<int> g[], bool mark[], int u, vector<int>&dis)
{
	int lastnode;
	queue<int> q;

	q.push(u);
	dis[u] = 0;

	
	while (!q.empty())
	{
		u = q.front();	 q.pop();
		
		if (mark[u])
			lastnode = u;

		
		for (int i = 0; i < g[u].size(); i++)
		{
			int v = g[u][i];
			
			
			if (dis[v] == -1)
			{
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
	// return last updated marked value
	return lastnode;
}


int find_origin_city(vector<int>g[], vector<int>hp, int x, int n)
{
	

	bool mark[n] = {false};
	
	for (int i = 0; i < n; i++)//marking given horspots 
		mark[hp[i]] = true;

	
	vector<int> tmp(n, -1);
	vector<int> dl(n, -1);
	vector<int> dr(n, -1);

	 int l,r;
	 
	l = bfsWithDistance(g, mark, 0, tmp);

	r = bfsWithDistance(g, mark, l, dl);

	int xyz = bfsWithDistance(g, mark, r, dr);

	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		if (dl[i] <= x && dr[i] <= x)
			ans++;
	}
	return ans;
}



int main()
{
	int n;	int h; 	int x;
	
	vector<int>g[n]; //graph
	//vector<vector<int>>g
	
	vector<int>hp; //for hotspot
	
	cout<<"enter number of cities ,number of hotsopt and distance x : ";
	cin>>n>>h>>x;
	
	cout<<"enter hotspot cities : "<<endl;
	while(h--)
	{
		int c;
		cin>>c;
		hp.push_back(c);
	}
	
	cout<<"enter n-1 edges in U & v form "<<endl;
	
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
	}
	
	int ans=find_origin_city(g,hp,x,n);
	
	cout<<endl<<"possible no of hotspot is : "<<ans<<endl;
	
	return 0;
}












