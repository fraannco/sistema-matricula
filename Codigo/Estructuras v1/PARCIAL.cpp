/*
 * nomPrograma: PARCIAL.cpp
 * descripción: Operaciones básicas usando la estructura EXPARCIAL.
 *              struct EXPARCIAL{
 *                char codAlu[10];
 *                char codCur[10];
 *                float expar;
 *              };
 * autores: Chávez Farro, Luis André
 *          Espinola Ravello, Annie Katerine
 *          Reyes De la Cruz, Andrés Eduardo
 *          Silva Barra, Ernesto Franco
 *          Tocto Mallqui, Alexis
 * fecha: 2/09/2020
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAX 40

using namespace std;

struct EXPARCIAL{
   char codAlu[10];
   char codCur[10];
   float expar;
};

void crearVectorParcial(EXPARCIAL *x,int *dx);
void leerDatosParcial(EXPARCIAL *x, int *dx);
void mostrarParcial(EXPARCIAL *x, int dx);
void buscarPorCodigoAlumno(EXPARCIAL *x,int dx);
void buscarPorCodigoCurso(EXPARCIAL *x,int dx);
void adicionaDato(EXPARCIAL *x,int *dx, EXPARCIAL dato);
void adicionaDato2(EXPARCIAL *x,int *dx, EXPARCIAL y[], int dy);
void EliminarParcialAlumno(EXPARCIAL x[], int *dx);
void ordenarCodigoAlumno(EXPARCIAL x[],int dx);
void ordenarCodigoCurso(EXPARCIAL x[],int dx);
void editarParcial(EXPARCIAL *x, int dx);

void Archivar(FILE *F, EXPARCIAL RegistroP[MAX], int dx);
void Leer(FILE *F, EXPARCIAL C);

void menu();
void encabezado();
void encabezado2();
void raya2();
void raya1();

int main()
{
   EXPARCIAL a[MAX];

   int nA, nB;
   int op;
   FILE *F;
   FILE *G;
   EXPARCIAL C;

   EXPARCIAL B[]={
      "113", "CO112", 18,
      "102", "CO111", 14,
      "115", "ST204", 8,
      "104", "PA711", 17,
      "109", "PA712", 15,
      "120", "CO111", 16,
   };

   EXPARCIAL A[]={
      "100", "MA113", 11,
      "101", "MA123", 15,
      "103", "MA133", 6,
      "106", "ST202", 10,
      "108", "ST204", 14,
      "110", "PA711", 10,
      "117", "PA712", 7,
      "119", "PA713", 13,
   };

   EXPARCIAL m={"125","TS215",16};

   nA=(sizeof(A)/(sizeof(int)+10*sizeof(char)+10*sizeof(char)));
   nB=(sizeof(B)/(sizeof(int)+10*sizeof(char)+10*sizeof(char)));

   menu();
   printf("\n");

   do{
      do{
        cout<<"Ingrese opcion [  ]"<<"\b\b\b";
        cin>>op;
      }while(op<0 || op>12);
      switch(op){
         case 1:  Archivar(F,A,nA);
                  break;
         case 2:  Leer(G,C);
                  break;
         case 3:  mostrarParcial(A,nA);
                  break;
         case 4:  buscarPorCodigoAlumno(A,nA);
                  break;
         case 5:  buscarPorCodigoCurso(A,nA);
                  break;
         case 6:  ordenarCodigoCurso(A,nA);
                  mostrarParcial(A,nA);
                  break;
         case 7:  ordenarCodigoAlumno(A,nA);
                  mostrarParcial(A,nA);
                  break;
         case 8:  mostrarParcial(A,nA);
                  EliminarParcialAlumno(A,&nA);
                  mostrarParcial(A,nA);
                  break;
         case 9:  printf("\n\nConjunto de notas del parcial que se van a anadir: \n");
                  mostrarParcial(B,nB);
                  printf("\n");
                  //system("cls");
                  printf("\nNUEVA LISTA DE NOTAS: \n");
                  adicionaDato2(A,&nA,B,nB);
                  mostrarParcial(A,nA);
                  break;
         case 10:  printf("\n\n- Se agregara una unica nota de parcial -\n");
                  adicionaDato(A,&nA,m);
                  mostrarParcial(A,nA);
                  break;
         case 11: system("cls");
                  editarParcial(A,nA);
                  mostrarParcial(A,nA);
                  break;
      }
      system("cls");
      menu();
      printf("\n");
   }
   while(op!=0);
   system("pause");
   return(0);
}

void encabezado(){
   char title[]="\tREPORTE DE NOTAS DEL PARCIAL";
   char num[]="NUMERO";
   char cod[]="COD.ALUM";
   char nom[]="COD.CURSO";
   char nota[]="NOTA";
   printf("\n");
   raya2();
   printf("\t\t%s\n",title);
   raya2();
   printf("%-6s\t%-13s%-31s%-5s\n",num,cod,nom,nota);
   raya1();
}

void encabezado2(){
   system("cls");
   cout << "\n\n\r E D I C I O N";
   cout << "\n\r 0.- TERMINAR";
   cout << "\n\r [1] SE EDITARA EL CODIGO DEL CURSO";
   cout << "\n\r [2] SE EDITARA EL CODIGO DEL ALUMNO";
   cout << "\n\r [3] SE EDITARA LA NOTA DEL PARCIAL";
}

void raya2(){
   printf("\r==============================================================================\n");
}

void raya1(){
   printf("\r------------------------------------------------------------------------------\n");
}

void menu(){
   int op;
   char s;
   char num[]="OPCION";
   char cod[]="ACCION";
   printf("\n");
   raya2();
   printf("\t\t\tPARCIAL: BLOQUE DE ACCIONES\n");
   raya2();
   printf(" %-6s\t\t%12s\n",num,cod);
   raya1();
   printf(" [0]\t\tFINALIZAR\n");
   printf(" [1]\t\tSE ARCHIVARA(SALVAR) A LOS EXAMENES PARCIALES\n");
   printf(" [2]\t\tSE LEERA(RECUPERAR) EL ARCHIVO DE EXAMENES PARCIALES\n");
   printf(" [3]\t\tSE VISUALIZAN LOS DATOS DE LOS ALUMNOS\n");
   printf(" [4]\t\tSE BUSCARA POR CODIGO DE ALUMNO\n");
   printf(" [5]\t\tSE BUSCARA POR CODIGO DE CURSO\n");
   printf(" [6]\t\tSE ELIMINA DE LA ESTRUCTURA EL PARCIAL INDICADO\n");
   printf(" [7]\t\tSE ORDENARAN POR CODIGO DE ALUMNO\n");
   printf(" [8]\t\tSE ORDENARAN POR CODIGO DE CURSO\n");
   printf(" [9]\t\tSE ADICIONA UN CONJUNTO DE NOTAS PARCIALES\n");
   printf(" [10]\t\tSE ADICIONA UNA NOTA DEL PARCIAL\n");
   printf(" [11] \t\tSE EDITARA UN VALOR DE LA ESTRUCTURA\n");
   raya1();
}

void crearVectorParcial(EXPARCIAL *x,int *dx){
   *dx=-1;
}

void leerDatosParcial(EXPARCIAL *x, int *dx){
   int i=0, n;
   printf("Ingrese la cantidad de notas que ingresara ---> ");
   scanf("%d", &n);
   if(n<MAX){
     while(i<n){
         fflush(stdin);
         printf("Codigo del alumno %d: \n", i+1);
         gets((x+i)->codAlu);
         printf("Codigo del curso  : " );
         gets((x+i)->codCur);
         printf("Nota del examen parcial: ");
         scanf("%f", &(x+i)->expar);
         i=i+1;
      }
      *dx=i;
   }
   else{
      printf("Dimension fuera de rango...\n");
   }
}

void mostrarParcial(EXPARCIAL *x, int dx){
   system("cls");
   int i=0;
   if(dx>0){
      encabezado();
      while(i<dx){
         printf("%3d\t%5s\t%12s%28.1f\n",i+1,(x+i)->codAlu,(x+i)->codCur,(x+i)->expar);
         i=i+1;
      }
      raya1();
   }
   else{
     printf("Dimension fuera de rango...\n");
   }
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
   getch();
   return;
}

void buscarPorCodigoAlumno(EXPARCIAL *x,int dx){
   EXPARCIAL aux;
   int i=0;
   system("cls");
   fflush(stdin);
   printf("\nIngrese el codigo del alumno: ");
   gets(aux.codAlu);
   strupr(aux.codAlu);
   bool encontrado=0;
   if(dx==0){
     printf("Vector vaciooo......");
   }
   else{
      while(i<dx) {
         if(strcmp(aux.codAlu,(x+i)->codAlu)==0){
            encontrado=1;
            printf("\n\n-- El dato buscado pertenece al vector --\n\n");
            printf("\n\nLos datos del codigo de alumno son: \n\n");
            encabezado();
            printf("%3d\t%5s\t%12s%28.1f\n",i+1,(x+i)->codAlu,(x+i)->codCur,(x+i)->expar);
            raya1();
            break;
         }
         i++;
      }
   }
   if(!encontrado){
     printf("El dato no pertenece al vector\n");
   }
}

void buscarPorCodigoCurso(EXPARCIAL *x,int dx){
   EXPARCIAL aux;
   int i=0;
   system("cls");
   fflush(stdin);
   printf("\nIngrese el codigo del curso: ");
   gets(aux.codCur);
   strupr(aux.codCur);
   bool encontrado=0;
   if(dx==0){
     printf("Vector vaciooo......");
   }
   else{
     while(i<dx) {
         if(strcmp(aux.codCur,(x+i)->codCur)==0){
            encontrado=1;
            printf("\n\n-- El dato buscado pertenece al vector --\n\n");
            printf("\n\nLos datos del codigo de curso son: \n\n");
            encabezado();
            printf("%3d\t%5s\t%12s%28.1f\n",i+1,(x+i)->codAlu,(x+i)->codCur,(x+i)->expar);
            raya1();
            break;
         }
         i++;
      }
   }
   if(!encontrado){
     printf("El dato no pertenece al vector\n");
   }
}

void adicionaDato(EXPARCIAL *x,int *dx, EXPARCIAL dato){
   int n;
   n=*dx;

   if(n<0){
      strcpy((x+0)->codAlu,dato.codAlu);
      strcpy((x+0)->codCur,dato.codCur);
      (x+0)->expar=dato.expar;
      *dx=1;
   }
   else{
      n=*dx;
      n=n+1;
      if(n<MAX){
         strcpy((x+n-1)->codAlu,dato.codAlu);
         strcpy((x+n-1)->codCur,dato.codCur);
         (x+n-1)->expar=dato.expar;
         *dx=n;
      }
      else{
         printf("Vector llenooo...\n\n");
      }
   }
}

void adicionaDato2(EXPARCIAL *x,int *dx, EXPARCIAL y[], int dy)
{
   int i=0,n;
   n=*dx;

   if(n<0){
      for(i=0;i<dy;i++){
         strcpy((x+i)->codAlu,y[i].codAlu);
         strcpy((x+i)->codCur,y[i].codCur);
         (x+i)->expar=y[i].expar;
         //i=i+1;
      }
      *dx=dy;
   }

   else{
      n=*dx;
      if(n<MAX){
         for(i=0;i<dy;){
            strcpy((x+n)->codAlu,y[i].codAlu);
            strcpy((x+n)->codCur,y[i].codCur);
            (x+n)->expar=y[i].expar;
            i++;
            n=n+1;
         }
         *dx=n;
      }
      else{
         printf("Vector llenooo...\n\n");
      }
   }
}

void EliminarParcialAlumno(EXPARCIAL x[], int *dx){
   EXPARCIAL aux;
   int i=0,a;
   fflush(stdin);
   printf("\nIngrese el codigo de alumno a eliminar nota del parcial: ");
   gets(aux.codAlu);

   a=*dx;
   bool encontrado=0;
   if(*dx==0){
      printf("Vector vaciooo......");
   }
   else{
      while(i<*dx) {
         if(stricmp(aux.codAlu,(x+i)->codAlu)==0){
            encontrado=1;
            printf("El dato buscado pertenece al vector\n");
            strcpy((x+i)->codCur,"\0");
            strcpy((x+i)->codAlu,"\0");
            (x+i)->expar=0;
            ordenarCodigoAlumno(x,a);
            *dx=*dx-1;
            break;
         }
         i++;
      }
   }
   if(!encontrado){
     printf("El dato no pertenece al vector\n");
   }
}

void ordenarCodigoAlumno(EXPARCIAL x[],int dx){
   int i,j;
   EXPARCIAL tempo;
   for (i = 0;i < dx; i++){
      for(j=0;j<dx-1;j++){
         if(strcmp(x[j].codAlu,x[j+1].codAlu)>0){
            tempo = x[j];
            x[j] = x[j+1];
            x[j+1] = tempo;
         }
      }
   }
}

void ordenarCodigoCurso(EXPARCIAL x[],int dx){
   int i,j;
   EXPARCIAL tempo;
   for (i = 0;i < dx; i++){
      for(j=0;j<dx-1;j++){
         if(strcmp(x[j].codCur,x[j+1].codCur)>0){
            tempo = x[j];
            x[j] = x[j+1];
            x[j+1] = tempo;
         }
      }
   }
}

void editarParcial(EXPARCIAL *x, int dx) {
   EXPARCIAL aux;
   int i=0,opc;
   fflush(stdin);
   printf("\nIngrese el codigo de alumno: ");
   gets(aux.codAlu);
   bool encontrado=0;
   if(dx==0){
      printf("Vector vaciooo......");
   }
   else{
      while(i<dx){
         if(stricmp(aux.codAlu,(x+i)->codAlu)==0){
            encontrado=1;
            printf("\n\n--Datos encontrados...!! --\n\n");
            printf("\n\nLos datos del codigo buscado son: \n\n");
            encabezado();
            printf("\n%3d\t%s\t%-30s\t%10.1f\n",i+1,(x+i)->codAlu,(x+i)->codCur,(x+i)->expar);
            raya1();
            printf("\n\n");
            system("pause");
            system("cls");

            encabezado2();

            printf("\n");
            cout<<"Ingrese lo que desea editar [ ]"<<"\b\b";
            cin>>opc;
            do{
               switch(opc){
                  case 1:
                     fflush(stdin);
                     printf("Ingrese el nuevo codigo de alumno: ");
                     gets((x+i)->codAlu);
                     break;
                  case 2:
                     fflush(stdin);
                     printf("Ingrese el nuevo codigo de curso: ");
                     gets((x+i)->codCur);
                     break;
                  case 3:
                     printf("Ingrese la nueva nota del parcial: ");
                     scanf("%f",&(x+i)->expar);
                     break;
               }
               encabezado2();
               cout<<"Ingrese lo que desea editar [ ]"<<"\b\b";
               cin>>opc;
            }while(opc!=0);
            break;
         }
         i++;
      }
   }
   if(!encontrado){
     printf("El dato no pertenece al vector\n");
   }
}

void Archivar(FILE *F, EXPARCIAL RegistroP[MAX], int dx){

   F = fopen("Parciales.dat","w");
   int i=0;
   if (F == NULL){
      printf("No se puede abrir el archivo\n");
      exit(1);
   }

   while(i<dx){
      fwrite(&RegistroP[i], sizeof(RegistroP[i]), 1, F);
      i++;
   }
   fclose(F);
   printf("\n *--- PARCIALES ARCHIVADOS ---*\n\n");
   system("pause");
}

void Leer(FILE *F, EXPARCIAL C){
   int i=1;
   F = fopen("Parciales.dat","rb");
   if(F == NULL){
      cout << "\n\n\n\rNo existe el archivo !!!\n";
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      getch();
   }

   fread(&C, sizeof(C), 1, F);
   system("cls");
   encabezado();
   while(!feof(F)){
      printf("%3d\t%5s\t%12s%28.1f\n",i,C.codAlu, C.codCur, C.expar);
      fread(&C,sizeof(C),1,F);
      i++;
   }
   fclose(F);
   cout << "\n\r------------------------------------------------------------------------------";
   cout << "\n\rFin del listado !!!\n";
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
   system("pause");
}
