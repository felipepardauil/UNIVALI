/*1) Utilizando sobrecarga de operador, crie a seguinte estrutura:
struct fracao {
 int numerador, denominador;
};
Crie um menu, considerando cálculos entre duas frac?ões (com denominador igual
ou diferente):
? Soma.
? Subtração.
? Multiplicação.
? Divisão.
Utilize regras matemáticas para o cálculo.*/

#include <iostream>
using namespace std;

struct fracao
{
    int numerador, denominador;
};

istream &operator>>(istream &is, fracao &fracaoGenerica) // sobrecarga de entrada
{
    is >> fracaoGenerica.numerador;
    is >> fracaoGenerica.denominador;

    return is;
}

ostream &operator<<(ostream &os, fracao &fracaoGenerica) // sobrecarga saída
{
    os << fracaoGenerica.numerador << "/" << fracaoGenerica.denominador;

    return os;
}

fracao operator+(fracao fracao1, fracao fracao2) // sobrecarga soma
{
    fracao soma;

    if (fracao1.denominador == fracao2.denominador)
    {
        soma.numerador = fracao1.numerador + fracao2.numerador;
        soma.denominador = fracao1.denominador;
    }
    else
    {
        int denominadorComum = fracao1.denominador * fracao2.denominador;
        int multiploCruzado1 = fracao1.numerador * fracao2.denominador;
        int multiplocruzado2 = fracao2.numerador * fracao1.denominador;

        soma.numerador = multiploCruzado1 + multiplocruzado2;
        soma.denominador = denominadorComum;
    }

    return (soma);
}

fracao operator-(fracao fracao1, fracao fracao2) // sobrecarga subtração
{
    fracao resto;

    if (fracao1.denominador == fracao2.denominador)
    {
        resto.numerador = fracao1.numerador - fracao2.numerador;
        resto.denominador = fracao1.denominador;
    }
    else
    {
        int denominadorComum = fracao1.denominador * fracao2.denominador;
        int multiploCruzado1 = fracao1.numerador * fracao2.denominador;
        int multiplocruzado2 = fracao2.numerador * fracao1.denominador;

        resto.numerador = multiploCruzado1 - multiplocruzado2;
        resto.denominador = denominadorComum;
    }

    return (resto);
}

fracao operator*(fracao fracao1, fracao fracao2)
{

    fracao produto;

    produto.numerador = fracao1.numerador * fracao2.numerador;
    produto.denominador = fracao1.denominador * fracao1.denominador;

    return (produto);
}

fracao operator/(fracao fracao1, fracao fracao2)
{

    fracao quociente;

    quociente.numerador = fracao1.numerador * fracao2.denominador;
    quociente.denominador = fracao1.denominador * fracao2.numerador;

    return (quociente);
}

void lerFracao(fracao &a, fracao &b) // entrada das frações
{
    cout << "\nInforme o numerador e o denominador da fração A:\n";
    cin >> a;
    cout << "\nInforme o numerador e o denominador da fração B:\n";
    cin >> b;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    fracao a, b;
    int input;
    bool menu = true;

    do // display menu;
    {
        cout << "Informe a operação:\n";
        cout << "1-Soma\n2-Subtração\n3-Multiplicação\n4-Divisão\n5-Finalizar\n"; // lista de operações
        cin >> input;

        if (input == 1) // soma
        {
            system("cls");
            lerFracao(a, b);

            fracao soma = a + b;
            cout << "\nSoma de a+b = " << soma << endl;
            system("pause");
        }
        else if (input == 2) // subtração
        {
            system("cls");
            lerFracao(a, b);

            fracao resto = a - b;
            cout << "\nSubtração de a-b = " << resto;
            system("pause");
        }
        else if (input == 3) // Multiplicação
        {
            system("cls");
            lerFracao(a, b);

            fracao produto = a * b;
            cout << "\nMultiplicação de a*b = " << produto;
            system("pause");
        }
        else if (input == 4) // Divisão
        {
            system("cls");
            lerFracao(a, b);

            fracao quociente = a / b;
            cout << "\nDivisão de a/b = " << quociente;
            system("pause");
        }
        else if (input == 5)
        {
            system("cls");
            menu = false;
        }
        else // entrada inválida
        {
            system("cls");
            cout << "Operação inválida. Por favor, tente novamente";
        }

    } while (menu);

    return 0;
}
