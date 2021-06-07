/*
 * nomPrograma: practica.cpp
 * descripción: Operaciones básicas usando la estructura PRACTICAS.
 *              struct PRACTICAS{
 *                char codAlu[7];
 *                char codCurso[10];
 *                float praCt;
 *              };
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
#define MAX_C 100

using namespace std;

struct PRACTICAS{
   char codAlu[7];
   char codCurso[10];
   float pract[10];
};

int  MenuPRINCIPAL();
void encabezado1();
void MenuEditar();
void raya1();
void raya2();

void MostrarRegistro(FILE *I, PRACTICAS RegistroC);
void BuscarRegistro(FILE *I, PRACTICAS RegistroC);
void EliminarRegistro(FILE *I, FILE *J,struct PRACTICAS RegistroC);
void EditarRegistro(FILE *I ,FILE *J,struct PRACTICAS RegistroC);

int main()
{
   int op;
   FILE *I;
   FILE *J;
   PRACTICAS RegistroC;
   MenuPRINCIPAL();
   do{
      do{
         cout<<"Ingrese opcion [ ]"<<"\b\b";
         cin>>op;
      }while(op<0 || op>8);

      switch(op){
         case 1 : MostrarRegistro(I,RegistroC);
                  break;
         case 2 : BuscarRegistro(I,RegistroC);
                  break;
         case 3 : EliminarRegistro(I,J,RegistroC);
                  break;
         case 4 : EditarRegistro(I,J,RegistroC);
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
   cout << "\n\r A R C H I V O    D E    P R A C T I C A S";
   cout << "\n\r  Proyecto Final Algoritmica I ";
   cout << "\n\n\n\r 0.- TERMINAR";
   cout << "\n\r [1] LECTURA DEL ARCHIVO DE PRACTICAS";
   cout << "\n\r [2] BUSQUEDA POR CODIGO";
   cout << "\n\r [3] ELIMINAR UN CURSO";
   cout << "\n\r [4] EDITAR UN CURSO";
   printf("\n");
}

void encabezado1(){
   system("cls");
   char title[]="\t\tREPORTE DE PRACTICAS";
   char num[]="NUMERO";
   char codAlumno[]="CODIGOA";
   char codCurso[]="CODIGOC";
   char notas[]="NOTAS DE PRACTICAS";
   printf("\n");
   raya2();
   printf("\t\t%s\n",title);
   raya2();
   printf("%-6s\t%-12s%-28s\t%s\n",num,codAlumno,codCurso,notas);
   raya1();
}

void MenuEditar(){
   system("cls");
   cout << "\n\r A R C H I V O    D E    P R A C T I C A S";
   cout << "\n\r  OPCIONES DE EDICION ";
   cout << "\n\n\n\r 0.- TERMINAR";
   cout << "\n\r [1] EDITAR CODIGO DEL ALUMNO";
   cout << "\n\r [2] EDITAR CODIGO DEL CURSO";
   cout << "\n\r [3] EDITAR NOTAS DE PRACTICAS";
   printf("\n");
}

void raya1(){
   printf("------------------------------------------------------------------------------------------\n");
}

void raya2(){
   printf("==========================================================================================\n");
}


void MostrarRegistro(FILE *I, PRACTICAS RegistroC){
   int i=0;
   I=fopen("Practicas.dat","a+");
   if(I==NULL){
      cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO"<<endl;
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      system("pause");
      exit(1);
   }

   fread(&RegistroC,sizeof(RegistroC),1,I);

   encabezado1();

   while(!feof(I)){

      printf("%3d\t%-12s%-10s\t",i+1,RegistroC.codAlu,RegistroC.codCurso);
      for(int j=0;j<10;j++){
            printf("%-5.1f ",RegistroC.pract[j]);
      }
      printf("\n");
      fread(&RegistroC,sizeof(RegistroC),1,I);

      i++;
   }

   fclose(I);
   raya1();
   cout << "\n\rFin del listado !!!\n";
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
   getch();
   return;
}

void BuscarRegistro(FILE *I,PRACTICAS RegistroC){

   system("cls");
   char Codigo[10];
   int i=0;
   printf("\n\rIngrese el codigo del alumno a buscar ---> ");
   fflush(stdin);
   gets(Codigo);

   encabezado1();

   I=fopen("Practicas.dat","a+");
   if(I==NULL){
      cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO"<<endl;
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      system("pause");
      exit(1);
   }
   while(!feof(I)){
      if(stricmp(RegistroC.codAlu,Codigo)==0){
         printf("%3d\t%-12s%-10s\t",i,RegistroC.codAlu,RegistroC.codCurso);
         for(int j=0;j<10;j++){
            printf("%-5.1f ",RegistroC.pract[j]);
         }
      printf("\n");
      }
      i++;
      fread(&RegistroC,sizeof(RegistroC),1,I);
   }

   fclose(I);
   cout << "\n\r----------------------------------------------------------------";
   cout << "\n\rFin del listado !!!\n";
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
   getch();
   return;
}

void EliminarRegistro(FILE *I ,FILE *J,struct PRACTICAS RegistroC){

   system("cls");
   int i=0,Hallado=0,remo,rena;
   char Codigo[10];

   printf("\n\rIngrese el codigo del alumno a eliminar ---> ");
   fflush(stdin);
   gets(Codigo);


   I=fopen("Practicas.dat","r+");
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

   fread(&RegistroC,sizeof(RegistroC),1,I);

   while(!feof(I)){
      if(stricmp(RegistroC.codAlu,Codigo)==0){
            Hallado=1;
            printf("%3d\t%-12s%-10s\t",i+1,RegistroC.codAlu,RegistroC.codCurso);
            for(int j=0;j<10;j++){
               printf("%-5.1f ",RegistroC.pract[j]);
            }
      printf("\n");
      }
      else{
         fwrite(&RegistroC,sizeof(RegistroC),1,J);
      }
      i++;
      fread(&RegistroC,sizeof(RegistroC),1,I);
   }

   fclose(I);
   fclose(J);

   remo=remove("Practicas.dat");

   rena=rename("Temporal.dat","Practicas.dat");

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

void EditarRegistro(FILE *I ,FILE *J,struct PRACTICAS RegistroC){

   system("cls");
   int i=0,Hallado=0,remo,rena,op;
   char Codigo[10];

   printf("\n\rIngrese el codigo del alumno a editar ---> ");
   fflush(stdin);
   gets(Codigo);


   I=fopen("Practicas.dat","r+");
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

   fread(&RegistroC,sizeof(RegistroC),1,I);

   while(!feof(I)){
      if(stricmp(RegistroC.codAlu,Codigo)==0){
         Hallado=1;
         printf("%3d\t%-12s%-10s\t",i+1,RegistroC.codAlu,RegistroC.codCurso);
         for(int j=0;j<10;j++){
            printf("%-5.1f ",RegistroC.pract[j]);
         }
      printf("\n");
         MenuEditar();
         do{
            do{
               cout<<"\nIngrese opcion [ ]"<<"\b\b";
               cin>>op;
            }while(op<0 || op>4);

            switch(op){
               case 1 : fflush(stdin);
                        printf("Nuevo codigo de alumno --> ");
                        gets(RegistroC.codAlu);
                        encabezado1();
                        printf("%3d\t%-12s%-10s\t",i+1,RegistroC.codAlu,RegistroC.codCurso);
                        for(int j=0;j<10;j++){
                           printf("%-5.1f ",RegistroC.pract[j]);
                        }
                        printf("\n");
                        cout << "\n\r<<< ... PRESIONE ENTER para continuar\n >>>";
                        getch();
                        break;
               case 2 : fflush(stdin);
                        printf("Nuevo codigo de curso --> ");
                        gets(RegistroC.codCurso);
                        encabezado1();
                        printf("%3d\t%-12s%-10s\t",i+1,RegistroC.codAlu,RegistroC.codCurso);
                        for(int j=0;j<10;j++){
                           printf("%-5.1f ",RegistroC.pract[j]);
                        }
                        printf("\n");
                        cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>\n";
                        getch();
                        break;
               case 3 : printf("Nuevo conjunto de notas de practicas --> \n");
                        for(int j=0;j<10;j++){
                           printf("Practica dirigina nro %d:",j+1);
                           scanf("%f",&RegistroC.pract[j]);
                        }
                        encabezado1();
                        printf("%3d\t%-12s%-10s\t",i+1,RegistroC.codAlu,RegistroC.codCurso);
                        for(int j=0;j<10;j++){
                           printf("%-5.1f ",RegistroC.pract[j]);
                        }
                        printf("\n");
                        cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>\n";
                        getch();
                        break;
            }
            system("cls");
            MenuEditar();

         }while(op != 0);
         fwrite(&RegistroC,sizeof(RegistroC),1,J);
      }
      else{
         fwrite(&RegistroC,sizeof(RegistroC),1,J);
      }
      i++;
      fread(&RegistroC,sizeof(RegistroC),1,I);
   }

   fclose(I);
   fclose(J);

   remo=remove("Practicas.dat");

   rena=rename("Temporal2.dat","Cursos.dat");

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
