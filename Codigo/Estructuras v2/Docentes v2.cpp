/*
 * nomPrograma: Cursos v2
 * descripcion:
 *
 *
 * autor: Chávez Farro, Luis André
 *        Espinola Ravello, Annie Katerine
 *        Reyes De la Cruz, Andrés Eduardo
 *        Silva Barra, Ernesto Franco
 *        Tocto Mallqui, Alexis
 * fecha:
 */

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX_C 20

using namespace std;
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

int  MenuPRINCIPAL();
void encabezado1();
void MenuEditar();
void raya1();
void raya2();

void MostrarRegistro(FILE *I, Docente RegistroD);
void BuscarRegistro(FILE *I,Docente RegistroD);
void EliminarRegistro(FILE *I, FILE *J,struct Docente RegistroD);
void EditarRegistro(FILE *I ,FILE *J,struct Docente RegistroD);


int main()
{
   int op;
   FILE *I;
   FILE *J;
   Docente RegistroD;
   MenuPRINCIPAL();
   do{
      do{
         cout<<"Ingrese opcion [ ]"<<"\b\b";
         cin>>op;
      }while(op<0 || op>8);

      switch(op){
         case 1 : MostrarRegistro(I,RegistroD);
                  break;
         case 2 : BuscarRegistro(I,RegistroD);
                  break;
         case 3 : EliminarRegistro(I,J,RegistroD);
                  break;
         case 4 : EditarRegistro(I,J,RegistroD);
                  break;
      }
      system("cls");
      MenuPRINCIPAL();
   }while(op != 0);
   system("pause");
   return(0);
}

int  MenuPRINCIPAL()
{
   system("cls");
   cout << "\n\r A R C H I V O    D E    C U R S O S";
   cout << "\n\r  * Proyecto Final  Algoritmica I * ";
   cout << "\n\n\n\r 0.- TERMINAR";
   cout << "\n\r [1] LECTURA DEL ARCHIVO CURSOS";
   cout << "\n\r [2] BUSQUEDA POR CODIGO";
   cout << "\n\r [3] ELIMINAR UN CURSO";
   cout << "\n\r [4] EDITAR UN CURSO";
   printf("\n");
}

void encabezado1(){
   system("cls");
   char title[]="\tREPORTE DE DOCENTES";
   char num[]="NRO.";
   char cod[]="CODIGO";
   char nom[]="DOCENTE";
   char escuela[]="ESCUELA";
   char curso[]="CURSO";
   char peso[]="PESO";
   raya2();
   printf("\t\t%s\n",title);
   raya2();
   printf("%s\t%-12s%-25s\t\t%5s\t\t%s%15s\n",num,cod,nom,escuela,peso,curso);
   raya1();
}

void MenuEditar(){
   system("cls");
   cout << "\n\r A R C H I V O    D E    D O C E N T E S";
   cout << "\n\r  OPCIONES DE EDICION ";
   cout << "\n\n\n\r 0.- TERMINAR";
   cout << "\n\r [1] EDITAR CODIGO DEL DOCENTE";
   cout << "\n\r [2] EDITAR NOMBRE DEL DOCENTE";
   cout << "\n\r [3] EDITAR ESCUELA DEL DOCENTE";
   cout << "\n\r [4] EDITAR PESO DEL DOCENTE";
   printf("\n");
}

void raya1(){
   printf("-------------------------------------------------------------------------------------------\n");
}

void raya2(){
   printf("===========================================================================================\n");
}


void MostrarRegistro(FILE *I, Docente RegistroD){
   int i=0;
   I=fopen("Docentes.dat","a+");
   if(I==NULL){
      cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO"<<endl;
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      system("pause");
      exit(1);
   }

   fread(&RegistroD,sizeof(RegistroD),1,I);

   encabezado1();

   while(!feof(I)){
      printf("\n%3d\t%d\t%-30s\t%s\t%10.1f\t%s\n",i+1,RegistroD.codDoc,RegistroD.nomDoc,RegistroD.escuela,RegistroD.peso,RegistroD.curso->nomC);
      fread(&RegistroD,sizeof(RegistroD),1,I);
      i++;
   }

   fclose(I);
   raya1();
   cout << "\n\rFin del listado !!!\n";
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
   getch();
   return;
}


void BuscarRegistro(FILE *I,Docente RegistroD){

   system("cls");
   int Codigo;
   int i=0;
   printf("\n\rIngrese el codigo del curso a buscar ---> ");
   fflush(stdin);
   scanf("%d",&Codigo);

   encabezado1();

   I=fopen("Docentes.dat","a+");
   if(I==NULL){
      cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO"<<endl;
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      system("pause");
      exit(1);
   }
   while(!feof(I)){
      if(RegistroD.codDoc==Codigo){
         printf("\n%3d\t%d\t%-30s\t%s\t%10.1f\t%s\n",i+1,RegistroD.codDoc,RegistroD.nomDoc,RegistroD.escuela,RegistroD.peso,RegistroD.curso->nomC);
      }
      i++;
      fread(&RegistroD,sizeof(RegistroD),1,I);
   }

   fclose(I);
   cout << "\n\r----------------------------------------------------------------";
   cout << "\n\rFin del listado !!!\n";
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
   getch();
   return;
}

void EliminarRegistro(FILE *I ,FILE *J,struct Docente RegistroD){

   system("cls");
   int i=0,Hallado=0,remo,rena;
   int Codigo;

   printf("\n\rIngrese el codigo del curso a eliminar ---> ");
   scanf("%d",&Codigo);


   I=fopen("Docentes.dat","r+");
   if(I==NULL){
      cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO"<<endl;
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      system("pause");
      exit(1);
   }

   J=fopen("Temporal.dat","a+");
   if(J==NULL){
      cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO"<<endl;
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      system("pause");
      exit(1);
   }

   encabezado1();

   fread(&RegistroD,sizeof(RegistroD),1,I);

   while(!feof(I)){
      if(RegistroD.codDoc==Codigo){
         Hallado=1;
         printf("\n%3d\t%d\t%-30s\t%s\t%10.1f\t%s\n",i+1,RegistroD.codDoc,RegistroD.nomDoc,RegistroD.escuela,RegistroD.peso,RegistroD.curso->nomC);
      }
      else{
         fwrite(&RegistroD,sizeof(RegistroD),1,J);
      }
      i++;
      fread(&RegistroD,sizeof(RegistroD),1,I);
   }

   fclose(I);
   fclose(J);

   remo=remove("Docentes.dat");

   rena=rename("Temporal.dat","Docentes.dat");

   if(Hallado==0){
      cout<<"\n\rERROR: EL  CODIGO NO EXISTE..."<<endl;
   }
   else{
      cout<<"\n\rSE ELIMINO EL REGISTRO CON EXITO"<<endl;
   }
   cout << "\n\r----------------------------------------------------------------";
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
   getch();
   return;

}

void EditarRegistro(FILE *I ,FILE *J,struct Docente RegistroD){

   system("cls");
   int i=0,Hallado=0,remo,rena,op;
   int Codigo;

   printf("\n\rIngrese el codigo del curso a eliminar ---> ");
   scanf("%d",&Codigo);


   I=fopen("Docentes.dat","r+");
   if(I==NULL){
      cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO"<<endl;
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      system("pause");
      exit(1);
   }

   J=fopen("Temporal2.dat","a+");
   if(J==NULL){
      cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO"<<endl;
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      system("pause");
      exit(1);
   }

   encabezado1();

   fread(&RegistroD,sizeof(RegistroD),1,I);

   while(!feof(I)){
      if(RegistroD.codDoc==Codigo){
         Hallado=1;
         printf("\n%3d\t%d\t%-30s\t%s\t%10.1f\t%s\n",i+1,RegistroD.codDoc,RegistroD.nomDoc,RegistroD.escuela,RegistroD.peso,RegistroD.curso->nomC);
         MenuEditar();
         do{
            do{
               cout<<"\NIngrese opcion [ ]"<<"\b\b";
               cin>>op;
            }while(op<0 || op>8);

            switch(op){
               case 1 : printf("Nuevo codigo --> ");
                        scanf("%d",&RegistroD.codDoc);
                        encabezado1();
                        printf("\n%3d\t%d\t%-30s\t%s\t%10.1f\t%s\n",i+1,RegistroD.codDoc,RegistroD.nomDoc,RegistroD.escuela,RegistroD.peso,RegistroD.curso->nomC);
                        cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
                        system("pause");
                        break;
               case 2 : fflush(stdin);
                        printf("Nuevo nombre --> ");
                        gets(RegistroD.nomDoc);
                        encabezado1();
                        printf("\n%3d\t%d\t%-30s\t%s\t%10.1f\t%s\n",i+1,RegistroD.codDoc,RegistroD.nomDoc,RegistroD.escuela,RegistroD.peso,RegistroD.curso->nomC);
                        cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
                        system("pause");
                        break;
               case 3 : fflush(stdin);
                        printf("Nueva escuela --> ");
                        gets(RegistroD.escuela);
                        encabezado1();
                        printf("\n%3d\t%d\t%-30s\t%s\t%10.1f\t%s\n",i+1,RegistroD.codDoc,RegistroD.nomDoc,RegistroD.escuela,RegistroD.peso,RegistroD.curso->nomC);
                        cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
                        system("pause");
                        break;
               case 4 : fflush(stdin);
                        printf("Nuevo peso --> ");
                        scanf("%f",&RegistroD.peso);
                        encabezado1();
                        printf("\n%3d\t%d\t%-30s\t%s\t%10.1f\t%s\n",i+1,RegistroD.codDoc,RegistroD.nomDoc,RegistroD.escuela,RegistroD.peso,RegistroD.curso->nomC);
                        cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
                        system("pause");
                        break;
            }
            system("cls");
            MenuEditar();

         }while(op != 0);
         fwrite(&RegistroD,sizeof(RegistroD),1,J);
      }
      else{
         fwrite(&RegistroD,sizeof(RegistroD),1,J);
      }
      i++;
      fread(&RegistroD,sizeof(RegistroD),1,I);
   }

   fclose(I);
   fclose(J);

   remo=remove("Docentes.dat");

   rena=rename("Temporal2.dat","Docentes.dat");

   if(Hallado==0){
      cout<<"\n\rERROR: EL  CODIGO NO EXISTE..."<<endl;
   }
   else{
      cout<<"\n\rSE EDITO EL REGISTRO CON EXITO"<<endl;
   }
   cout << "\n\r----------------------------------------------------------------";
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
   getch();
   return;

}

