# Introducción al Proyecto Philosophers

- Este proyecto se centra en la programación concurrente. Te reta a resolver un problema clásico de la programación, diseñado para enseñar cómo gestionar recursos compartidos entre múltiples procesos de forma eficiente y sincronizada. Los conceptos clave de este proyecto son la concurrencia, la sincronización y el uso de **hilos** y **mutexes**.

- En el problema que abordarás, un grupo de filósofos debe alternar entre tres actividades esenciales: **comer, pensar y dormir**. Sin embargo, su acceso a los recursos necesarios para comer está limitado, y la solución del problema radica en garantizar que todos los filósofos puedan completar sus ciclos sin interferencias o bloqueos.

## 1. El problema de los filósofos comensales

- Planteado inicialmente por **Edsger Dijkstra**, es una metáfora clásica de la programación concurrente. Donde Varios procesos (los filósofos) deben coordinarse para acceder a recursos compartidos limitados (los tenedores), evitando conflictos como interbloqueos o inanición.

## 1.1 Planteamiento del problema
La premisa es la siguiente podríamos iniciar por ejemplo con un nº de filósofos:

- Cinco filósofos están sentados en una mesa redonda.
  
- Cada filósofo alterna entre tres actividades: **comer** ,**pensar** y **dormir**.
  
- En el centro de la mesa hay cinco tenedores, uno colocado entre cada par de filósofos.
  
- Para que un filósofo pueda comer, necesita dos tenedores: el de su izquierda y el de su derecha.
  
- Una vez que termina de comer, el filósofo deja los tenedores disponibles, pasa a pensar durante un tiempo y, finalmente, se toma un descanso para dormir antes de repetir el ciclo.
  
- La principal dificultad radica en que los recursos compartidos (los tenedores) son limitados. Si los filósofos no se sincronizan adecuadamente, pueden surgir varios problemas:

## 1.2 Problemas principales
**Interbloqueo o deadlock:**

- Esto ocurre cuando cada filósofo toma un tenedor y espera indefinidamente por el otro. En este estado, ningún filósofo puede avanzar, y el sistema queda completamente bloqueado.

**Inanición o starvation:**

- En este caso, uno o más filósofos no logran comer porque otros monopolizan constantemente los recursos, dejando a algunos sin acceso. Este problema se debe a la falta de un mecanismo justo de reparto de los recursos.

**Condiciones de carrera o race conditions:**

- Este problema aparece cuando varios filósofos intentan acceder simultáneamente al mismo recurso, lo que puede generar inconsistencias en el estado de los tenedores y errores impredecibles en el programa.

## 2. Fundamentos teóricos

- El proyecto te introduce a dos conceptos fundamentales en la programación concurrente: los hilos y los mutexes. Estas herramientas te permitirán simular las actividades de los filósofos y gestionar el acceso a los recursos compartidos de forma segura.

## 2.1 Hilos (Threads)

- Un hilo es la unidad más pequeña de ejecución dentro de un programa. A diferencia de los procesos tradicionales, que tienen su propia memoria independiente, los hilos comparten la memoria y los recursos del proceso principal, lo que los hace más ligeros y rápidos. Sin embargo, esta característica también introduce riesgos, ya que un hilo puede modificar datos compartidos por otros hilos, causando errores si no se gestionan adecuadamente.

- En este proyecto, cada filósofo será representado por un hilo independiente. Esto significa que los filósofos podrán comer, pensar y dormir de manera simultánea. Sin embargo, como todos comparten los tenedores, será necesario coordinar sus acciones para evitar conflictos.

- En C, trabajarás con la biblioteca **POSIX Threads (pthreads)**, que proporciona funciones esenciales para crear y gestionar hilos. Algunas de las funciones clave que usarás incluyen:

- **pthread_create:** Crea un nuevo hilo y asigna una función para que este ejecute.
  
- **pthread_join:** Permite que el programa principal espere a que un hilo termine antes de continuar. Esto es útil para asegurar que todos los filósofos completen sus ciclos correctamente.
 
- **pthread_exit:** Finaliza un hilo de forma segura, liberando los recursos asociados.
  
- Además, necesitarás simular el tiempo que los filósofos tardan en realizar cada actividad (comer, pensar y dormir). Para ello, puedes usar funciones como **usleep** para introducir pausas en los hilos.

**Contexto de la concurrencia**

- Aunque los hilos parecen ejecutarse simultáneamente, en realidad el sistema operativo alterna entre ellos, asignándoles pequeños intervalos de tiempo en la CPU. Este comportamiento es conocido como multitarea y puede causar resultados inesperados si los hilos no están sincronizados correctamente. Por esta razón, la sincronización es un aspecto crucial del proyecto.

## 2.2 Exclusión mutua y mutexes

- La exclusión mutua es un mecanismo que asegura que solo un hilo pueda acceder a un recurso compartido en un momento dado. Esto es fundamental para evitar conflictos en programas concurrentes.

- En el proyecto, implementarás exclusión mutua utilizando mutexes, que son estructuras de sincronización diseñadas para proteger recursos compartidos. Un mutex actúa como un “candado” que un hilo debe bloquear antes de acceder a un recurso. Una vez que termina de usar el recurso, debe liberar el mutex para que otros hilos puedan acceder.

- En el contexto del problema de los filósofos, cada tenedor estará asociado a un mutex. Esto significa que:

- Antes de comer, un filósofo debe bloquear los mutexes de los dos tenedores que necesita.
- Después de comer, debe liberar ambos mutexes para que otros filósofos puedan usarlos.
- Las funciones clave para trabajar con mutexes en pthreads son:

- **pthread_mutex_init:** Inicializa un mutex antes de usarlo.
- **pthread_mutex_lock:** Bloquea un mutex, permitiendo que un hilo acceda al recurso que protege. Si el mutex ya está bloqueado, el hilo esperará hasta que esté disponible.
- **pthread_mutex_unlock:** Libera un mutex bloqueado, permitiendo que otros hilos accedan al recurso.
- **pthread_mutex_destroy:** Libera los recursos asociados a un mutex cuando ya no se necesita.
  
- El uso adecuado de mutexes es esencial para evitar problemas como interbloqueos y condiciones de carrera. Sin embargo, diseñar una lógica eficiente para su uso puede ser un desafío, ya que requiere anticipar todas las posibles interacciones entre los hilos.

## 3. Estrategias de solución

- Resolver el problema de los filósofos comensales implica diseñar una solución que evite los problemas de interbloqueo, inanición y condiciones de carrera. Algunas estrategias comunes incluyen:

## 3.1 Asignación ordenada de recursos
En esta estrategia, los filósofos toman los tenedores en un orden específico. Por ejemplo:

- Algunos filósofos pueden tomar primero el tenedor de la izquierda y luego el de la derecha, mientras que otros toman primero el de la derecha. Esto evita que todos intenten acceder a los mismos recursos al mismo tiempo.
  
## 3.2 Control del número de filósofos
Otra solución consiste en limitar el número de filósofos que pueden intentar comer al mismo tiempo. Esto garantiza que siempre haya suficientes tenedores disponibles para al menos un filósofo.

## 3.3 Introducción de jerarquías
Puedes asignar una jerarquía a los tenedores y forzar a los filósofos a tomarlos en un orden estricto (por ejemplo, siempre de menor a mayor). Esto elimina los ciclos en el sistema, evitando el riesgo de interbloqueo.

## 4. Conclusión

- El proyecto Philosophers es una introducción práctica al mundo de la programación concurrente y te prepara para enfrentar desafíos reales en el desarrollo de sistemas modernos. Además de los conceptos técnicos, te enseña a analizar problemas, diseñar soluciones eficientes y garantizar la estabilidad y sincronización de un sistema.

