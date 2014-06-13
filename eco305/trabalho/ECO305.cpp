#include <iostream>
#include <cstring>
#include <algorithm>

#define MAX 100
#define INF 0x3F3F3F3F
using namespace std;

int n;
int g[MAX][MAX];

struct vertice{
	int v;
	int grau;

	bool operator<(const vertice &x) const {
		return grau < x.grau;
	}
};

int wp(){
	vertice v[n];

	for(int i = 0; i < n; i++){
		v[i].v = i;
		v[i].grau = 0;
		for(int j = 0; j < n; j++)
			if(g[i][j])
				v[i].grau++;
	}

	sort(v,v+n);
	reverse(v,v+n);

	int cor[n];

	for(int i = 0; i < n; i++)
		cor[i] = 0;	
	
	int corAtual = 0;
	for(int i = 0; i < n; i++){
		int va = v[i].v;

		if(cor[va])
			continue;
		
		cor[va] = ++corAtual;

		for(int j = 0; j < n; j++){
			if(g[va][j] == 0 && cor[j] == 0){
				int vok = 1;
				for(int k = 0; k < n; k++){
					if(g[j][k] && cor[k] == cor[va]){
						vok = 0;
						break;
					}
				}

				if(vok)
					cor[j] = cor[va];
			}
		}
	}

	return corAtual;
}

void warshall(){
	bool ga[n][n];

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)	
			ga[i][j] = g[i][j];

	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				ga[i][j] = ga[i][j] || (ga[i][k] && ga[k][j]);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			ga[i][j] ? cout << "1 " :	cout << "0 ";
		
		cout << endl;
	}	
}

void djk(int v){
	int custo[n];
	int visitado[n];

	memset(custo, INF, sizeof custo);
	memset(visitado, 0, sizeof visitado);

	custo[v] = 0;

	while(!visitado[v]){
		visitado[v] = 1;
		for(int i = 0; i < n; i++)
			if(g[v][i] && custo[i] > custo[v] + g[v][i])
				custo[i] = custo[v] + g[v][i];
		
		int c = INF;
		for(int i = 0; i < n; i++)
			if(!visitado[i] && custo[i] < c){
				v = i;
				c = custo[i];
			}	
	}

	for(int i = 0; i < n; i++)
		(custo[i] == INF) ? cout << "*" : cout << custo[i];

	cout << endl;
}

int main(){	
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> g[i][j];

	//warshall();
	djk(2);
}