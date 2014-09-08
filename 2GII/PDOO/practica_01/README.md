Programación y Diseño Orientado a Objetos
=========================================
2º Grado en Ingeniería Informática 2011/2012
--------------------------------------------


# Práctica 1: Lenguajes de Programación Orientados a Objetos
### Germán Martínez Maldonado

### Competencias específicas de la primera práctica

* Conseguir una visión inicial acerca de los lenguajes de programación orientados a objetos Java y Smalltalk.
* Trabajar con entornos de desarrollo en Java y Smalltalk.
* Tomar contacto con la sintaxis de programación en Java y Smalltalk.
* Interpretar los resultados obtenidos tras ejecutar un determinado código en Java y Smalltalk.
* Analizar las principales diferencias entre Java y Smalltalk.
* Desarrollar código sencillo en Java y Smalltalk.

### Primera sesión

1) Ejecuta NetBeans (desde Ubuntu 8.10). Si deseas lanzar NetBeans desde un ordenador del aula de prácticas, deberás crear una macro con el código que podrás encontrar en swad en documentos/practica/primeraPractica (lanzaNetbeans.txt). Al ejecutar la macro, se iniciará el entorno de desarrollo NetBeans. Es importante que en ningún caso ejecutes NetBeans en el aula usando el acceso directo ya que saturará tu cuenta de usuario.

2) Crea un proyecto de tipo aplicación Java. Una vez en NetBeans, crea un nuevo proyecto denominado PrimeraPractica en el directorio personal, indicando la clase que incluye el main: primerapractica.PruebaPrimeraPractica.

3) Crea una clase denominada Alumno.

4) Selecciona la clase Alumno e incluye el siguiente código (se encuentra en el fichero claseAlumno1.txt en swad en documentos/practica/primeraPractica):

```
package primerapractica; import java.util.Calendar;
import java.util.GregorianCalendar;

class Alumno {
    String nombre;
    int[] fechaNacimiento = {0,0,0};
    String titulacion = null;

    // Constructor que inicializa los atributos de la clase.
    Alumno (String unNombre, int[] unaFechNaci, String unaTitulacion){ 
        nombre = unNombre;
        fechaNacimiento = unaFechNaci; 
        titulacion = unaTitulacion;
    }

    // Constructor que crea alumnos sin matricular 
    Alumno(String unNombre, int[] unaFecha){
        nombre = unNombre; 
        fechaNacimiento = unaFecha;
    }

    // Métodos Consultores String getNombre() {
        return nombre;
    }

    int getAnioNacimiento() { 
        return fechaNacimiento[2];
    }

    int getMesNacimiento() { 
        return fechaNacimiento[1];
    }

    int getDiaNacimiento() {  
        return fechaNacimiento[0];
    }

    String getFechaNacimiento(){
        return fechaNacimiento[0]+"-"+fechaNacimiento[1]+"-"+fechaNacimiento[2];
    }

    String getTitulacion() { 
        return titulacion;
    }

    //Métodos Modificadores
    void setTitulacion(String unaTitulacion) { 
        titulacion = unaTitulacion;
    }

    void setNombre(String unNombre) { 
        nombre = unNombre;
    }

    void matricular(String unaTitulacion){  
        if(titulacion == null){
            titulacion = unaTitulacion;
        }
    }

    @override
    public String toString(){ 
        if(titulacion != null)
            return this.getNombre() + " con fecha de nacimiento el "
                + this.getFechaNacimiento()+" está estudiando "
                + this. getTitulacion();
        else
            return this.getNombre() + " con fecha de nacimiento el "
                + this.getFechaNacimiento()+" aun no se ha matriculado";
    }

    void comer(String alimento){  
        if (alimento.equals("Solido"))
            System.out.println("ñan ñan"); 
        else if (alimento.equals("Liquido"))
            System.out.println("glup glup");
    }

    void respirar(){ 
        System.out.println("inspira... espira...");
    }

    void dormir(){     
        System.out.println("Zzzzzz");
    }

    void estudiar(){ 
        if(titulacion != null)
            System.out.println("Estudiar, estudiar, tomar un café, estudiar..."); 
        else
            System.out.println("No tengo que estudiar");
    }

    int edad(){
        Calendar c = new GregorianCalendar();
        return c.get(Calendar.YEAR)-fechaNacimiento[2];
    }

    String cumple(){
        return " Mi cumpleaños es el " + fechaNacimiento[0] + " del "
            + fechaNacimiento[1];
    }

    boolean esMenorQue(Alumno a1) { 
        if(this.getAnioNacimiento()>a1.getAnioNacimiento())
            return true;
        else if(this.getAnioNacimiento()<a1.getAnioNacimiento()) 
            return false;
        else if(this.getMesNacimiento()>a1.getMesNacimiento()) 
            return true;
        else if(this.getMesNacimiento()<a1.getMesNacimiento()) 
            return false;
        else if(this.getDiaNacimiento()>a1.getDiaNacimiento()) 
            return true;
        else if (this.getDiaNacimiento()<a1.getDiaNacimiento()) 
            return false;

        return false;
    }
}
```

5) Lee detenidamente el código anterior, tratando de entenderlo y preguntando todo lo que no se entienda.

6) Implementa un método que permita indicar que un alumno ha terminado su carrera tomando la decisión que consideres oportuna para representar ese estado de fin de estudios.

7) Incluye un atributo en la clase Alumno que guarde el curso en el que se matricula el alumno. Implementa también el consultor y el modificador de dicho atributo y modifica los métodos correspondientes para que se vea reflejada dicha modificación. Estos métodos son:

* Alumno (String unNombre, int[] unaFechNaci, String unaTitulacion) 
* void matricular(String unaTitulacion)
* public String toString()

8) Incluye el siguiente código en el método main() de la clase PruebaPrimeraPractica (este código se encuentra en el fichero mainPrimeraPractica.txt de documentos/practica/primeraPractica de swad).

```
package primerapractica;
public class PruebaPrimeraPractica {

    public static void main(String[] args) { 
        int[] fn = {2,12,1970};
        Alumno alu = new Alumno("Juan Pedro",fn, "informatica");
        System.out.println(alu.toString());

        int[] fn2 = {31,5,1980};
        Alumno alu2 = new Alumno("Ana Maria",fn2); 
        System.out.println(alu2.toString()); 
        System.out.println(alu.edad());

        for (int i = 0; i < 5; i++) { 
            alu.dormir(); 
            alu.respirar();
            alu.comer("solido"); 
            alu.estudiar();
        }

        int i=0;
        while (i < 5) { 
            alu2.dormir(); 
            alu2.respirar(); 
            alu2.comer("solido");
            alu2.estudiar(); 
            i++;
        }
        System.out.println(alu.esMenorQue(alu2));
    }
}
```

9) Ejecuta este código tratando de entenderlo, manipulándolo todo lo que se desee y volviéndolo a ejecutar con esas modificaciones. Pregunta todo aquello que no entiendas.

10) Responde al cuestionario que se entregará durante la sesión de prácticas.


### Segunda sesión

1) Crea una clase denominada Asignatura.

2) Selecciona  la  clase  creada  e  incluye  el  siguiente  código  (se  encuentra  en  el  fichero claseAsignatura.txt de documentos/practicas/primeraPractica de swad).

```
package primerapractica; 

class Asignatura {
    int codigo; 
    String titulo;
    float creditosECTS;

     Asignatura(int unCodigo, String unTitulo, float creditos){
        codigo = unCodigo;
        titulo = unTitulo; 
        creditosECTS = creditos;
     }

    int getCodigo() {
        return codigo;
    }

    String getTitulo(){
        return titulo;
    }

    float getCreditosECTS(){
        return creditosECTS;
    }

    void setTitulo(String unTitulo){ 
        titulo = unTitulo;
    }

    void setCreditosECTS(float creditos){ 
        creditosECTS = creditos;
    }

    @Override
    public String toString(){
        String creditos = Float.toString (creditosECTS); 
        return "Asignatura de " + titulo + " con " + creditos
            + " créditos ECTS";
    }
}
```

3) Lee detenidamente el código introducido, tratando de entenderlo, preguntando todo lo que no entiendas.

4) Define el siguiente atributo en la clase Alumno:

```
List<Asignatura> asignaturas = new ArrayList();
```

Se trata de una estructura que va a almacenar todas las asignaturas en la que está matriculado el alumno.

5) Incluye el siguiente código en la clase Alumno (se encuentra en el fichero claseAlumno2.txt en documentos/practicas/primeraPractica en swad).

```
    void matricularAsignatura(Asignatura asig){ 
        if (titulacion != null)
            if(!estaMatriculado(asig.getCodigo())) 
                asignaturas.add(asig);
            else
                System.out.println("Este alumno ya está matriculado de esa asignatura");
        else
            System.out.println("El alumno no se encuentra estudiando en este momento");
    }

    void desmatricularAsignatura(int codAsig){ 
        if (titulacion != null)
            if(estaMatriculado(codAsig)) 
                asignaturas.remove(buscarAsignatura(codAsig));
            else
                System.out.println("Este alumno no tiene esa asignatura  matriculada");
        else
            System.out.println("El alumno no se encuentra estudiando en  este momento");
    }

    void mostrarMatricula (){ 
        if (titulacion != null){
            System.out.println("El alumnon :" + getNombre()
                + "se encuentra matriculado de:"); 
            for (Asignatura asignatura : asignaturas)
                System.out.println(asignatura.toString());
        }else
            System.out.println("El alumno no se encuentra estudiando en este momento");
    }

    Asignatura buscarAsignatura (int codAsig){ 
        Asignatura asig = null;
        boolean encontrado = false
        ListIterator<Asignatura> itAsig = asignaturas.listIterator();

        while(itAsig.hasNext() & !encontrado){ 
            asig = itAsig.next(); 
            if(asig.getCodigo() == codAsig)
                encontrado = true;
        }
        return asig;
    }

    boolean estaMatriculado (int codAsig){ 
        boolean encontrado = false;
        ListIterator<Asignatura> itAsig = asignaturas.listIterator(); 
        while(itAsig.hasNext() & !encontrado){
            if(itAsig.next().getCodigo()==codAsig) 
                encontrado = true;
        }
        return encontrado;
    }
```

6) Lee detenidamente el código introducido, tratando de entenderlo y preguntando todo lo que entiendas.

7) Añade el siguiente trozo de código al método main() de la clase PruebaPrimeraPractica.

```
Asignatura asig1 = new Asignatura(1,"PDOO",6);
 Asignatura asig2 = new Asignatura(2,"FIS",6); 
Asignatura asig3 = new Asignatura(3,"SO",6);
 alu.matricularAsignatura(asig1); 
alu.matricularAsignatura(asig2); 
alu2.matricularAsignatura(asig3); 
alu.mostrarMatricula();
alu2.mostrarMatricula();
```

8) Ejecuta  el  código  anterior  tratando  de  entenderlo,  manipulándolo  todo  lo  que  desees  y volviendo a ejecutarlo con esas modificaciones. Pregunta todo aquello que no entiendas.

9) Añade el siguiente trozo de código al método main() de la clase PruebaPrimeraPractica.

```
alu.desmatricularAsignatura(1);
alu.mostrarMatricula();
alu2.matricular("informatica", 4);
alu2.matricularAsignatura(asig3);
alu2.matricularAsignatura(asig2);
alu2.mostrarMatricula();
alu2.desmatricularAsignatura(1);
```

10) Ejecuta este código tratando de entenderlo, manipulándolo todo lo que desees y volviendo a ejecutarlo con esas modificaciones. Pregunta todo aquello que no entiendas.

11) Define un nuevo método en la clase Alumno que se encargue de eliminar todas las asignaturas matriculadas del Alumno y cambie su estado a no matriculado (abandonar los estudios).

12) Define una variable en el método main que almacene a todos los alumnos que se vayan creando.

13) Incluye código en el main para que se muestre la información asociada a todos los alumnos del sistema.

14) Responde al cuestionario que será entregado durante la sesión de prácticas.


### Tercera sesión

1) Modificar la clase Asignatura. Cambiar el tipo del código de la asignatura (codigo) a String. Modificar todos los métodos de la clase Asignatura que se vean afectados por este cambio.

2) Modificar la clase Alumno. En swad en documentos/practica/PrimeraPractica en el fichero claseAlumno3.txt tenéis el código de la clase Alumno con los siguientes cambios:

1. Cambiado el tipo de la fecha de nacimiento del Alumno a GregorianCalendar. En el apéndice tenéis un pequeño ejemplo de cómo se manipulan los objetos de GregorianCalendar y también en el enlace que se indica más abajo.
2. Cambiado el tipo de la colección que almacena los objetos de la clase Alumno a Map. Podéis consultar  la funcionalidad de Map(interfaz) o HashMap(clase) en el enlace indicado más abajo.
3. Introducido el manejo de excepciones necesarias en un ejemplo simple.

Más información (API Specification of Java): [http://download.oracle.com/javase/6/docs/api/](http://download.oracle.com/javase/6/docs/api/)

3) Analizar detenidamente todos estos cambios, si no se entiende algo, preguntarlo al profesor/profesora.

4) Implementar el método edad() de la clase Alumno, teniendo en cuenta la modificación introducida para la fecha de nacimiento del alumno. Existe dos formas:

```
    Primera forma:
        fnm = fechaNacimiento en minutos; 
        fam = fechaActual en minutos;
        edad = truncar(fam-fnm/minutos de un año);

    Segunda forma:
        if (mesActual < mesNacimiento)
            edad = añoActual-añoNacimiento-1; 
        else if( mesActual == mesNacimiento)
            if(diaActual < diaNacimiento)
                edad = añoActual-añoNacimiento-1; 
            else
                edad = añoActual-añoNacimiento;
        else 
            edad = añoActual-añoNacimiento;
```

5) Modificar el ejemplo de prueba (PruebaPrimerPractica.java) de la sesión dos para que no tenga errores de compilación y que funcione con los cambios introducidos.

6) Intentar dar de baja una asignatura en la que el alumno no esté matriculado. Observar cuál es el resultado y modificar el ejemplo de prueba para que se capture las posibles excepciones que se produzcan.

7) Responder al cuestionario que será entregado durante la sesión de la práctica.

Apéndice: Un ejemplo simple de cómo se trabaja con los objetos de la clase GregorianCalendar.

OJO: los meses empiezan a contar en 0 (0 es enero, 1 febrero ... 11 diciembre), los días y años cuentan desde uno.

```
import java.util.Calendar;
import java.util.GregorianCalendar;

public class Main {
    public static void main(String[] args) { 
        GregorianCalendar fecha = new GregorianCalendar(); 
        fecha.set(2009, 0, 13); //13 de Enero de 2009
        System.out.println(fecha.get(Calendar.DAY_OF_MONTH)+"/"+
            (fecha.get(Calendar.MONTH)+1)+"/"+ fecha.get(Calendar.YEAR));
    }
}
```

El mismo ejemplo pero usando la fecha actual del sistema:

```
import java.util.Calendar; 
import java.util.Date;
import java.util.GregorianCalendar;

public class Main {
    public static void main(String[] args) { 
        GregorianCalendar fecha = new GregorianCalendar(); 
        Date hoy = new Date();
        fecha.setTime(hoy); 
        System.out.println(fecha.get(Calendar.DAY_OF_MONTH)+"/"+
            (fecha.get(Calendar.MONTH)+1)+"/"+ fecha.get(Calendar.YEAR));
    }
}
```


### Cuarta sesión

#### Trabajando en Squeak con Smalltalk (Ubuntu 8.10).

1) Abre el System Workspace (Tool->Workspace).

2) Escribe cada una de las expresiones de mensaje que se indican a continuación, para cada una de ellas pulsa botón azul del ratón y selecciona print it (o control-p), analiza el resultado y pregunta todo lo que no entiendas. Ten en cuenta la siguiente norma: las expresiones de mensaje se evalúan de izquierda a derecha, las unarias tienen precedencia sobre las binarias y éstas sobre las de palabra clave. Aunque se pueden usar los paréntesis para cambiar este criterio.

    `5+6*3.`                  “operaciones con enteros.Expr. De mensaje binario”
    `5+(6*3).`                “uso de paréntesis”
    `6.8 * 7.2.`              “multiplicación de reales”
    `-3 abs.`                 “valor absoluto. Expresión de mensaje unario” 
    `'aprende', 'mucho'.`     “concatenación de cadenas”
    `'aprende' at:1.`         “acceso a un elemento de la cadena. Expresión de palabra clave”
    `'mucho' at:2 put:$o.`    “modificación de un elemento de la cadena”
    `#(2 7 17) size.`         “tamaño de un array de enteros”
    `#($a $b $c $d) at:4.`    “array de caracteres”

3) Haz lo mismo que anteriormente pero ten en cuenta que algunas son grupos de expresiones de mensajes.

```
“Definición y uso de variables locales”
| var1|
var1 := #($a $b $c $d). 
var1 at:4 put:$r.
var1 at:4. 
var1.

“Expresiones lógicas” 
true and: true.

true and: true and: false. 

“Expresiones selectivas”
|var2|
(3>5) ifTrue: [var2:='cierto'].

|var2|
(3>5) ifTrue: [var2:='cierto'] ifFalse: [var2:='falso'].

“Expresiones iterativas”
|var3| 
var3:=1.
[var3 < 5] whileTrue: [var3:=var3+1]. 
var3 inspect.

|var4|
var4 := Array new:4.
#(1 2 3 4) do: [:i | var4 at: i put: $B].
var4 inspect.

#(6 9 3 0 5 18 123) select:[:i | i> 8].

#(3 $e 'palabra' 78) select:[:j | j isInteger].

“Definición y uso de variables globales” 
Smalltalk at:#varGlobal put:3.

varGlobal := varGlobal + 4. 

Smalltalk at:#varGlobal.

varGlobal:= Fraction numerator:5 denominator:3.

varGlobal numerator.

varGlobal asFloat.
```

4) Abre el System Transcript (Tool->Transcript) y escribe en el Workspace lo siguiente  y observa qué pasa.

```
|var5|
var5:= Fraction new.
var5 setNumerator:9 denominator:3.
(var5>varGlobal) ifTrue:[Transcript show:'es una fracción más grande'].
```

5) Abre el System Browser (Tool->Browser).

6) Trata de entender cada uno de los apartados del System Browser. Para ello selecciona una categoría de clases (parte superior izquierda), por ejemplo la Kernel-Numbers, a su derecha aparecen todas las clases de esa categoría, selecciona una de ellas, por ejemplo la Fraction, a su derecha aparece todas la categorías de métodos de la clase Fraction, selecciona una de ellas, por ejemplo la comparing, a su derecha aparecen todos los métodos de esa categoría, si seleccionas un método, en la parte inferior del Browser aparece su implementación.

7) Incluir una categoría de clases: Incluye una nueva categoría de clases llamada PrimeraPractica, para ello sobre la zona de categorías de clases presiona botón azul de ratón, elige la opción add item.

8) Incluir una clase: Incluye la clase Alumno en esa categoría, para ello selecciona la categoría PrimeraPractica y en la parte inferior del Browser aparece una plantilla, modifícala para que quede de la siguiente forma:

```
Object subclass: #Alumno
instanceVariableNames: 'nombre fechaNacimiento titulacion curso' 
classVariableNames: ''
poolDictionaries: '' 
category: 'PrimeraPractica'
```

9) Una vez modificado el código y comprobado que está todo bien, pulsa botón azul de ratón, selecciona accept (o control-s), como puedes ver te aparece una clase llamada Alumno en el apartado correspondiente.

10) Añadir categoría de métodos: De nuevo en el System Browser, categoría PrimeraPractica clase Persona, crea una categoría de métodos llamada consultoresBasico y otra llamada modificadoresBasicos. Para ello, como siempre botón azul de ratón sobre la zona de categoría de métodos y selecciona new category -> new.

11) Añadir métodos: Selecciona la categoría de consultoresBasicos y en la parte inferior del Browser aparece una plantilla, sustituye la plantilla por el siguiente código, pulsa botón azul de ratón, selecciona accept y observa como aparece un nuevo método dentro del apartado correspondiente.

```
getNombre
    ^nombre    “^ devolución del objeto asociado a esa expresión”
```

12) Repite el procedimiento explicado en el apartado 11 para todos los métodos que hay a continuación.

```
getFechaNacimiento
    ^fechaNacimiento

getTitulacion
    ^titulacion

getCurso
    ^curso

edad
    ^((Date today subtractDate:fechaNacimiento asDate)/365) asFloat truncated
```

13) Selecciona la categoría de métodos modificadoresBasicos y repite el procedimiento explicado en el paso 11 para los siguientes métodos:

```
setNombre: unNombre
    nombre := unNombre

setFechaNacimiento: unaFechaNacimiento 
    fechaNacimiento := unaFechaNacimiento

setTitulacion:unaTitulacion 
    titulación := unaTitulacion

setCurso:unCurso
    curso:=unCurso
```

14) Añade la categoría de métodos consultores y define los siguientes métodos dentro de esa categoría:

```
edad
^((Date today subtractDate:fechaNacimiento asDate)/365) asFloat truncated

cumpleaños
^fechaNacimiento dayOfMonth asString	,	' de ' , fechaNacimiento monthName

asString
^ 'el alumno: ', self getNombre,
    ' nacido: ', self getFechaNacimiento asString,
    ' se encuentra estudiando: ', self getCurso asString, 
    ' de ', self getTitulacion
```

15) Añade la categoría de métodos comparadores y define el siguiente método dentro de esa categoría:

```
esMenorQue: unAlumno
^ fechaNacimiento < unAlumno getFechaNacimiento
```

16) Añadir el constructor (método de clase): En el apartado de las clases, en la parte inferior izquierda hay dos opciones una instance y otra class, selecciona class, vete al apartado de categoría de métodos, pulsa botón azul de ratón y selecciona instance creation. Sustituya la plantilla que sale en la parte inferior de browser por el siguiente código:

```
nombre:unNom fechaNacimiento: unaFechaNac titulacion:unaTit curso:unCurso 

    “expresión de mensaje en cascada”
    |alumno| 
    alumno:=Alumno new.
    alumno setNombre:unNom;
           setFechaNacimiento:unaFechaNac; 
           setTitulacion:unaTit; 
           setCurso:unCurso.
    ^alumno
```

15) Usar la clase Alumno: Ya tenemos a la clases Alumno lista para ser usada, vete al Workspace y escribe el siguiente código:

```
|alu1 alu2|
alu1:=Alumno nombre:'ana' fechaNacimiento:(Date year: 1999 month:12 day:3) 
            titulacion:'informatica' curso:1.
alu2 := alu1.
alu2 setFechaNacimiento: (Date year:2000 month:2 day:1). 
alu1 getFechaNacimiento.

|alu1|
alu1:=Alumno nombre:'ana' fechaNacimiento:(Date year: 1999 month:12 day:3) 
    titulacion:'informatica' curso:1.
alu1 class.

|alu1 alu2|
alu1:=Alumno nombre:'ana' fechaNacimiento:(Date year: 1999 month:12 day:3) 
    titulacion:'informatica' curso:1.
alu2:=	Alumno nombre:'ana' fechaNacimiento:(Date year: 2000 month:1 day:30)
    titulacion:'informatica' curso:1.
alu1 esMenorQue:alu2
```

16) Cuando se evalúa este último grupo de expresiones de mensaje da un resultado que no se corresponde con el que debe ser, esto es consecuencia de que hay un error en el código, corrígelo.

17) En el workspace escribe código para modificar el estado del alumno y consultar todo lo que desees.

18) Responde al cuestionario que será entregado en la sesión de práctica.


### Quinta sesión

1) Sitúate en el directorio de trabajo de Squeak y lánzalo mediante el comando squeak &.

2) Añade una nueva clase: Crea la clase Asignatura en la categoría PrimeraPractica creada en la sesión anterior. Para ello selecciona la categoría PrimeraPractica en el primer panel del System Browser y modifica la plantilla que aparece en el panel inferior, de forma que la clase tenga tres variables de instancia: codigo, titulo y creditosECTS.

3) En la nueva clase, define la categoría de métodos consultoresBasicos y añádele los tres métodos unarios: codigo, titulo y creditosECTS que devuelven los atributos correspondientes. Para crear la nueva categoría de métodos procede de forma similar a como lo hiciste para crear la nueva categoría de clases, pero usando el tercer panel en lugar del primero.

4) Define la categoría de métodos modificadoresBasicos y añádele los tres métodos de palabras clave: codigo:unCodigo, titulo: unTitulo y creditosECTS: cECTS que modifican los atributos correspondientes.

5) Define la categoría de métodos consultores y sobrescribe el método asString de la clase Object para “serializar” un objeto de la clase Asignatura (es decir, crear un ByteString que lo describa en modo texto).

6) Crea la categoría de métodos de clase instanceCreation (debajo del panel de las clases, pulsa el “selector class”) y crea un nuevo constructor que inicialice el objeto creado con su código, título y número de créditos. Usa para ello, el siguiente código.

```
new: unInteger titulo: unByteString creditosECTS: unFloat
“constructor de Asignatura”
^ (self new) codigo: unInteger; titulo: unByteString; creditosECTS:
unFloat
```

7) En el espacio de trabajo, Workspace, crea una asignatura para probar los métodos de construcción, de inicialización y de serialización que has creado.

8) Modifica la clase Alumno: Añade a la clase Alumno creada en la sesión anterior el atributo asignaturas. Para ello modifica la plantilla de creación de la clase, de forma que la clase tenga, ahora, cinco variables de instancia: nombre, fechaNacimiento, titulacion, curso y asignaturas.

9) Crea en la categoría de modificadoresBasicos un método unario (es decir, sin argumentos) de nombre setAsignaturas para que el atributo asignaturas sea un nuevo objeto de la clase OrderedCollection sin ninguna asignatura.

10) Modifica el constructor nombre:unNom fechaNacimiento: unaFechaNac titulacion:unaTit curso:unCurso creado en la práctica anterior para incluir la incialización de asignaturas usando el método setAsignaturas que acabas de crear.

11) Crea la categoría de métodos gestionAsignaturas y añádele los métodos de palabras clave matricularAsignatura: unaAsignatura y estaMatriculado: unCodigoAsignatura, usando el código que aparecen a continuación.

```
matricularAsignatura: unaAsignatura
(self estaMatriculado: unaAsignatura codigo)
ifFalse:[asignaturas
add: unaAsignatura]
ifTrue: [^'el alumno ya esta matriculado de esa asignatura']
```

```
estaMatriculado: unCodigoAsignatura
| i encontrado |
i := 1.
encontrado := false.
[encontrado not & (i<= asignaturas size)] whileTrue:[
    (((asignaturas at:i) codigo) = unCodigoAsignatura)
        ifTrue:[encontrado := true ].
    i := i+1.
].
^ encontrado
```

12) Añade también en la categoría gestionAsignaturas el método unario mostrarMatricula, usando el siguiente código.

```
mostrarMatricula
| result |
result:=''.
    asignaturas do: [:i| result:=result,i asString, Character cr asString].
^result
```

13) Modifica  el  método  asString de  la  clase  Alumno para  que  haga  uso  del  método mostrarMatricula e incluya la información de las asignaturas en las que está matriculado.

14) Crea una nueva clase llamada PruebaPrimeraPractica dentro de la categoría PrimeraPractica. Crea para dicha clase una categoría de métodos de clase llamada pruebas. Crea dentro un método de clase unario llamado prueba1 que:

a) Cree tres objetos Asignatura para las asignaturas PDOO, FIS y SO de 6 créditos cada una.
b) Cree dos objetos Date que representen las fechas 2 dic 1970 y 31 may 1980 respectivamente (ejemplo: para la fecha 1 de diciembre de 1995, el objeto puede crearse mediante Date year: 1995 month:12 day:1).
c) Cree dos objetos Alumno para Juan (estudiante de Informática nacido el 2 dic de 1970) y Ana Maria (estudiante de titulación desconocida, nacida el 31 de mayo de 1980).
d) Matricule a Juan en las asignaturas PDOO y FIS y a Ana Maria en la SO.
e) Devuelva como resultado una OrderedCollection con los dos alumnos (los cuales podremos “inspeccionar” desde fuera).

15) Prueba el método prueba1 desde el espacio de trabajo usando la opción inspect.

16) Modifica el método prueba1 para que devuelva los alumnos ya serializados (es decir, convertidos a ByteString). Para ello observa como se hace esto en la implementación del método mostrarMatricula.

17) Responde al cuestionario, que será entregado durante la sesión de prácticas.


### Sexta sesión

1) Organizados en grupos buscad, seleccionad y organizad información sobre un lenguaje orientado a objetos previamente acordado con el profesor.

2) Completad la siguiente plantilla con la información que se requiere sobre el lenguaje elegido. Podéis extenderos tanto como consideréis conveniente para describir cada apartado añadiendo filas a la parte derecha cuando sea necesario.

[Ada](ada/ada.md)

[Presentación](ada/presentacion.md)

Todas las fuentes consultadas deben añadirse en el apartado “Referencias”. Si se trata de libros o artículos deben aparecer el nombre de los autores, la fecha de publicación, el título y el nombre del libro o revista. Si se trata de páginas web, debe figurar el autor de la página, la fecha en que fue visitada, la fecha en que se actualizó por última vez, el título de la página y su URL.

Ejemplos:

```
García, A., González, P. 2010. Título del libro. Ed. Manzano.

Pérez, M. 2009. Título de la página web http://url [Consultada: 4 octubre 2011]
```

3) Preparad una presentación oral apoyada en diapositivas para contar a vuestros compañeros estas y otras características que consideréis relevantes del lenguaje elegido. Durante la exposición deberán participar todos los integrantes del grupo y responder correctamente a las preguntas que se les puedan hacer sobre la misma. La duración de la exposición será acordada previamente con el profesor.

4) Responded al cuestionario que se entregará durante la sesión de prácticas, sobre los lenguajes expuestos en clase.
