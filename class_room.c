#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
//Struct que armazena as os dados de cada aluno
    char nome [40];
    double nota1;
    double nota2;
    double media;
}Aluno;
typedef struct aluno *AlunoPtr; //Usar typedef reduz o numero de letras par representar a struct

    int aprovados(AlunoPtr alunos,int tam); //Função que calcula o numero de alunos que obtiveram media igual ou superior a 6
    double soma_media(AlunoPtr alunos,int tam); // Função que calcula a media das notas
    double soma_nota1(AlunoPtr alunos,int tam); // Função que calcula a soma da nota 1
    double soma_nota2(AlunoPtr alunos,int tam); // Função que calcula a soma da nota 2

double soma_nota1(AlunoPtr alunos,int tam) { //Função recursiva que soma os valores de nota 1

    double nota1 = 0; //Inicialização de variavel

    if( tam == 0 ) //Teste condicial, quando o usuario digita tam = 0
     return 0;

    alunos->nome; // -> indica aonde vai na struct
    nota1 += alunos->nota1; // -> indica aonde vai na struct
    alunos->nota2; // -> indica aonde vai na struct

    tam--;
    return nota1 + soma_nota1 ( ++alunos , tam ); //Retorno da função recursiva
}
double soma_nota2 ( AlunoPtr alunos , int tam ) { //Função recursiva que soma os valores de nota 2

    double nota2 = 0; //Inicialização de variavel

    if(tam==0) //Teste condicial, quando o usuario digita tam = 0
     return 0;

    alunos->nome; // -> indica aonde vai na struct
    alunos->nota1; // -> indica aonde vai na struct
    nota2 += alunos->nota2; // -> indica aonde vai na struct

    tam--;
    return nota2 + soma_nota2 ( ++alunos , tam ); //Retorno da função recursiva

}
double soma_media(AlunoPtr alunos,int tam) { //Função responsavel pelo calculo da media

    if(tam==0) //Teste condicial quando o usuario digita tam = 0
     return 0;

    alunos->nome; // -> indica aonde vai na struct
    alunos->nota1; // -> indica aonde vai na struct
    alunos->nota2; // -> indica aonde vai na struct

    tam--;
    return alunos->media + soma_media ( ++alunos , tam ); //Retorno da função
}
int aprovados(AlunoPtr alunos,int tam){ //Função responsavel por indicar os alunos aprovados e reprovadas

    int i,aprovados = 0;

    for(i=0;i<tam;i++) {

       alunos->nome; // -> indica aonde vai na struct
       alunos->nota1; // -> indica aonde vai na struct
       alunos->nota2; // -> indica aonde vai na struct

      if(alunos->media >= 6 ) //teste condicional que indica o numero de alunos que obtiveram nota igual ou superior a 6.
           aprovados++;

      alunos++;
    }

    return aprovados;
}
int main() {

    int n = 0;
    int i;

    printf("Digite o numero de alunos: "); //Variavel n recebe o numero de alunos
    scanf("%d",&n);

    AlunoPtr alunos = (Aluno*)malloc(sizeof(Aluno)*n); //Alocação dinamica de alunoPtr a partir de n alunos
    AlunoPtr t1 = alunos , t2 = alunos; //t1 e t2 são variaveis do tipo AlunoPtr que estão recebendo o valor de alunos

    float n1 = 0, n2 = 0; //Inicialização de variaveis

    for(i=0;i<n;i++){ // Estrutura de repetição que percorre de 0 ate n, recolhendo os valores digitados pelo usuario
        printf("Digite o nome do aluno: ");
        scanf("%s", alunos->nome);
        printf("Digite a nota 1: ");
        scanf("%f" , &n1);
        alunos->nota1 = n1; // -> indica aonde vai na struct
        printf("Digite a nota 2: ");
        scanf("%f" , &n2);
        alunos->nota2 = n2;
        alunos->media = (n1 + n2) /2; //Calculo de média
        alunos++; //Incrementando a variavel alunos
    }
    printf("\n"); //Quebra de linha
    printf("Media nota 1 da sala: %.2f\n",soma_nota1(t1,n)/n); //Exibe na tela a media da nota 1, chamando a função
    printf("Media nota 2 da sala: %.2f\n",soma_nota2(t1,n)/n); //Exibe na tela a media da nota 2, chamando a função
    printf("Media Geral da Sala: %.2f\n",soma_media(t1,n)/n); //Exibe na tela a media geral da nota 1, chamando a função
    printf("Quantidade de aprovados: %d\n",aprovados(t1,n)); //Exibe na tela a quantidade de aprovados, chamando a função

    free(alunos); // Liberação de memoria, que foi alocada durante o programa.

return 0;
}