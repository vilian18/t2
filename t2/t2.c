#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_STRING 50
#define TAM_FILE 30

/*void aloca_vetor_nomes(char** vetor){
   int i=0;
   vetor= (char**)malloc(TAM_FILE*sizeof(char*));
   for(i=0; i<; i++){
      vetor[i]=(char*)malloc(TAM_STRING*sizeof(char));
   }
   testa_alocacao_nomes(vetor);
}*/

void le_notas(int* matriculas, float* notas){
   int i=0, mat;
   float nota1=0.0, nota2=0.0;
   FILE *f= fopen("notas.txt", "r");
   if(f==NULL){
      printf("Erro ao abrir arquivo!\n");
      exit(1);
   }
   while(feof(f)==0){
      if (fscanf(f,"%d %f %f\n", &mat, &nota1, &nota2)<0)
         break;
      matriculas[i]= mat;
      notas[i]= (nota1+nota2)/2;
      i++;
   }
   fclose(f);
}

void le_alunos(int* matriculas, char** nomes, int* n){
   int mat, i, linha=0;
   char nome[TAM_STRING];
   char c;
   FILE *f;
   f = fopen("alunos.txt", "r");
   if(f==NULL){
      printf("Erro ao abrir arquivo.\n");
      exit(1);
      }
   while(feof(f)==0){
      if(fscanf(f, "%d", &mat)<0)
         break;
      i=0;
      c=fgetc(f);
      while(c != '\n'){
         nome[i]=c;
         i++;
         c=fgetc(f);
      }
      nome[i]='\0';
      matriculas[linha]=mat;
      strcpy(nomes[linha], nome);
      linha++;
   }
   *n=linha;
   fclose(f);
}

int main(int argc, char** argv){
   int n=0, cont;
   int* vetor_matric_notas;
   int* vetor_matric_nomes;
   float* vetor_notas;
   char** vetor_nomes;
   vetor_matric_notas= (int*)malloc(TAM_FILE*sizeof(float));
   vetor_matric_nomes= (int*)malloc(TAM_FILE*sizeof(int));
   vetor_notas= (float*)malloc((TAM_FILE*sizeof(float)));
   vetor_nomes= (char**)malloc(TAM_FILE*sizeof(char*));
   for(cont=0; cont<TAM_FILE; cont++){
      vetor_nomes[cont]= (char*)malloc(TAM_STRING*sizeof(char));
   }
   le_alunos(vetor_matric_nomes, vetor_nomes, &n);
   le_notas(vetor_matric_notas, vetor_notas);

   return 0;
}
