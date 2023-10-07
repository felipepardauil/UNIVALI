#include <iostream>
using namespace std;

void define_N(int &N)
{
    cout << "Tamanho do vetor: ";
    cin >> N;
}

void preencherVetores(int *vetA, int *vetB, int *vetC, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << "Elemento " << i << " do vetor A: ";
        cin >> *(vetA + i);
    }
    cout << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "Elemento " << i << " do vetor B: ";
        cin >> *(vetB + i);
    }

    for (int i = 0; i < N; i++)
    {
        *(vetC + i) = *(vetA + i) - *(vetB + i);
    }
}

void exibirVetores(int *vetA, int *vetB, int *vetC, int N)
{
    cout << "\nVetor A: ";
    for (int i = 0; i < N; i++)
    {
        cout << *(vetA + i) << " ";
    }

    cout << "\nVetor B: ";
    for (int i = 0; i < N; i++)
    {
        cout << *(vetB + i) << " ";
    }

    cout << "\nVetor C:";
    for (int i = 0; i < N; i++)
    {
        cout << *(vetC + i) << " ";
    }
}

int main()
{
    int *vetA, *vetB, *vetC, N;

    define_N(N);
    vetA = new int[N];
    vetB = new int[N];
    vetC = new int[N];

    preencherVetores(vetA, vetB, vetC, N);
    exibirVetores(vetA, vetB, vetC, N);

    delete[] vetA;
    delete[] vetB;
    delete[] vetC;

    return 0;
}