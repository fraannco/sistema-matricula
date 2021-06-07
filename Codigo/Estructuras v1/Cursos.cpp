/*
 * nomPrograma: OpBasicasCURSOS.cpp
 * descripción: Operaciones básicas usando la estructura CURSOS.
 *             struct CURSOS{
 *                char codC[10];
 *                char nomC[40];
 *                int creditC;
 *                char sist_calif[2];
 *             };
 * autores: Chávez Farro, Luis André
 *          Espinola Ravello, Annie Katerine
 *          Reyes De la Cruz, Andrés Eduardo
 *          Silva Barra, Ernesto Franco
 *          Tocto Mallqui, Alexis
 * fecha: 2/09/2020
 */

 struct CURSOS{
   char codC[10];
   char nomC[40];
   int creditC;
   char sist_calif[2];
};


#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_C 20

void crearVectorCurso(CURSOS *x,int *dx);
void leerDatosCurso(CURSOS *x, int *dx);
void mostrarCursos(CURSOS *x, int dx);
void buscarPorCodigoC(CURSOS *x,int dx);
void buscarPorNombreC(CURSOS *x,int dx);
void ordenarNombre(CURSOS x[],int dx);
void adicionaDato(CURSOS *x,int *dx, CURSOS dato);
void adicionaDato2(CURSOS *x,int *dx, CURSOS y[], int dy);
void EliminarCurso(CURSOS x[], int *dx);
void editarCurso(CURSOS *x, int dx);

void Archivar(FILE *F, CURSOS RegistroC[MAX_C], int dx);
void Leer(FILE *G, CURSOS A);

void menu();
void encabezado1();
void encabezado2();
void raya2();
void raya1();

using namespace std;

int main()
{
   CURSOS InsertCurso[MAX_C];
   int nC,nD,nic,nDoc;
   int op;

   CURSOS A;

   CURSOS C[]={
      "CO111", "Calculo I", 4,"F",
      "CO112", "Calculo II", 4, "G",
      "CO113", "Calculo III", 4, "F",
      "FS116", "Fisica I", 4, "G",
      "FS116", "Fisica II", 4, "G",
      "FS116", "Fisica III", 4, "G",
   };

   CURSOS D[]={
      "MA113", "Matematica I", 4,"F",
      "MA123", "Matematica II", 4, "G",
      "MA133", "Matematica III", 6, "F",
      "ST202", "Prog. estructurada", 4, "F",
      "ST204", "Prog. o. a objetos", 4, "F",
      "PA711", "Inv. operativa I", 3, "F",
      "PA712", "Inv. operativa II", 3, "G",
      "PA713", "Inv. operativa III", 3, "G",
   };
   CURSOS m={"OA201", "Organizacion y Adiministracion", 3, "G"};

   nC=(sizeof(C)/(sizeof(int)+40*sizeof(char)+10*sizeof(char)+2*sizeof(char)));
   nD=(sizeof(D)/(sizeof(int)+40*sizeof(char)+10*sizeof(char)+2*sizeof(char)));
   char c='S';
   FILE *F;
   FILE *G;
   //crearVectorCurso(InsertCurso,&nic);
   //leerDatosCurso(InsertCurso,&nic);
   //mostrarCursos(InsertCurso,nic);
   menu();
   do{
      do{
         cout<<"Ingrese opcion [  ]"<<"\b\b\b";
         cin>>op;
      }while(op<0 || op>10);
      switch(op){
         case 1:  Archivar(F,D,nD);
                  break;
         case 2:  Leer(G,A);
                  break;
         case 3:  mostrarCursos(D,nD);
                  break;
         case 4:  buscarPorCodigoC(D,nD);
                  break;
         case 5:  buscarPorNombreC(D,nD);
                  break;
         case 6:  ordenarNombre(D,nD);
                  mostrarCursos(D,nD);
                  break;
         case 7:  EliminarCurso(D,&nD);
                  mostrarCursos(D,nD);
                  break;
         case 8:  mostrarCursos(C,nC);
                  adicionaDato2(D,&nD,C,nC);
                  mostrarCursos(D,nD);
                  break;
         case 9:  adicionaDato(D,&nD,m);
                  mostrarCursos(D,nD);
                  break;
         case 10: editarCurso(D,nD);
                  mostrarCursos(D,nD);
                  break;
         }
      menu();
   }while(op!=0);
   system("pause");
   return(0);
}

void encabezado1(){
   system("cls");
   char title[]="\tREPORTE DE CURSOS";
   char num[]="NUMERO";
   char cod[]="CODIGO";
   char nom[]="CURSO";
   char credito[]="CREDITO";
   char sist_calif[]="SIST. CALIF.";
   printf("\n");
   raya2();
   printf("\t\t%s\n",title);
   raya2();
   printf("%-12s%-32s%-5s %15s\n",cod,nom,credito,sist_calif);
   raya1();
}

void encabezado2(){
   system("cls");
   char title[]="\tREPORTE DE CURSOS";
   char num[]="NUMERO";
   char cod[]="CODIGO";
   char nom[]="CURSO";
   char credito[]="CREDITO";
   char sist_calif[]="SIST. CALIF.";
   printf("\n");
   raya2();
   printf("\t\t%s\n",title);
   raya2();
   printf("%-6s\t%-12s%-32s%-5s %15s\n",num,cod,nom,credito,sist_calif);
   raya1();
}

void encabezado3(){
   system("cls");
   cout << "\n\n\r E D I C I O N";
   cout << "\n* Proyecto Final  Algoritmica I * \n";
   cout << "\n\r 0.- TERMINAR";
   cout << "\n\r [1] SE EDITARA EL CODIGO";
   cout << "\n\r [2] SE EDITARA EL NOMBRE";
   cout << "\n\r [3] SE EDITARA EL CREDITO";
   cout << "\n\r [4] SE EDITARA EL SISTEMA DE CALIFICACION";
}

void raya2(){
   printf("============================================================================\n");
}

void raya1(){
   printf("----------------------------------------------------------------------------\n");
}

void menu(){
   system("cls");
   char title[]="CURSOS: BLOQUE DE ACCIONES";
   int op;
   char s;
   char num[]="OPCION";
   char cod[]="ACCION";
   printf("\n");
   printf("%s\n",title);
   raya2();
   printf(" %-6s\t\t%-12s\n",num,cod);
   raya1();
   printf(" [0]\t\tFINALIZAR\n");
   printf(" [1]\t\tSE ARCHIVARA A LOS CURSOS\n");
   printf(" [2]\t\tSE LEERA EL ARCHIVO DE CURSOS\n");
   printf(" [3]\t\tSE VISUALZIARA LA ESTRUCTURA CURSOS\n");
   printf(" [4]\t\tSE BUSCARA UN CURSO POR SU CODIGO\n");
   printf(" [5]\t\tSE BUSCARA UN CURSO POR SU NOMBRE\n");
   printf(" [6]\t\tSE ORDENARAN LOS CURSOS EN ORDEN ALFABETICO\n");
   printf(" [7]\t\tSE ELIMINAR DE LA ESTRUCTURA EL CURSO INDICADO\n");
   printf(" [8]\t\tSE ADICIONA UN CONJUNTO DE CURSOS A LA MALLA\n");
   printf(" [9]\t\tSE ADICIONA UN CURSO A LA MALLA\n");
   printf(" [10]\t\tSE EDITARA UN VALOR DE LA ESTRUCTURA\n");
   raya1();
}

void crearVectorCurso(CURSOS *x,int *dx){
   *dx=-1;
}
void leerDatosCurso(CURSOS *x, int *dx){
   int i=0, n;
   printf("Ingrese la cantidad de cursos que se van a crear ---> ");
   scanf("%d", &n);
   if(n<MAX_C){
      while(i<n){
         fflush(stdin);
         printf("Codigo del curso %d: \n", i+1);
         gets((x+i)->codC);
         printf("Nombre del curso  : " );
         gets((x+i)->nomC);
         printf("Credito    : ");
         scanf("%d", &(x+i)->creditC);
         fflush(stdin);
         printf("Sis. del cursos del curso  : " );
         gets((x+i)->sist_calif);
         i=i+1;
      }
      *dx=i;
   }
   else{
      printf("Dimension fuera de rango...\n");
   }
}


void mostrarCursos(CURSOS *x, int dx){
   system("cls");
   int i=0;
   if(dx>0){
      encabezado2();
      while(i<dx){
         printf("%3d\t%s\t%-30s%10.1d\t%5s\n",i+1,(x+i)->codC,(x+i)->nomC,(x+i)->creditC,(x+i)->sist_calif);
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

void buscarPorCodigoC(CURSOS *x,int dx){
   system("cls");
   CURSOS aux;
   int i=0;
   fflush(stdin);
   printf("\nIngrese el codigo del curso: ");
   gets(aux.codC);
   strupr(aux.codC);
   bool encontrado=0;
   if(dx==0){
      printf("Vector vaciooo......");
   }
   else{
      while(i<dx) {
         if(strcmp(aux.codC,(x+i)->codC)==0){
            system("cls");
            encontrado=1;
            printf("\t -- El dato buscado pertenece al vector --\n");
            printf("\n\nLos datos del curso buscado son: \n\n");
            encabezado2();
            printf("%3d\t%s\t%-30s%10.1d\t%5s\n",i+1,(x+i)->codC,(x+i)->nomC,(x+i)->creditC,(x+i)->sist_calif);
            printf("\n");
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

void buscarPorNombreC(CURSOS *x,int dx){
   system("cls");
   CURSOS aux;
   int i=0;
   fflush(stdin);
   printf("\nIngrese el nombre del curso a eliminar: ");
   gets(aux.nomC);
   bool encontrado=0;
   if(dx==0){
      printf("Vector vaciooo......");
   }
   else{
      while(i<dx){
         if(stricmp(aux.nomC,(x+i)->nomC)==0){
            encontrado=1;
            system("cls");
            printf("\t -- El dato buscado pertenece al vector --\n");
            printf("\n\nLos datos del curso buscado son: \n\n");
            encabezado2();
            printf("%3d\t%s\t%-30s%10.1d\t%5s\n",i+1,(x+i)->codC,(x+i)->nomC,(x+i)->creditC,(x+i)->sist_calif);
            raya1();
            printf("\n\n");
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

void ordenarNombre(CURSOS x[],int dx){
   int i,j;
   CURSOS tempo;
   for (i = 0;i < dx; i++){
      for(j=0;j<dx-1;j++){
         if(strcmp(x[j].nomC,x[j+1].nomC)>0){
            tempo = x[j];
            x[j] = x[j+1];
            x[j+1] = tempo;
         }
      }
   }
}

void ordenarNombreD(CURSOS x[],int dx){
   int i,j;
   CURSOS tempo;
   for (i = 0;i < dx; i++){
      for(j=0;j<dx-1;j++){
         if(strcmp(x[j].nomC,x[j+1].nomC)<0){
            tempo = x[j];
            x[j] = x[j+1];
            x[j+1] = tempo;
         }
      }
   }
}

void EliminarCurso(CURSOS x[], int *dx){
   system("cls");
   CURSOS aux;
   int i=0,a;
   fflush(stdin);
   printf("Ingrese el nombre del curso a eliminar: ");
   gets(aux.nomC);

   a=*dx;
   bool encontrado=0;
   if(*dx==0){
      printf("Vector vaciooo......");
   }
   else{
      while(i<*dx) {
         if(stricmp(aux.nomC,(x+i)->nomC)==0){
            encontrado=1;
            system("cls");
            printf("El dato buscado pertenece al vector\n");
            printf("La nueva lista de cursos es: ");
            strcpy((x+i)->codC,"\0");
            strcpy((x+i)->nomC,"\0");
            (x+i)->creditC=0;
            strcpy((x+i)->sist_calif,"\0");
            ordenarNombreD(x,a);
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


void adicionaDato2(CURSOS *x,int *dx, CURSOS y[], int dy){
   int i=0,n;
   n=*dx;

   if(n<0){
      for(i=0;i<dy;i++){
         strcpy((x+i)->codC,y[i].codC);
         strcpy((x+i)->nomC,y[i].nomC);
         (x+i)->creditC=y[i].creditC;
         strcpy((x+i)->sist_calif,y[i].sist_calif);
         i=i+1;
      }
      *dx=dy;
   }

   else{
      n=*dx;
      if(n<MAX_C){
         for(i=0;i<dy;){
            strcpy((x+n)->codC,y[i].codC);
            strcpy((x+n)->nomC,y[i].nomC);
            (x+n)->creditC=y[i].creditC;
            strcpy((x+n)->sist_calif,y[i].sist_calif);
            i++;
            n=n+1;
         }
         *dx=n;// Se asgina el nuevo tamaño a la estructura
         }
         else{
            printf("Vector llenooo...\n\n");
        }
   }
}


void adicionaDato(CURSOS *x,int *dx, CURSOS dato){
   system("cls");
   printf("\n- Se agregara un unico curso -\n");
   int n;
   n=*dx;

   if(n<0){
      strcpy((x+0)->codC,dato.codC);
      strcpy((x+0)->nomC,dato.nomC);
      (x+0)->creditC=dato.creditC;
      strcpy((x+0)->sist_calif,dato.sist_calif);
      *dx=1;
   }
   else{
      n=*dx;
      n=n+1;
      if(n<MAX_C){
         strcpy((x+n-1)->codC,dato.codC);
         //puts((x+n-1)->codC);
         strcpy((x+n-1)->nomC,dato.nomC);
         //puts((x+n-1)->nomC);
         (x+n)->creditC=dato.creditC;
         strcpy((x+n-1)->sist_calif,dato.sist_calif);
         *dx=n;
      }
      else{
         printf("Vector llenooo...\n\n");
      }
   }

}

void editarCurso(CURSOS *x, int dx) {
   system("cls");
   CURSOS aux;
   int i=0,opc;
   fflush(stdin);
   printf("\nIngrese el nombre del curso a editar: ");
   gets(aux.nomC);
   bool encontrado=0;
   if(dx==0){
      printf("Vector vaciooo......");
   }
   else{
      while(i<dx){
         if(stricmp(aux.nomC,(x+i)->nomC)==0){
            system("cls");
            encontrado=1;
            printf("\n-- El dato buscado pertenece al vector --\n\n");
            printf("\n\nLos datos del curso buscando buscado son: \n\n");
            encabezado2();
            printf("%3d\t%s\t%-30s%10.1d\t%5s\n",i+1,(x+i)->codC,(x+i)->nomC,(x+i)->creditC,(x+i)->sist_calif);
            printf("\n\n");
            system("pause");
            encabezado3();
            printf("\n");
            printf("Indique lo que va a editar: ");
            scanf("%d",&opc);
            fflush(stdin);
            do{
               switch(opc){
                  case 1:
                     system("cls");
                     fflush(stdin);
                     printf("Ingrese el nuevo codigo: ");
                     gets((x+i)->codC);
                     fflush(stdin);
                     break;
                  case 2:
                     system("cls");
                     fflush(stdin);
                     printf("Ingrese el nuevo nombre: ");
                     gets((x+i)->nomC);
                     fflush(stdin);
                     break;
                  case 3:
                     system("cls");
                     fflush(stdin);
                     printf("Ingrese el nuevo credito: ");
                     scanf("%d",&(x+i)->nomC);
                     fflush(stdin);
                     break;
                  case 4:
                     system("cls");
                     fflush(stdin);
                     printf("Ingrese el nuevo sist. de calificacion: ");
                     gets((x+i)->sist_calif);
                     fflush(stdin);
                     break;
               }
               encabezado3();
               printf("\nIndique lo que va a editar: ");
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

void Archivar(FILE *F, CURSOS RegistroC[MAX_C], int dx){
   F = fopen("Cursos.dat","w");
   int i=0;
   if(F == NULL){
      printf("No se puede abrir el archivo\n");
      exit(1);
   }

   while(i<dx){
      fwrite(&RegistroC[i], sizeof(RegistroC[i]), 1, F);
      i++;
   }

   fclose(F);
   printf("\n\n--- CURSOS ARCHIVADOS ---\n\n");
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>\n";
   getch();
}

void Leer(FILE *G, CURSOS A){
   system("cls");
   G = fopen("Cursos.dat","a+");
   if (G == NULL){
      printf("No se puede abrir el archivo\n");
      exit(1);
   }
   fread(&A, sizeof(A), 1, G);
   encabezado1();
   while(!feof(G)){
      printf("%s ",A.codC);
      printf("\t%-30s ",A.nomC);
      printf("%10.1d",A.creditC);
      printf("\t%5s",A.sist_calif);
      printf("\n");
      fread(&A,sizeof(A),1,G);
   };
   fclose(G);
   printf("\n\n");
   system("pause");
}
