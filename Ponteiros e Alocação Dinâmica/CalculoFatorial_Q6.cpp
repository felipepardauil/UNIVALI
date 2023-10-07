#include <iostream>
using namespace std;

void define_N(int &N)
{
    cout << "Tamanho do vetor: ";
    cin >> N;
}

int fatMaior(int maior)
{
    int fatorial = maior;

    for (int i = 1; i < maior; i++)
    {
        fatorial *= (maior - i);
    }

    return fatorial;
}

int fatMenor(int menor)
{
    int fatorial = menor;

    for (int i = 1; i < menor; i++)
    {
        fatorial *= (menor - i);
    }

    return fatorial;
}

int menorElemento(int *vetor, int N)
{
    int menor = *vetor;
    for (int i = 0; i < N; i++)
    {
        if (*(vetor + i) < menor)
            menor = *(vetor + i);
    }

    return menor;
}

int maiorElemento(int *vetor, int N)
{
    int maior = *vetor;
    for (int i = 0; i < N; i++)
    {
        if (*(vetor + i) > maior)
            maior = *(vetor + i);
    }

    return maior;
}

void preencherVetor(int *vetor, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << "Elemento " << i << " do vetor: ";
        cin >> *(vetor + i);
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int *vetor, N;

    define_N(N);
    vetor = new int[N];

    preencherVetor(vetor, N);
    int maior = maiorElemento(vetor, N);
    int menor = menorElemento(vetor, N);

    cout << "\nMaior elemento = " << maior << "\nFatorial = " << fatMaior(maior);
    cout << "\nMenor elemento = " << menor << "\nFatorial = " << fatMenor(menor);

    delete[] vetor;

    return 0;
}