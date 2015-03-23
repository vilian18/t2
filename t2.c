#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void testa_alocacao_mat(int* vetor){
   if(vetor==NULL){
      printf("Impossivel alocar a memoria\n Encerrando...\n");
      exit(1);
   }
}

void testa_alocacao_notas(float* vetor){
   if(vetor==NULL){
      printf("Impossivel alocar a memoria\n Encerrando...\n");
      exit(1);
   }
}

void testa_alocacao_nomes(char** vetor){
   if(vetor==NULL){
      printf("Impossivel alocar a memoria\n Encerrando...\n");
      exit(1);
   }
}

void aloca_notas(float* vetor, int n){
   vetor= (float*)malloc(n * sizeof(float));
   testa_alocacao_notas(vetor);
}

void aloca_vetor_mat(int* vetor, int n){
   vetor= (int*)malloc(n* sizeof(int));
   testa_alocacao_mat(vetor);
}

void aloca_vetor_nomes(char** vetor, int n, int tam_string){
   int i=0;
   vetor= (char**)malloc(n*sizeof(char*));
   for(i=0; i<n; i++){
      vetor[i]=(char*)malloc(tam_string*sizeof(char));
   }
   testa_alocacao_nomes(vetor);
}

void le_notas(int* matriculas, float* notas){
   int mat, i=0;
   float nota1= 0.0, nota2= 0.0;
   FILE *f= fopen("notas.txt", "r");
   if(f==NULL){
      printf("Erro ao abrir arquivo\n");
      exit(1);
   }
   while(feof(f)==0){
      if(fscanf(f, "%d" "%f" "%f", &mat, &nota1, &nota2)<0)
         break;
      matriculas[i]= mat;
      notas[i]= (nota1+nota2)/2;
      i++;
   }
   fclose(f);
}


int main(int argc, char** argv){
   int* vetor_matriculas;
   int tam_string= 50;
   int n=50;
   float* vetor_notas;
   char** vetor_nomes;
   aloca_vetor_nomes(vetor_nomes, n, tam_string);
   aloca_notas(vetor_notas, n);
   aloca_vetor_mat(vetor_matriculas, n);
   le_notas(vetor_matriculas, vetor_notas);
   free(vetor_matriculas);
   free(vetor_nomes);
   free(vetor_notas);
   return 0;
}
