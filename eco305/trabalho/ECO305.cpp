// 27586 SAULO ANTUNES SILVA
// 23927 ALEXANDRE SILVEIRA MOREIRA TOLEDO

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 100
#define INF 0x3F3F3F3F

int grafo[MAX][MAX]; // representação por Matriz de Adjacência 

struct Vertice{
    int vertice;
    int grau;

    bool operator<(const Vertice &v) const {
        return grau < v.grau;
    }
};

void WelchPowell(int n){
    Vertice v[n];

    // Cria uma lista de vertices
    for(int i = 0; i < n; i++){
        v[i].vertice = i;
        v[i].grau = 0;
    }
    
    // Atualiza o grau de cada vertice
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            if(grafo[i][j])
                v[i].grau++;
    }

    // Ordena em ordem decrescente
    sort(v,v+n);
    reverse(v,v+n);

    // Vetor de cor para cada vertice
    int cor[n];
    int corAtual = 0;

    // Cor = 0, significa não colorido.
    for(int i = 0; i < n; i++)
        cor[i] = 0; 
    
    for(int i = 0; i < n; i++){
        // Pega um vertice da lista de vertices
        int verticeAtual = v[i].vertice;

        // Se o vertice já estiver colorido, saí.
        if(cor[verticeAtual])
            continue;
        
        // Caso contrário, verticeAtual recebe uma nova cor.
        cor[verticeAtual] = ++corAtual;

        // Verifica os vertices NAO vizinhos para colorir da mesma cor
        for(int j = 0; j < n; j++){
            // Se o vertice não for vizinho E ainda não for colorido
            if(grafo[verticeAtual][j] == 0 && cor[j] == 0){
                // Colore o vertice com a cor do verticeAtual
                cor[j] = cor[verticeAtual];

                // Verifica se esse vertice tem algum vizinho com a cor do verticeAtual
                for(int k = 0; k < n; k++){
                    // Se existir, 'descolore' o vertice   
                    // OBS: O vertice eh colorido primeiro e depois verificado, para evitar o uso de flags
                    if(grafo[j][k] && cor[k] == cor[verticeAtual]){
                        cor[j] = 0;
                        break;
                    }
                }                
            }
        }
    }

    // no final corAtual sera o número cromatico
    cout << corAtual << endl;
}
void Warshall(int n){
    bool ga[n][n];

    // Copia o grafo para o GrafoAuxiliar ga[][]
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)  
            ga[i][j] = grafo[i][j];

    // k é como se fosse um pivo entre i e j
    // O algoritmo faz uma verificação se k pode ser uma ponte
    // de i até j:  i --> k --> j
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                ga[i][j] = ga[i][j] || (ga[i][k] && ga[k][j]);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            ga[i][j] ? cout << "1 " :   cout << "0 ";
        
        cout << endl;
    }   
}


void Dijkstra(int n, int v){
    int custo[n];
    int visitado[n];

    memset(custo, INF, sizeof custo);
    memset(visitado, 0, sizeof visitado);

    // Zera vertice de origem
    custo[v] = 0;


    while(!visitado[v]){
        // Marca vertice como visitado
        visitado[v] = 1;

        // Verifica vizinhos
        for(int i = 0; i < n; i++)
            // Se for vizinho E o custo atual do vizinho for maior do que o vertice atual mais o custo de se chegar a esse vizinho
            if(grafo[v][i] && custo[i] > custo[v] + grafo[v][i])
                // atualiza custo do vizinho
                custo[i] = custo[v] + grafo[v][i];
        
        int c = INF;
        // Procura o vertice nao visitado que tem o menor custo
        for(int i = 0; i < n; i++)
            if(!visitado[i] && custo[i] < c){
                v = i;
                c = custo[i];
            }
        // Caso não tiver mais vertices que não foram visitados
        // v não ira mudar e o algoritmo sairá do while na proxima iteração

    }

    for(int i = 0; i < n; i++)
        (custo[i] == INF) ? cout << "*" : cout << custo[i];

    cout << endl;
}
void BellmanFord(int n, int v){
    // Criação e inicialização do vetor de custo
    int custo[n];

    memset(custo, INF, sizeof custo);
    custo[v] = 0;

    // Criação do vetor de arestas
    vector< pair<int,int> > arestas;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(grafo[i][j])
                arestas.push_back(make_pair(i,j));

    // Relaxamento semelhante ao algoritmo de dijkstra
    // A diferença é que no Dijkstra, você tem um vértice, e então você relaxa os vizinhos daquele vértice
    // Aqui você relaxa através das arestas        
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < arestas.size(); j++){
            int u = arestas[j].first;
            int v = arestas[j].second;

            if(custo[v] > custo[u] + grafo[u][v])
                custo[v] = custo[u] + grafo[u][v];
        }
    }

    // Verifica se o grafo possui ciclo negativo
    // Para todas as aresta do grafo
    for(int i = 0; i < arestas.size(); i++){
        int u = arestas[i].first;
        int v = arestas[i].second;

        // Verifica-se se o vertice de origem(u) é alcançável(custo[u] !=  INF)
        // E se o custo para se chegar no destino por essa aresta for menor
        // do que o custo atual do vertice destino, então existe ciclo.
        if(custo[u] != INF && custo[v] > custo[u] + grafo[u][v]){
            cout << "Possui ciclo negativo." << endl;
            return;  
        }
    }
    
    // Se chegou aqui é porque não possui ciclo negativo
    for(int i = 0; i < n; i++)
        custo[i] == INF ? cout << "*" : cout << custo[i];
    cout << endl;
}


struct Aresta{
    int origem;
    int destino;
    int peso;

    Aresta(){}
    Aresta(int o, int d, int p)
        : origem(o), destino(d), peso(p) {}

    bool operator <(const Aresta &a) const{
        return peso < a.peso;
    }
};

void Kruskal(int n){
    // Criação do vetor de Arestas e inicialização
    vector<Aresta> arestas;

    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
            if(grafo[i][j])
                arestas.push_back(Aresta(i,j,grafo[i][j]));


    // Ordena o vetor de arestas de forma crescente
    sort(arestas.begin(), arestas.end());

    // Duas iteração para gerar as arvores maxima e minima
    int it = 2;
    while(it--){
        // Soma do caminho
        int total = 0;
        // Variáveis auxiliares
        int p[n],u,v;

        // O vetor p[] é usado para verificação de conjuntos
        for(int i = 0; i < n; i++)
            p[i] = i;

        // Iteração sobre as arestas
        // k é qtd de aresta já inseridas
        for(int i = 0, k = 0; i < n && k < n -1 ; i++){
            Aresta a = arestas[i];

            // Verifica se os dois vertices da aresta estao no mesmo conjunto
            // ou seja, se ao adicionar essa aresta ira formar ciclo
            // Referencia: [http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=disjointDataStructure]
            for(u = a.origem; u != p[u]; u = p[u]);
            for(v = a.destino; v != p[v]; v = p[v]);

            // Se estao no mesmo conjunto, a aresta não pode ser adicionada
            if(u == v)
                continue;

            // Caso contrário, 
            p[u] = v;
            k++;
            total += a.peso;
        }

        cout << total << " ";
        // Inverte a ordem para achar a arvore máxima
        reverse(arestas.begin(), arestas.end());
    }
    cout << endl;
}

bool ehConexo(int n){
    int visitado[n], pilha[n], topo = -1;
    memset(visitado, 0, sizeof visitado);

    pilha[++topo] = 0;

    while(topo != -1){
        int v = pilha[topo--];
        visitado[v] = 1;

        for(int i = 0; i < n; i++)
            if(grafo[v][i] && !visitado[i])
                pilha[++topo] = i;
    }

    for(int i = 0; i < n; i++)
        if(!visitado[i])
            return false;
    
    return true;
}

// Funções desenvolvidas no trabalho
bool Regular(int ordem){
    int grau = 0, grau_aux;

    for (int i = 0; i < ordem; i++)
        grau += (grafo[0][i] != 0 ? 1 : 0);
    
    for (int i=1; i < ordem; i++) {
        grau_aux = 0;
        for (int j = 0; j < ordem; j++)
            grau_aux += (grafo[i][j] != 0 ? 1 : 0);
        
        if (grau != grau_aux) 
            return false;
    }
    return true;
}    

int main(){
    int ordem, operacao, origem;
    /*
    Declaração de outras variáveis necessárias ao trabalho
    int a, b, p;
    int i, j, k;

    int Soma;
    */
    cin >> ordem;
    for (int i=0; i < ordem; i++) 
        for (int j=0; j < ordem; j++) 
            cin >> grafo[i][j];

    while (cin >> operacao, operacao) {
        switch (operacao){
            case 1: // Caso exemplo - Verificar se Grafo é regular
                if (Regular(ordem))
                    printf("Grafo regular\n");
                else
                    printf("Grafo nao regular\n");
                break;
            case 2:
                WelchPowell(ordem);
                break;
            case 3:
                Warshall(ordem);
                break;
            case 4:
                cin >> origem;
                Dijkstra(ordem, origem);
                break;
            case 5:
                cin >> origem;
                BellmanFord(ordem, origem);
                break;                
            case 6:
                if(ehConexo(ordem))
                    Kruskal(ordem);
                else 
                    cout << "NAO CONEXO" << endl;
                break;
/*                
            case 7:
                cout << FordFulkerson(ordem,0,2);
                break;
            case 8:
                KernighanLin();
                break;
*/
        }
    }
}