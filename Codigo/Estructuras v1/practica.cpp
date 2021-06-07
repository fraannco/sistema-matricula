/*
 * nomPrograma: practica.cpp
 * descripción: Operaciones básicas usando la estructura PRACTICA.
 *              struct PRACTICA{
 *                char codAlu[7];
 *                char codCurso[10];
 *                float praCt;
 *                };
 * autores: Chávez Farro, Luis André
 *          Espinola Ravello, Annie Katerine
 *          Reyes De la Cruz, Andrés Eduardo
 *          Silva Barra, Ernesto Franco
 *          Tocto Mallqui, Alexis
 * fecha: 7/09/2020
 */
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_C 100

using namespace std;

struct PRACTICA{
   char codAlu[7];
   char codCurso[10];
   float praCt[10];
};

void crearVectorPractica(PRACTICA *x,int *dx);
void leerDatosPractica(PRACTICA *x, int *dx);
void mostrarPractica(PRACTICA *x, int dx);
void buscarPorCodigoC(PRACTICA *x,int dx);
void buscarPorCodigoA(PRACTICA *x,int dx);
void ordenarCodigoA(PRACTICA x[],int dx);
void adicionaDato(PRACTICA *x,int *dx, PRACTICA dato);
void adicionaDato2(PRACTICA *x,int *dx, PRACTICA y[], int dy);
void EliminarPractica(PRACTICA x[], int *dx);
void editarPractica(PRACTICA *x, int dx);

void Archivar(FILE *F, PRACTICA RegistroP[MAX_C], int dx);
void Leer(FILE *F, PRACTICA C);

void menu();
void encabezado();
void raya2();
void raya1();


int main()
{
   PRACTICA InsertPracticas[MAX_C];
   int nC,nD,nic;
   int op;
   PRACTICA A;
   FILE *F;
   FILE *G;

   PRACTICA C[]={
      "113","CO111",{16,11,12,13,14,15,12,11,19,14},
      "102","CO112",{13,14,13,14.48,16,12,11,16,19,10},
      "115","CO113",{11,4,8,12,9,13,7,11,11,13},
      "104","AM116",{14,12,16,13,19,14,18.5,16,10,16},
      "109","PA712",{10,12,11,18,8,14,18.5,10,5,16},
      "120","CO111",{14,10,16,18,19,8,18.5,10,14,7},
   };

   PRACTICA D[]={
      "100","MA113",{11,8,11.5,12,16,14,20,12.6,16,11},
      "101","MA123",{15,15,12,16,19,17,18,13,16,11},
      "103","MA133",{18,18,11,12,13,14,15,10,8,16},
      "106","ST202",{12,10,5,16,17,20,15.70,16.2,14,15},
      "108","ST204",{10,10,10,13,14,12,11,8,16,14},
      "110","PA711",{16,15,15,12,13,11,12,14,15,20},
      "117","PA712",{17,11,19,15,16,13,12.8,16,16,10},
      "119","PA713",{13,12,11,10,11,13,14,12,16,11.76},
   };

   PRACTICA m={"126","OA201",13,11,16,12,13,10,18,19,14,12};

   nC=(sizeof(C)/(10*sizeof(float)+10*sizeof(char)+7*sizeof(char)));
   nD=(sizeof(D)/(10*sizeof(float)+10*sizeof(char)+7*sizeof(char)));

   menu();
   printf("\n");

   do{
      do{
        cout<<"Ingrese opcion [  ]"<<"\b\b\b";
        cin>>op;
      }while(op<0 || op>11);
      switch(op){
         case 1:  Archivar(F,D,nD);
                  break;
         case 2:  Leer(G,A);
                  break;
         case 3:  mostrarPractica(D,nD);
                  break;
         case 4:  buscarPorCodigoC(D,nD);
                  break;
         case 5:  buscarPorCodigoA(D,nD);
                  break;
         case 6:  ordenarCodigoA(D,nD);
                  mostrarPractica(D,nD);
                  break;
         case 7:  EliminarPractica(D,&nD);
                  mostrarPractica(D,nD);
                  break;
         case 8:  printf("\n\nConjunto de practicas que se van a añadir: \n");
                  mostrarPractica(C,nC);
                  printf("\n");
                  adicionaDato2(D,&nD,C,nC);
                  mostrarPractica(D,nD);
                  break;
         case 9:  printf("\n\n- Se agregara un unico curso -\n");
                  adicionaDato(D,&nD,m);
                  mostrarPractica(D,nD);
                  break;
         case 10:  editarPractica(D,nD);
                  mostrarPractica(D,nD);
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
   char title[]="\tREPORTE DE PRACTICAS";
   char num[]="NUMERO";
   char coda[]="COD.ALUM";
   char cod[]="COD.CURSO";
   char prac[]="NOTAS DE PRACTICAS";
   printf("\n");
   raya2();
   printf("\t\t%s\n",title);
   raya2();
   printf("%-6s\t%-15s%-35s%-5s\n",num,coda,cod,prac);
   raya1();
}

void encabezado2(){
   system("cls");
   cout << "\n\n\r E D I C I O N";
   cout << "\n\r 0.- TERMINAR";
   cout << "\n\r [1] SE EDITARA EL CODIGO DEL CURSO";
   cout << "\n\r [2] SE EDITARA EL CODIGO DEL ALUMNO";
   cout << "\n\r [3] SE EDITARA LAS NOTAS DE PRACTICA";
}

void raya2(){
   printf("\r===================================================================================================\n");
}

void raya1(){
   printf("\r---------------------------------------------------------------------------------------------------\n");
}

void menu(){
   int op;
   char num[]="OPCION";
   char cod[]="ACCION";
   printf("\n");
   raya2();
   printf("\t\t\t\tPRACTICAS: BLOQUE DE ACCIONES\n");
   raya2();
   printf(" %-6s\t\t%12s\n",num,cod);
   raya1();
   printf(" [0]\t\tFINALIZAR\n");
   printf(" [1].\t\tGUARDAR/ARCHIVAR LA ESTRUCTURA\n");
   printf(" [2].\t\tLEER LA ESTRUCTURA ARCHIVADA\n");
   printf(" [3].\t\tSE VISUALIZAN LOS DATOS DE LAS PRACTICAS\n");
   printf(" [4].\t\tSE BUSCARA UNA PRACTICA POR SU CODIGO\n");
   printf(" [5].\t\tSE BUSCARA UNA PRACTICA POR SU CODIGO DE ALUMNO\n");
   printf(" [6].\t\tSE ORDENARAN LAS PRACTICAS POR CODIGO DE ALUMNO\n");
   printf(" [7].\t\tSE ELIMINAR DE LA ESTRUCTURA LA PRACTICA INDICADA\n");
   printf(" [8].\t\tSE AGREGA UN CONJUNTO DE PRACTICAS A LA MALLA\n");
   printf(" [9].\t\tSE AGREGA UNA PRACTICA A LA MALLA\n");
   printf(" [10].\t\tSE EDITA UN VALOR DE LA ESTRUCTURA\n");
   raya1();
}

void crearVectorPractica(PRACTICA *x,int *dx){
   *dx=-1;
}
void leerDatosPractica(PRACTICA *x, int *dx){
   int i=0, n;
   printf("Ingrese la cantidad de practicas que se van a crear ---> ");
   scanf("%d", &n);
   if(n<MAX_C){
      while(i<n){
         fflush(stdin);
         printf("Codigo del alumno %d: \n ", i+1);
         gets((x+i)->codAlu);
         printf("Codigo del curso : \n", i+1);
         gets((x+i)->codCurso);
         for(int j=0;j<10;j++){
            printf("Practica [%d] : ",j+1);
            scanf("%f",&(x+i)->praCt[j]);
         }
         i=i+1;
      }
      *dx=i;
   }
   else{
      printf("Dimension fuera de rango...\n");
   }
}

void mostrarPractica(PRACTICA *x, int dx){
   system("cls");
   int i=0;
   if(dx>0){
      encabezado();
      while(i<dx){
         printf("%3d\t%5s\t%12s   ",i+1,(x+i)->codAlu,(x+i)->codCurso);
         printf("[");
         for(int j=0;j<10;j++){
            printf("%-4.1f  ",(x+i)->praCt[j]);
         }
         printf("\b\b]");
         printf("\n");
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

void buscarPorCodigoC(PRACTICA *x,int dx){
   PRACTICA aux;
   int i=0;

   fflush(stdin);
   printf("\nIngrese el codigo del curso: ");
   gets(aux.codCurso);

   strupr(aux.codCurso);
   bool encontrado=0;
   if(dx==0){
      printf("Vector vaciooo......");
   }
   else{
      while(i<dx){
         if(strcmp(aux.codCurso,(x+i)->codCurso)==0){
            encontrado=1;
            printf("El dato buscado pertenece al vector\n");
            printf("\n\nLos datos del codigo de alumno son: \n\n");
            encabezado();
            printf("%3d\t%5s\t%12s%28.1f\n",i+1,(x+i)->codAlu,(x+i)->codCurso);
            for(int j=0;j<10;j++){
               printf("%.1f ",(x+i)->praCt[j]);
            }
            raya1();
            printf("\n");
            break;
         }
         i++;
      }
   }
   if(!encontrado){
      printf("El dato no pertenece al vector\n");
   }
}

void buscarPorCodigoA(PRACTICA *x,int dx){
   PRACTICA aux;
   int i=0;

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
            printf("El dato buscado pertenece al vector\n");
            printf("\n\nLos datos del codigo de curso son: \n\n");
            encabezado();
            printf("%3d\t%5s\t%12s%28.1f\n",i+1,(x+i)->codAlu,(x+i)->codCurso);
            for(int j=0;j<10;j++){
               printf("%.1f ",(x+i)->praCt[j]);
            }
            raya1();
            printf("\n");
            break;
         }
         i++;
      }
   }
    if(!encontrado){
      printf("El dato no pertenece al vector\n");
   }
}

void ordenarCodigoA(PRACTICA x[],int dx){
   int i,j;
   PRACTICA tempo;
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

void ordenarCodigoAD(PRACTICA x[],int dx){
   int i,j;
   PRACTICA tempo;
   for (i = 0;i < dx; i++){
      for(j=0;j<dx-1;j++){
         if(strcmp(x[j].codAlu,x[j+1].codAlu)<0){
            tempo = x[j];
            x[j] = x[j+1];
            x[j+1] = tempo;
         }
      }
   }
}

void EliminarPractica(PRACTICA x[], int *dx){
   PRACTICA aux;
   int i=0,a;
   fflush(stdin);
   printf("\nIngrese el codigo de alumno a eliminar nota de practicas: ");
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
            strcpy((x+i)->codCurso,"\0");
            strcpy((x+i)->codAlu,"\0");
            for(int j=0;j<10;j++){
               (x+i)->praCt[j]=0;
            }
            ordenarCodigoAD(x,a);
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

void adicionaDato(PRACTICA *x,int *dx, PRACTICA dato){
   int n;
   n=*dx;

   if(n<0){
        strcpy((x+0)->codCurso,dato.codCurso);
        strcpy((x+0)->codAlu,dato.codAlu);
        for(int j=0;j<10;j++){
         (x+0)->praCt[j]=dato.praCt[j];
        }
        *dx=1;
   }
   else{
      n=*dx;
      n=n+1;
      if(n<MAX_C){
         strcpy((x+n-1)->codCurso,dato.codCurso);
         //puts((x+n-1)->codCurso);
         strcpy((x+n-1)->codAlu,dato.codAlu);
         //puts((x+n-1)->codAlu);
         for(int j=0;j<10;j++){
            (x+n-1)->praCt[j]=dato.praCt[j];
         }
         *dx=n;
      }
      else{
         printf("Vector llenooo...\n\n");
      }
   }
}

void adicionaDato2(PRACTICA *x,int *dx, PRACTICA y[], int dy)
{
   int i=0,n;
   n=*dx;

   if(n<0){
      for(i=0;i<dy;i++){
         strcpy((x+i)->codCurso,y[i].codCurso);
         strcpy((x+i)->codAlu,y[i].codAlu);
         for(int j=0;j<10;j++){
            (x+i)->praCt[j]=y[i].praCt[j];
         }
         i=i+1;
      }
      *dx=dy;
   }

   else{
      n=*dx;
      if(n<MAX_C){
         for(i=0;i<dy;){
            strcpy((x+n)->codCurso,y[i].codCurso);
            strcpy((x+n)->codAlu,y[i].codAlu);
            for(int j=0;j<10;j++){
               (x+i)->praCt[j]=y[i].praCt[j];
            }
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

void editarPractica(PRACTICA *x, int dx)
{
   PRACTICA aux;
   int i=0,op;

   encabezado2();

   printf("\nIndique lo que desea editar: ");
   scanf("%d",&op);
   while(op<0 || op>3){
      printf("\nIndique una opcion valida: ");
      scanf("%d",&op);
   }
   bool busc=0;
   switch (op) {
        case 1:
            fflush(stdin);
            printf("\nIngrese el codigo del curso: ");
            gets(aux.codCurso);
            strupr(aux.codCurso);
            if(dx==0){
                printf("Vector vaciooo......");
            }
            else{
                while(i<dx) {
                    if(strcmp(aux.codCurso,(x+i)->codCurso)==0){
                        busc=1;
                        printf("Ingrese el nuevo codigo: \n");
                        gets((x+i)->codCurso);
                        break;
                    }
                    i++;
                }
            }
            if(!busc){
                printf("El dato no pertenece al vector\n");
            }
            break;
        case 2:
            fflush(stdin);
            printf("\nIngrese el codigo del alumno: ");
            gets(aux.codAlu);
            if(dx==0){
                printf("Vector vaciooo......");
            }
            else{
                while(i<dx) {
                    if(stricmp(aux.codAlu,(x+i)->codAlu)==0){
                        busc=1;
                        printf("Ingrese el nuevo codigo del alumno: \n");
                        gets((x+i)->codAlu);
                        break;
                    }
                    i++;
                }
            }
            if(!busc){
                printf("El dato no pertenece al vector\n");
            }
            break;
        case 3:
            fflush(stdin);
            printf("\nIngrese el codigo del alumno: ");
            gets(aux.codAlu);
            if(dx==0){
                printf("Vector vaciooo......");
            }
            else{
                while(i<dx) {
                    if(stricmp(aux.codAlu,(x+i)->codAlu)==0){
                        busc=1;
                        for(int j=0;j<10;j++){
                           printf("Ingrese la nueva practica [%d]: \n",j+1);
                           scanf("%d",&(x+i)->praCt[j]);
                        }
                        break;
                    }
                    i++;
                }
            }
            if(!busc){
                printf("El dato no pertenece al vector\n");
            }
            break;
    }
}

void Archivar(FILE *F, PRACTICA RegistroP[MAX_C], int dx){

   F = fopen("Practicas.dat","w");
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
   printf("\n *--- PRACTICAS ARCHIVADAS ---*\n\n");
   system("pause");
}

void Leer(FILE *G, PRACTICA A){
   int i=1;
   G = fopen("Practicas.dat","rb");
   if(G == NULL){
      cout << "\n\n\n\rNo existe el archivo !!!\n";
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      getch();
   }
   fread(&A, sizeof(A), 1, G);
   system("cls");

   encabezado();

   while(!feof(G)){
      printf("%3d\t%5s\t%12s\t\t",i,A.codAlu, A.codCurso);
      printf("[");
      for(int j=0;j<10;j++){
         printf("%-4.1f ",A.praCt[j]);
      }
      printf("\b]\n\n");
      fread(&A,sizeof(A),1,G);
      i++;
   }
   fclose(G);
   cout << "\n\r---------------------------------------------------------------------------------------------------";
   cout << "\n\rFin del listado !!!\n";
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>\n";
   system("pause");
}
