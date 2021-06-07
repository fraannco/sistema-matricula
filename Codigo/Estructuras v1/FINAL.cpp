/*
 * nomPrograma: FINAL.cpp
 * descripción: Operaciones básicas usando la estructura EXFINAL.
 *              struct EXFINAL{
 *                char codAlu[10];
 *                char codCur[10];
 *                float exfin;
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

struct EXFINAL{
   char codAlu[10];
   char codCur[10];
   float exfin;
};

void crearVectorFinal(EXFINAL *x,int *dx);
void leerDatosFinal(EXFINAL *x, int *dx);
void mostrarFinal(EXFINAL *x, int dx);
void buscarPorCodigoAlumno(EXFINAL *x,int dx);
void buscarPorCodigoCurso(EXFINAL *x,int dx);
void adicionaDato2(EXFINAL *x,int *dx, EXFINAL y[], int dy);
void adicionaDato(EXFINAL *x,int *dx, EXFINAL dato);
void EliminarFinalAlumno(EXFINAL x[], int *dx);
void ordenarCodigoAlumno(EXFINAL x[],int dx);
void ordenarCodigoCurso(EXFINAL x[],int dx);
void editarFinal(EXFINAL *x, int dx);

void Archivar(FILE *F, EXFINAL RegistroF[MAX], int dx);
void Leer(FILE *G, EXFINAL C);

void menu();
void menueditar();
void encabezado1();
void encabezado2();
void raya2();
void raya1();

int main()
{
   EXFINAL a[MAX];

   int nA, nB;
   int op;
   FILE *F;
   FILE *G;
   EXFINAL C;



   EXFINAL B[]={
      "113", "CO112", 14,
      "102", "CO111", 6,
      "115", "ST204", 8,
      "104", "PA711", 15,
      "109", "PA712", 15,
      "120", "CO111", 10,
   };

   EXFINAL m={"125","TS215",10};

   EXFINAL A[]={
      "100", "MA113", 11,
      "101", "MA123", 10,
      "103", "MA133", 12,
      "106", "ST202", 10,
      "108", "ST204", 11,
      "110", "PA711", 13,
      "117", "PA712", 17,
      "119", "PA713", 13,
   };

   nA=(sizeof(A)/(sizeof(int)+10*sizeof(char)+10*sizeof(char)));
   nB=(sizeof(B)/(sizeof(int)+10*sizeof(char)+10*sizeof(char)));

   //crearVectorFinal(a,&nA);
   //leerDatosFinal(a,&nA);
   //mostrarFinal(a,nA);
   menu();
   printf("\n");
   do{
      do{
         cout<<"Ingrese opcion [  ]"<<"\b\b\b";
         cin>>op;
      }while(op<0 || op>11);
      switch(op){
         case 1:  Archivar(F,A,nA);
                  break;
         case 2:  Leer(G,C);
                  break;
         case 3:  mostrarFinal(A,nA);
                  break;
         case 4:  buscarPorCodigoAlumno(A,nA);
                  break;
         case 5:  buscarPorCodigoCurso(A,nA);
                  break;
         case 6:  printf("\n\n- Se agregara una unica nota de exam final -\n");
                  adicionaDato(A,&nA,m);
                  mostrarFinal(A,nA);
                  break;
         case 7:  printf("\n\nConjunto de notas del examen final que se van a anadir: \n");
                  mostrarFinal(B,nB);
                  printf("\n");
                  adicionaDato2(A,&nA,B,nB);
                  mostrarFinal(A,nA);
                  break;
         case 8:  EliminarFinalAlumno(A,&nA);
                  mostrarFinal(A,nA);
                  break;
         case 9:  ordenarCodigoAlumno(A,nA);
                  mostrarFinal(A,nA);
                  break;
         case 10: ordenarCodigoCurso(A,nA);
                  mostrarFinal(A,nA);
                  break;
         case 11: editarFinal(A,nA);
                  mostrarFinal(A,nA);
                  break;
      }
      menu();
   }while(op!=0);
   system("pause");
   return(0);
}

void crearVectorFinal(EXFINAL *x,int *dx){
   *dx=-1;
}

void leerDatosFinal(EXFINAL *x, int *dx){
   int i=0, n;
   printf("Ingrese la cantidad de notas que ingresara ---> ");
   scanf("%d", &n);
   if(n<MAX){
      while(i<n){
         fflush(stdin);
         printf("Codigo del alumno %d: \n", i+1);
         gets((x+i)->codAlu);
         printf("Codigo del curso  : ");
         gets((x+i)->codCur);
         printf("Nota del examen final: ");
         scanf("%f", &(x+i)->exfin);
         i=i+1;
      }
     *dx=i;
   }
   else{
     printf("Dimension fuera de rango...\n");
   }
}

void mostrarFinal(EXFINAL *x, int dx){
   system("cls");
   int i=0;
   if(dx>0){
      encabezado2();
      while(i<dx){
         printf("%3d\t%5s\t%12s%28.1f\n",i+1,(x+i)->codAlu,(x+i)->codCur,(x+i)->exfin);
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

void buscarPorCodigoAlumno(EXFINAL *x,int dx){
   EXFINAL aux;
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
            printf("\n\n-- El dato buscado pertenece al vector --\n\n");
            printf("\n\nLos datos del codigo de alumno son: \n\n");
            encabezado2();
            printf("%3d\t%5s\t%12s%28.1f\n",i+1,(x+i)->codAlu,(x+i)->codCur,(x+i)->exfin);
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

void buscarPorCodigoCurso(EXFINAL *x,int dx){
   EXFINAL aux;
   int i=0;
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
            encabezado2();
            printf("%3d\t%5s\t%12s%28.1f\n",i+1,(x+i)->codAlu,(x+i)->codCur,(x+i)->exfin);
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

void adicionaDato2(EXFINAL *x,int *dx, EXFINAL y[], int dy)
{
   int i=0,n;
   n=*dx;

   if(n<0){
      for(i=0;i<dy;i++){
         strcpy((x+i)->codAlu,y[i].codAlu);
         strcpy((x+i)->codCur,y[i].codCur);
         (x+i)->exfin=y[i].exfin;
         i=i+1;
      }
      *dx=dy;
   }

   else{
      n=*dx;
      if(n<MAX){
         for(i=0;i<dy;){
            strcpy((x+n)->codAlu,y[i].codAlu);
            puts((x+n)->codAlu);
            strcpy((x+n)->codCur,y[i].codCur);
            (x+n)->exfin=y[i].exfin;
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

void adicionaDato(EXFINAL *x,int *dx, EXFINAL dato)
{
   int n;
   n=*dx;

   if(n<0){
      strcpy((x+0)->codAlu,dato.codAlu);
      strcpy((x+0)->codCur,dato.codCur);
      (x+0)->exfin=dato.exfin;
      *dx=1;
   }
   else{
      n=*dx;
      n=n+1;
      if(n<MAX){
         strcpy((x+n-1)->codAlu,dato.codAlu);
         //puts((x+n-1)->codAlu);
         strcpy((x+n-1)->codCur,dato.codCur);
         //puts((x+n-1)->codCur);
         (x+n)->exfin=dato.exfin;
         *dx=n;
      }
      else{
         printf("Vector llenooo...\n\n");
      }
   }
}

void EliminarFinalAlumno(EXFINAL x[], int *dx){
   EXFINAL aux;
   int i=0,a;
   fflush(stdin);
   printf("\nIngrese el codigo de alumno a eliminar: ");
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
            (x+i)->exfin=0;
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

void ordenarCodigoAlumno(EXFINAL x[],int dx){
   int i,j;
   EXFINAL tempo;
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

void ordenarCodigoCurso(EXFINAL x[],int dx){
   int i,j;
   EXFINAL tempo;
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

void editarFinal(EXFINAL *x, int dx) {
   EXFINAL aux;
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
            printf("\n\n-- El dato buscado pertenece al vector --\n\n");
            printf("\n\nLos datos del codigo buscado son: \n\n");
            encabezado2();
            printf("\n%3d\t%s\t%-30s\t%10.1f\n",i+1,(x+i)->codAlu,(x+i)->codCur,(x+i)->exfin);
            printf("\n");
            menueditar();
            do{
               cout<<"\n\tIngrese lo que desea editar [ ]"<<"\b\b";
               cin>>opc;
               switch(opc){
                  case 1:
                     fflush(stdin);
                     printf("\tIngrese el nuevo codigo de alumno: ");
                     gets((x+i)->codAlu);
                     break;
                  case 2:
                     fflush(stdin);
                     printf("\tIngrese el nuevo codigo de curso: ");
                     gets((x+i)->codCur);
                     break;
                  case 3:
                     printf("\tIngrese la nueva nota del examen final: ");
                     scanf("%f",&(x+i)->exfin);
                     break;
               }
               menueditar();
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

void menueditar(){
   system("cls");
   cout << "\t E D I C I O N";
   cout << "\n\t* Proyecto Final  Algoritmica I * \n";
   cout << "\n\t 0.- TERMINAR";
   cout << "\n\t [1] SE EDITARA EL CODIGO";
   cout << "\n\t [2] SE EDITARA EL CURSO";
   cout << "\n\t [3] SE EDITARA LA NOTA";
}


void encabezado1(){
   //system("cls");
   char title[]="\tREPORTE DE NOTAS DEL PARCIAL";
   char cod[]="COD.ALUM";
   char nom[]="COD.CURSO";
   char nota[]="NOTA";
   printf("\n");
   raya2();
   printf("\t\t%s\n",title);
   raya2();
   printf("%-13s%-31s%-5s\n",cod,nom,nota);
   raya1();
}

void encabezado2(){
   //system("cls");
   char title[]="\tREPORTE DE NOTAS DEL EXAMEN FINAL";
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

void raya2(){
   printf("============================================================================\n");
}

void raya1(){
   printf("----------------------------------------------------------------------------\n");
}

void menu(){
   system("cls");
   char title[]="FINAL: BLOQUE DE ACCIONES";
   int op;
   char s;
   char num[]="OPCION";
   char cod[]="ACCION";
   printf("\n");
   printf("%s\n",title);
   raya2();
   printf("\t%-6s\t\t%-12s\n",num,cod);
   raya1();
   printf("\t[0]\t\tTERMINAR\n");
   printf("\t[1]\t\tSE ARCHIVARA(SALVAR) LOS EXAMENES FINALES\n");
   printf("\t[2]\t\tSE LEERA(RECUPERAR) EL ARCHIVO DE LOS EXAMENES FINALES\n");
   printf("\t[3]\t\tSE VISUALIZARA LA MALLA DECURSOS\n");
   printf("\t[4]\t\tSE BUSCARA POR CODIGO DE ALUMNO\n");
   printf("\t[5]\t\tSE BUSCARA POR CODIGO DE CURSO\n");
   printf("\t[6]\t\tSE ADICIONA UNA NOTA DEL EXAM FINAL\n");
   printf("\t[7]\t\tSE ADICIONA UN CONJUNTO DE NOTAS FINALES\n");
   printf("\t[8]\t\tSE ELIMINA DE LA ESTRUCTURA EL EXAMEN FINAL INDICADO\n");
   printf("\t[9]\t\tSE ORDENARAN POR CODIGO DE ALUMNO\n");
   printf("\t[10]\t\tSE ORDENARAN POR CODIGO DE CURSO\n");
   printf("\t[11]\t\tSE EDITARA UN VALOR DE LA ESTRUCTURA\n");
   raya1();
}

void Archivar(FILE *F, EXFINAL RegistroF[MAX], int dx){

   F = fopen("Finales.dat","w");
   int i=0;
   if (F == NULL){
      printf("No se puede abrir el archivo\n");
      exit(1);
   }
   while(i<dx){
      fwrite(&RegistroF[i], sizeof(RegistroF[i]), 1, F);
      i++;
   }
   fclose(F);
   printf("\n *--- EXAMENES FINALES ARCHIVADOS ---*\n\n");
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>\n";
   getch();
}

void Leer(FILE *G, EXFINAL C){

   G = fopen("Finales.dat","rb");
   if(G == NULL){
      cout << "\n\n\n\rNo existe el archivo !!!\n";
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      getch();
   }
   cout << "\n\r================================================================";
   cout << "\n\r CODIGO         COD CURSO                       NOTA";
   cout << "\n\r----------------------------------------------------------------";
   fread(&C, sizeof(C), 1, G);
   while(!feof(G)){
      printf("\n\r %6s\t\t%-30s\t%-4.1f\t",C.codAlu, C.codCur, C.exfin);
      fread(&C,sizeof(C),1,G);
   }
   fclose(G); // Cierra el archivo ALUMNOS
   cout << "\n\r----------------------------------------------------------------";
   cout << "\n\rFin del listado !!!\n";
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>\n";
   getch();

}

