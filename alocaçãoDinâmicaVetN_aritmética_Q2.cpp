#include <iostream>
using namespace std;

void define_N(int &N)
{
    cout << "Tamanho do vetor: ";
    cin >> N;
}

void exibirVetor(int *vetor, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << *(vetor + i) << " ";
    }
}

void preencherVetor(int *vetor, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << "Elemento " << i << " do vetor: ";
        cin >> *(vetor + i);
    }
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

int menorElemento(int *vetor, int N)
{
    int menor = *vetor;

    for (int i = 0; i < N; i++)
    {
        if (*(vetor + i) < menor)
        {
            menor = *(vetor + i);
        }
    }

    return menor;
}

float calcularMedia(int *vetor, int N)
{
    float soma = 0;

    for (int i = 0; i < N; i++)
    {
        soma += *(vetor + i);
    }

    return (soma / N);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int maior = 0, menor = 0;
    float media = 0;
    int N;      // tamanho do vetor
    int *vetor; // ponteiro do vetor

    define_N(N);

    vetor = new int[N]; // criando uma alocação dinâmica de memória com N espaços alocados

    preencherVetor(vetor, N);
    exibirVetor(vetor, N);

    maior=maiorElemento(vetor, N); menor=menorElemento(vetor, N); media=calcularMedia(vetor, N);

    cout<<"\nMaior elemento do vetor = "<<maior;
    cout<<"\nMenor elemento do vetor = "<<menor;
    cout<<"\nMédia dos elementos do vetor = "<<media;

    delete []vetor;
    
    return 0;
}