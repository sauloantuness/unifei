#include <iostream>
#include <algorithm>

#define MAX 100

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

int main(){	
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> g[i][j];

	cout << wp() << endl;
}