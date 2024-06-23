# P8-Ficheros_23-24

## Práctica Final de Ampliación de sistemas telemáticos.

Toda la documentación sobre todo este proyecto generado por doxygen se encuentra en el pdf llamado [refman.pdf](https://github.com/clases-julio/p8-ficheros-23-24-alacoste2017/blob/main/refman.pdf). Así como el [uml](https://github.com/clases-julio/p8-ficheros-23-24-alacoste2017/blob/main/P8-uml.pdf) con los diagramas de clases.

### Compilación y ejecución:

Una vez descargado el repositorio abrir el terminal en la carpeta donde se haya guardado y ejecutar lo siguiente:

```bash
make
./main
```
### NOTA IMPORTANTE:

Para que puedas autenticarte y poder hacer uso pleno para probar el programa, por defecto el programa incluye una cuenta de administrador con las siguientes credenciales:

**NIF:** 12345678

**ID (password):** 12345

### Funcionamiento general:

El código que aquí se encuentra es el culmen del sistema de monitorización de *Julio Veganos e hijos* propuesto por nuestro profesor a principio de curso. 

El código incluye TODO lo que hemos dado durante el curso SALVO templates, porque no han hecho falta. Sin embargo, está lleno de allocamiento de memoria dinámica, lectura/escritura de ficheros, control de excepciones...

Al ejecutar el programa, lo primero que se te pedirá será autenticarte (revisa el apartado **NOTA IMPORTANTE** para que esto no sea un problema). Luego de autenticarte, se abrirá el menú principal. En dicho menú, dependiendo de tu nivel de permiso, podrás consultar o modificar unas cosas u otras.

**Como administrador**: Podrás consultar y modificar todo (incluidos los usuarios).

**Como supervisor**: Tendrás acceso a la información de los sensores y a la alarma.

**Como trabajador**: Sólo tendrás acceso a los sensores.

### Bases de Datos:

Este programa usa 2 bases de datos. 

Una base de datos(**SensorDB.txt**) en formato .txt (de texto) donde se guarda la información necesaria para crear sensores. Al principio del programa se creará una base de datos vacía (si no existe) y se leerá la información de dicha base de datos.

Cada sensor que se carga en la base de datos o que se crea nuevo, se hace usando memoria dinámica, ya que no sabemos el número a priori de los sensores que se van a cargar.

Por otro lado, tenemos una base de datos para los usuarios con binario en su interior (**UserDB.dat**). En ella se guardan directamente los usuarios en binario, por lo que cualquiera que quiera intentar leer la base de datos buscando contraseñas o intenciones maliciosas, se va a llevar una decepción muy grande ya que lo que se aloja ahí es ininteligible. Así como la anterior base de datos, cuando se arranca el programa se cargan los usuarios en la base de datos de forma dinámica.

**Respecto a cuándo se guardan los datos en las bases de datos**: 

A medida que gestionas sensores o usuarios en el programa, hay un mecanismo de control (un booleano clásico) que se encarga todo el rato de verificar si se han modificado las bases de datos. Gracias a esto, sólo se abren los ficheros para guardar en el momento en el que sales del menú de gestionar sensores o usuarios y sólo en caso de haber modificado la base de datos. 

De esta forma, cuando estás gestionando las bases de datos, sólo estás haciendo modificaciones añadiendo o liberando elementos de la memoria dinámica; por ejemplo, puedes añadir 2 sensores y eliminar 3, y aún no se habrá abierto el fichero para guardar los cambios. Sólo se abrirá en el momento en el que selecciones la opción **"save and back"**. 

Asimismo, la opción **"save and back"** no siempre abre el fichero para guardar los cambios. Sólo lo hará en caso de que hayas modificado la base de datos. Si lo único que has hecho ha sido consultar los sensores, aunque des a **"save and back"** no se perderá el tiempo sobreescribiendo el fichero correspondiente a la base de datos.