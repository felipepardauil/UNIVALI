#include <iostream>
using namespace std;

void define_N(int &N)
{
    cout << "Quantidade de notas: ";
    cin >> N;
}

float calcularMedia(float *notas, int N)
{
    float somaNotas = 0;

    for (int i = 0; i < N; i++)
    {
        somaNotas += *(notas + i);
    }

    return (somaNotas / N);
}

int compararNotasMedia(float *notas, float media, int N)
{
    int alunos = 0;

    for (int i = 0; i < N; i++)
    {
        if (*(notas + i) > media)
            alunos++;
    }

    return alunos;
}

void preencherNotas(float *notas, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << "Nota do " << i + 1 << "º aluno: ";
        cin >> *(notas + i);
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float *notas, media = 0;
    int N;

    define_N(N);

    notas = new float[N];

    preencherNotas(notas, N);
    media = calcularMedia(notas, N);

    cout << "\nMédia das notas = " << media;

    cout << "\nQuantidade de alunos com nota superior à média = " << compararNotasMedia(notas, media, N);

    delete[] notas;

    return 0;
}
