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

void exibirVetor(int *vetor, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << *(vetor + i) << " ";
    }
}

int elementosMaiores(int *vetor, int N)
{
    int elementos = 0, maior = *vetor;

    for (int i = 0; i < N; i++)
    {
        if (*(vetor + i) > maior)
            elementos++;
    }

    return elementos;
}

int elementosMenores(int *vetor, int N)
{
    int elementos = 0, menor = *vetor;

    for (int i = 0; i < N; i++)
    {
        if (*(vetor + i) < menor)
            elementos++;
    }

    return elementos;
}

int elementosIguais(int *vetor, int N)
{
    int elementos = 0, igual = *vetor;

    for (int i = 0; i < N; i++)
    {
        if (*((vetor + i) + 1) == igual)
            elementos++;
    }

    return elementos;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int *vetor, N, qtd_maiores = 0, qtd_menores = 0, qtd_iguais = 0;

    define_N(N);
    vetor = new int[N];

    preencherVetor(vetor, N);
    exibirVetor(vetor, N);

    qtd_maiores = elementosMaiores(vetor, N);
    qtd_menores = elementosMenores(vetor, N);
    qtd_iguais = elementosIguais(vetor, N);

    cout << "\nQuantidade de elementos maiores do que o 1º elemento = " << qtd_maiores;
    cout << "\nQuantidades de elementos menores do que o 1º elemento = " << qtd_menores;
    cout << "\nQuantidade de elementos iguais ao 1º elemento = " << qtd_iguais;

    delete[] vetor;

    return 0;
}