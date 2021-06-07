/*
 * nomPrograma: CALCULO.cpp
 * descripción: Se realizara el calculo del promedio en base a los archivos de registro
 *
 *
 *
 * autores: Chávez Farro, Luis André
 *          Espinola Ravello, Annie Katerine
 *          Reyes De la Cruz, Andrés Eduardo
 *          Silva Barra, Ernesto Franco
 *          Tocto Mallqui, Alexis
 * fecha: 26/08/2020
 */

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct FECHA{
   int dd;
   int mm;
   int aaaa;
};

 struct ALUMNO{
   char codA[10];
   char nomA[40];
   char escA[4];
   float peso;
   FECHA fnac[40];
};

 struct CURSOS{
   char codC[10];
   char nomC[40];
   int creditC;
   char sist_calif[2];
};

struct Docente{
   int codDoc;
   char nomDoc[40];
   char escuela[10];
   float peso;
   CURSOS curso[40];
};

struct PRACTICA{
   char codAlu[7];
   char codCurso[10];
   float praCt[10];
};

struct EXPARCIAL{
   char codAlu[10];
   char codCur[10];
   float expar;
};

struct EXFINAL{
   char codAlu[10];
   char codCur[10];
   float exfin;
};


struct CALCULO{
   char codAlu[10];
   char codCur[10];
   float NOTAFINAL;
};

void MostrarRegAlumno(FILE *F, ALUMNO RegistroA);
void MostrarRegCURSO(FILE *G, CURSOS RegistroC);
void MostrarRegDOCENTE(FILE *H, Docente RegistroD);
void MostrarRegPRACTICAS(FILE *I, PRACTICA RegistroP);
void MostrarRegPRACIAL(FILE *J, EXPARCIAL RegistroPAR);
void MostrarRegFINAL(FILE *K, EXFINAL RegistroF);

void MostrarM(FILE *I, FILE *J, FILE *K,FILE *N, ALUMNO RegistroA, Docente RegistroD, CURSOS RegistroC, CALCULO RegistroCAL);
void Calculo(FILE *I, FILE *J, FILE *K,FILE *L, PRACTICA RegistroP, EXPARCIAL RegistroPAR, EXFINAL RegistroF, CALCULO RegistroCAL);
void MostrarRegCALCULO(FILE *L, FILE *F, CALCULO RegistroCAL, ALUMNO RegistroA);
void MostrarMC(FILE *I, FILE *J, FILE *K,FILE *L, ALUMNO RegistroA, Docente RegistroD, CURSOS RegistroC,CALCULO RegistroCAL);
int  MenuCURSO();

int main(){
   FILE *F;
   FILE *G;
   FILE *H;
   FILE *I;
   FILE *J;
   FILE *K;
   FILE *L;
   FILE *M;
   FILE *N;
   ALUMNO RegistroA;
   CURSOS RegistroC;
   Docente RegistroD;
   PRACTICA RegistroP;
   EXPARCIAL RegistroPAR;
   EXFINAL RegistroF;
   CALCULO RegistroCAL;
   MenuCURSO();
   int op;
   do{
      do{
      cout<<"\nIngrese una opcion: [  ]"<<"\b\b\b";
      cin>>op;
   }while(op<0||op>11);

      switch(op){
         case 1 : MostrarRegAlumno(F,RegistroA);
                  break;
         case 2 : MostrarRegCURSO(G,RegistroC);
                  break;
         case 3 : MostrarRegDOCENTE(H,RegistroD);
                  break;
         case 4 : MostrarRegPRACTICAS(I,RegistroP);
                  break;
         case 5 : MostrarRegPRACIAL(J,RegistroPAR);
                  break;
         case 6:  MostrarRegFINAL(K,RegistroF);
                  break;
         case 7:  Calculo(I,J,K,L,RegistroP,RegistroPAR,RegistroF,RegistroCAL);
                  break;
         case 8:  MostrarRegCALCULO(M,F,RegistroCAL,RegistroA);
                  break;
         case 9:  MostrarM(F,H,G,N,RegistroA,RegistroD,RegistroC,RegistroCAL);
                  break;
         case 10: MostrarMC(I,J,K,L,RegistroA,RegistroD,RegistroC,RegistroCAL);
                  break;
      }
   system("cls");
   MenuCURSO();
   }while(op != 0);
   printf("\n\n");
   system("pause");
   return(0);
}

int  MenuCURSO()
{
   cout << "\n\n\r A R C H I V O    D E    M A T R I C U L A - P R O M E D I O S";
   cout << "\n\t\t  * Proyecto Final  Algoritmica I * ";
   cout << "\n\n\n\r 0.- TERMINAR";
   cout << "\n\r [1]. MOSTRAR Registros ALUMNOS";
   cout << "\n\r [2]. MOSTRAR Registros CURSOS";
   cout << "\n\r [3]. MOSTRAR Registros DOCENTES";
   cout << "\n\r [4]. MOSTRAR Registros PRACTICAS";
   cout << "\n\r [5]. MOSTRAR Registros PARCIAL";
   cout << "\n\r [6]. MOSTRAR Registros FINAL";
   cout << "\n\r [7]. CALCULAR PROMEDIOS";
   cout << "\n\r [8]. MOSTRAR PROMEDIO DE ALUMNOS";
   cout << "\n\r [9]  MOSTRAR DATOS POR ALUMNO";
   cout << "\n\r [10] MOSTRAR PROMEDIO POR ALUMNOS";
}

void MostrarRegAlumno(FILE *F, ALUMNO RegistroA){
   int i=0;
   system("cls");

   cout << "\n\rLISTADO DE REGISTROS DE ALUMNOS";
   F = fopen("Alumnos.dat","rb");
   if(F == NULL){
      cout << "\n\n\n\rNo existe el archivo !!!\n";
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      getch();
      return;
   }

   cout << "\n\r==============================================================================================";
   cout << "\n\ NRO.    CODIGO         N O M B R E                  ESCUELA      PESO        FECHA DE NAC.";
   cout << "\n\r----------------------------------------------------------------------------------------------";
   fread(&RegistroA, sizeof(RegistroA), 1, F);
   while(!feof(F)){
      printf("\n\r%3d\t  %-4s\t\t%-30s\t%-4s\t%6.1f",i+1, RegistroA.codA, RegistroA.nomA, RegistroA.escA, RegistroA.peso);
      printf("\t\t%d / %d / %d",RegistroA.fnac->dd,RegistroA.fnac->mm,RegistroA.fnac->aaaa);
      fread(&RegistroA,sizeof(RegistroA),1,F);
      i++;
   }
   fclose(F);
   cout << "\n\r----------------------------------------------------------------------------------------------";
   cout << "\n\rFin del listado !!!\n";
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
   getch();
   return;
}

void MostrarRegCURSO(FILE *G, CURSOS RegistroC){
   system("cls");
   int i=0;
   cout << "\n\rLISTADO DE REGISTROS DE CURSOS";
   G = fopen("Cursos.dat","rb");
   if(G == NULL){
      cout << "\n\n\n\rNo existe el archivo !!!\n";
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      getch();
      return;
   }

   cout << "\n\r==============================================================================";
   cout << "\n\rNRO.     CODIGO         N O M B R E                     CREDITO    SIST.CALIF.";
   cout << "\n\r------------------------------------------------------------------------------";
   fread(&RegistroC, sizeof(RegistroC), 1, G);
   while(!feof(G)){
      printf("\n\r%3d\t%6s\t\t%-30s\t%4d\t%6s",i+1,RegistroC.codC,RegistroC.nomC,RegistroC.creditC,RegistroC.sist_calif);
      fread(&RegistroC,sizeof(RegistroC),1,G);
      i++;
   }
   fclose(G);
   cout << "\n\r------------------------------------------------------------------------------";   cout << "\n\rFin del listado !!!\n";
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
   getch();
   return;
}


void MostrarRegDOCENTE(FILE *H, Docente RegistroD){
   system("cls");
   int i=0;
   cout << "\n\rLISTADO DE REGISTROS DE DOCENTES";
   H = fopen("Docentes.dat","rb");
   if(H == NULL){
      cout << "\n\n\n\rNo existe el archivo !!!\n";
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      getch();
      return;
   }

   cout << "\n\r=======================================================================";
   cout << "\n\rNRO.      CODIGO        N O M B R E                   ESCUELA     PESO";
   cout << "\n\r-----------------------------------------------------------------------";
   fread(&RegistroD, sizeof(RegistroD), 1, H);
   while(!feof(H)){
         printf("\n\r%3d\t%6i\t\t%-30s\t%-4s\t%6.1f",i+1, RegistroD.codDoc, RegistroD.nomDoc, RegistroD.escuela, RegistroD.peso);
         fread(&RegistroD,sizeof(RegistroD),1,H);
         i++;
   }
   fclose(H);
   cout << "\n\r-----------------------------------------------------------------------";
   cout << "\n\rFin del listado !!!\n";
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
   getch();
   return;
}

void MostrarRegPRACTICAS(FILE *I, PRACTICA RegistroP){
   system("cls");
   int i=0;
   cout << "\n\rLISTADO DE REGISTROS DE PRACTICAS";
   I = fopen("Practicas.dat","rb");
   if(I == NULL){
      cout << "\n\n\n\rNo existe el archivo !!!\n";
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      getch();
      return;
   }

   cout << "\n\r======================================================================================================";
   cout << "\n\rNRO.     ALU_COD       CURSO_COD                \t\t   PRACTICAS";
   cout << "\n\r-------------------------------------------------------------------------------------------------------";
   fread(&RegistroP, sizeof(RegistroP), 1, I);
   while(!feof(I)){
         printf("\n%3d\t%5s\t%12s\t\t   ",i+1,RegistroP.codAlu,RegistroP.codCurso);
            printf("[");
            for(int j=0;j<10;j++){
               printf("%-4.1f  ",RegistroP.praCt[j]);
            }
            printf("\b\b]");
         fread(&RegistroP,sizeof(RegistroP),1,I);
         i++;
   }
   fclose(I);
   cout << "\n\r-------------------------------------------------------------------------------------------------------";
   cout << "\n\rFin del listado !!!\n";
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
   getch();
   return;
}

void MostrarRegPRACIAL(FILE *J, EXPARCIAL RegistroPAR){
   system("cls");
   int i=0;
   cout << "\n\rLISTADO DE REGISTROS DE EXAMENES PARCIALES";
   J = fopen("Parciales.dat","rb");
   if(J == NULL){
      cout << "\n\n\n\rNo existe el archivo !!!\n";
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      getch();
      return;
   }
   cout << "\n\r========================================================";
   cout << "\n\rNRO.      CODIGO       COD CURSO                    NOTA";
   cout << "\n\r--------------------------------------------------------\n";
   fread(&RegistroPAR, sizeof(RegistroPAR), 1, J);
   while(!feof(J)){
         printf("\%3d\t%5s\t%12s%28.1f\n",i+1,RegistroPAR.codAlu,RegistroPAR.codCur,RegistroPAR.expar);
         fread(&RegistroPAR,sizeof(RegistroPAR),1,J);
         i++;
   }
   fclose(J);
   cout << "\n\r--------------------------------------------------------\n";
   cout << "\n\rFin del listado !!!\n";
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
   getch();
   return;
}

void MostrarRegFINAL(FILE *K, EXFINAL RegistroF){
   system("cls");
   int i=0;
   cout << "\n\rLISTADO DE REGISTROS DE EXAMENES FINALES";
   K = fopen("Finales.dat","rb");
   if(K == NULL){
      cout << "\n\n\n\rNo existe el archivo !!!\n";
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      getch();
      return;
   }

   cout << "\n\r=========================================================";
   cout << "\n\rNRO.      CODIGO       COD CURSO                    NOTA";
   cout << "\n\r---------------------------------------------------------\n";
   fread(&RegistroF, sizeof(RegistroF), 1, K);
   while(!feof(K)){
         printf("%3d\t%5s\t%12s%28.1f\n",i+1,RegistroF.codAlu,RegistroF.codCur,RegistroF.exfin);
         fread(&RegistroF,sizeof(RegistroF),1,K);
         i++;
   }
   fclose(K);
   cout << "\r---------------------------------------------------------\n";
   cout << "\rFin del listado !!!\n";
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
   getch();
   return;
}

void Calculo(FILE *I, FILE *J, FILE *K,FILE *L, PRACTICA RegistroP, EXPARCIAL RegistroPAR, EXFINAL RegistroF, CALCULO RegistroCAL){

   float cont=0,promedio=0;

   I = fopen("Practicas.dat","rb");

   if(I == NULL){
      cout << "\n\n\n\rNo existe el archivo !!!\n";
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      getch();
      return;
   }

   fread(&RegistroP, sizeof(RegistroP), 1, I);

   J = fopen("Parciales.dat","rb");
   if(J == NULL){
      cout << "\n\n\n\rNo existe el archivo !!!\n";
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      getch();
      return;
   }

   fread(&RegistroPAR, sizeof(RegistroPAR), 1, J);

   K = fopen("Finales.dat","rb");

   if(K == NULL){
      cout << "\n\n\n\rNo existe el archivo !!!\n";
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      getch();
      return;
   }

   fread(&RegistroF, sizeof(RegistroF), 1, K);

   L = fopen("Promedios.dat","w");

   if (L == NULL){
      printf("No se puede abrir el archivo\n");
      exit(1);
   }
   while(!feof(I)){
      for(int j=0;j<10;j++){
         cont=cont+RegistroP.praCt[j];
      }
      cont=cont/10;
      promedio=(cont+RegistroPAR.expar+RegistroF.exfin)/3;
      strcpy(RegistroCAL.codAlu,RegistroP.codAlu);
      strcpy(RegistroCAL.codCur,RegistroP.codCurso);
      RegistroCAL.NOTAFINAL=promedio;
      cont=0;
      fwrite(&RegistroCAL, sizeof(RegistroCAL),1, L);
      fread(&RegistroP,sizeof(RegistroP),1,I);
   }

   fclose(I);
   fclose(J);
   fclose(K);
   fclose(L);

   printf("\n *--- CALCULO ARCHIVADO ---*\n\n");
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
   getch();
   return;

}

void MostrarRegCALCULO(FILE *L, FILE *F, CALCULO RegistroCAL, ALUMNO RegistroA){

   system("cls");
   int i=0;
   cout << "\nLISTADO DE PROMEDIOS FINALES";

   F = fopen("Alumnos.dat","rb");

   if(F == NULL){
      cout << "\n\n\n\rNo existe el archivo !!!\n";
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      getch();
      return;
   }

   fread(&RegistroA, sizeof(RegistroA), 1, F);

   L = fopen("Promedios.dat","rb");

   if(L == NULL){
      cout << "\n\n\n\rNo existe el archivo !!!\n";
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      getch();
      return;
   }
   printf("\n\r===================================================================================================");
   cout<<"\nNRO.      COD_A        CURSO         PROMEDIO            ESCUELA                 ALUMNO"<<endl;
   printf("\r---------------------------------------------------------------------------------------------------\n");

   fread(&RegistroCAL, sizeof(RegistroCAL), 1, L);

   while(!feof(L)){
      printf("%3d\t%5s\t%12s%15.1f\t\t%5s\t\t%5s\n",i+1,RegistroCAL.codAlu,RegistroCAL.codCur,RegistroCAL.NOTAFINAL,RegistroA.escA,RegistroA.nomA);
      fread(&RegistroCAL,sizeof(RegistroCAL),1,L);
      fread(&RegistroA,sizeof(RegistroA), 1, F);
      i++;
   }
   fclose(L);
   cout << "\r----------------------------------------------------------------------------------------------------\n";
   cout << "\n\rFin del listado !!!\n";
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
   getch();
   return;
}


void MostrarM(FILE *I, FILE *J, FILE *K,FILE *N, ALUMNO RegistroA, Docente RegistroD, CURSOS RegistroC, CALCULO RegistroCAL){
   system("cls");
   char ALUMNO[40];
   int i=1, Sw1;
   Sw1=0;
   cout << "\n\rLISTADO DE REGISTROS DE MATRICULA por CURSO\n\n";
   cout <<" ...CODIGO del ALUMNO  ---> ";

   fflush(stdin);
   gets(ALUMNO);

   system("cls");
   printf("\n\r             UNIVERSIDAD NACIONAL MAYOR DE SAN MARCOS");
   printf("\n\r          Facultad de Ingenieria de Sistemas e informatica\n\n");

   I = fopen("Alumnos.dat","rb");

   if(I == NULL){
      cout << "\n\n\n\rNo existe el archivo !!!\n";
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      getch();
      return;
   }

   fread(&RegistroA, sizeof(RegistroA), 1, I);

   J = fopen("Docentes.dat","rb");

   if(J == NULL){
      cout << "\n\n\n\rNo existe el archivo !!!\n";
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      getch();
      return;
   }

   fread(&RegistroD, sizeof(RegistroD), 1, J);

   K = fopen("Cursos.dat","rb");

   if(K == NULL){
      cout << "\n\n\n\rNo existe el archivo !!!\n";
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      getch();
      return;
   }

   fread(&RegistroC, sizeof(RegistroC), 1, K);

   N = fopen("Promedios.dat","a+");

   if (N == NULL){
      printf("No se puede abrir el archivo\n");
      exit(1);
   }

   fread(&RegistroCAL, sizeof(RegistroCAL), 1, N);

   while(!feof(N)){

      if(stricmp(RegistroCAL.codAlu,ALUMNO)==0){
         Sw1=1;
         printf("\n\rC U R S O:  %6s\t%-30s\t", RegistroC.codC, RegistroC.nomC);
         printf("\n\rCREDITOS : %6d\tSistema de Calificacion: %6s", RegistroC.creditC, RegistroC.sist_calif);
         printf("\n\rDOCENTE  : %6i\t%-30s\n", RegistroD.codDoc, RegistroD.nomDoc);
         cout << "\n\r================================================================";
         cout << "\n\r Nº   CODIGO         N O M B R E                      ESCUELA   ";
         cout << "\n\r----------------------------------------------------------------";
         printf("\n\r%4d %6s\t%-30s\t\t%-4s", i+1,RegistroA.codA, RegistroA.nomA, RegistroA.escA);
         i++;
      }

      fread(&RegistroA, sizeof(RegistroA), 1, I);
      fread(&RegistroC, sizeof(RegistroC), 1, K);
      fread(&RegistroD, sizeof(RegistroD), 1, J);
      fread(&RegistroCAL, sizeof(RegistroCAL), 1, N);
   }

   if(Sw1==0){
   	printf("\n\rCURSO SECCION NO EXISTE...\n");
   }

   fclose(I); // Cierra el archivo de CURSOS
   fclose(J); // Cierra el archivo de DOCENTES
   fclose(K); // Cierra el archivo de TRANSACCION MATRICULA
   fclose(N); // Cierra el archivo de TRANSACCION MATRICULA

   cout << "\n\r----------------------------------------------------------------";
   cout << "\n\rFin del listado !!!\n";
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>\n";
   system("pause");

}

void MostrarMC(FILE *I, FILE *J, FILE *K,FILE *L, ALUMNO RegistroA, Docente RegistroD, CURSOS RegistroC,CALCULO RegistroCAL){
   system("cls");
   char CODIGO[2];
   int i=1, Docen, Sw1, Sw2, Sw3, Sw4;
   Sw1=0; Sw2=0; Sw3=0; Sw4=0;
   cout << "\n\rLISTADO DE REGISTROS DE MATRICULA por CURSO\n\n";
   cout <<" ...CODIGO del ALUMNO  ---> ";
   fflush(stdin);
   gets(CODIGO);

   system("cls");
   printf("\n\r             UNIVERSIDAD NACIONAL MAYOR DE SAN MARCOS");
   printf("\n\r          Facultad de Ingenieria de Sistemas e informatica\n\n");

   I = fopen("Alumnos.dat","rb");

   if(I == NULL){
      cout << "\n\n\n\rNo existe el archivo !!!\n";
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      getch();
      return;
   }

   fread(&RegistroA, sizeof(RegistroA), 1, I);

   J = fopen("Docentes.dat","rb");

   if(J == NULL){
      cout << "\n\n\n\rNo existe el archivo !!!\n";
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      getch();
      return;
   }

   fread(&RegistroD, sizeof(RegistroD), 1, J);

   K = fopen("Cursos.dat","rb");

   if(K == NULL){
      cout << "\n\n\n\rNo existe el archivo !!!\n";
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      getch();
      return;
   }

   fread(&RegistroC, sizeof(RegistroC), 1, K);

   L = fopen("Promedios.dat","rb");

   if(L == NULL){
      cout << "\n\n\n\rNo existe el archivo !!!\n";
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      getch();
      return;
   }

   fread(&RegistroCAL, sizeof(RegistroCAL), 1, L);

   while(!feof(L)){
      //puts(RegistroCAL.codAlu);
      if(strcmp(RegistroCAL.codAlu,CODIGO)==0){
         Sw1=1;
         printf("\n\rC U R S O:  %6s\t%-30s\t", RegistroC.codC, RegistroC.nomC);
         printf("\n\rCREDITOS : %6d\tSistema de Calificacion: %6s", RegistroC.creditC, RegistroC.sist_calif);
         printf("\n\rDOCENTE  : %6i\t%-30s\n", RegistroD.codDoc, RegistroD.nomDoc);
         cout << "\n\r================================================================";
         cout << "\n\r Nº   CODIGO         N O M B R E                      ESCUELA   ";
         cout << "\n\r----------------------------------------------------------------";
         printf("\n\r%4d %6s\t%-30s\t\t%-4s", i+1,RegistroA.codA, RegistroA.nomA, RegistroA.escA);
         cout << "\n\r----------------------------------------------------------------";
         printf("\n\n\tNOTA --> %-4.1f",RegistroCAL.NOTAFINAL);
         if(RegistroCAL.NOTAFINAL>10.5){
            cout<<"\n\n\tEL ALUMNO ESTA APROBADO"<<endl;
         }
         else{
            cout<<"\n\n\tEL ALUMNO ESTA DESAPROBADO"<<endl;
         }
         i++;
      }

      fread(&RegistroA, sizeof(RegistroA), 1, I);
      fread(&RegistroC, sizeof(RegistroC), 1, K);
      fread(&RegistroD, sizeof(RegistroD), 1, J);
      fread(&RegistroCAL, sizeof(RegistroCAL), 1, L);
   }

   if(Sw1==0){
   	printf("\n\rEL CODIGO NO EXISTE...\n");
   }

   fclose(I); // Cierra el archivo de CURSOS
   fclose(J); // Cierra el archivo de DOCENTES
   fclose(K); // Cierra el archivo de TRANSACCION MATRICULA

   cout << "\n\r----------------------------------------------------------------";
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>\n";
   system("pause");

}
