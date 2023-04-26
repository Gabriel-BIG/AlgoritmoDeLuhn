#include <stdio.h>
#include <cs50.h>
#include <math.h>

//Protótipo das funções
int somaCheck(long creditCard);
int multNum(int numV);
int digcard(long creditCard);
int flag(long creditCard, int qtdDigitos, bool valid);

int main(void)
{
    //var
    int qtdDigitos;
    bool valid;
    //Pedido do Cartão de credito
    long creditCard = get_long("Número do cartão: ");

    valid = somaCheck(creditCard);

    qtdDigitos = digcard(creditCard);
    flag(creditCard, qtdDigitos, valid);
}


//Faz a soma dos digitos do cartão
int somaCheck(long creditCard)
{
    int numV, check = 0;
    bool position = false;
    while (creditCard > 0)
    {
        numV = creditCard % 10;
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
    if (check == 0){
        return true;
    }
    else{
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


//Calcula a quantidade de digitos do cartão
int digcard(long creditCard)
{
    int count = 0;
    while (creditCard > 0)
    {
        creditCard = creditCard / 10;
        count++;
    }
    return count;
}

//Calcula qual a bandeira do cartão
int flag(long creditCard, int qtdDigitos, bool valid)
{
    int fnum;
   if (valid == true)
   {
    if (qtdDigitos == 16){
        fnum = creditCard / pow(10, 14);
        if (fnum > 50 && fnum < 56){
            return printf("MASTERCARD\n");
        }
        else if (fnum > 39 && fnum < 50){
            return printf("VISA\n");
        }
        else {
            return printf("INVALID\n");
        }
    }
    else if (qtdDigitos == 15){
        fnum = creditCard / pow(10, 13);
        if (fnum == 34 || fnum == 37){
            return printf("AMEX\n");
        }
        else {
            return printf("INVALID\n");
        }
    }
    else if (qtdDigitos == 13){
        fnum = creditCard / pow(10, 12);
        if (fnum == 4){
            return printf("VISA\n");
        }
        else {
            printf("INVALID\n");
        }
    }
    else {
        printf("INVALID\n");
    }
   }

   else {
    printf("INVALID\n");
   }
    return 0;
}