#include <iostream>
using namespace std;

void define_N(int &N)
{
    cout << "Tamanho do vetor: ";
    cin >> N;
}

void preencherVetor(int *vetor, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << "Elemento " << i << " do vetor: ";
        cin >> *(vetor + i);
    }
}

void inverterVetor(int *vetor, int N)
{
    for (int i = N - 1; i >= 0; i--)
    {
        cout<<*(vetor+i)<<" ";
    }
}

void exibirVetor(int *vetor, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << *(vetor + i) << " ";
    }
    cout << endl;
}

int main()
{
    int *vetor, N;

    define_N(N);
    vetor = new int[N];

    preencherVetor(vetor, N);
    exibirVetor(vetor, N); // exibe vetor original

    inverterVetor(vetor, N); // inverte o vetor e exibe o rsultado

    delete[] vetor;
    return 0;
}
