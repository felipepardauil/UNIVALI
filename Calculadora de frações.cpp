/*1) Utilizando sobrecarga de operador, crie a seguinte estrutura:
struct fracao {
 int numerador, denominador;
};
Crie um menu, considerando c�lculos entre duas frac?�es (com denominador igual
ou diferente):
? Soma.
? Subtrac?�o.
? Multiplicac?�o.
? Divis�o.
Utilize regras matem�ticas para o c�lculo.*/

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

ostream &operator<<(ostream &os, fracao &fracaoGenerica) // sobrecarga sa�da
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

fracao operator-(fracao fracao1, fracao fracao2) // sobrecarga subtra��o
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

void lerFracao(fracao &a, fracao &b) // entrada das fra��es
{
    cout << "\nInforme o numerador e o denominador da fra��o A:\n";
    cin >> a;
    cout << "\nInforme o numerador e o denominador da fra��o B:\n";
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
        cout << "Informe a opera��o:\n";
        cout << "1-Soma\n2-Subtra��o\n3-Multiplica��o\n4-Divis�o\n5-Finalizar\n"; // lista de opera��es
        cin >> input;

        if (input == 1) // soma
        {
            system("cls");
            lerFracao(a, b);

            fracao soma = a + b;
            cout << "\nSoma de a+b = " << soma << endl;
            system("pause");
        }
        else if (input == 2) // subtra��o
        {
            system("cls");
            lerFracao(a, b);

            fracao resto = a - b;
            cout << "\nSubtra��o de a-b = " << resto;
            system("pause");
        }
        else if (input == 3) // Multiplica��o
        {
            system("cls");
            lerFracao(a, b);

            fracao produto = a * b;
            cout << "\nMultiplica��o de a*b = " << produto;
            system("pause");
        }
        else if (input == 4) // Divis�o
        {
            system("cls");
            lerFracao(a, b);

            fracao quociente = a / b;
            cout << "\nDivis�o de a/b = " << quociente;
            system("pause");
        }
        else if (input == 5)
        {
            system("cls");
            menu = false;
        }
        else // entrada inv�lida
        {
            system("cls");
            cout << "Opera��o in�lida. Por favor, tente novamente";
        }

    } while (menu);

    return 0;
}
