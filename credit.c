#include <stdio.h>
#include <math.h>
#include <stdbool.h>

//Protótipo das funções

int somaCheck(double creditCard);
int multNum(int numV);
int flag(double creditCard, bool valid);

int main()
{
    //var
    bool valid;
    double creditCard; 
    //Pedido do Cartão de credito
    printf("Card Number:");
    scanf("%lf", &creditCard);

    valid = somaCheck(creditCard);
    flag(creditCard, valid);

    printf("\nPressione qualquer tecla para continuar");
    fflush(stdin);
    getchar();


}


//Faz a soma dos digitos do cartão e verifica se é valido.
int somaCheck(double creditCard)
{
    int numV; 
    int check = 0;
    bool position = false;
    for (int i = 0; i < 16; i++)
    {
        numV = fmodl(creditCard, 10);
        if (position == true)
        {
            check = check + multNum(numV);
        }
        else
        {
            check = check + numV;
        }
        creditCard = creditCard / 10;
        position = !position;
    }
    check = check % 10;
    if (check == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


//Faz a soma dos digitos do produto da multiplicação
int multNum(int numV)
{
    int mult = 0;
    numV = numV * 2;
    if (numV > 9)
    {
        mult = numV % 10;
        mult = mult + (numV / 10);
        return mult;
    }
    else
    {
        return numV;
    }
}


//Calcula qual a bandeira do cartão
int flag(double creditCard, bool valid)
{
    int fnum;
   if (valid == true)
   {
    fnum = creditCard / pow(10, 12);
    if (fnum == 4)
    {
        return printf("VISA\n");
    }
    else if (fnum < 5599)
    {
        fnum = creditCard / pow(10, 13);
        if (fnum == 34 || fnum == 37)
        {
            return printf("AMEX\n");
        }
        else if (fnum > 509 && fnum < 560)
        {
            return printf("MASTERCARD\n");
        }
        else if (fnum > 399 && fnum < 500)
        {
            return printf("VISA\n");
        }
        else
        {
            return printf("INVALID\n");
        }
    } 
    else if (fnum > 5599)
    {
        return printf("INVALID\n");
    }
    else
    {
        return printf("INVALID\n");
    }
   }

   else
   {
    printf("INVALID\n");
   }
    return 0;
}