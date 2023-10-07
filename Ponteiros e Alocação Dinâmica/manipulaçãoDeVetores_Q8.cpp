#include <iostream>
using namespace std;

void define_N(int &N)
{
    cout << "Tamanho do vetor A: ";
    cin >> N;
}
void define_M(int &M)
{
    cout << "Tamanho do vetor B: ";
    cin >> M;
}

void preencherVetores(int *vetorA, int *vetorB, int *vetorC, int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        cout << "Elemento " << i << " do vetor A: ";
        cin >> *(vetorA + i);
        *(vetorC + i) = *(vetorA + i);
    }
    cout << endl;

    for (int i = 0; i < M; i++)
    {
        cout << "Elemento " << i << " do vetor B: ";
        cin >> *(vetorB + i);
        *((vetorC + i) + N) = *(vetorB + i);
    }
}

void exibirVetores(int *vetorA, int *vetorB, int *vetorC, int N, int M)
{
    cout << "\nVetor A: ";
    for (int i = 0; i < N; i++)
    {
        cout << *(vetorA + i) << " ";
    }

    cout << "\nVetor B: ";
    for (int i = 0; i < M; i++)
    {
        cout << *(vetorB + i) << " ";
    }

    cout << "\nVetor C: ";
    for (int i = 0; i < N + M; i++)
    {
        cout << *(vetorC + i) << " ";
    }
}

int main()
{
    int *vetorA, *vetorB, *vetorC, N, M;

    define_N(N);
    vetorA = new int[N];

    define_M(M);
    vetorB = new int[M];

    vetorC = new int[N + M];

    preencherVetores(vetorA, vetorB, vetorC, N, M);
    exibirVetores(vetorA, vetorB, vetorC, N, M);

    delete[] vetorA;
    delete[] vetorB;
    delete[] vetorC;

    return 0;
}