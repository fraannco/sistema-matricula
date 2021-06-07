/*
 * nomPrograma: OpBasicasCURSOS.cpp
 * descripción: Operaciones básicas usando la estructura DOCENTES.
 *
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
#include <stdlib.h>
#define MAX_DOC 20

using namespace std;

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

void crearVectorDocente(Docente *x,int *dx);
void leerDatosDocente(Docente *x, int *dx);
void mostrarDatosDocente(Docente *x, int dx);
void mostrarDocenteCurso(Docente *x, int dx);
void buscarPorCodigoDoc(Docente *x,int dx);
void buscarPorNombreDoc(Docente *x,int dx);
void ordenarNombreAscendente(Docente x[],int dx);
void ordenarNombreDescendente(Docente x[],int dx);
void EliminarDocente(Docente x[], int *dx);
void adicionaDato(Docente *x,int *dx, Docente dato);
void adicionaDatoDocente(Docente *x,int *dx, Docente y[], int dy);
void editarDocente(Docente *x, int dx);

void Archivar(FILE *F, Docente RegistroD[MAX_DOC], int dx);
void Leer(FILE *G, Docente A);


void menu();
void encabezado1();
void encabezado2();
void encabezado4();
void encabezado3();
void raya2();
void raya1();
void raya4();
void raya5();
void raya6();
void raya7();


int main(){

   int nDoc;
   int nAux,nC,nA;
   int op;
   char c='s';
   FILE *F;
   FILE *G;
   Docente A;
   int n=1;
   Docente aux[]={
      1010,"Vargas Guerrero, Pepe","T3",42.1,{"CO111", "Calculo I", 4,"F"},
      1011,"Hinojoza Espeinola, Romario","T4",65.23,{"CO112", "Calculo II", 4, "G",},
      1012,"Parlato de la Cruz, Favio","T5",47.9,{"CO113", "Calculo III", 4, "F"},
      1013,"Del Monte Quemado, Mario","T6",72,{"FS116", "Fisica I", 4, "G"},
      1014,"Polo Quispe, Marco","T7",45,{"FS116", "Fisica II", 4, "G"},
      1015,"Washintong Quiste, George","T8",42.1,{"FS116", "Fisica III", 4, "G"},
   };

   nAux=(sizeof(aux)/(40*(sizeof(int)+40*sizeof(char)+10*sizeof(char)+2*sizeof(char))+sizeof(int)+40*sizeof(char)+10*sizeof(char)+sizeof(float)+40*sizeof(char)));

   Docente Doc[]={
      1001,"GONZALES ALE, Eva","T1",40, {"MA113", "Matematica I", 4,"F"},
      1002,"SALVADOR DATOS, Jorge","T2",67,{"MA123", "Matematica II", 4, "G"},
      1004,"MORALES ARISTO, Juan","T2",45.5,{"MA133", "Matematica III", 6, "F"},
      1005,"ROMAN RAMON, Ulises","T2",45.6,{"ST202", "Prog. estructurada", 4, "F"},
      1006,"SALMON TERONE, Luigui","T1",55,{"ST204", "Prog. o. a objetos", 4, "F"},
      1007,"OROPEZA PEREZ, Pablo","T2",75,{"PA711", "Inv. operativa I", 3, "F"},
      1008,"DIAZ OLMO, Virina","T2",55,{"PA712", "Inv. operativa II", 3, "G"},
      1009,"VENTURA LOAYZA, Evaristo","T2",45,{"PA713", "Inv. operativa III", 3, "G"},
   };

   Docente s={1003,"RODRIGUEZ POLO, Aioria","E2",40,{"OA201", "Organizacion y Adiministracion", 3, "G"}};

   nDoc=(sizeof(Doc)/(40*(sizeof(int)+40*sizeof(char)+10*sizeof(char)+2*sizeof(char))+sizeof(int)+40*sizeof(char)+10*sizeof(char)+sizeof(float)+40*sizeof(char)));

   menu();

   do{
      do{
         cout<<"Ingrese opcion [  ]"<<"\b\b\b";
         cin>>op;
      }while(op<0 || op>11);
      switch(op){
          case 1: Archivar(F,Doc,nDoc);
                  break;
         case 2:  Leer(G,A);
                  break;
         case 3:  mostrarDatosDocente(Doc,nDoc);
                  break;
         case 4:  mostrarDocenteCurso(Doc,nDoc);
                  break;
         case 5:  buscarPorCodigoDoc(Doc,nDoc);
                  break;
         case 6:  buscarPorNombreDoc(Doc,nDoc);
                  break;
         case 7:  ordenarNombreAscendente(Doc,nDoc);
                  mostrarDatosDocente(Doc,nDoc);
                  printf("\n");
                  break;
         case 8:  mostrarDatosDocente(Doc,nDoc);
                  EliminarDocente(Doc,&nDoc);
                  mostrarDatosDocente(Doc,nDoc);
                  break;
         case 9:  printf("\nConjunto de docentes que se van a agregar: \n");
                  mostrarDatosDocente(aux,nAux);
                  printf("\nConjunto de datos ya modificados: \n");
                  adicionaDatoDocente(Doc,&nDoc,aux,nAux);
                  mostrarDatosDocente(Doc,nDoc);
                  break;
         case 10: adicionaDato(Doc,&nDoc,s);
                  mostrarDatosDocente(Doc,nDoc);
                  break;
         case 11: editarDocente(Doc,nDoc);
                  mostrarDatosDocente(Doc,nDoc);
                  printf("\n");
                  break;
      }
      menu();
   }
   while(op!=0);
   return(0);
}

void encabezado1(){
   system("cls");
   char title[]="\tREPORTE DE DOCENTES";

   char cod[]="CODIGO";
   char nom[]="DOCENTE";
   char escuela[]="ESCUELA";
   char curso[]="CURSO";
   char peso[]="PESO";
   raya2();
   printf("\t\t%s\n",title);
   raya2();
   printf("%-12s%-25s%5s%15s%15s\n",cod,nom,escuela,peso,curso);
   raya1();
}

void encabezado2(){
   system("cls");
   char title[]="\tREPORTE DE DOCENTES";
   char num[]="NUMERO";
   char cod[]="CODIGO";
   char nom[]="DOCENTE";
   char escuela[]="ESCUELA";
   char curso[]="CURSO";
   char peso[]="PESO";
   raya2();
   printf("\t\t%s\n",title);
   raya2();
   printf("%-6s\t%-12s%-25s%5s%15s%15s\n",num,cod,nom,escuela,peso,curso);
   raya1();
}

void encabezado3(){
   system("cls");
   cout << "\t E D I C I O N";
   cout << "\n\t* Proyecto Final  Algoritmica I * \n";
   cout << "\n\t 0.- TERMINAR";
   cout << "\n\t [1] SE EDITARA EL CODIGO";
   cout << "\n\t [2] SE EDITARA EL NOMBRE";
   cout << "\n\t [3] SE EDITARA EL ESCUELA";
   cout << "\n\t [4] SE EDITARA EL PESO";
}

void raya4(){
   printf("=====================================================================================================================\n");
}

void raya5(){
   printf("---------------------------------------------------------------------------------------------------------------------\n");
}

void encabezado4(){
   system("cls");
   char title[]="\tREPORTE DE CURSOS";
   char num[]="NUMERO";
   char doc[]="DOCENTE";
   char cod[]="CODIGO";
   char nom[]="CURSO";
   char escuela[]="ESCUELA";
   char curso[]="CURSO";
   char peso[]="PESO";
   printf("\n");
   raya4();
   printf("\t\t%s\n",title);
   raya4();
   printf("%s\t\t%s\t\t\t%s\t\t%s\t\t\t\t\t%s\t\t%s\n",num,doc,cod,nom,peso,curso);
   raya5();
}

void raya2(){
   printf("=====================================================================================================\n");
}

void raya1(){
   printf("-----------------------------------------------------------------------------------------------------\n");
}

void raya6(){
   printf("==================================================================================\n");
}

void raya7(){
   printf("----------------------------------------------------------------------------------\n");
}

void menu(){
   system("cls");
   char title[]="DOCENTES: BLOQUE DE ACCIONES";
   int op;
   char s;
   char num[]="OPCION";
   char cod[]="ACCION";
   printf("\n");
   printf("%s\n",title);
   raya6();
   printf("\t%-6s\t\t%-12s\n",num,cod);
   raya7();
   printf("\t[1]\t\tGUARDAR/ARCHIVAR LA ESTRUCTURA\n");
   printf("\t[2]\t\tLEER LA ESTRUCTURA ARCHIVADA\n");
   printf("\t[3]\t\tSE VISUALIZAR DATOS DEL DOCENTE\n");
   printf("\t[4]\t\tSE VISUALIZARA EL DOCENTE Y LOS DATOS DEL CURSO QUE DICTA\n");
   printf("\t[5]\t\tSE BUSCARA UN DOCENTE POR SU CODIGO\n");
   printf("\t[6]\t\tSE BUSCARA UN DOCENTE POR SU NOMBRE\n");
   printf("\t[7]\t\tSE ORDENARAN LOS DOCENTES EN ORDEN ALFABETICO\n");
   printf("\t[8]\t\tSE ELIMINARA EL DOCENTE INDICADO\n");
   printf("\t[9]\t\tSE ADICIONA UN CONJUNTO DE DOCENTES\n");
   printf("\t[10]\t\tSE ADICIONA UN DOCENTE\n");
   printf("\t[11]\t\tSE EDITARA UN VALOR DE LA ESTRUCTURA DOCENTE\n");
   raya7();
}

void crearVectorDocente(Docente *x,int *dx)
{
   *dx=-1;
}
void leerDatosDocente(Docente *x, int *dx)
{
   int i=0, n;
   printf("Cuantos docentes se van a crear ---> ");
   scanf("%d", &n);
   if(n<MAX_DOC){
      while(i<n){
         fflush(stdin);
         printf("-- Docente %d --\n", i+1);

         printf("Codigo : " );
         scanf("%d", &(x+i)->codDoc);

         printf("Nombre  : " );
         fflush(stdin);
         gets((x+i)->nomDoc);

         printf("Escuela: ");
         fflush(stdin);
         gets((x+i)->escuela);

         printf("Peso: ");
         scanf("%f",&(x+i)->peso);

         fflush(stdin);
         printf("Curso que dicta: ");
         gets((x+i)->curso->nomC);

         fflush(stdin);
         printf("Codigo del curso que dicta: ");
         gets((x+i)->curso->codC);

         printf("Creditos del curso: ");
         scanf("%d",&(x+i)->curso->creditC);

         fflush(stdin);
         printf("Sistema de calificacion del curso: ");
         gets((x+i)->curso->sist_calif);
         i++;
      }
      *dx=i;
    }
   else{
      printf("Dimension fuera de rango...\n");
   }
}

void mostrarDatosDocente(Docente *x, int dx){
   system("cls");
   int i=0;
   encabezado2();
   if(dx>0){
      while(i<dx){
         printf("\n%3d\t%d\t%-30s\t%s\t%10.1f\t%s\n",i+1,(x+i)->codDoc,(x+i)->nomDoc,(x+i)->escuela,(x+i)->peso,(x+i)->curso->nomC);
         i=i+1;
      }
   }
   else{
      printf("Vector vacioooo...\n");
   }
   printf("-----------------------------------------------------------------------------------------------------\n");
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
   getch();
   return;
}

void mostrarDocenteCurso(Docente *x, int dx){
   system("cls");
   int i=0;
   encabezado4();
   if(dx>0){
      while(i<dx){
         printf("\n%3d\t%-30s%s\t\t%-30s%10.1d\t\t%s\n",i+1,(x+i)->nomDoc,(x+i)->curso->codC,(x+i)->curso->nomC,(x+i)->curso->creditC,(x+i)->curso->sist_calif);
         i=i+1;
      }
      printf("\n");
   }
   else{
      printf("Vector vacioooo...\n");
   }
   printf("---------------------------------------------------------------------------------------------------------------------\n");
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
   getch();
   return;
}


void buscarPorCodigoDoc(Docente *x,int dx){
   system("cls");
   Docente aux;
   int i=0;

   fflush(stdin);
   printf("\nIngrese el codigo del docente: ");
   scanf("%d",&aux.codDoc);
   bool encontrado=0;
   if(dx==0){
      printf("Vector vaciooo......");
   }
   else{
      while(i<dx) {
         if(aux.codDoc==(x+i)->codDoc){
            system("cls");
            encontrado=1;
            printf("-- El dato buscado pertenece al vector --\n");
            printf("\n\nLos datos del docente buscado son: \n\n");
            encabezado2();
            printf("\n%3d\t%d\t%-30s\t%s\t%10.1f\t%s\n",i+1,(x+i)->codDoc,(x+i)->nomDoc,(x+i)->escuela,(x+i)->peso,(x+i)->curso);
            raya1();
            break;
         }
         i++;
      }
   }
   if(!encontrado){
      printf("El dato no pertenece al vector\n");
   }
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
   getch();
   return;
}

void buscarPorNombreDoc(Docente *x,int dx){
   system("cls");
   Docente aux;
   int i=0;
   fflush(stdin);
   printf("\nIngrese el nombre del docente: ");
   gets(aux.nomDoc);
   bool encontrado=0;
   if(dx==0){
      printf("Vector vaciooo......");
   }
   else{
      while(i<dx){
         if(stricmp(aux.nomDoc,(x+i)->nomDoc)==0){
            system("cls");
            encontrado=1;
            printf("-- El dato buscado pertenece al vector --\n");
            printf("\n\nLos datos del docente buscado son: \n\n");
            encabezado2();
            printf("\n%3d\t%d\t%-30s\t%s\t%10.1f\t%s\n",i+1,(x+i)->codDoc,(x+i)->nomDoc,(x+i)->escuela,(x+i)->peso,(x+i)->curso);
            raya1();
            break;
         }
         i++;
      }
   }
   if(!encontrado){
      printf("El dato no pertenece al vector\n");
   }
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
   getch();
   return;
}

void ordenarNombreAscendente(Docente x[],int dx){
   int i,j;
   Docente tempo;
   for (i = 0;i < dx; i++){
      for(j=0;j<dx-1;j++){
         if(strcmp(x[j].nomDoc,x[j+1].nomDoc)>0){
            tempo = x[j];
            x[j] = x[j+1];
            x[j+1] = tempo;
         }
      }
   }
}

void ordenarNombreDescendente(Docente x[],int dx){
   int i,j;
   Docente tempo;
   for (i = 0;i < dx; i++){
      for(j=0;j<dx-1;j++){
         if(strcmp(x[j].nomDoc,x[j+1].nomDoc)<0){
            tempo = x[j];
            x[j] = x[j+1];
            x[j+1] = tempo;
         }
      }
   }
}

void EliminarDocente(Docente x[], int *dx){
   Docente aux;
   int i=0,a;
   fflush(stdin);
   system("cls");
   printf("\nE L I M I N A R   D O C E N T E\n\n");
   printf("\nIngrese el nombre del docente a eliminar: ");
   gets(aux.nomDoc);

   a=*dx;
   bool encontrado=0;
   if(*dx==0){
      printf("Vector vaciooo......");
   }
   else{
      while(i<*dx) {
         if(stricmp(aux.nomDoc,(x+i)->nomDoc)==0){
            encontrado=1;
            printf("\n-- El dato buscado pertenece al vector --\n");
            strcpy((x+i)->nomDoc,"\0");
            (x+i)->codDoc=0;
            strcpy((x+i)->nomDoc,"\0");
            strcpy((x+i)->escuela,"\0");
            (x+i)->peso=0;
            //strcpy((x+i)->curso,"\0");
            ordenarNombreDescendente(x,a);
            *dx=*dx-1;
            break;
         }
         i++;

      }
      if(!encontrado){
         printf("El dato no pertenece al vector\n");
      }
   }
}

void adicionaDato(Docente *x,int *dx, Docente dato){
   int n;
   n=*dx;

   if(n<0){
      (x+0)->codDoc=dato.codDoc;
      strcpy((x+0)->nomDoc,dato.nomDoc);
      strcpy((x+0)->escuela,dato.escuela);
      (x+0)->peso=dato.peso;
      //strcpy((x+0)->curso->nomC,dato.curso->nomC);
      *dx=1;
   }
   else{
      n=*dx;
      n=n+1;
      if(n<MAX_DOC){
         (x+n-1)->codDoc=dato.codDoc;

         strcpy((x+n-1)->nomDoc , dato.nomDoc);

         strcpy((x+n-1)->escuela,dato.escuela);
         (x+n-1)->peso=dato.peso;
         strcpy((x+n-1)->curso->nomC,dato.curso->nomC);
         strcpy((x+n-1)->curso->codC,dato.curso->codC);
         strcpy((x+n-1)->curso->sist_calif,dato.curso->sist_calif);
         (x+n-1)->curso->creditC=dato.curso->creditC;
         *dx=n;
      }
      else{
         printf("Vector llenooo...\n\n");
      }
   }
}


void adicionaDatoDocente(Docente *x,int *dx, Docente y[], int dy){

   int i=0,n;
   n=*dx;

   if(n<0){
      for(i=0;i<dy;i++){
         (x+i)->codDoc=y[i].codDoc;
         strcpy((x+i)->nomDoc,y[i].nomDoc);
         strcpy((x+i)->escuela,y[i].escuela);
         (x+i)->peso=y[i].peso;
         strcpy((x+i)->curso->codC,y[i].curso->codC);
         strcpy((x+i)->curso->nomC,y[i].curso->nomC);
         (x+i)->curso->creditC=y[i].curso->creditC;
         strcpy((x+i)->curso->sist_calif,y[i].curso->sist_calif);
         i=i+1;
      }
      *dx=dy;
   }

   else{
      n=*dx;
      if(n<MAX_DOC){
         for(i=0;i<dy;){
            (x+n)->codDoc=y[i].codDoc;
            strcpy((x+n)->nomDoc,y[i].nomDoc);
            strcpy((x+n)->escuela,y[i].escuela);
            (x+n)->peso=y[i].peso;
            strcpy((x+n)->curso->sist_calif,y[i].curso->sist_calif);
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


void editarDocente(Docente *x, int dx) {
   Docente aux;
   int i=0,opc;
   fflush(stdin);
   printf("\nIngrese el nombre del docente: ");
   gets(aux.nomDoc);
   bool encontrado=0;
   if(dx==0){
      printf("Vector vaciooo......");
   }
   else{
      while(i<dx){
         if(stricmp(aux.nomDoc,(x+i)->nomDoc)==0){
            encontrado=1;
            printf("\n-- El docente se encuentra en la estructura --\n\n");
            encabezado2();
            printf("\n%3d\t%d\t%-30s\t%s\t%10.1f\t%s\n",i+1,(x+i)->codDoc,(x+i)->nomDoc,(x+i)->escuela,(x+i)->peso,(x+i)->curso);
            raya1();
            printf("\n\n");
            system("pause");
            system("cls");
            encabezado3();
            do{
               printf("\n");
               printf("\tIndique lo que va a editar: ");
               scanf("%d",&opc);
               switch(opc){
                  case 1:
                     printf("\tIngrese el nuevo codigo: ");
                     scanf("%d",&(x+i)->codDoc);
                     break;
                  case 2:
                     fflush(stdin);
                     printf("\tIngrese el nuevo nombre: ");
                     gets((x+i)->nomDoc);
                     break;
                  case 3:
                     fflush(stdin);
                     printf("\tIngrese la nueva escuela: ");
                     gets((x+i)->escuela);
                     break;
                  case 4:
                     printf("\tIngrese el nuevo peso: ");
                     scanf("%f",&(x+i)->peso);
                     break;
                  }
                  encabezado3();
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

void Archivar(FILE *F, Docente RegistroD[MAX_DOC], int dx){
   F = fopen("Docentes.dat","w");
   int i=0;
   if (F == NULL){
      printf("No se puede abrir el archivo\n");
      exit(1);
   }
   while(i<dx){
      fwrite(&RegistroD[i], sizeof(RegistroD[i]), 1, F);
      i++;
   }
   fclose(F);
   printf("\n *--- DOCENTES ARCHIVADOS ---*\n\n");
   system("pause");
}

void Leer(FILE *G, Docente A){
   G = fopen("Docentes.dat","a+");
   if (G == NULL){
      printf("No se puede abrir el archivo\n");
      exit(1);
   }

   fread(&A, sizeof(A), 1, G);

   system("cls");
   encabezado1();
   while(!feof(G)){
      printf("%d ",A.codDoc);
      printf("\t%-30s ",A.nomDoc);
      printf("\t%5s",A.escuela);
      printf("\t%10.1f\t",A.peso);
      printf("\t%s",A.curso->nomC);
      printf("\n");
      fread(&A,sizeof(A),1,G);
   };
   fclose(G);
   printf("\n");
   system("pause");
}


