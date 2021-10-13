<h1>UNIVERSIDAD NACIONAL MAYOR DE SAN MARCOS - Facultad de Ingeniería de Sistemas e Informática</h1>
<h2>Curso: Algorítmica I - Prof. G. A. Salinas A - Proyecto de fin Curso</h2>

<p style="line-height: 1;">Se tiene los siguientes registros:</p>
<p style="line-height: 1;">&nbsp; struct ALUMNO{ &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;struct PRACTICA{ &nbsp; &nbsp; &nbsp;struct FECHA{ &nbsp; &nbsp; struct EXPARCIAL{</p>
<p style="line-height: 1;">&nbsp; &nbsp; &amp;int codAlu; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;int codAlu; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;int dd; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;int codAlu</p>
<p style="line-height: 1;">&nbsp; &nbsp; char nomAlu[40]; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;int codCurso; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; int mm; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; int codCur;</p>
<p style="line-height: 1;">&nbsp; &nbsp; char escuela[4]; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; int prac[10]; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; int aaaa;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; float expar;</p>
<p style="line-height: 1;">&nbsp; &nbsp; FECHA fnac; //&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; };&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;};&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;};</p>
<p style="line-height: 1;">&nbsp; &nbsp; float peso; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;</p>
<p style="line-height: 1;">&nbsp; };</p>
<p style="line-height: 1;">&nbsp; struct EXFINAL{ &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; struct Docente{ &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;struct CURSO{&nbsp;</p>
<p style="line-height: 1;">&nbsp; &nbsp; int codAlu; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;int codDoc; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;int codCur;&nbsp;</p>
<p style="line-height: 1;">&nbsp; &nbsp; int codCur; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;int nomDoc; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; char nomCur[40]</p>
<p style="line-height: 1;">&nbsp; &nbsp; float exfin; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; CURSO c[10]; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;char scal;</p>
<p style="line-height: 1;">&nbsp; }; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; };&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp;</p>
<p>Implementar para obtener los archivos cuyas estructuras se detallan y se muestran algunos reportes con algunos campos</p>
<h3>ALUMNOS</h3>
<table>
    <tr>
        <th>
        Nº
        </th>
        <th>
        Código
        </th>
        <th>
        APELLIDOS y Nombres
        </th>
        <th>
        Escuela
        </th>
        <th>
        Peso
        </th>
    </tr>
    <tr>
        <td>
        1
        </td>
        <td>
        100
        </td>
        <td>
        CONZALES ALE, Eva
        </td>
        <td>
        I1 
        </td>
        <td>
        40.0
        </td>
    </tr>
    <tr>
        <td>
        2 
        </td>
        <td>
        101 
        </td>
        <td>
        ARPASSI MAMAGNI, Juana 
        </td>
        <td>
        I1 
        </td>
        <td>
        55.0
        </td>
    </tr>
    <tr>
        <td>
        3 
        </td>
        <td>
        103 
        </td>
        <td>
        ARONES LOTAS, Felipe 
        </td>
        <td>
        I2 
        </td>
        <td>
        65.5
        </td>
    </tr>
    <tr>
        <td>
        4 
        </td>
        <td>
        106 
        </td>
        <td>
        AKATA MAKO, Marimon Kobe 
        </td>
        <td>
        I2 
        </td>
        <td>
        45.6
        </td>
    </tr>
    <tr>
        <td>
        5 
        </td>
        <td>
        108 
        </td>
        <td>
        MARISLAV NOLAK, Yashin 
        </td>
        <td>
        I1 
        </td>
        <td>
        55.0
        </td>
    </tr>
    <tr>
        <td>
        6 
        </td>
        <td>
        110 
        </td>
        <td>
        PEREZ LOZANO, Jose Luis 
        </td>
        <td>
        I2 
        </td>
        <td>
        75.0
        </td>
    </tr>
    <tr>
        <td>
        7 
        </td>
        <td>
        117 
        </td>
        <td>
        QUIROZ BENITES, Andre 
        </td>
        <td>
        I2 
        </td>
        <td>
        55.0
        </td>
    </tr>
    <tr>
        <td>
        8 
        </td>
        <td>
        119 
        </td>
        <td>
        ZEVALLOS SELMA, Mariluz 
        </td>
        <td>
        I2 
        </td>
        <td>
        45.0
        </td>
    </tr>
    <tr>
        <td>
        9 
        </td>
        <td>
        120 
        </td>
        <td>
        BIELA VELLATIN, Rosa 
        </td>
        <td>
        I1 
        </td>
        <td>
        53.0
        </td>
    </tr>
</table>
<p>El proyecto se desarrollara en forma incremental, cada entregable consta de avances del informe y codificación de las estructuras mencionadas.</p>
<h3>Entregable 1: 26.Agosto.2020 (Semana 12)</h3>
<p>El grupo debe presentar un folder proy.ap1-ap2.doc en donde se irán acumulando los entregables y la calificación de los mismos. Analice, diseñe e implemente las operaciones básicas (crear, leer, mostrar, buscar, insertar, eliminar, ordenar, editar, etc. ) de todas y cada una de las estructuras. En todos los entregables deben mostrar las observaciones resueltas.</p>
<h3>Entregable 2: 02.Septiembre.2020 (Semana 13)</h3>
<p>Debe agregar a la codificación anterior las operaciones salvar y recuperar. Además debe crear tres archivos secuenciales de tres registros que ustedes elijan.</p>
<p>Debe entregar un informe preliminar y la versión 2 de la codificación y los archivos de prueba con los datos mostrados en las tablas.</p>
<h3>Entregable 3: 09.Septiembre.2020 (Semana 14</h3>
<p>Ahora analice, diseñe e implemente al estructura Calculo con la cual debe determinar el promedio final calificaciones. El resultado del promedio final puede estar en un vector o en un archivo</p>
<p>Debe entregar un informe preliminar y la versión 3 de la codificación y los archivos de prueba con los datos mostrados en las tablas y el tabla con los datos del promedio final. </p>
<h3>Entregable 4 18.Septiembre.2020:</h3>
<p>Presentación y exposición del informe final, el programa y datos de prueba. Nota Proyecto = (E1 +E2 +E3)/4</p>
<h3>Protocolo presentación informe final</h3>
<p>Crear una carpeta con el número de grupo y los apellidos paterno de cada uno de los integrantes en orden alfabético y dentro de esta dos subcarpetas info y código; en info archivaran el informe final en word y la presentación ppt; y en código todos los programas de la última versión y los archivos de prueba.</p>
