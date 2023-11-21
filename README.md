# Analizador Léxico
## Datos de Entrega
### Integrantes:
- Rogelio Eduardo Benavides De La Rosa - 574161
- Marcela Alejandra Elizondo Rojas - 574161

### Materia
Teoría de Autómatas

### Profesor
Ing. Romeo A. Sánchez López, M.Ed., M.Sc. (Sr. Java)

### Fecha de Entrega
21 de Noviembre del 2023

### Código de Honor
*Damos nuestra palabra que hemos realizado esta actividad con integridad académica*

## Instrucciones de Compilación
### Windows
Para compilar este programa en Windows, necesitas tener instalado MinGW o un entorno similar que incluya g++. Abre la línea de comandos y navega hasta el directorio donde se encuentra el código fuente. Luego, ejecuta el siguiente comando:
```cmd
g++ -o AnalizadorLexico analizador.cpp
```
Esto generará un archivo ejecutable llamado AnalizadorLexico.exe en el mismo directorio.

### MacOS
En MacOS, asegúrate de tener instalado Xcode y las herramientas de línea de comandos. Abre la Terminal, navega hasta el directorio del código fuente y ejecuta:
```bash
g++ -o AnalizadorLexico analizador.cpp
```
Esto creará un ejecutable llamado AnalizadorLexico que puedes correr desde la Terminal.

### Linux
En sistemas basados en Linux, abre una terminal y asegúrate de tener instalado g++. Navega al directorio del código fuente y ejecuta:
```bash
g++ -o AnalizadorLexico analizador.cpp
```
Este comando compilará tu código y creará un ejecutable llamado AnalizadorLexico en el mismo directorio.

## Ejecución

### Windows
Después de compilar el programa, puedes ejecutarlo desde la línea de comandos. En Windows, usa:
```cmd
.\AnalizadorLexico.exe
```

### MacOS y Linux
En MacOS y Linux, utiliza:
```bash
./AnalizadorLexico
```

## Indicaciones de Uso
Existen 2 maneras de utilizar el programa
### Ejecución por Entubamiento
Puedes ejecutar el Analizador Léxico y hacer que procese directamente los datos de un archivo llamado `test.txt` utilizando el entubamiento. A continuación, se muestran los pasos para hacerlo en Windows, MacOS y Linux.

### Windows
En la línea de comandos de Windows, después de haber compilado el programa, utiliza el siguiente comando:
```cmd
type test.txt | AnalizadorLexico.exe
```

### MacOS y Linux
En la Terminal de MacOS o Linux, después de compilar el programa, ejecuta:
```bash
cat test.txt | ./AnalizadorLexico
```

## Abrir el archivo ejecutable
Al abrir el archivo ejecutable ingresar las líneas de prueba línea tras línea, al acabar ingresar la palabra "exit".