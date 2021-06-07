/*
 * nomPrograma: ALUMNOS v2
 * descripción:
 *
 *
 * autor: Chávez Farro, Luis André
 *        Espinola Ravello, Annie Katerine
 *        Reyes De la Cruz, Andrés Eduardo
 *        Silva Barra, Ernesto Franco
 *        Tocto Mallqui, Alexis
 * fecha: 16/09/2020
 */

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <string.h>

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

void  MenuPRINCIPAL();
void encabezado1();
void MenuEditar();
void raya1();
void raya2();

void MostrarRegistro(FILE *I, ALUMNO RegistroA);
void BuscarRegistro(FILE *I,ALUMNO RegistroA);
void EliminarRegistro(FILE *I, FILE *J,struct ALUMNO RegistroA);
void EditarRegistro(FILE *I ,FILE *J,struct ALUMNO RegistroA);

int main()
{
   int op;
   FILE *I;
   FILE *J;
   ALUMNO RegistroA;
   MenuPRINCIPAL();
   do{
      do{
         cout<<"Ingrese opcion [ ]"<<"\b\b";
         cin>>op;
      }while(op<0 || op>4);

      switch(op){
         case 1 : MostrarRegistro(I,RegistroA);
                  break;
         case 2 : BuscarRegistro(I,RegistroA);
                  break;
         case 3 : EliminarRegistro(I,J,RegistroA);
                  break;
         case 4 : EditarRegistro(I,J,RegistroA);
                  break;
      }
      system("cls");
      MenuPRINCIPAL();
   }while(op != 0);

   system("pause");
   return(0);
}

void  MenuPRINCIPAL()
{
   system("cls");
   cout << "\n\r A R C H I V O    D E    A L U M N O S ";
   cout << "\n\r  * Proyecto Final  Algoritmica I * ";
   cout << "\n\n\n\r 0.- TERMINAR";
   cout << "\n\r [1] LECTURA DEL ARCHIVO ALUMNOS";
   cout << "\n\r [2] BUSQUEDA POR CODIGO";
   cout << "\n\r [3] ELIMINAR UN ALUMNO";
   cout << "\n\r [4] EDITAR UN ALUMNO";
   printf("\n");
}

void encabezado1(){
   system("cls");
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
   printf("%-8s%-15s%10s%20s%13s%17s\n",num,cod,nom,escuela,peso,fnac);
   raya1();
}

void MenuEditar(){
   system("cls");
   cout << "\n\r A R C H I V O    D E    A L U M N O S";
   cout << "\n\r  OPCIONES DE EDICION ";
   cout << "\n\n\n\r 0.- TERMINAR";
   cout << "\n\r [1] EDITAR CODIGO DEL ALUMNO";
   cout << "\n\r [2] EDITAR NOMBRE DEL ALUMNO";
   cout << "\n\r [3] EDITAR ESCUELA DEL ALUMNO";
   cout << "\n\r [4] EDITAR PESO DEL ALUMNO";
   printf("\n");
}

void raya1(){
   printf("-------------------------------------------------------------------------------------------\n");
}

void raya2(){
   printf("===========================================================================================\n");
}

void MostrarRegistro(FILE *I, ALUMNO RegistroA){
   int i=0;
   I=fopen("Alumnos.dat","rb");
   if(I==NULL){
      cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO"<<endl;
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      system("pause");
      exit(1);
   }

   fread(&RegistroA,sizeof(RegistroA),1,I);

   encabezado1();

   while(!feof(I)){

      printf("\n%3d\t%4s\t%-30s\t%s\t%10.1f",i+1,RegistroA.codA,RegistroA.nomA,RegistroA.escA,RegistroA.peso);
      printf("\t%d/%d/%d\n",RegistroA.fnac->dd,RegistroA.fnac->mm,RegistroA.fnac->aaaa);

      fread(&RegistroA,sizeof(RegistroA),1,I);
      i++;
   }

   fclose(I);
   raya1();
   cout << "\n\rFin del listado !!!\n";
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
   getch();
   return;
}

void BuscarRegistro(FILE *I,ALUMNO RegistroA){

   system("cls");
   char Codigo[4];
   int i=0;
   printf("\n\rIngrese el codigo del curso a buscar ---> ");
   fflush(stdin);
   gets(Codigo);

   encabezado1();

   I=fopen("Alumnos.dat","rb");
   if(I==NULL){
      cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO"<<endl;
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      system("pause");
      exit(1);
   }
   while(!feof(I)){
      if(strcmp(RegistroA.codA,Codigo)==0){

         printf("\n%3d\t%4s\t%-30s\t%s\t%10.1f",i+1,RegistroA.codA,RegistroA.nomA,RegistroA.escA,RegistroA.peso);
         printf("\t%d/%d/%d\n",RegistroA.fnac->dd,RegistroA.fnac->mm,RegistroA.fnac->aaaa);

      }
      i++;
      fread(&RegistroA,sizeof(RegistroA),1,I);
   }

   fclose(I);
   cout << "\n\r--------------------------------------------------------------------------------------";
   cout << "\n\rFin del listado !!!\n";
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
   getch();
   return;
}

void EliminarRegistro(FILE *I ,FILE *J,struct ALUMNO RegistroA){

   system("cls");
   int i=0,Hallado=0,remo,rena;
   char Codigo[4];

   printf("\n\rIngrese el codigo del curso a eliminar ---> ");
   fflush(stdin);
   gets(Codigo);


   I=fopen("Alumnos.dat","rb");
   if(I==NULL){
      cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO"<<endl;
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      system("pause");
      exit(1);
   }

   J=fopen("TemporalAlu.dat","a+");
   if(J==NULL){
      cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO"<<endl;
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      system("pause");
      exit(1);
   }

   encabezado1();

   fread(&RegistroA,sizeof(RegistroA),1,I);

   while(!feof(I)){
      if(strcmp(RegistroA.codA,Codigo)==0){
         Hallado=1;

         printf("\n%3d\t%4s\t%-30s\t%s\t%10.1f",i+1,RegistroA.codA,RegistroA.nomA,RegistroA.escA,RegistroA.peso);
         printf("\t%d/%d/%d\n",RegistroA.fnac->dd,RegistroA.fnac->mm,RegistroA.fnac->aaaa);

      }
      else{
         fwrite(&RegistroA,sizeof(RegistroA),1,J);
      }
      i++;
      fread(&RegistroA,sizeof(RegistroA),1,I);
   }

   fclose(I);
   fclose(J);

   remo=remove("Alumnos.dat");

   rena=rename("TemporalAlu.dat","Alumnos.dat");

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

void EditarRegistro(FILE *I ,FILE *J,struct ALUMNO RegistroA){

   system("cls");
   int i=0,Hallado=0,remo,rena,op;
   char Codigo[4];

   printf("\n\rIngrese el codigo del alumno a eliminar ---> ");
   fflush(stdin);
   gets(Codigo);


   I=fopen("Alumnos.dat","rb");
   if(I==NULL){
      cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO"<<endl;
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      system("pause");
      exit(1);
   }

   J=fopen("TemporalAlu2.dat","a+");
   if(J==NULL){
      cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO"<<endl;
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      system("pause");
      exit(1);
   }

   encabezado1();

   fread(&RegistroA,sizeof(RegistroA),1,I);

   while(!feof(I)){
      if(strcmp(RegistroA.codA,Codigo)==0){
         Hallado=1;

         printf("\n%3d\t%4s\t%-30s\t%s\t%10.1f",i+1,RegistroA.codA,RegistroA.nomA,RegistroA.escA,RegistroA.peso);
         printf("\t%d/%d/%d\n",RegistroA.fnac->dd,RegistroA.fnac->mm,RegistroA.fnac->aaaa);

         MenuEditar();
         do{
            do{
               cout<<"\NIngrese opcion [ ]"<<"\b\b";
               cin>>op;
            }while(op<0 || op>4);

            switch(op){
               case 1 : fflush(stdin);
                        printf("Nuevo codigo --> ");
                        gets(RegistroA.codA);
                        encabezado1();
                        printf("\n%3d\t%4s\t%-30s\t%s\t%10.1f",i+1,RegistroA.codA,RegistroA.nomA,RegistroA.escA,RegistroA.peso);
                        printf("\t%d/%d/%d\n",RegistroA.fnac->dd,RegistroA.fnac->mm,RegistroA.fnac->aaaa);
                        cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
                        system("pause");
                        break;
               case 2 : fflush(stdin);
                        printf("Nuevo nombre --> ");
                        gets(RegistroA.nomA);
                        encabezado1();
                        printf("\n%3d\t%4s\t%-30s\t%s\t%10.1f",i+1,RegistroA.codA,RegistroA.nomA,RegistroA.escA,RegistroA.peso);
                        printf("\t%d/%d/%d\n",RegistroA.fnac->dd,RegistroA.fnac->mm,RegistroA.fnac->aaaa);
                        cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
                        system("pause");
                        break;
               case 3 : fflush(stdin);
                        printf("Nueva escuela --> ");
                        gets(RegistroA.escA);
                        encabezado1();
                        printf("\n%3d\t%4s\t%-30s\t%s\t%10.1f",i+1,RegistroA.codA,RegistroA.nomA,RegistroA.escA,RegistroA.peso);
                        printf("\t%d/%d/%d\n",RegistroA.fnac->dd,RegistroA.fnac->mm,RegistroA.fnac->aaaa);
                        cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
                        system("pause");
                        break;
               case 4 : fflush(stdin);
                        printf("Nuevo peso --> ");
                        scanf("%f",&RegistroA.peso);
                        encabezado1();
                        printf("\n%3d\t%4s\t%-30s\t%s\t%10.1f",i+1,RegistroA.codA,RegistroA.nomA,RegistroA.escA,RegistroA.peso);
                        printf("\t%d/%d/%d\n",RegistroA.fnac->dd,RegistroA.fnac->mm,RegistroA.fnac->aaaa);
                        cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
                        system("pause");
                        break;
            }
            system("cls");
            MenuEditar();

         }while(op != 0);
         fwrite(&RegistroA,sizeof(RegistroA),1,J);
      }
      else{
         fwrite(&RegistroA,sizeof(RegistroA),1,J);
      }
      i++;
      fread(&RegistroA,sizeof(RegistroA),1,I);
   }

   fclose(I);
   fclose(J);

   remo=remove("Alumnos.dat");

   rena=rename("TemporalAlu2.dat","Alumnos.dat");

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
