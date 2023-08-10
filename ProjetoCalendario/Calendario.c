#include <stdio.h>
#include <string.h>

/*
Integrantes: Fábio S. Ruver; Nicolas Gabriel


A ideia do programa é, a partir do momento que o usuário digitar o mes e ano, o programa vai, primeiro verificar qual o ultimo dia do mes digitado.
Após isso, é criada uma matriz de 7 colunas por 6 linhas (6 linhas é o maximo que são usadas para gerar um calendário).

Para saber em qual dia da semana o mes se inicia, utilizamos a algoritmo de "Congruência de Zeller", a explicação pode ser
encontrada na wikipedia <https://pt.wikipedia.org/wiki/Congru%C3%AAncia_de_Zeller>.

O preenchimento da matriz é feito em 3 etapas: 1º é colocado o valor 0 na linha 1 até uma coluna antes do dia em que se inicia o mes.
2º é preenchido o resto da linha 1 até o final desta.
3º é preenchido os valores para as demais colunas.

Para mostrar os valores da matriz, substituimos os valores "0" por "   "

*/

int mostraMes(int numeroMes, int anoAux){
    //char nomeMes[] = "    Janeiro";

    switch (numeroMes)
    {   //usando printf em todos os Cases pois o runcodes não permite algo relacionado com String
        case 2:
            printf("   Fevereiro %d\n", anoAux);
        break;
        case 3:
            printf("     Marco %d\n", anoAux);
        break;
        case 4:
            printf("     Abril %d\n", anoAux);
        break;
        case 5:
            printf("      Maio %d\n", anoAux);
        break;
        case 6:
            printf("     Junho %d\n", anoAux);
        break;
        case 7:
            printf("     Julho %d\n", anoAux);
        break;
        case 8:
            printf("     Agosto %d\n", anoAux);
        break;
        case 9:
            printf("    Setembro %d\n", anoAux);
        break;
        case 10:
            printf("    Outubro %d\n", anoAux);
        break;
        case 11:
            printf("    Novembro %d\n", anoAux);
        break;
        case 12:
            printf("    Dezembro %d\n", anoAux);
        break;
        default:
            printf("    Janeiro %d\n", anoAux);
    }

    return 0;
}

int imprimirDiasMes(int mesDigitado, int anoDigitado, int ultimoDiaMes) {
    int i, m = 0, dia = 1, h, k = 0, anoAux, mesAux;
    anoAux = anoDigitado;
    mesAux = mesDigitado;

    //inicio do algoritmo de zeller
    if(mesDigitado<3)
    {
        anoDigitado=anoDigitado-1;
        mesDigitado = mesDigitado + 12;
    }
    m = anoDigitado/100;
    k = anoDigitado%100;

    //o resto desse MOD representa os dias da semana
    //dia da semana 0= sabado | 6= sexta | 5=quinta | 4=quarta | 3=terca | 2= segunda | 1=domingo
    h = (1 +(((mesDigitado+1)*26)/10) + k +(k/4) + (m/4) + (5*m) )%7;

    //fim do algoritmo de zeller

    //colocar sabado como dia 7 para facilitar para preencher a matriz
    if(h==0){
        h=7;
    }



    //imprimindo a matriz no console
    mostraMes(mesAux, anoAux);
    printf("do se te qu qu se sa\n");
        //for para mostrar a primeira linha vazio até o dia da semana que começa o mes
        int countDias = 0;//serve para contar quantos dias foram mostrados e dar \n após o sétimo dia ter sido mostrado
        printf(" ");//espaço inicial necessário
        for (i = 1; i < h; i++) {
            printf("   ");
            countDias++;
        }

        //preenche o restante da primeira linha
        for(i = h; i <=7; i++){
            printf("%d  ", dia);
            dia++;
        }
        printf("\n");
        countDias = 0;
        //preenche o restando das linhas
        for (i = 1; i < 35; i++) {
            if(countDias==7){
                printf("\n");
                countDias = 0;
            }
            if(dia>ultimoDiaMes){
                return 0;
            }
            //verifica se tem dois digitos
            if(dia>9){
                printf("%d ", dia);
            } else {
                printf(" %d ", dia);
            }


            dia++;
            countDias++;
        }

    return 0;
}


int main(){
	int mesDigitado, anoDigitado, ultimoDiaMes;

    scanf("%d %d", &mesDigitado, &anoDigitado);

    if((mesDigitado<1)||(mesDigitado>12)){
        printf("mes invalido\n");
        return(0);
    }

    if(anoDigitado < 1970){
        printf("Ano invalido\n");
        return(0);
    }

//----------------------------------------------------------------------------------------------------------------


    //verifica se o mes digitado tem 31 dias
    if(mesDigitado == 1 || mesDigitado == 3
        || mesDigitado == 5 || mesDigitado == 7
        || mesDigitado == 8 || mesDigitado == 10
        || mesDigitado == 12){

        ultimoDiaMes = 31;

    //verifica se o mes digitado tem 30 dias
    }else if(mesDigitado == 4
        || mesDigitado == 6 || mesDigitado == 9
        || mesDigitado == 11){

        ultimoDiaMes = 30;

    //mesDigitado == 2
    //verificação se é ano bissexto e passa o valor 29 como o ultimo dia no mes, caso contrário, o mes 2 tem 28 dias
    }else{
        if(anoDigitado%400 == 0
           || (anoDigitado%4 == 0 && anoDigitado%100 != 0)){
            ultimoDiaMes = 29;
        }else{
            ultimoDiaMes = 28;
        }
    }

    imprimirDiasMes(mesDigitado, anoDigitado, ultimoDiaMes);
    return 0;
}
