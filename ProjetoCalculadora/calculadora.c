#include<stdio.h>
#define pi 3.14159265359
#define e  2.71828182845
// alunos: Fábio S. Ruver; Nicolas Gabriel
// O objetivo desse programa é rodar uma calculadora cientifica, com algumas operações restritas. O as funções erão receber 1 ou 2 valores de entrada,
// dependendo da operação

double soma(double x, double y){
    return x+y;
}

double subtracao(double x, double y){
    return x-y;
}

double divisao(double x, double y){
    return x/y;
}

double multiplicacao(double x, double y){
    return x*y;
}

double exponencial(double x, double y){
    double retorno = 1.0;
    for(int i=0; i<y; i++)
    {
        retorno *= x;

        if(y == 0) // Qualquer numero elevado a 0 é igual 1
        {
            retorno = 1.0;
        }
    }
    return retorno;
}

double logaritmoNatural(double x){
    double somatorio = 0.0, n;

    for(int i= 0; i<20; i++){
        n = 2*i + 1;
        somatorio += ((1)/(n))*exponencial((x-1)/(x+1), n);
    }
    return somatorio*2;
}

double fatorial(double x){
    double retorno = 1.0;
    for(int i =1; i<=x; i++){
        retorno *= i;
    }
    return retorno;
}

double seno(double x){
    double n, retorno = 0.0, dividendo, divisor;
    while (x > 2*pi) { //para deixar o valor de X dentro do intervalo de Pi
        x = x - 2*pi;
    }
    for(int i =0;i <20; i++){
        n = 2*i + 1;
        dividendo = exponencial(-1.0, i);
        divisor = fatorial(n);
        retorno += (dividendo/divisor) * exponencial(x, n);
    }
    return retorno;
}

double cosseno(double x){
    double n, retorno = 0.0, dividendo, divisor;
    while (x > 2*pi) {//para deixar o valor de X dentro do intervalo de Pi
        x = x - 2*pi;
    }
    for(int i =0;i <20; i++){
        n = 2*i;
        dividendo = exponencial(-1.0, i);
        divisor = fatorial(n);
        retorno += (dividendo/divisor) * exponencial(x, n);
    }
    return retorno;
}

double tangente(double x){
    return seno(x)/cosseno(x);
}

double exponencialNatural(double x){
    double retorno = 0.0, divisor, dividendo;
    for(int i =0;i <20; i++){
        dividendo = exponencial(x,i);
        divisor =  fatorial(i);
        retorno += dividendo/divisor;
    }
    return retorno;
}

double logaritmo(double x, double y){
    return logaritmoNatural(x)/logaritmoNatural(y);
}

double raizYesima(double x, double y){
    return exponencialNatural((1/y)* logaritmoNatural(x));
}

double modulo(double x){
    if(x < 0){
        return x*(-1);
    } else {
        return x;
    }
}

void chamaFuncoes (char operacao) {
    double x = 0.0, y = 0.0;

    switch(operacao)
    {
    case '+':
        scanf("%lf %lf", &x, &y);
        printf("%.2lf", soma(x, y));
        break;

    case 'n':
        scanf("%lf", &x);
        printf("%.2lf", exponencialNatural(x));
        break;

    case '-':
        scanf("%lf %lf", &x, &y);
        printf("%.2lf", subtracao(x, y));
        break;

    case '*':
        scanf("%lf %lf", &x, &y);
        printf("%.2lf", multiplicacao(x, y));
        break;

    case '/':
        scanf("%lf %lf", &x, &y);
        printf("%.2lf", divisao(x, y));
        break;

    case 'f':
        scanf("%lf", &x);
        if (x >= 0) {
            printf("%.2lf", fatorial(x));
        } else{
            break;
        }
        break;

    case 'e':
        scanf("%lf %lf", &x, &y);
        printf("%.2lf", exponencial(x, y));
        break;

    case 's':
        scanf("%lf", &x);
        printf("%.2lf", seno(x));
        break;

    case 'c':
        scanf("%lf", &x);
        printf("%.2lf", cosseno(x));
        break;

    case 'm':
        scanf("%lf", &x);
        printf("%.2lf", modulo(x));
        break;

    case 'l':
        scanf("%lf %lf", &x, &y);
        if (x >= 0 && y >= 0) {
            printf("%.2lf", logaritmo(x, y));
        }
        else{
            break;
        }
        break;

    case 'r':
        scanf("%lf %lf", &x, &y);
        if (x > 0 && y > 0) {
            printf("%.2lf", raizYesima(x, y));
        } else{
            break;
        }
        break;

    case 't':
        scanf("%lf", &x);
        printf("%.2lf", tangente(x));
        break;

    case 'g':
        scanf("%lf", &x);
        if (x > 0) {
            printf("%.2lf", logaritmoNatural(x));
        } else{
            break;
        }
        break;
    }
}

int main(){
    char operacao;

    scanf("%c", &operacao);
    chamaFuncoes(operacao);
}
