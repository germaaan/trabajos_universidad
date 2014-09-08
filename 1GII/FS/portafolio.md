# TEMA 1: SISTEMAS DE CÓMPUTO 


## DEFINICIONES 

* **Informática**: Conjunto de conocimientos científicos y técnicas que hacen posible el tratamiento automático de la información por medio de ordenadores. 
* **Dato**: Información dispuesta de manera adecuada para su tratamiento por un ordenador. 
* **Instrucción**: Expresión formada por números y letras que indica, en un ordenador, la operación que debe realizar y los datos correspondientes. 
* **Software**: Conjunto de programas, instrucciones y reglas informáticas para ejecutar ciertas tareas en un ordenador. 
* **Hardware**: Conjunto de los componentes que integran la parte material de un ordenador. 
* **Ordenador**: Máquina electrónica dotada de una memoria y de métodos de tratamiento de la información, capaz de resolver problemas aritméticos y lógicos gracias a la utilización automática de programas registrados en ella. 
* **Arquitectura**: Estructura lógica y física de los componentes de un computador. 
* **Bit**: Unidad mínima de información empleada en informática. 
* **Byte**: es una secuencia de 8 bits contiguos. Se usa comúnmente como unidad básica de almacenamiento de información en combinación con los prefijos de cantidad. 
* **Firmware**: es el intermediario entre las órdenes externas que reciben el dispositivo y su electrónica, ya que es el encargado de controlar a esta última para ejecutar correctamente dichas órdenes externas. 
* **Lenguaje máquina**: es el sistema de códigos directamente interpretables por un circuito microprogramable, como el microprocesador de un ordenador o el microcontrolador de un autómata. 
* **Lenguaje ensamblador**: es un tipo de lenguaje de bajo nivel utilizado para escribir programas informáticos, y constituye la representación más directa del código maquina específico para cada arquitectura de ordenadores legible por un programador. 
* **Lenguaje de alto nivel**: es un lenguaje de programación que se caracteriza por expresa los algoritmos de una manera adecuada a la capacidad cognitiva humana, en lugar de a la capacidad ejecutora de las máquinas. 


## 1.1 ELEMENTOS BÁSICOS

La función principal de un ordenador es ejecutar programas, esto se puede llevar a cabo gracias a la interconexión de los cuatro elementos estructurales principales: 

* **Procesador**. Controla el funcionamiento del ordenador y realiza sus funciones de procesamiento de datos. 
* **Memoria principal**. Almacena datos y programas. Esta memoria normalmente es volátil, también puede recibir el nombre de memoria real o memoria primaria. 
* **Módulos de entrada/salida**. Transfieren datos entre el ordenador y el exterior. Este exterior pueden ser dispositivos como dispositivos de memoria secundaria (por ejemplo, discos), equipos de comunicación o terminales. 
* **Bus del sistema**. Permite que se comuniquen los procesadores, la memoria principal y os módulos de entrada/salida. 

Para cumplir con su función de intercambiar datos con la memoria y los dispositivos de E/S, el procesador tiene varios registros internos: 

* **Registro de dirección de memoria (RDIM)**: que especifica la dirección de memoria de la siguiente lectura o escritura. 
* **Registro de datos de memoria (RDAM)**: que contiene los datos que se van a escribir en la memoria o que recibe los datos leídos de la memoria. 
* **Registro de dirección de E/S (RDIE/S)**: que especifica un determinado dispositivo de E/S. 
* **Registro de datos de E/S (RDAE/S)**: que permite intercambiar datos entre un módulo de E/S y el procesador. 

Un módulo de memoria tiene un conjunto de posiciones definidas mediante direcciones numeradas secuencialmente. Cada posición contiene un patrón de bits que se puede interpretar como una instrucción o como datos.

Un módulo de E/S transfiere datos desde los dispositivos externos hacia el procesador y la memoria, y viceversa. Contiene buffers que almacenarán los datos temporalmente hasta que se puedan enviar. 


## 1.2 REGISTROS DEL PROCESADOR

Un procesador incluye un conjunto de registros que proporciona un tipo memoria más rápida y de menor cantidad que la memoria principal. Tienen dos funciones: 

* **Registros visibles para el usuario**. Permiten al programador en lenguaje maquina o en ensamblador minimizar las referencias a memoria principal optimizando el uso de registros. 
* **Registros de control y estado**. Usados por el procesador para controlar su operación y por rutinas privilegiadas del sistema operativo para controlar la ejecución de programas. 

### REGISTROS VISIBLES PARA EL USUARIO 

A este tipo de registros se puede acceder por medio del lenguaje de máquina ejecutado por el procesador. Los tipos de registros disponibles normalmente son registros de datos, de dirección y de código de condición. 

Los **registros de datos** se pueden utilizar para diversas funciones. Son de propósito general y pueden usarse con cualquier instrucción de máquina que realice operaciones sobre datos. Aunque suelen haber restricciones como puede ser diferentes registros para operaciones de coma flotante y registros para operaciones con enteros. 

Los **registros de dirección** contienen direcciones de memoria principal de datos e instrucciones, o una parte de la dirección que se utiliza en el cálculo de la dirección completa. Estos registros pueden ser de propósito general o pueden estar dedicados a una forma particular de direccionamiento de memoria. Un ejemplo de este registro puede ser el **puntero de pila**, que será un registro que apunta a la cima de la pila. Esto permite que no sea necesario el campo de dirección en las instrucciones para apilar (push) o extraer (pop). 

En algunas máquinas el procesador realiza las operaciones de salvar y restaurar todos los registros visibles como parte de la ejecución de las instrucciones de llamada y de retorno, pero en otras, es el programador el responsable de guardar el contenido de los registros visibles para el usuario antes de la llamada al procedimiento. Conclusión, salvar y restaurar registros se puede realizar por hardware o software dependiendo del procesador.

### REGISTROS DE CONTROL Y ESTADO 
Se emplean varios registros del procesador para controlar el funcionamiento del mismo. En la mayoría de las máquinas, muchos de ellos no son visibles para el usuario. A algunos de ellos se puede acceder mediante instrucciones de máquina ejecutadas en modo kernel. 

Además de los registros RDIM, RDAM, RDIE/S y RDAE/S, hay dos registros más que son esenciales para la ejecución de instrucciones: 

* **Contador de programa (Program Counter, PC)**: contiene la dirección de la próxima instrucción que se leerá de la memoria. 
* **Registro de instrucción (Instruction Register, IR)**: contiene la última instrucción leída. 

Todos los diseños de procesador incluyen también un registro, o conjunto de registros, llamado normalmente la **Palabra de Estado del Programa (Program Status Word, PSW)**. Normalmente contiene códigos de condición, además de otra información de estado, como un bit para habilitar/inhabilitar las interrupciones y un bit de modo de usuario/supervisor. 

Los **códigos de condición** son bits cuyo valor lo asigna normalmente el hardware de procesador teniendo en cuenta el resultado de las operaciones. Además de almacenarse el resultado en un registro o en la memoria, se fija también un código de condición relacionado con el resultado de la ejecución de la instrucción. 


## 1.3 EJECUCIÓN DE INSTRUCCIONES

Un programa que va a ejecutarse en un procesador consta de un conjunto de instrucciones almacenado en memoria. El procesamiento de una instrucción consta de partes: el procesador lee (busca) instrucciones en memoria, una por vez, y ejecuta cada una de ellas. La ejecución de un programa consiste en repetir la búsqueda y ejecución de todas las instrucciones del programa. 

Un ciclo de instrucción es el procesamiento para una única instrucción. Se divide en fase de búsqueda y de ejecución. Le ejecución solo se detendrá si se apaga el ordenador, se produce un error irrecuperable o se ejecuta una instrucción del programa que para el procesador. 

### BUSQUEDA Y EJECUCION DE UNA INSTRUCCIÓN 

Al principio de cada ciclo de instrucción, el procesador lee una instrucción de memoria. Normalmente, el contador de programa (PC) almacena la dirección de la siguiente instrucción a leer. A no ser que se indique lo contrario, el procesador siempre incrementa el PC después de ejecutar una instrucción, leyendo la siguiente instrucción en orden secuencial. 

Al leer una instrucción esta se carga en un registro de instrucción del procesador. Está contiene bits que indican la acción que realizará el procesador. Estas acciones se dividen en cuatro categorías: 

* **Procesador-memoria**. Se pueden transferir datos en ambos sentidos entre el procesador y la memoria. 
* **Procesador-E/S**. Se pueden transferir datos en ambos sentidos entre un módulo de E/S y el procesador. 
* **Procesamiento de datos**. El procesador puede realizar operaciones aritméticas o lógicas sobre los datos. 
* **Control**. Una instrucción puede indicar que se a alterar la secuencia de ejecución. 


## 1.4 INTERRUPCIONES

Prácticamente todos los ordenadores tienen un mecanismo para que otro módulos (memoria y E/S) puedan interrumpir el secuenciado normal del procesador. Clases de interrupciones: 

* **De programa**: por resultado de la ejecución de una instrucción, como pueden ser desbordamiento aritmético, división por cero, intento de ejecutar una instrucción de máquina ilegal y referencias fuera del espacio de memoria permitido para el usuario. 
* **Por temporizador**: por un temporizador del procesador. Permite al sistema operativo realizar funciones de forma regular. 
* **De E/S**: por un controlador de E/S para indicar la finalización de un operación o indicar errores producidos. 
* **Por fallo del hardware**: por un fallo como en el suministro de energía o un error de paridad en la memoria. 

### INTERRUPCIONES Y EL CICLO DE INSTRUCCIÓN 

Gracias a las interrupciones, el procesador puede ejecutar otras instrucciones mientras que la operación de E/S se lleva a cabo. Después de ejecutar las instrucciones, se devuelve el control al programada de usuario y mientras, el dispositivo externo está ocupado aceptando datos de la memoria e imprimiéndolos. 

Cuando el dispositivo esté listo para aceptar más datos del procesador, el módulo de este dispositivo externo manda una señal de petición de interrupción al procesador. El procesador responde suspendiendo la ejecución del programa actual, saltando al manejador de interrupción, y reanudando la ejecución original después de haber atendido al dispositivo. 

El programa de usuario no tiene que contener ningún código especial para tratar las interrupciones: el procesador y el sistema operativo son responsable de suspender el programa de usuario y, posteriormente, reanudarlo en el mismo punto. 

Para tratar las interrupciones, se añade una fase de interrupción al ciclo de instrucción, aquí el procesador comprueba si se ha producido cualquier interrupción, comprobando si hay señal de interrupción. Si no hay interrupciones pendientes, el procesador continúa con la fase de búsqueda y lee la siguiente instrucción del programa actual. Si hay interrupciones pendientes, el procesador suspende la ejecución de la programación actual y ejecuta la rutina del manejador de interrupción, esta rutina es normalmente parte del sistema operativo. 

### PROCESAMIENTO DE INTERRUPCIONES 

Cuando se produce una interrupción, se disparan varios eventos tanto hardware como software. Cuando un dispositivo de E/S completa la operación de E/S se produce la siguiente secuencia de eventos en el hardware: 

1. El dispositivo genera una señal de interrupción hacia el procesador. 
2. El procesador termina la ejecución de la instrucción actual antes de responder a la interrupción. 
3. El procesador comprueba si hay una petición de interrupción pendiente, determina que hay una y manda una señal de reconocimiento al dispositivo. Esto hace que el dispositivo elimine su señal de interrupción. 
4. El procesador se prepara para transferir el control a la rutina de interrupción. Salva la información necesaria para luego poder reanudar el programa actual al momento de la interrupción. Como mínimo será la palabra de estado (PSW) y la posición de la siguiente instrucción, que está contenida en el contador del programa. 
5. El procesador carga el contado del programa con la posición del punto de entrada de la rutina de manejo de interrupción que responder a la interrupción. 

Con el contador de programa cargado, el procesador continúa con el siguiente ciclo de instrucción, comenzando con una lectura de instrucción. Como la lectura de la interrupción está determinada por el contenido del contador del programa, el resultado es que se transfiere el control al programa manejador de interrupción. Lo que lleva a lo siguiente: 

6. El contador de programa y la PSW vinculados con el programa interrumpido se han almacenado en la pila del sistema. También se necesita salvar el contenido de los registros del procesador, puesto que estos registros los podría utilizar el manejador de interrupciones. 
7. El manejador de interrupción puede comenzar a procesar la interrupción, examinando la información de estado relacionada con le operación de E/S o con otro evento distinto que haya causado la interrupción. Esto puede implicar el envío de mandatos adicionales o reconocimientos al dispositivo de E/S. 
8. Cuando se completa el procesamiento de la interrupción, se recuperan los valores de los registros salvados en la pila y se restauran en los registros. 
9. Finalmente, se restauran de la pila los valores de la PSW y del contador de programa, y se continúa con la ejecución del programa previamente interrumpido. 

Es importante salvar toda la información de estado del programa interrumpido para su posterior reanudación, porque una interrupción no es llamada por el programa, se puede producir en cualquier momento. 


## 1.5 TÉCNICAS DE COMUNICACIÓN DE E/S 

### E/S PROGRAMADA 
Cuando el procesador ejecuta un programa y encuentra una instrucción relacionada con la E/S, ejecuta esa instrucción generando un mandato al módulo de E/S apropiado. En el caso de la E/S programada, el módulo de E/S realiza la acción solicitada y fija los bits correspondientes en el registro de estado de E/S, pero no realiza ninguna acción para avisar al procesador. Después de que se llame a la instrucción de E/S, el procesador debe estar atento para enterarse de cuándo se completa la instrucción de E/S. Para eso el procesador comprueba periódicamente el estado del módulo de E/S hasta que se ha completado la operación. 

El procesador es el responsable de extraer los datos de la memoria principal en una operación de salida y de almacenarlos en ella en una operación de entrada. Ejecutará instrucciones que le dan control directo de la operación de E/S, estas instrucciones se pueden dividir en las siguientes categorías: 

* **Control**: activa un dispositivo externo e indicarle que hacer. 
* **Estado**: comprueba las condiciones de estado de un módulo de E/S y sus periféricos. 
* **Transferencia**: lee y/o escribe datos entre los registros del procesador y los dispositivos externos. 

Usando E/S programada para leer un bloque de datos de un dispositivo externo y almacenarlo en memoria, los datos se leerán palabra a palabra. Por cada palabra que se lee, el procesador debe permanecer en un bucle de comprobación del estado hasta que se comprueba que la palabra está disponible en el registro de datos del módulo de E/S. 

### E/S DIRIGIDA POR INTERRUPCIONES 

El problema de la E/S programada es que como el procesador tiene que estar comprobando repetidamente el estado del módulo de E/S, baja enormemente el nivel de rendimiento de todo el sistema. 

Una solución puede ser que el procesador genere un mandato de E/S para un módulo y seguidamente continúe realizando otras operaciones. El módulo de E/S interrumpirá al procesador para solicitar su servicio cuando esté listo para intercambiar datos. El procesador ejecutara la transferencia de datos y después reanudara el procesamiento previo. 

Desde el punto de vista del procesador, se genera un mandato de LECTURA. Salva el contexto del programa actual y lo abandona, pasando a hacer otra cosa. Al final de cada ciclo de instrucción, el procesador comprueba si hay interrupciones. Cuando se produce la interrupción del módulo de E/S, el procesador salva el contexto del programa que se está ejecutando actualmente y comienza a ejecutar un programa de manejo de interrupción que procesa la interrupción. En este caso, el procesador lee la palabra de datos del módulo de E/S y la almacena en memoria. A continuación, restaura el contexto del programa que había realizado el mandado de E/S y reanuda su ejecución. 

### ACCESO DIRECTO A MEMORIA 

La E/S dirigida por interrupciones, aunque más eficiente que la programada simple, todavía requiere la intervención activa del procesador para transferir datos entre la memoria y un módulo de E/S, ya que cualquier transferencia de datos debe pasar por el procesador 
produciendo dos inconvenientes: 

1. La tasa de transferencia de E/S está limitada por la velocidad con la que el procesador puede comprobar el estado de un dispositivo y ofrecerle servicio. 
2. El procesador está involucrado en la gestión de una transferencia de E/S; se deben ejecutar varias instrucciones por cada transferencia de E/S.

Cuando se van a transferir grandes volúmenes de datos, se requiere una técnica más eficiente: el **Acceso Directo a Memoria (Direct Memory Access, DMA)**. La función del DMA puede llevarla a cabo un módulo separado conectado en el bus del sistema o puede estar incluida en un módulo de E/S. En cualquier caso, la técnica funciona como se describe a continuación. Cuando el procesador desea leer o escribir un bloque de datos, genera un mandato al módulo de DMA, enviándole la siguiente información: 

* **Si se trata de una lectura o de una escritura**. 
* **La dirección del dispositivo de E/S involucrado**. 
* **La posición inicial de memoria en la que se desea leer los datos o donde se quieren escribir**. 
* **El número de palabras que se pretenden leer o escribir**.

A continuación, el procesador continúa con otro trabajo. Ha encargado esta operación de E/S al módulo de DMA, que se ocupará de la misma. El módulo de DMA transferirá el bloque completo de datos, palabra a palabra, hacia la memoria o desde ella sin pasar a través del procesador. Por tanto, el procesador solamente está involucrado al principio y al final de la transferencia. 

El módulo de DMA necesita tomar el control del bus para transferir datos hacia la memoria o desde ella. Debido a esta competencia en el uso del bus, puede haber veces en las que el procesador necesita el bus y debe esperar al módulo de DMA. Nótese que esta no es una interrupción; el procesador no salva un contexto y pasa a hacer otra cosa. En su lugar, el procesador se detiene durante un ciclo de bus (el tiempo que se tarda en transferir una palabra a través del bus). El efecto global es causar que el procesador ejecute más lentamente durante una transferencia de DMA en el caso de que el procesado requiera acceso al bus. Sin embargo, para una transferencia de E/S de múltiples palabra, el DMA más eficiente que la E/S dirigida por interrupciones o la programada. 


## 1.6 CONTROL DE PROCEDIMIENTOS 

### IMPLEMENTACION DE LA PILA 

Una pila es un conjunto ordenado de elementos al que en cada momento sólo se puede acceder al que se haya añadido más recientemente. 

Para implementar una pila es necesario reservar en la memoria principal un bloque contiguo de posiciones en las que se irán guardando los elementos de la misma. Son necesarias tres direcciones para que la pila funcione correctamente: 

* **Puntero de pila**: contiene la dirección de la cima de la pila, cambiará cuando se añadan o extraigan elementos de la misma. 
* **Base de pila**: contiene la dirección de la primera posición que se utiliza para añadir un elemento a la pila vacía. 
* **Límite de la pila**: contiene la dirección de la cima del bloque reservado para la pila. 

### LLAMADAS Y RETORNOS DE PROCEDIMIENTOS 

Se usan pilas para gestionar las llamadas y los retornos de los procedimientos. Cuando se ejecuta una llamada, se almacena la dirección de retorno en la pila. Cuando se ejecuta el retorno, se usa la dirección de la cima de la pila y se elimina de la pila. 

Cuando es necesario pasar parámetros en una llamada a procedimiento, una de las mejores formas es pasar los parámetros a la pila conjuntamente con la dirección de retorno, porque los parámetros de retorno se podrán almacenar también en la pila, debajo de la dirección de retorno. Todo el conjunto de parámetros que se almacena en la invocación de procedimiento se denomina pila. 


***
# TEMA 2: INTRODUCCIÓN A LOS SISTEMAS OPERATIVOS


## 2.1 OBJETIVOS Y FUNCIONES DE LOS SISTEMAS OPERATIVOS 

Un sistema operativo es un programa que controla la ejecución de aplicaciones y programas que actúa como interfaz entre las aplicaciones y el hardware del ordenador. Tiene 3 objetivos. 

* **Facilidad de uso**. Un sistema operativo facilita el uso de un ordenador. 
* **Eficiencia**. Un sistema operativo permite que los recursos de un ordenador se puedan usar de forma más eficiente. 
* **Capacidad para evolucionar**. Un sistema operativo debe construirse de forma que se puedan añadir nuevas funciones sin interferir con sus servicios. 

### EL SISTEMA OPERATIVO COMO UNA INTERFAZ DE USUARIO/ORDENADOR 

El sistema operativo debe proporcionar normalmente servicios en las siguientes áreas: 

* **Desarrollo de programas**. Se deben ofrecer una variedad de utilidades y servicios, como editores y depuradores, para ayudar al programador en la creación de los programas. Ejecución de programas. Realizando labores de planificación en nombre del usuario. 
* **Ejecución de programas**. Se necesita realizar una serie de pasos para ejecutar un programa. Las instrucciones y los datos se deben cargar en memoria principal. Los dispositivos de E/S y los ficheros se deben inicializar, y otros recursos deben preparar. 
* **Acceso a dispositivos de E/S**. Simplificando la forma en la que los programadores pueden acceder a dichos dispositivos mediante lecturas y escrituras sencillas. 
* **Acceso controlado a ficheros**. Proporcionando la estructura y los mecanismos de protección para acceder a ellos. 
* **Acceso al sistema**. Protegiendo los recursos y datos, evitando usos no autorizados y resolviendo conflictos. 
* **Detección y respuestas a errores**. Dando respuestas a los errores tanto hardware como software del sistema, finalizando el programa, reintentando la operación o informando del error. 
* **Contabilidad**. Recogiendo estadísticas de uso y parámetros de rendimiento para anticipar necesidades futuras y optimizar su rendimiento. 

### EL SISTEMA OPERATIVO COMO GESTOR DE RECURSOS 

El sistema operativo se encarga de gestionar los recursos que tiene un ordenador, controlando el transporte, almacenamiento y procesamiento de los datos, aunque teniendo en cuenta que: 

* Las funciones del sistema operativo funcionan como las del resto del software, es un programa o conjunto de programas ejecutados por el procesador. 

* Este cede el control y depende del procesador para retomarlo. 

El sistema operativo es un conjunto de programas como otro cualquiera que proporciona instrucciones al procesador, pero con la gran diferencia de que es el que dirige al procesador en el uso de los demás recursos del sistema y la temporización de la ejecución de otros programas. 

### FACILIDAD DE EVOLUCION DE UN SISTEMA OPERATIVO 

Un sistema operativo debe evolucionar con el tiempo por las siguientes razones: 

* **Actualizaciones de hardware más nuevos tipos de hardware**. Deberán ser capaces de gestionar los nuevos tipos de hardware que vayan apareciendo para aprovechar al máximo el rendimiento que ofrezcan. 
* **Nuevos servicios**. Deberán ofrecer nuevos servicios en función a la de los usuarios o a la demanda de los gestores del sistema. 
* **Resolución de fallos**. Siempre pueden producirse fallos, pero un diseño modular, con interfaces entre los módulos y bien documentado, simplificará las cosas. 


## 2.2 LA EVOLUCIÓN DE LOS SISTEMAS OPERATIVOS

### PROCESAMIENTO SERIE 

Con los primeros ordenadores, el programador interaccionaba directamente con el hardware del ordenador, no existía sistema operativo. Sus principales problemas eran: 

* **Planificación**. Normalmente se solicitaban bloques de tiempo múltiplos de alrededor de media hora. Si se terminaba antes, el tiempo restante era desperdiciado, y si no daba tiempo a finalizar, era forzado a terminar. 
* **Tiempo de configuración**. Se tardaba una cantidad considerable de tiempo en configurar el programa que se iba a usar, y si se producía un error, el usuario normalmente tenía que volver a empezar. 

### SISTEMAS EN LOTES SENCILLOS 

La idea central es el uso de una pieza software, el monitor. Con este tipo de sistema operativo, el usuario no tiene acceso directamente a la máquina. El usuario envía un trabajo al operador del ordenador, este crea un sistema por lotes con todos los trabajos enviados y coloca la secuencia de trabajos en el dispositivo de entrada, para que lo utilice el monitor. 

Cuando un programa finaliza, devuelve el control al monitor, comenzando el monitor la carga del siguiente programa. 

El monitor, o sistema operativo por lotes, es simplemente un programa. Depende de que el procesador cargue correctamente las instrucciones en la memoria principal que le deje alternativamente tomar y abandonar el control. 

### SISTEMAS EN LOTES MULTIPROGRAMADOS 

El problema de los sistemas en lotes está en que los dispositivos de E/S son lentos comparados con el procesador, por lo que procesador se suele encontrar desocupado muchas veces durante su tiempo de trabajo. 

Para evitar esto, cuando un trabajo necesita esperar por la E/S, se puede asignar el procesador a otro trabajo que no esté esperando por una operación de E/S. La mejor opción es aumentar la memoria para que pueda almacenar varios programas y pueda haber multiplexación entre ellos. Esto es la multiprogramación o multitarea. 

Es necesario disponer de un hardware que soporte las interrupciones de E/S y DMA. Al gestionar la E/S mediante interrupciones o DMA, el procesador puede solicitar la E/S de un trabajo y, mientras seguir con la ejecución de otro trabajo hasta que se gestione le operación de E/S. Cuando esta finaliza, el procesador es interrumpido y se pasa el control a un programa de tratamiento de interrupciones del sistema operativo, pasando el sistema operativo a otro trabajo. 

### SISTEMAS DE TIEMPO COMPARTIDO 
Aunque el uso de multiprogramación es muy eficiente, para otro tipos de trabajos, es más útil tener un modo mediante el cual el usuario interaccione directamente con el procesador. 

Tiempo compartido es compartir el tiempo de procesador entre múltiples usuarios. En un sistema de tiempo compartido, múltiples usuarios acceden simultáneamente al sistema a través de terminales, siendo el sistema operativo el encargado de entrelazar la ejecución de cada programa de usuario en pequeños intervalos de tiempo. 

La compartición de tiempo y la multiprogramación implican nuevos problemas para el sistema operativo. Si existen múltiples trabajos en memoria, deben protegerse para que evitar que interfieran entre sí. Con múltiples usuarios interactivos, el sistema de ficheros debe ser protegido, sólo usuarios autorizados deberán tener acceso a un archivo concreto. También deberán gestionarse conflictos entre recursos, como impresoras o dispositivos de almacenamiento masivo. 


## 2.3 PRINCIPALES LOGROS 

Los cinco principales avances teóricos en el desarrollo de los sistemas operativos: 

* **Procesos**. 
* **Gestión de memoria**. 
* **Protección y seguridad de la información**. 
* **Planificación y gestión de los recursos**. 
* **Estructura del sistema**. 

### PROCESOS 

Definiciones dadas a proceso: 

* Un programa en ejecución. 
* Una instancia de un programa ejecutándose en un ordenador. 
* La entidad que se puede asignar o ejecutar en un procesador. 
* Una unidad de actividad caracterizada por un solo hilo secuencial de ejecución, un estado actual, y un conjunto de recursos del sistema asociado. 

La principal herramienta disponible para que los programadores desarrollasen inicialmente la multiprogramación y los sistemas interactivos fue la interrupción, pero el diseño del software del sistema para coordinar estas actividades resultó ser muy complicado. Para facilitar esta tarea, es necesaria una forma sistemática de monitorizar y controlar la ejecución de varios programas en el procesador. El concepto de proceso proporciona los fundamentos. Un proceso está formado por los siguientes componentes: 

* Un programa ejecutable. 
* Los datos asociados que necesita el programa (variables, espacio de trabajo, buffers) 
* El contexto de ejecución del programa. 

Este último es esencial. El contexto de ejecución, o estado del proceso, es el conjunto de datos interno por el cual el sistema operativo es capaz de supervisar y controlar el proceso. Esta información interna está separada del proceso, porque el sistema operativo tiene información a la que el proceso no puede acceder. El contexto incluye todo la información que el sistema operativo necesita para gestionar el proceso y que el procesador necesita para ejecutar el proceso apropiadamente. Además, incluye el contenido de diversos registros del procesador, tales como el contador de programa y los registro de datos. También incluye información de uso del sistema operativo, como la prioridad del proceso y si un proceso está esperando por la finalización de un evento de E/S particular. 

Un proceso puede estar en ejecución o esperando ejecutarse. El estado completo del proceso en un instante dado se contiene en su contexto. 

### GESTION DE MEMORIA 

Cinco responsabilidades principales del sistema operativo para la gestión de almacenamiento: 

* **Aislamiento del proceso**. El sistema operativo debe evitar que los procesos independientes interfieran en la memoria de otro proceso. 
* **Asignación y gestión automática**. Los programas deben tener una asignación dinámica de memoria. La asignación debe ser transparente al programador. 
* **Soporte a la programación modular**. Los programadores deben ser capaces de definir módulos de programación y crear, destruir, y alterar el tamaño de los módulos dinámicamente. 
* **Protección y control de acceso**. La compartición de memoria permite que un programa direccione un espacio de memoria de otro proceso. Esto es útil cuando se necesita la compartición por parte de determinadas aplicaciones, pero otras veces amenaza la integridad de los programas e incluso el sistema operativo. El propio sistema operativo debe permitir que varios usuarios puedan acceder de distintas formas a porciones de memoria. 
* **Almacenamiento a largo plazo**. Muchas aplicaciones deben almacenar la información durante largos periodos de tiempo, después que el ordenador se haya apagado. 

Esto se consigue con el uso de la memoria virtual, una utilidad que permite a los programas direccionar la memoria desde un punto de vista lógico, sin importar la cantidad de memoria principal física disponible. Se utilizan sistemas de paginación para comprimir los procesos en un determinar número de bloque de tamaño fijo, llamados páginas. Un programa referencia una palabra por medio de una dirección virtual, que consiste en un número de página y un desplazamiento dentro de la página. La paginación proporciona una proyección dinámica entre las direcciones de memoria virtuales utilizadas en el programa y una dirección real, o dirección física de memoria principal. 

El hardware del procesador, junto con el sistema operativo, dota al usuario de un "procesador virtual" que tiene acceso a la memoria virtual. Este almacén podría ser un espacio de almacenamiento lineal o una colección de segmentos, que son bloques de longitud variable de direcciones contiguas. En ambos casos, las instrucciones del lenguaje de programación pueden referenciar al programa y a las ubicaciones de los datos en el área de memoria virtual. El aislamiento de los procesos se puede lograr dando a cada proceso una única área de memoria virtual, que no se solape con otras áreas. La compartición de memoria se puede logar a través de porciones de dos espacios de memoria virtual que se solapan. Los ficheros se mantienen en un almacenamiento a largo plazo. Los ficheros o parte de los mismos se pueden copiar en la memoria virtual para que los programas los manipulen. 

### PROTECCION Y SEGURIDAD DE INFORMACIÓN 

La mayoría del trabajo en seguridad y protección relacionada con los sistemas operativos se puede agrupar de forma genérica en cuatro categorías: 

* **Disponibilidad**. Relacionado con la protección del sistema frente a las interrupciones. 
* **Confidencialidad**. Asegura que los usuarios no puedan leer los datos sobre los cuales no tiene autorización de acceso. 
* **Integridad de los datos**. Protección de los datos frente a modificaciones no autorizadas. 
* **Autenticidad**. Relacionado con la verificación apropiada de la identidad de los usuarios y la validez de los mensajes o los datos. 

### PLANIFICACIÓN Y GESTIÓN DE LOS RECURSOS 

Una responsabilidad clave de los sistemas operativos es la gestión de varios recursos disponible para ellos (espacio de memoria principal, dispositivos de E/S, procesadores) y para planificar su uso por parte de los distintos procesos activos. Cualquier asignación de recursos y política de planificación debe tener en cuenta tres factos: 

* **Equitatividad**. Todo proceso que compite por un recurso debe tener un acceso equilibrado a dicho recurso. 
* **Respuesta diferencial**. El sistema operativo debe tomar las decisiones de asignación y planificación con el objetivo de satisfacer el conjunto total de requisitos, aunque sea discriminando entre diferentes clases de trabajos con diferentes requisitos de servicio. 
* **Eficiencia**. El sistema operativo debe intentar maximizar la productividad, minimizar el tiempo de respuesta, y, en caso de sistemas de tiempo compartido, acomodar tantos usuarios como sea posible. 

El sistema operativo mantiene un número de colas, cada una de las cuales es simplemente una lista de procesos esperando por algunos recursos. La cola a corto plazo está compuesta por procesos que se encuentran en memoria principal y están listos para ejecutar. Cualquiera de estos procesos podría usar el procesador a continuación. El planificador a largo plazo (dispatcher) debe elegir uno de ellos mediante alguna técnica de asignación. 

La cola a largo plazo es una lista de nuevos trabajos esperando a utilizar el procesador. El sistema operativo añade trabajos al sistema transfiriendo un proceso desde la cola a largo plazo hasta la cola a corto plazo. En este punto, se debe asignar una porción de memoria principal al proceso entrante. El sistema operativo debe no sobrecargar la memoria o el tiempo de procesamiento admitiendo demasiados procesos. Hay una cola de E/S por cada dispositivo de E/S. todos los procesos que esperan utilizar un dispositivo, se encuentran en la cola del mismo. El sistema operativo determinará a qué proceso le asigna un dispositivo de E/S disponible. Si ocurre una interrupción, el sistema operativo recibe el control del procesador a través de un manejador de interrupciones. 


***
# TEMA 3: DESCRIPCIÓN Y CONTROL DE PROCESOS


## 3.1 ¿QUÉ ES UN PROCESO?

### PROCESOS Y BLOQUES DE CONTROL DE PROCESOS 

Otra forma de ver un proceso puede ser el de una entidad que consiste en un número de elementos. Los dos elementos esenciales serian el código de programa (que puede compartirse con otros procesos que estén ejecutando el mismo programa) y un conjunto de datos asociados a dicho código. Cuando el procesador comience con la ejecución de dicho código de programa, este proceso tendrá las siguientes características: 

* **Identificador**. 
* **Estado**. 
* **Prioridad**. 
* **Contador de programa**. 
* **Punteros a memoria**. Los punteros al código de programa y los datos asociados a dicho proceso, además de cualquier bloque de memoria compartido con otros procesos. 
* **Datos de contexto**. Los datos que están en los registros del procesador cuando el proceso está corriendo. 
* **Información de estado de E/S**. Las peticiones de E/S pendientes, dispositivos de E/S asociados a dicho proceso, una lista de los ficheros en uso por el mismo, etc. 
* **Información de auditoria**. Datos como la cantidad de tiempo de procesado y de tiempo de reloj utilizados, límites de tiempo, registros contables, etc.

Todos los puntos anteriores son almacenados en una estructura de datos que recibe el nombre de **PCB (Process Control Block o Bloque de Control de Proceso)**, el sistema operativo lo crea y lo gestiona. El PCB tiene la suficiente información para interrumpir el proceso cuando está corriendo y posteriormente restaurarlo a sus estado de ejecución como si nunca se hubiese interrumpido, gracias a esto se podrá permitir la multiprogramación, ya que el sistema operativo podrá dar soporte a varios procesos simultáneamente. 


## 3.2 ESTADOS DE LOS PROCESOS

Se acaba de ver que para que un programa se ejecute, se debe crea un proceso para dicho programa. La ejecución de un programa significará la ejecución de una secuencia de instrucciones dentro de dicho programa, el listado de las secuencias de instrucciones que se ejecutan para un proceso, recibe el nombre de traza del proceso. 

Si existen varios programas en ejecución en memoria principal, el encargado de intercambiar el procesador de un proceso a otro es el **activador o dispatcher**. 

### UN MODELO DE PROCESOS DE DOS ESTADOS 

Básicamente un proceso puede estar en dos estados: Ejecutando o No ejecutando. Cuando el sistema operativo crea un proceso, crea un PCB asociado a este y lo introduce en el sistema en estado No ejecutando. Cuando se interrumpa la ejecución actual en el procesador, el dispatcher buscará otro proceso a ejecutar. Los procesos que no están en ejecución, estarán en una cola, esperando su turno de ejecución. 

### CREACIÓN Y TERMINACIÓN DE PROCESOS 

**CREACIÓN DE UN PROCESO**. Cuando se va a añadir un nuevo proceso, el sistema operativo crea su PCB y le reserva el espacio de direcciones en memoria principal. Cuando el sistema operativo crea un proceso por petición explicita de otro, dicha acción se llama creación del proceso. Al primero se le llamará proceso padre y al creado, proceso hijo. 

**TERMINACIÓN DE UN PROCESO**. Todo sistema debe proporcionar los mecanismos mediantes los cuales un proceso indica su finalización o que ha completado su tarea, una instrucción que generará una interrupción para indicar al sistema operativo que dicho proceso ha finalizado. Para finalmente, solicitar un servicio al sistema operativo para terminar con el proceso saliente. En algunos sistemas operativos, un proceso hijo puede finalizar por parte del proceso padre o porque dicho proceso padre también haya terminado su ejecución. 

### MODELO DE PROCESO DE CINCOS ESTADOS 

Es posible que un proceso en estado No ejecutándose este listo para ejecutarse, mientras que otro este bloqueado por un operación de E/S. Si el dispatcher sólo se fija en que proceso lleva más tiempo en la cola, se podrán producir situaciones como la descrita, algo que no interesa. 

Se deben dividir los procesos en 5 estados: 

* **Ejecutando**
* **Listo**
* **Bloqueado**
* **Nuevo**
* **Saliente**

Los posibles cambios de estado son los siguientes: 

* **Null -> Nuevo**
* **Nuevo -> Listo**
* **Listo -> Ejecutando**
* **Ejecutando -> Saliente**
* **Ejecutando -> Listo**
* **Ejecutando -> Bloqueado**
* **Bloqueado -> Listo**
* **Listo -> Saliente**
* **Bloqueado -> Saliente**

Esto hace la idea de considerar un esquema con dos colas: la cola de Listos y la cola de Bloqueados. Cuando un proceso es admitido por el sistema, se añade a la cola de Listos. Cuando el sistema tenga que seleccionar otro proceso a ejecutar, lo hará de la cola de Listos. Cuando un proceso en ejecución termina de utilizar el procesador, o finaliza, o pasa a la lista de Listos o Bloqueados. El último caso posible, es que cuando se produce un evento, si un proceso de la lista de Bloqueados estaba esperando a dicho evento, este se mueve a la lista de Listos. 


## 3.3 CONTROL DE PROCESOS 

### MODOS DE EJECUCIÓN 

Hay instrucciones que sólo se pueden ejecutar en modos privilegiados, como podrían ser: lectura y modificación de los registros de control, instrucciones de E/S primitivas e instrucciones relacionadas con la gestión de memoria. Además, ciertas regiones de memoria sólo se pueden acceder en modos privilegiados. 

El modo menos privilegiado se suele llamar **modo usuario**, porque los programas de usuaria normalmente se ejecutan en ese modo. El modo más privilegiado se denomina modo sistema, **modo control o modo núcleo o kernel**, este último en referencia al núcleo del sistema operativo, la parte del sistema operativo que engloba las funciones más importante del sistema. 

Es necesario que existan diferentes modos de ejecución para proteger al sistema operativo y, a las tablas clave del sistema, como el PCB, de la interferencia con programas de usuario. En modo kernel, el software tiene control completo del procesador y de sus instrucciones, registros y memoria. 

El procesador conoce el modo en el que está ejecutándose gracias a un bit en la PSW que indica esto. Este puede cambiar cuando un usuario realiza una llamada a un servicio del sistema operativo o cuando una interrupción dispara la ejecución de una rutina del sistema operativo, este modo de ejecución se cambia a modo kernel y cuando finaliza el servicio, el modo vuelve a usuario. 

### CREACIÓN DE PROCESOS 

Cuando el sistema operativo crea un proceso, lleva a cabo los siguientes pasos: 

1. **Asignar un identificador de proceso único al proceso**. Añadiendo una nueva entrada a la tabla primaria de procesos. 
2. **Reservar espacio para el proceso**. Para lo que el sistema operativo debe conoce cuanta memoria es necesaria para el espacio de direcciones privado (programas y datos), para la pila de usuario y el PCB. 
3. **Inicialización del PCB**. Con la dirección inicial de comienzo del programa, la dirección de la pila de sistema, la memoria donde reside el programa y el resto de campos inicializados con valores por omisión. 
4. **Establecer los enlaces apropiados**. El proceso debe situarse en la cola que le corresponda. 
5. **Creación o expansión de otras estructuras de datos**. Como puede ser mantener un registro de auditoria por cada proceso para utilizarlo posteriormente con algún fin específico. 

### CAMBIO DE PROCESO 

El cambio de proceso permite que se turnen los procesos en ejecución en el procesador, esto se producirá cuando se interrumpa la ejecución de un proceso y el sistema operativo asigne el estado en Ejecutando a otro proceso. 

Un cambio de proceso se puede producir en cualquier momento en el que el sistema operativo obtiene el control sobre el proceso en ejecución.

Hay dos tipos de interrupciones de sistema, las interrupciones normales y las traps. Las primeras se producen por causa de algún tipo de evento que es externo e independiente al proceso actualmente en ejecución, como la finalización de la operación de E/S. Las otras están asociadas a una condición de error o excepción generada dentro del proceso que esta ejecutando, como un intento de acceso no permitido a un fichero. 

Con una interrupción normal, el control se transfiere al manejador de interrupción, que realiza determinadas tareas internas y posteriormente salta a una rutina del sistema operativo. 

Con una trap, el sistema operativo conoce si una condición de error o de excepción es irreversible, cuyo caso, el proceso en ejecución cambia su estado a Saliente y se hace un cambio de proceso. Sino, se puede intentar un procedimiento de recuperación o simplemente la notificación al usuario. 

### CAMBIO DE MODO 

En la fase de interrupción, el procesador comprueba que no exista ninguna interrupción pendiente, indicada por la presencia de una señal de interrupción. Si no hay interrupciones pendientes, el procesador pasa a la fase de búsqueda de instrucción, siguiendo con el programa del proceso actual. Si hay una interrupción pendiente, el proceso actúa de la siguiente manera: 

1. Coloca el contador de programa en la dirección de comienzo de la rutina del programa manejador de la interrupción. 
2. Cambia de modo usuario a modo kernel de forma que el código de tratamiento de la interrupción pueda incluir instrucciones privilegiadas. 

El procesador, acto seguido, pasa a la fase de búsqueda de instrucción y busca la primera instrucción del programa de manejo de interrupción, que dará servicio a la misma. En ese punto, habitualmente, el contexto del proceso que se ha interrumpido se salvaguarda en el bloque de control de proceso del programa interrumpido. 

El cambio de contexto a guardar será toda la información que se pueda ver alterada por la ejecución de la rutina de interrupción y que se necesitara para la continuación del proceso que ha sido interrumpido. Se guardará la parte del PCB del proceso que hace referencia a la información de estado del procesador: el contador de programa, otros registros del procesador y la información de la pila. Normalmente esto es hecho por el hardware. 

### CAMBIO DEL ESTADO DEL PROCESO 

Pasos para realizar completamente un cambio de proceso: 

1. Salvar el estado del procesador, incluyendo el contador de programa y otros registros. 
2. Actualizar el bloque de control del proceso que está actualmente en el estado Ejecutando, una cosa será cambiar el estado del proceso. También se tienen que actualizar otros campos importantes, incluyendo la razón por la cual el proceso ha dejado el estado de Ejecutando y demás información de auditoría. 
3. Mover el bloque de control de proceso a la cola apropiada.
4. Selección de un nuevo proceso a ejecutar. 
5. Actualizar el bloque de control del proceso elegido. Esto incluye pasarlo al estado Ejecutando. 
6. Actualizar las estructuras de datos de gestión de memoria. 
7. Restaurar el estado del proceso al que tenía en el momento cuando salió del estado Ejecutando por última vez, leyendo los valores anteriores de contador de programa y registros. 


***
# TEMA 4: HILOS, SMP Y MICRONÚCLEOS

## 4.1 PROCESOS E HILOS 

Un proceso tiene dos características: 

* **Propiedad de recursos**. Un proceso incluye un espacio de direcciones virtuales para el manejo de la imagen del proceso. Puede tener asignado el control o propiedad de recursos tales como la memoria principal, canales E/S, dispositivos E/S y archivos. 
* **Planificación/ejecución**. La ejecución de un proceso sigue una ruta de ejecución (traza) a través de uno o más programas. Esta ejecución puede estar intercalada con ese u otros procesos. De esta manera, un proceso tiene un estado de ejecución y una prioridad de activación y ésta es la entidad que se planifica y activa por el sistema operativo. 

Estas dos características son independientes y de esa forma pueden ser reconocidas por el sistema operativo. La unidad que se activa se suele denominar **hilo (thread) o hebra** mientras que la unidad de propiedad de recursos se suele denominar **proceso o tarea**. 

### MULTIHILO 

Multihilo se refiere a la capacidad de un sistema operativo de dar soporte a múltiples hilos de ejecución en un solo proceso. 

En un entorno multihilo, un proceso se define como la unidad de asignación de recursos y una unidad de protección Se asocian con procesos los siguientes: 

* Un espacio de direcciones virtuales que soporta la imagen del proceso. 
* Acceso protegido a procesadores, otros procesos (para comunicación entre procesos), archivos y recursos de E/S (dispositivos y canales). 

Dentro de un proceso puede haber uno o más hilos, cada uno con: 

* Un estado de ejecución por hilo. 
* Un contexto de hilo que se almacena cuando no está en ejecución; una forma de ver a un hilo es como un contador de programa independiente dentro de un proceso. 
* Una pila de ejecución. 
* Por cada hilo, espacio de almacenamiento para variables locales. 
* Acceso a la memoria y recursos de su proceso, compartido con todos los hilos de su mismo proceso. 

Todos los hilos de un proceso comparten el estado y los recursos de ese proceso, residen en el mismo espacio de direcciones y tiene acceso a los mismos datos. 

Beneficios de los hilos: 

1. Es mucho más rápido crear un hilo de un proceso que crear un proceso nuevo. 
2. Lleva menos tiempo finalizar un hilo que un proceso. 
3. Lleva menos tiempo cambiar entre dos hilos dentro del mismo proceso. 
4. Los hilos mejoran la eficiencia de la comunicación entre diferentes programas que están ejecutando. 

### FUNCIONALIDAD DE LOS HILOS 

**ESTADOS DE LOS HILOS**. Hay cuatro operaciones básicas de hilos asociadas con un cambio de estado del hilo: 

* **Creación**
* **Bloqueo**
* **Desbloqueo**
* **Finalización**

**SINCRONIZACIÓN DE LOS HILOS**. Todos los hilos de un proceso comparten el mismo espacio de direcciones y otros recursos, como por ejemplo, los archivos abiertos. Cualquier alteración de un recurso por cualquiera de los hilos, afecta al entorno del resto de los hilos del mismo proceso. Por tanto, en necesario sincronizar las actividades de los hilos para que no interfieran entre ellos o corrompan estructuras de datos. 


***
# TEMA 5: GESTIÓN DE MEMORIA


## 5.1 REQUISITOS DE LA GESTIÓN DE MEMORIA 

### CARGA ABSOLUTA 

El primer paso en la creación de un proceso activo es cargar un programa en memoria principal y crear una imagen del proceso. La aplicación está formada por varios módulos compilados o ensamblados en formato de código objeto. 

La asignación de valores de direcciones específicas a referencias de programa dentro de un programa lo puede hacer el programador o se hacen en tiempo de compilación o ensamblado. 

Las desventajas de la primera opción son que el programa debe conocer la estrategia de asignación para colocar los módulos en memoria principal y, que si se hace cualquier modificación en el programa que suponga inserciones o borrados en el cuerpo del módulo, tendrán que cambiarse todas las direcciones. Es mejor que las referencias a memoria dentro de los programas se hagan simbólicamente, para así resolver esas referencias simbólicas en tiempo de compilación o ensamblado. 

### REUBICACIÓN 

Cuando un programa que estaba cargado en memoria principal, es llevado a disco, es difícil que al volver a memoria principal, pueda volver a ocupar el espacio que ocupaba, por lo que se deberá reubicar a un área de memoria diferente. 

En el código del programa se podrán encontrar instrucciones de salto que contengan una dirección para referenciar la instrucción que se va a ejecutar a continuación y, instrucciones de referencia de los datos, que contendrán la dirección del byte o palabra de datos referenciados. El hardware del procesador y el software del sistema operativo deben poder traducir las referencias anteriores en direcciones de memoria física, que será donde se encuentra actualmente el programa dentro de la memoria principal. 


## 5.2 PAGINACIÓN 

Consiste en dividir la memoria principal en pequeñas partes de tamaño fijo, y dividir también cada proceso en partes del mismo tamaño. A las partes de los procesos, se les da el nombre de página, y se les asigna una parte disponible de la memoria, que recibirán el nombre de marcos o marco de página. 

Deberá existir una tabla de páginas por cada proceso, que mostrará la ubicación del marco por cada página del proceso. Dentro del programa, cada dirección lógica está formada por un número de página y un desplazamiento dentro de la página. Cuando la CPU genera una dirección lógica (número de página, desplazamiento), la misma CPU utilizará la tabla de páginas para obtener la correspondiente dirección física (número de marco, desplazamiento). 


## 5.3 SEGMENTACIÓN 

Consiste en dividir un programa y sus datos asociados en segmentos. No todos tienen que ser de la misma longitud, aunque hay una longitud máxima para los segmentos. Una dirección lógica estará compuesta por dos partes, un número de segmento y un desplazamiento. 

Al ser los segmentos de distinto tamaño, no hay una relación simple entre direcciones lógicas y direcciones físicas. Un esquema de segmentación sencillo usara una tabla de segmentos por cada proceso y una lista de bloques libres de memoria principal. Cada entrada de la tabla tendrá que dar la dirección inicial en memoria principal del correspondiente segmento y la longitud del segmento. 

Cuando un proceso es llevado a memoria, todos sus segmentos se cargan en regiones de memoria disponibles y, se crea la tabla de segmentos. 
