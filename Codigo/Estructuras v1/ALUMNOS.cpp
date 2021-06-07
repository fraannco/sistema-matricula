/*
 * nomPrograma: OpBasicasALUMNOS.cpp
 * descripción: Operaciones básicas usando las estructuras ALUMNO y FECHA.
 *           struct FECHA{
 *                int dd;
 *                int mm;
 *                int aaaa;
 *            };
 *
 *           struct ALUMNO{
 *                char codA[10];
 *                char nomA[40];
 *                char escA[4];
 *                float peso;
 *                FECHA fnac;
 *           };
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
#define MAX_A 50

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

void crearVectorAlumno(ALUMNO *x,int *dx);
void leerDatosAlumno(ALUMNO *x, int *dx);
void mostrarAlumno(ALUMNO *x, int dx);
void buscarPorCodigoA(ALUMNO *x,int dx);
void buscarPorNombreA(ALUMNO *x,int dx);
void ordenarNombre(ALUMNO x[],int dx);
void ordenarNombreDes(ALUMNO x[],int dx);
void adicionaDato(ALUMNO *x,int *dx, ALUMNO dato);
void adicionaDatoAlumno(ALUMNO *x,int *dx, ALUMNO y[], int dy);
void EliminarAlumno(ALUMNO x[], int *dx);
void editarAlumno(ALUMNO *x, int dx);

void Archivar(FILE *F, ALUMNO RegistroA[MAX_A], int dx);
void Leer(FILE *G, ALUMNO A);

void menuA();
void encabezadoA();
void encabezado2A();
void raya2();
void raya1();

int main()
{
   int nAlu;
   int nAux,nA,dc;
   int opA;
   char c='s';
   ALUMNO A;
   FILE *F;
   FILE *G;

   ALUMNO Aux[]={
      "113", "EVANS VECO, Jorge", "I2" ,68.0,{9,1,2000},
      "102", "ZELA GATTI, Luis", "I2", 65.0,{18,11,1998},
      "115", "AREVALO TORO, Alina", "I2", 48.5,{24,6,2001},
      "104", "BERNAOLA CRUZSACO, Karenina", "I2", 47.6,{19,5,2001},
      "109", "BIELA VELLANTIN, Rosa", "I1", 53.0,{2,8,2001},
      "120","BERNAOLA-CRUZSACO, Karenina", "I1", 47.0,{22,5,1999},
   };

   ALUMNO Alu[]={
      "100", "CONCALES ALE, Eva", "I1", 45.0,{5,9,2001},
      "101", "ARPASSI MAMAGNI, Juana", "I1", 55.0,{26,2,1999},
      "103", "ARONES LOTAS, Felipe", "I2", 65.5,{30,5,2000},
      "106", "AKATA MAKO, Marimon Kobe", "I2", 45.6,{9,11,2000},
      "108", "MARISLAV NOLAK, Yashin", "I1", 55.0,{15,9,1998},
      "110", "PEREZ LOZANO, Jose Luis", "I2", 75.0,{9,1,2000},
      "117", "QUIROZ BENITES, Andre", "I2", 55.0,{6,7,1997},
      "119", "ZEVALLOS SELMA, Mariluz", "I2", 45.0,{16,3,2001},
   };

   ALUMNO M={"140","GONZALES AVA, Felix","I1", 60.5,{24,6,2001}};

   nAux=(sizeof(Aux)/(40*(sizeof(int)+sizeof(int)+sizeof(int))+sizeof(float)+40*sizeof(char)+10*sizeof(char)+4*sizeof(char)));
   nAlu=(sizeof(Alu)/(40*(sizeof(int)+sizeof(int)+sizeof(int))+sizeof(float)+40*sizeof(char)+10*sizeof(char)+4*sizeof(char)));


   menuA();
   printf("\n");

   do{
      do{
         cout<<"\nIngrese una opcion: [  ]"<<"\b\b\b";
         cin>>opA;
      }while(opA<0 || opA>11);
      switch(opA){
         case 1:  Archivar(F,Alu,nAlu);
                  break;
         case 2:  Leer(G,A);
                  break;
         case 3:  mostrarAlumno(Alu,nAlu);
                  break;
         case 4:  buscarPorCodigoA(Alu,nAlu);
                  printf("\n");
                  break;
         case 5:  buscarPorNombreA(Alu,nAlu);
                  printf("\n");
                  break;
         case 6:  ordenarNombre(Alu,nAlu);
                  mostrarAlumno(Alu,nAlu);
                  printf("\n");
                  break;
         case 7:  mostrarAlumno(Alu,nAlu);
                  EliminarAlumno(Alu,&nAlu);
                  mostrarAlumno(Alu,nAlu);
                  printf("\n");
                  break;
         case 8:  printf("\n\nConjunto de alumnos que se van a añadir: \n");
                  mostrarAlumno(Aux,nAux);
                  printf("\n");
                  system("cls");
                  printf("\nNUEVA LISTA DE ALUMNOS: \n");
                  adicionaDatoAlumno(Alu,&nAlu,Aux,nAux);
                  mostrarAlumno(Alu,nAlu);
                  printf("\n");
                  break;
         case 9:  system("cls");
                  printf("\n- Se agregara un unico alumno -\n");
                  adicionaDato(Alu,&nAlu,M);
                  mostrarAlumno(Alu,nAlu);
                  break;
         case 10:  system("cls");
                  editarAlumno(Alu,nAlu);
                  mostrarAlumno(Alu,nAlu);
                  printf("\n");
                  break;
      }
      system("cls");
      menuA();
      printf("\n");
   }
   while(opA!=0);
   return(0);
}

void encabezadoA(){
   char title[]="\tREPORTE DE ALUMNOS";
   char num[]="NUMERO";
   char cod[]="CODIGO";
   char nom[]="ALUMNO";
   char escuela[]="ESCUELA";
   char peso[]="PESO";
   char fnac[]="FECHA DE NAC.";
   printf("\n");
   raya2();
   printf("\t\t%s\n",title);
   raya2();
   printf("%-6s\t%-12s%-25s%5s%11s%20s\n",num,cod,nom,escuela,peso,fnac);
   raya1();
}

void encabezado2A(){
   system("cls");
   cout << "\n\n\r E D I C I O N";
   cout << "\n\r 0.- TERMINAR";
   cout << "\n\r [1] SE EDITARA EL CODIGO";
   cout << "\n\r [2] SE EDITARA EL NOMBRE";
   cout << "\n\r [3] SE EDITARA EL ESCUELA";
   cout << "\n\r [4] SE EDITARA EL PESO";
   cout << "\n\r [5] SE EDITARA LA FECHA DE NACIMIENTO";
}

void raya2(){
   printf("\r===========================================================================================\n");
}

void raya1(){
   cout << "\r-------------------------------------------------------------------------------------------\n";
}

void menuA(){
   int op;
   char s;
   char num[]="OPCION";
   char cod[]="ACCION";
   printf("\n");
   raya2();
   printf("\t\t\t\tBLOQUE DE ACCIONES\n");
   raya2();
   printf(" %-6s\t\t%-12s\n",num,cod);
   raya1();
   printf("\n");
   printf(" [0]\tFINALIZAR\n");
   printf(" [1].\tGUARDAR/ARCHIVAR LA ESTRUCTURA\n");
   printf(" [2].\tLEER LA ESTRUCTURA ARCHIVADA\n");
   printf(" [3].\tSE VISUALIZAN LOS DATOS DE LOS ALUMNOS\n");
   printf(" [4].\tSE BUSCA A ALUMNO POR SU CODIGO\n");
   printf(" [5].\tSE BUSCA A UN ALUMNO POR SU NOMBRE\n");
   printf(" [6].\tSE ORDENARAN LOS ALUMNOS ALFABETICAMENTE\n");
   printf(" [7].\tSE ELIMINAR AL ALUMNO INDICADO DE LA LISTA\n");
   printf(" [8].\tSE AGREGA UN CONJUNTO DE ALUMNOS AL REGISTRO\n");
   printf(" [9].\tSE AGREGA UN ALUMNO A LA LISTA\n");
   printf(" [10].\tSE EDITA UN DATO DEL ALUMNO ELEGIDO\n");
   raya1();
}

void crearVectorAlumno(ALUMNO *x,int *dx){
   *dx=-1;
}

void leerDatosAlumno(ALUMNO *x, int *dx){
   int i=0, n;
   printf("Ingrese la cantidad de cursos que se van a crear ---> ");
   scanf("%d", &n);
   if(n<MAX_A){
      while(i<n){
         fflush(stdin);
         printf("Codigo del alumno %d: \n", i+1);
         gets((x+i)->codA);

         printf("Nombre del alumno  :" );
         gets((x+i)->nomA);

         printf("Escuela:  " );
         gets((x+i)->escA);

         printf("Peso  : ");
         scanf("%d", &(x+i)->peso);
         fflush(stdin);

         i=i+1;
      }
      *dx=i;
   }
    else{
      printf("Dimension fuera de rango...\n");
   }
}

void mostrarAlumno(ALUMNO *x, int dx){
   system("cls");
   int i=0;
   if(dx>0){
      encabezadoA();
      while(i<dx){
         printf("%4d\t%4s\t%-24s%10s\t%8.2f",i+1,(x+i)->codA,(x+i)->nomA,(x+i)->escA,(x+i)->peso);
         printf("\t%d/%d/%d\n",(x+i)->fnac->dd,(x+i)->fnac->mm,(x+i)->fnac->aaaa);
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

void buscarPorCodigoA(ALUMNO *x,int dx){
   system("cls");
   ALUMNO aux;
   int i=0;

   fflush(stdin);
   printf("\nIngrese el codigo del alumno: ");
   gets(aux.codA);

   strupr(aux.codA);
   bool encontrado=0;
   if(dx==0){
      printf("Vector vaciooo......");
   }
   else{
      while(i<dx) {
         if(strcmp(aux.codA,(x+i)->codA)==0){
            system("cls");
            encontrado=1;
            printf("\nAlumno encontrado!!\n");
            printf("Los datos del alumno buscado son: \n");
            encabezadoA();
            printf("%4d\t%4s\t%-24s%10s\t%8.2f",i+1,(x+i)->codA,(x+i)->nomA,(x+i)->escA,(x+i)->peso);
            printf("\t%d/%d/%d\n",(x+i)->fnac->dd,(x+i)->fnac->mm,(x+i)->fnac->aaaa);
            raya1();
         }
         i++;
      }

   }
   if(!encontrado){
      printf("Alumno no encontrado\n");
   }
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
   getch();
   return;
}

void buscarPorNombreA(ALUMNO *x,int dx){
   system("cls");
   ALUMNO aux;
   int i=0;

   fflush(stdin);
   printf("\nIngrese el nombre del alumno: ");
   gets(aux.nomA);

   bool encontrado=0;
   if(dx==0){
      printf("Vector vaciooo......");
   }
   else{
      while(i<dx) {
         if(stricmp(aux.nomA,(x+i)->nomA)==0){
            encontrado=1;
            system("cls");
            printf("\nAlumno encontrado\n");
            printf("\nLos datos del alumno son: \n");
            encabezadoA();
            printf("%4d\t%4s\t%-24s%10s\t%8.2f",i+1,(x+i)->codA,(x+i)->nomA,(x+i)->escA,(x+i)->peso);
            printf("\t%d/%d/%d\n",(x+i)->fnac->dd,(x+i)->fnac->mm,(x+i)->fnac->aaaa);
            raya1();
            printf("\n\n");
         }
         i++;
      }
   }
   if(!encontrado){
      printf("Alumno no encontrado\n");
   }
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
   getch();
   return;
}

void ordenarNombre(ALUMNO x[],int dx){
   int i,j;
   ALUMNO tempo;
   for (i = 0;i < dx; i++){
      for(j=0;j<dx-1;j++){
         if(strcmp(x[j].nomA,x[j+1].nomA)>0){
            tempo = x[j];
            x[j] = x[j+1];
            x[j+1] = tempo;
         }
      }
   }
}

void ordenarNombreDes(ALUMNO x[],int dx){
   int i,j;
   ALUMNO tempo;
   for (i = 0;i < dx; i++){
      for(j=0;j<dx-1;j++){
         if(strcmp(x[j].nomA,x[j+1].nomA)<0){
            tempo = x[j];
            x[j] = x[j+1];
            x[j+1] = tempo;
         }
      }
   }
}

void EliminarAlumno(ALUMNO x[], int *dx){
   ALUMNO aux;
   int i=0,a;
   fflush(stdin);
   printf("\nIngrese el nombre del alumno a eliminar: ");
   gets(aux.nomA);

   a=*dx;
   bool encontrado=0;
   if(*dx==0){
      printf("Vector vaciooo......");
   }
   else{
      while(i<*dx) {
         if(stricmp(aux.nomA,(x+i)->nomA)==0){
            encontrado=1;
            system("cls");
            printf("El dato buscado pertenece al vector\n");
            strcpy((x+i)->codA,"\0");
            strcpy((x+i)->nomA,"\0");
            strcpy((x+i)->escA,"\0");
            (x+i)->peso=0;
            (x+i)->fnac->dd=0;
            (x+i)->fnac->mm=0;
            (x+i)->fnac->aaaa=0;
            ordenarNombreDes(x,a);
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

void adicionaDato(ALUMNO *x,int *dx, ALUMNO dato){
   int n;
   n=*dx;

   if(n<0){
      strcpy((x+0)->codA,dato.codA);
      strcpy((x+0)->nomA,dato.nomA);
      strcpy((x+0)->escA,dato.escA);
      (x+0)->peso=dato.peso;
      (x+0)->fnac->dd=dato.fnac->dd;
      (x+0)->fnac->mm=dato.fnac->mm;
      (x+0)->fnac->aaaa=dato.fnac->aaaa;
      *dx=1;
   }
   else{
      n=*dx;
      n=n+1;
      if(n<MAX_A){
         strcpy((x+n-1)->codA,dato.codA);
         strcpy((x+n-1)->nomA,dato.nomA);
         strcpy((x+n-1)->escA,dato.escA);
         (x+n-1)->peso=dato.peso;
         (x+n-1)->fnac->dd=dato.fnac->dd;
         (x+n-1)->fnac->mm=dato.fnac->mm;
         (x+n-1)->fnac->aaaa=dato.fnac->aaaa;

         *dx=n;
      }
      else{
         printf("Vector llenooo...\n\n");
      }
   }
}

void adicionaDatoAlumno(ALUMNO *x,int *dx, ALUMNO y[], int dy)
{
   int i=0,n;
   n=*dx;

   if(n<0){
      for(i=0;i<dy;i++){
         strcpy((x+i)->codA,y[i].codA);
         strcpy((x+i)->nomA,y[i].nomA);
         strcpy((x+i)->escA,y[i].escA);
         (x+i)->peso=y[i].peso;
         (x+i)->fnac->dd=y[i].fnac->dd;
         (x+i)->fnac->mm=y[i].fnac->mm;
         (x+i)->fnac->aaaa=y[i].fnac->aaaa;
      }
      *dx=dy;
   }

   else{
      n=*dx;
      if(n<MAX_A){
         for(i=0;i<dy;){
            printf("-----------TESTING---------");
            strcpy((x+n)->codA,y[i].codA);
            strcpy((x+n)->nomA,y[i].nomA);
            strcpy((x+n)->escA,y[i].escA);
            (x+n)->peso=y[i].peso;
            (x+n)->fnac->dd=y[i].fnac->dd;
            (x+n)->fnac->mm=y[i].fnac->mm;
            (x+n)->fnac->aaaa=y[i].fnac->aaaa;
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

void editarAlumno(ALUMNO *x, int dx)
{
   ALUMNO aux;
   int i=0,opc;

   fflush(stdin);
   printf("\nIngrese el nombre del alumno a editar: ");
   gets(aux.nomA);
   bool encontrado=0;
   if(dx==0){
      printf("Vector vaciooo......");
   }
   else{
      while(i<dx){
         if(stricmp(aux.nomA,(x+i)->nomA)==0){
            system("cls");
            encontrado=1;
            printf("\n-- Alumno encontrado!! --\n\n");
            printf("\n\nLos datos del alumno buscando buscado son: \n\n");
            encabezadoA();
            printf("%4d\t%4s\t%-24s%10s\t%8.2f",i+1,(x+i)->codA,(x+i)->nomA,(x+i)->escA,(x+i)->peso);
            printf("\t%d/%d/%d\n",(x+i)->fnac->dd,(x+i)->fnac->mm,(x+i)->fnac->aaaa);
            raya1();
            printf("\n\n");
            system("pause");
            system("cls");

            encabezado2A();

            printf("\n");
            printf("Indique lo que va a editar: ");
            scanf("%d",&opc);
            do{
               switch(opc){
                  case 1:
                     fflush(stdin);
                     printf("Ingrese el nuevo codigo: ");
                     gets((x+i)->codA);
                     break;
                  case 2:
                     fflush(stdin);
                     printf("Ingrese el nuevo nombre: ");
                     gets((x+i)->nomA);
                     break;
                  case 3:
                     fflush(stdin);
                     printf("Ingrese la nueva escuela: ");
                     gets((x+i)->escA);
                     break;
                  case 4:
                     printf("Ingrese el nuevo peso: ");
                     scanf("%f",&(x+i)->peso);
                     break;
                  case 5:
                     printf("Ingrese la nueva fecha de nacimiento:\n");
                     printf("Dia:\n");
                     scanf("%d",&(x+i)->fnac->dd);
                     printf("Mes:\n");
                     scanf("%d",&(x+i)->fnac->mm);
                     printf("Año:\n");
                     scanf("%d",&(x+i)->fnac->aaaa);
                     break;
               }
               encabezado2A();
               printf("Indique lo que va a editar: ");
               scanf("%d",&opc);
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

void Archivar(FILE *F, ALUMNO RegistroA[MAX_A], int dx){
   F = fopen("Alumnos.dat","w");
   int i=0;
   if (F == NULL){
      printf("No se puede abrir el archivo\n");
      exit(1);
   }
   while(i<dx){
      fwrite(&RegistroA[i], sizeof(RegistroA[i]), 1, F);
      i++;
   }
   fclose(F);
   printf("\n *--- ALUMNOS ARCHIVADOS ---*\n\n");
   system("pause");
}

void Leer(FILE *G, ALUMNO A){
   int i=0;
   G = fopen("Alumnos.dat","rb");
   if (G == NULL){
      printf("No se puede abrir el archivo\n");
      exit(1);
   }
   fread(&A, sizeof(A), 1, G);
   system("cls");
   encabezadoA();
   while(!feof(G)){
      printf("%4d\t%4s\t%-24s%10s\t%8.2f",i+1,A.codA,A.nomA,A.escA,A.peso);
      printf("\t%d/%d/%d\n",A.fnac->dd,A.fnac->mm,A.fnac->aaaa);
      fread(&A,sizeof(A),1,G);
      i++;
   };
   fclose(G);
   cout << "\n\r-------------------------------------------------------------------------------------------";
   cout << "\n\rFin del listado !!!\n";
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>\n";
   system("pause");
}

