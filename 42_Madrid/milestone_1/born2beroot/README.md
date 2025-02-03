 [![COMMONCORE 0](https://img.shields.io/badge/%20%20<<%20C%20O%20M%20M%20O%20N%20%20C%20O%20R%20E%20%20-c988f9)](https://github.com/fran-byte/Cursus-42-Madrid)

<div align="center"> 

<a href="#"><img src="https://img.shields.io/badge/%20%20Born2beroot%20%20-4682B4" style="width:150px;height:40px;"></a>

</div>

# Born2BeRoot en Debian

# Tutorial  (Solamente Parte Obligatoria)

➤ Creamos la máquina virtual y la imagen de Debian en mi directorio **sgoinfre**, un servidor accesible desde la red de la Escuela 42. Este servidor de documentos tiene un directorio con tu nombre de usuario al que solo tú puedes acceder, a diferencia de **goinfre**. La carpeta **sgoinfre** permite almacenar más documentos y su contenido es diferente en cada computadora.

➤ Si colocas tu máquina virtual en **sgoinfre**, puedes cambiar de computadora durante tu proyecto. En cambio, si la colocas en **goinfre**, debes quedarte en la misma computadora.

## 1- Descargando ISO de Debian e instalando Virtual Box

➤ Crearemos una máquina virtual vacía. Para configurarla posteriormenete.

➤ Lins de descarga:

:point_right: [Click](https://www.debian.org/distrib/index.es.html) URL  ISO Debian

:point_right: [Click](https://www.virtualbox.org/) URL  Virtual Box

## 2- Instalación VM de Debian

1. Abrirmos VirtualBox y clikeamos en **Nueva**

<img width="632" alt="" src="img/nueva.png">

2. Pondremos nombre de nuestra máquina y ubicación, debe de ir la carpeta **sgoinfre**, para no quedaremos sin espacio.

<img width="632" alt="" src="img/nombremaquina.png">

3. Seleccionamos la cantidad de memoria RAM que reservaremos para la máquina.

<img width="632" alt="" src="img/ram.png">

4. **Disco duro**, seleccionamos la segunda opción para así crear un disco duro **virtual ahora**.

<img width="632" alt="" src="img/ssd.png">

5. Tipo de **archivo**, escogemos la primera opción **VDI**, ya que nos hemos descargado una imagen de disco.

<img width="632" alt="" src="img/tipoarchivo.png">

6. Seleccionamos  **Reservado dinámicamente** ya que nos irá reservando memoria en la máquina real según la utilicemos hasta límite máximo disponible en la VM.

<img width="632" alt="" src="img/unidadfisica.png">

7. Después de elegir la cantidad de memoria recomendada **12 GB** o **30 Gb** si hacemos bonus, y le damos a **crear**.

<img width="632" alt="" src="img/ubicaciontamaño.png">

8. Ahora nos vamos a **Configuración** / **Almacenamiento** / **Controlador IDE** / **Vacío** y nos vamos a **unidad óptica** / y sobre **IDE secundario maestro** clickeamos en el icono del **disco** y elegimos **Seleccionar un archivo de disco**...

<img width="60" alt="" src="img/configuracion.png">

<img width="632" alt="" src="img/almacenamientoseleccionarchivo.png">

9. Seleccionaremos la ISO que tenemos y le damos a **Abrir** / **Aceptar**.

10.  Ya podemos **Iniciar** nuestra máquina virtual.

<img width="83" alt="" src="img/flecha.png">


## 3- Instalación de Debian en nuestra VM

➤ En esta sección, configurarás los elementos iniciales de tu máquina, incluyendo:

- Selección de idioma, zona horaria y país.
- Creación de un nombre de host (tu_login_42) y una contraseña para tu máquina.
- Creación de un primer usuario (tu_login_42) y su contraseña.
- Configuración de las particiones de tu máquina.

### ¿Qué es el particionamiento de disco con LVM?

El **particionamiento de disco** consiste en crear una o más regiones de almacenamiento, cada una gestionable de forma independiente. En Linux, las particiones se designan como `sdXN`, donde `X` representa el medio y `N` el número de partición (por ejemplo, `sdb3`).

El particionamiento mejora la seguridad, permitiendo reservar espacio para servicios que generan grandes volúmenes de datos y evitando la saturación de las particiones del sistema.

**Particiones comunes en este proyecto:**

- `/`: Contiene el árbol del sistema.
- `/boot`: Datos utilizados antes de que el kernel ejecute programas en modo usuario.
- `/var`: Archivos variables.
- `/tmp`: Archivos temporales.
- `/home`: Directorios de los usuarios.

### ¿Qué es LVM? (Logical Volume Manager)

LVM permite crear, redimensionar o eliminar particiones dinámicamente (volúmenes lógicos) desde la línea de comandos mientras el sistema está en funcionamiento, sin reiniciar para que el kernel reconozca los cambios.
1. Versión **SIN** interfaz gráfica **Install**, (indicado por el subject)

<img width="632" alt="" src="img/1-install.png">

2. Seleción de idioma que usaremos para instalar y el predeterminado de nuestro sistema **English**.

<img width="632" alt="" src="img/17.png">

3. Introducimos el País, territorio o zona. para colocar España nos vamos a **Other** / **Europe** / **Spain**.

<img width="632" alt="" src="img/VirtualBox_born2beroot_13_10_2024_18_12_47.png">
<img width="632" alt="" src="img/VirtualBox_born2beroot_13_10_2024_18_13_14.png">
<img width="632" alt="" src="img/VirtualBox_born2beroot_13_10_2024_18_13_28.png">

4. Combinación lenguaje / país **Configure locales** seleccionamos **United States**.

<img width="632" alt="" src="img/VirtualBox_born2beroot_13_10_2024_18_13_56.png">

5. Debemos seleccionar **American English** en configuración de teclado, si no habrá problemas de teclas mal enlazadas.

<img width="632" alt="" src="img/VirtualBox_born2beroot_13_10_2024_18_14_06.png">

6. Nombre de **Host Name** de la máquina, será tu login seguido de 42.

<img width="632" alt="" src="img/VirtualBox_born2beroot_13_10_2024_18_14_42.png">

7. **Domain name** apartado que dejaremos vacío, en el subject no menciona rellenarlo, y le damos a continuar .

<img width="632" alt="" src="img/VirtualBox_born2beroot_13_10_2024_18_16_30.png">

1. Nuestra contraseña de la cuenta de administración del sistema. **Apúntala**, la usaremos. Asegurate que la has escrito correctamente, tabula hasta la opción **Show Password in Clear** dale a la barra espaciadora y podrás ver tu clave.

<img width="632" alt="" src="img/VirtualBox_born2beroot_13_10_2024_18_20_29.png">

9. Repetimos el proceso de nuevo.

10. Nombre de nuestro nuevo usuario. tenemos que crear un usuario adicional como menciona el subject y no debe de ser el root con nuestro login, así que llamaremos **frromero** al nuevo usuario, y nos lo vuelve a pedir de nuevo.

<img width="632" alt="" src="img/VirtualBox_born2beroot_13_10_2024_18_22_50.png">

11. Introduciremos la contraseña de nuestro nuevo usuario. repitiendolo dos veces el proceso, es importante que la guardes porque la utilizaremos.

<img width="632" alt="" src="img/VirtualBox_born2beroot_13_10_2024_18_28_09.png">

12. Colocamos la hora de nuestra localización.

<img width="632" alt="" src="img/VirtualBox_born2beroot_13_10_2024_18_28_52.png">

13. Selecionamos la tercera opción **Guied - use entire disk and set up encrypted LVM**, el subject nos comenta que deben ser particiones cifradas, **Manual** para el bonus (pero no te sirve este tutorial)

<img width="632" alt="" src="img/VirtualBox_born2beroot_13_10_2024_18_29_28.png">

14. Disco en el que queremos hacer el particionado (Debe de haber solo un disco).

<img width="632" alt="" src="img/VirtualBox_born2beroot_13_10_2024_18_29_38.png">

15. **Particiones**, seleccionar la segunda opción **Separate /home partition**.

<img width="632" alt="" src="img/VirtualBox_born2beroot_13_10_2024_18_30_18.png">

16. Validamos **Yes** para guardar los cambios en el disco y configurar el gestor de volúmenes lógicos (LVM).

<img width="632" alt="" src="img/VirtualBox_born2beroot_13_10_2024_18_30_32.png">

17. No es necesario borrar los datos, daremos a **Cancel** ya que lo estamos haciendo en un entrono virtual .

<img width="632" alt="C" src="img/VirtualBox_born2beroot_13_10_2024_18_31_37.png">

18. Otra contraseña, ahora será la frase de encriptación. Repites proceso, y anótala la usaremos después.

<img width="632" alt="" src="img/VirtualBox_born2beroot_13_10_2024_18_33_38.png">

19. Colocar la cantidad de volumen que usaremos en la partición guiada. ponemos **max** o el número máximo disponible.

<img width="632" alt="" src="img/VirtualBox_born2beroot_13_10_2024_18_34_18.png">

20. Finalizamos y escribimos los cambios, selecionamos **Finish partitioning and write changes to disk**.

<img width="632" alt="" src="img/VirtualBox_born2beroot_13_10_2024_18_34_29.png">

21. **Yes** para continuar y confirmar los cambios en el disco.

<img width="632" alt="" src="img/VirtualBox_born2beroot_13_10_2024_18_34_55.png">

22. **No** necesitamos paquetes adicionales.

<img width="632" alt="" src="img/VirtualBox_born2beroot_13_10_2024_18_46_34.png">

23. **Package Manager** elegimos nuestro país.

<img width="632" alt="" src="img/VirtualBox_born2beroot_13_10_2024_18_46_51.png">

24. **Configure package manager**, elegimos la opción recomendada **deb.debian.org**

<img width="632" alt="" src="img/VirtualBox_born2beroot_13_10_2024_18_47_06.png">

25. El proxy lo dejamos vacío y le daremos **Continue**.

<img width="632" alt="" src="img/VirtualBox_born2beroot_13_10_2024_18_47_29.png">

26. **No** para que los developers vean nuestras estadísticas aunque sean anónimas.

<img width="632" alt="" src="img/VirtualBox_born2beroot_13_10_2024_18_49_29.png">

27.  Eliminamos todas las opciones de software (con barra espaciadora) y **Continue**.

<img width="632" alt="" src="img/VirtualBox_born2beroot_13_10_2024_18_49_56.png">

28. **Yes** para instalar **GRUB boot**.
➤ GNU GRUB (GNU GRand Unified Bootloader) es un cargador de arranque múltiple, desarrollado por el proyecto GNU que nos permite **elegir qué Sistema Operativo** arrancar de los instalados.

<img width="632" alt="" src="img/VirtualBox_born2beroot_13_10_2024_18_52_27.png">

29. Selecionamos el dispositivo instalar del cargador de arranque **/dev/sda (ata_VBOX_HARDDISK)**.

<img width="632" alt="" src="img/VirtualBox_born2beroot_13_10_2024_18_52_35.png">

30. **Continue** finalizar la instalación.

<img width="632" alt="" src="img/VirtualBox_born2beroot_13_10_2024_18_54_22.png">

# 4 Configurando la máquina virtual (VM)
- Herramientas de gestión de paquetes:
## aptitude
➤ Recuerda qué paquetes se solicitaron explícitamente y cuáles se instalaron solo debido a dependencias. Y  desinstalará automáticamente los paquetes que no se solicitaron explícitamente cuando ya no sean necesarios.
## apt
➤ Solo hará exactamente lo que se le indique en la línea de comandos.

## APPArmor

➤ Es un sistema de seguridad en Linux que proporciona control de acceso obligatorio (MAC). Permite al administrador del sistema restringir las acciones que los procesos pueden realizar. Está incluido por defecto en Debian.

➤ Ejecuta aa-status para comprobar si está funcionando.

## SSH (Secure Shell)

➤ SSH significa "Secure Shell", permitirá administrar tus servidores Linux, tanto localmente, (físicamente frente a tu servidor), o remota a tus servidores para administrarlos.

## UFW (Uncomplicated Firewall)

➤ Protección de red definiendo comunicaciones permitidas o prohibidas mediante reglas. Supervisa el tráfico de red entrante y saliente y decide si bloquear o permitir dicho tráfico.

➤ Nosotrtos en este proyecto dejaremos abierto solo el puerto 4242.

## Política de Contraseñas

➤ Es un conjunto de reglas que mejora la seguridad alentando a usar contraseñas seguras (que expiren cada 30 días, tengan más de 10 caracteres, sin secuencias lógicas, y que incluyan mayúsculas, caracteres especiales y números).

➤ Los usuario deberá seguir las siguientes reglas de contraseñas:
```
    PASS_MAX_DAYS 30
    PASS_MIN_DAYS 2
    PASS_WARN_AGE 7
```

Es posible que tu usuario predeterminado no tenga estas modificaciones, por lo que deberás hacerlo manualmente.

Ver los parámetros de contraseña de un usuario:

```bash
sudo chage -l nombre_usuario
```
➤ Si no corresponde con lo indicado, deben cambiarse:

``` bash

sudo chage -M 30 <usuario>
sudo chage -m 2 <usuario>
sudo chage -W 7 <usuario>
```
## Grupos y usuarios

➤ Linux usa grupos para organizar usuarios y simplificar la gestión de permisos de archivos y carpetas. Está diseñado para permitir que varios usuarios accedan al sistema simultáneamente, pero con permisos distintos.


➤ **root** es el superusuario y tiene la capacidad de hacer cualquier cosa en el sistema. Para tener una capa adicional de seguridad, generalmente se usa un usuario **sudo** en lugar de **root**.

➤ Debes instalar **sudo**, significa "superuser do". Otorga al usuario permisos temporales de administrador para realizar tareas administrativas sin iniciar sesión como root. Los derechos asignados se gestionan en el archivo **/etc/sudoers**.

## Crontab

➤ **Cron** es un programa en sistemas Unix que ejecuta scripts o comandos automáticamente en intervalos o momentos predefinidos.

➤ En este proyecto, debes publicar un mensaje cada 10 minutos.

➤ Crea un script de monitoreo y usa **sudo crontab -u root -e** para abrir crontab y agregar la regla.

La regla:

``` bash

* * * * * <ruta>/<nombre_del_programa_a_ejecutar>

Donde * * * * * significa cada minuto de cada hora de cada día de cada mes y cada día de la semana. Algunos ejemplos:

    0 * * * *: esto significa que cron se ejecutará siempre cuando los minutos sean 0 (entonces, cada hora).
    0 1 * * *: esto significa que cron se ejecutará siempre a la 1 en punto.
    * 1 * * *: esto significa que cron se ejecutará cada minuto cuando la hora sea la 1, es decir, 1:00, 1:01... hasta las 1:59.
    */10 * * * *: significa que cron se ejecutará cada 10 minutos.
```
## Signature.txt

➤ Una firma es un identificador único para un disco duro u otro dispositivo de almacenamiento, que el sistema operativo usa para diferenciarlos.

# INICIANDO EL SISTEMA

➤ Seleccionamos **Debian GNU/Linux**.

➤ Nos pide la contraseña de encriptación.

<img width="300" alt="" src="img/VirtualBox_born2beroot_13_10_2024_18_55_04.png">

➤ Debemos introducir el usuario y contraseña que hemos creado. Usuario **frromero** y la contraseña **42Madrid13/12**

<img width="632" alt="" src="img/VirtualBox_born2beroot_13_10_2024_23_09_08.png">

### Ya tenemos todo listo para empezar a configurar nuestra máquina virtual Debian

### 4.1 - Instalación de sudo y configuración de usuarios y grupos

➤ Si detectas un error en **/etc/hosts**, verifica y corrige el archivo.

➤ Asegúrate de que contenga la entrada correcta para el nombre del host. Edita el archivo con:

```bash
nano /etc/hosts

127.0.0.1   localhost
127.0.1.1   frromero42
```

1. Para instalar **sudo**, cambia al usuario root usando **su** en el terminal e ingresa la contraseña **42Madrid13/12**. Luego, ejecuta el comando:

```bash
apt install sudo
```

➤ Esto instalará los paquetes necesarios.

<img width="514" alt="" src="img/installsudopeque.png">

2. Reiniciamos la máquina para aplicar cambios **sudo reboot**.

<img width="514" alt="" src="img/sudoreboot.png">

3. Luego, introduce las contraseñas de cifrado y usuario nuevamente. Verifica la instalación como usuario root usando:

```bash
sudo -V
```

➤ Este comando muestra la versión de sudo y los argumentos usados para su configuración, además de los plugins. Para ver el contenido completo, usa:

```bash
sudo -V | more
```

➤ Para crear un nuevo grupo llamado **user42**:

4. Crea el grupo con el siguiente comando:

```bash
sudo addgroup user42
```

➤ El **GID** es el identificador de grupo (Group ID).

5. Verifica la creación correcta del grupo con:

```bash
getent group user42
```
➤ O bien, puedes ver todos los grupos en **/etc/group** usando:

```bash
cat /etc/group
```

6. Para incluir al usuario en los grupos **sudo** y **user42**, usa el comando:

```bash
sudo adduser user sudo
sudo adduser user user42
```

7. Después de incluir el usuario en los grupos, puedes verificarlo con:

```bash
getent group sudo
getent group user42
```

- O editando **/etc/group** con:

```bash
nano /etc/group
```

En los grupos **sudo** y **user42**, deberá aparecer tu usuario.

<img width="514" alt="" src="img/sudogroup.png">

### 4.2 - SSH Instalación y configuración

➤ **¿Qué es SSH?** Es un protocolo y programa que proporciona acceso remoto a un servidor a través de un canal seguro con cifrado de información.

1. Actualiza los repositorios con:

```bash
sudo apt update
```

2. Instala la herramienta SSH, **OpenSSH**, con el siguiente comando:

```bash
sudo apt install openssh-server
```

3. Para comprobar que se ha instalado correctamente, ejecuta:

```bash
sudo service ssh status
```

➤ Debería aparecer como **active**.

<img width="702" alt="" src="img/sshstatus.png">

3. Después de la instalación, hay archivos que configurar. Usaremos **Nano** para ello.

➤ El primer archivo que editaremos es:

   ```bash
   sudo nano /etc/ssh/sshd_config
   ```

➤ Si necesitas permisos de escritura, puedes usar **su** o simplemente el comando anterior.

4. Los comentarios de línea comienzan con **#**; debes eliminar el **#** de las líneas que quieras modificar.

➤ Líneas a modificar, descomentalas y dejalas al puerto 4242 :


     Port 4242
     PermitRootLogin prohibit-password

<img width="632" alt="" src="img/editportpass.png">


5. Ahora editamos el fichero **/etc/ssh/ssh_config**.

➤ Editaremos la siguiente línea:

 #Port **22** a Port **4242**

<img width="632" alt="" src="img/editsshconf.png">

6. Reiniciamos el servicio ssh para actualizar los cambios **sudo service ssh restart** y revisaremos los cambios con  **sudo service ssh status** y veremos la escucha del servidor debe aparecer el Puerto **4242**.

<img width="632" alt="" src="img/verpuertos.png">


### 4-3 Instalación y configuración de UFW

➤ **UFW** (Uncomplicated Firewall) es un firewall que utiliza la línea de comandos para configurar **iptables** mediante un conjunto sencillo de comandos.

1. Para instalar **UFW**, ejecuta el siguiente comando:

   ```bash
   sudo apt install ufw
   ```

2. Habilita el firewall con:

   ```bash
   sudo ufw enable
   ```

   Verás que el firewall está activo.

<img width="632" alt="" src="img/firewallenable.png">

3. Nuestro firewall debe permitir las conexiones por el puerto **4242**. Para hacerlo, ejecuta el siguiente comando:

   ```bash
   sudo ufw allow 4242
   ```

4. Para comprobar la configuración, utiliza el comando:

   ```bash
   sudo ufw status
   ```

<img width="632" alt="" src="img/permitirpuerto.png">
### 4-4 Configurando contraseña fuerte para sudo

1. Crearemos un archivo en la ruta **/etc/sudoers.d/** llamado **sudo_config**, que almacenará la configuración de la contraseña. Puedes crearlo con el siguiente comando:

   ```bash
   sudo touch /etc/sudoers.d/sudo_config
   ```

<img width="632" alt="" src="img/sudoconfig.png">

2. Debemos crear el directorio **sudo** en la ruta **/var/log/**, ya que cada comando que ejecutemos con **sudo**, tanto la entrada como la salida, se almacenará en ese directorio. Puedes crear el directorio con el siguiente comando:

```bash
sudo mkdir /var/log/sudo
```
<img width="632" alt="" src="img/dirsudo.png">

3. Edita el archivo de configuración de sudo con el siguiente comando:

```bash
sudo nano /etc/sudoers.d/sudo_config
```

4. Una vez que estés editando el archivo, deberás introducir los siguientes comandos para cumplir con todos los requisitos solicitados. (Asegúrate de incluir las configuraciones específicas que se requieren en este paso).

<img width="632" alt="" src="img/fileconfgsudo.png">

## DESGLOSANDO LOS COMANDOS

➤ Introduce las siguientes configuraciones en el archivo **/etc/sudoers.d/sudo_config**:

```plaintext
Defaults  passwd_tries=3              # Número de reintentos
Defaults  badpass_message="Password entry failure!"  # Mensaje en caso de error
Defaults  logfile="/var/log/sudo/sudo_config"        # Archivos de registro de comandos sudo
Defaults  log_input, log_output         # Registrar tanto la entrada como la salida de los comandos
Defaults  iolog_dir="/var/log/sudo"     # Directorio para los registros de entrada/salida
Defaults  requiretty                    # Activar modo TTY
Defaults  secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"  # Restringir los directorios utilizables por sudo
```
### 4-5 Configuración de política de contraseñas fuerte

1. Edita el archivo **login.defs** con el siguiente comando:

   ```bash
   sudo nano /etc/login.defs
   ```

2. Una vez que estés editando el archivo, modifica los siguientes parámetros:

```
PASS_MAX_DAYS 30 # Tiempo de expiración de la contraseña (30 días).
PASS_MIN_DAYS 2  # Número mínimo de días antes de que una contraseña pueda ser cambiada.
PASS_WARN_AGE 7  # El usuario recibirá un aviso 7 días antes de que expire su contraseña.
```

<img width="802" alt="Captura de pantalla 2022-07-16 a las 3 05 49" src="https://user-images.githubusercontent.com/66915274/179328449-32a40f67-a18d-4f29-993b-94d013cd7670.png">

### Continuación de la configuración

3. Para seguir con la configuración, instala el paquete **libpam-pwquality** con el siguiente comando:

   ```bash
   sudo apt install libpam-pwquality
   ```

   Acto seguido, presiona **Y** para confirmar la instalación y espera a que finalice.

4. A continuación, edita el archivo **common-password** con el siguiente comando:

   ```bash
   sudo nano /etc/pam.d/common-password
   ```

5. Después de la línea que contiene **retry=3**, añade los siguientes comandos:

   ```plaintext
   minlen=10         # Longitud mínima de la contraseña (10 caracteres).
   ucredit=-1        # Requiere al menos 1 carácter en minúscula.
   dcredit=-1        # Requiere al menos 1 dígito.
   lcredit=-1        # Requiere al menos 1 carácter en mayúscula.
   maxrepeat=3       # Permite un máximo de 3 caracteres consecutivos iguales.
   reject_username   # Rechaza contraseñas que contengan el nombre de usuario.
   difok=7           # Requiere que al menos 7 caracteres sean diferentes de la contraseña anterior.
   enforce_for_root  # Aplica las mismas reglas a la cuenta root.
   ```


<img width="800" alt="Captura de pantalla 2022-07-16 a las 3 38 08" src="https://user-images.githubusercontent.com/66915274/179329787-1b718843-9272-43e4-8d92-8d83933cc938.png">


### Actualización de las cuentas de usuario

6. **La política de contraseñas** afecta solo a los nuevos usuarios. Para aplicar los nuevos requisitos de seguridad a las cuentas de usuario creadas antes de esta política, utiliza el siguiente comando para verificar la configuración actual de una cuenta:

   ```bash
   sudo chage -l username
   ```

   Reemplaza **username** con el nombre del usuario que deseas verificar.

7. Para actualizar las configuraciones de la cuenta de usuario **frromero** y establecer un mínimo de 2 días y un máximo de 30 días, ejecuta el siguiente comando:

   ```bash
   sudo chage -m 2 -M 30 frromero
   ```

   - **-m** especifica el número mínimo de días antes de que el usuario pueda cambiar su contraseña (en este caso, **2 días**).
   - **-M** especifica el número máximo de días que puede transcurrir antes de que la contraseña deba ser cambiada (en este caso, **30 días**).

➤ Esto asegurará que la cuenta de **frromero** cumpla con las nuevas políticas de contraseñas.

### 4-6 Conectarse vía SSH

1. Para conectarnos por SSH debemos cerrar la máquina, abrir VirtualBox y darle a configuración.

<img width="832" alt="Captura de pantalla 2022-07-18 a las 10 15 13" src="https://user-images.githubusercontent.com/66915274/179470948-d9a863ef-f1a3-41fb-a103-25378064e747.png">

2. Una vez en configuración debemos pinchar sobre el apartado de **Red**, pincharemos sobre **Avanzadas** para que así nos muestre más opciones y le daremos a **Reenvío de puertos**.

<img width="684" alt="Captura de pantalla 2022-07-18 a las 10 18 32" src="https://user-images.githubusercontent.com/66915274/179471690-cfbdbf4b-ab93-4b12-9504-2482712652a3.png">

3. Pincharemos sobre el siguiente emoticono para agregar una regla de reenvío.

<img width="585" alt="Captura de pantalla 2022-07-18 a las 10 21 24" src="https://user-images.githubusercontent.com/66915274/179471855-913a684d-c7b0-43e2-9e01-d2c954fe75a4.png">

4. Por último, agregaremos el puerto **4242** al anfitrión y al invitado. Las IP's no son necesarias. Pincharemos sobre el botón de aceptar para que así se apliquen los cambios.

<img width="588" alt="Captura de pantalla 2022-07-18 a las 10 22 29" src="https://user-images.githubusercontent.com/66915274/179472105-5942b3ec-5c29-4d49-a00e-67f9cde289e8.png">

➤ Para poder conectarnos a la máquina virtual desde la real debemos abrir un terminal en la máquina real y escribir **ssh frromero@localhost -p 4242** nos pedirá la clave del usuario y una vez la introduzcamos ya nos saldrá el login en verde y eso significa que estaremos conectados.



## 5- Script


➤ Es una secuencia de comandos guardada en un fichero que cuando se ejecuta hará la función de cada comando.
Claro, aquí está la modificación del texto, adaptando las variables del script que has proporcionado:

---

### 5-1 Arquitectura

➤ El comando `uname -a` muestra información completa sobre el sistema, y el argumento `-a` es equivalente a `--all`. Ambos muestran todos los detalles disponibles del sistema en una sola línea.

**Explicación de `uname -a`:**

➤ El comando `uname` se usa para mostrar información sobre el sistema operativo y el hardware. La opción `-a` o `--all` incluye toda la información disponible.

```bash
#!/bin/bash

# O.S. ARCHITECTURE
architecture=$(uname -a)
```

---

### 5-2 Núcleos Físicos

```bash
cpu_phy=$(grep "physical id" /proc/cpuinfo | wc -l)
```

➤ **/proc/cpuinfo**: Contiene información detallada sobre los procesadores del sistema.
➤ **`grep "physical id"`**: Busca todas las líneas en `/proc/cpuinfo` que contienen "physical id". Este campo aparece una vez por cada núcleo físico o cada hilo, dependiendo del soporte de Hyper-Threading del sistema.
➤ **`wc -l`**: Cuenta el número de líneas, indicando cuántos núcleos físicos o CPUs físicas están presentes en el sistema.

**Resultado**: El número se almacena en la variable `cpu_phy`.

---

### 5-3 Núcleos Virtuales

```bash
vcpus=$(grep "processor" /proc/cpuinfo | wc -l)
```

➤ **`grep "processor"`**: Busca en `/proc/cpuinfo` todas las líneas que contengan "processor", representando cada núcleo virtual (vCPU).
➤ **`wc -l`**: Cuenta el número de líneas que contienen "processor", indicando el total de CPUs virtuales.

**Resultado**: El número se almacena en la variable `vcpus`.

---

### 5-4 Memoria RAM

```bash
total_memory=$(free --mega | awk '$1 == "Mem:" {print $2}')
used_memory=$(free --mega | awk '$1 == "Mem:" {print $3}')
memory_usage_percent=$(free --mega | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')
```

➤ **`free --mega`**: Muestra el uso de memoria en megabytes (MB).
➤ **`awk`**: Filtra y extrae el total de memoria y la memoria usada.

**Resultado**:
➤ `total_memory`: Memoria total en MB.
➤ `used_memory`: Memoria utilizada en MB.
➤ `memory_usage_percent`: Porcentaje de uso de memoria.

---

### 5-5 Uso de Disco

```bash
total_disk_space=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_t += $2} END {printf ("%.1fGb\n"), disk_t/1024}')
used_disk_space=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} END {print disk_u}')
disk_usage_percent=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} {disk_t += $2} END {printf("%d"), disk_u/disk_t*100}')
```

➤ **`df -m`**: Muestra el uso de disco en megabytes (MB).
➤ **`grep`**: Filtra las líneas que contienen "/dev/", excluyendo "/boot".
➤ **`awk`**: Suma y calcula el total y uso de disco, y el porcentaje de uso.

**Resultado**:
➤ `total_disk_space`: Espacio total en disco (en GB).
➤ `used_disk_space`: Espacio usado en disco (en MB).
➤ `disk_usage_percent`: Porcentaje de uso de disco.

---

### 5-6 Porcentaje de Uso de CPU

```bash
inactive_cpu=$(vmstat 1 2 | tail -1 | awk '{printf $15}')
cpu_usage=$(expr 100 - $inactive_cpu)
formatted_cpu=$(printf "%.1f" $cpu_usage)
```

➤ **`vmstat 1 2`**: Recoge estadísticas del sistema.
➤ **`tail -1`**: Selecciona la última línea con las estadísticas recientes.
➤ **`awk`**: Extrae el porcentaje de tiempo que el CPU está inactivo.
➤ **`expr`**: Calcula el porcentaje de uso del CPU.

**Resultado**:
➤ `formatted_cpu`: Porcentaje de uso del CPU con un decimal.

---

### 5-7 Último Reinicio

```bash
last_boot=$(who -b | awk '$1 == "system" {print $3 " " $4}')
```

➤ **`who -b`**: Muestra la fecha y hora del último arranque del sistema.
➤ **`awk`**: Filtra para extraer la fecha y hora.

**Resultado**: El resultado se almacena en la variable `last_boot`.

---

### 5-8 Uso de LVM

```bash
lvm_use=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)
```

➤ **`lsblk`**: Lista información sobre los dispositivos de bloque.
➤ **`grep "lvm"`**: Busca líneas que contengan "lvm".
➤ **`wc -l`**: Cuenta las líneas.

**Resultado**:
-➤ `lvm_use`: Contendrá "yes" si LVM está en uso, "no" si no.

---

### 5-9 Conexiones TCP

```bash
tcp_connections=$(ss -ta | grep ESTAB | wc -l)
```

➤ **`ss -ta`**: Muestra estadísticas de sockets de conexiones TCP.
➤ **`grep ESTAB`**: Filtra las conexiones en estado ESTABLISHED.
➤ **`wc -l`**: Cuenta el número total de conexiones activas.

**Resultado**: El número se almacena en la variable `tcp_connections`.

---

### 5-10 Número de Usuarios

```bash
user_log=$(users | wc -w)
```

➤ **`users`**: Muestra una lista de usuarios conectados.
➤ **`wc -w`**: Cuenta el número de palabras (usuarios activos).

**Resultado**: Se almacena en la variable `user_log`.

---

### 5-11 Dirección IP y MAC

```bash
ip_net=$(hostname -I)
mac=$(ip link | grep "link/ether" | awk '{print $2}')
```

➤ **`hostname -I`**: Obtiene la dirección IP del host.
➤ **`ip link`**: Muestra información sobre las interfaces de red.
➤ **`grep` y `awk`**: Filtran y extraen la dirección MAC.

---

### 5-12 Número de Comandos Ejecutados con Sudo

➤ Para obtener el número de comandos ejecutados con `sudo`, utiliza el siguiente comando:

```bash
sudo_commands=$(journalctl _COMM=sudo | grep COMMAND | wc -l)
```

1. **`journalctl _COMM=sudo`**: Utiliza `journalctl` para acceder a los registros del sistema y filtrar las entradas relacionadas con el comando `sudo`.

2. **`grep COMMAND`**: Filtra los resultados para incluir solo las líneas que contienen la palabra **COMMAND**, limitando así los resultados a las entradas de comandos ejecutados con `sudo`.

3. **`wc -l`**: Cuenta el número de líneas en la salida anterior, lo que indica cuántos comandos se han ejecutado con `sudo`.

---

```
#!/bin/bash

# O.S. ARCHITECTURE
architecture=$(uname -a)

# PHYSICAL CPU identifier
cpu_phy=$(grep "physical id" /proc/cpuinfo | wc -l)

# Number of virtual processors (vCPUs)
vcpus=$(grep "processor" /proc/cpuinfo | wc -l)

# MEMORY RAM
total_memory=$(free --mega | awk '$1 == "Mem:" {print $2}')
used_memory=$(free --mega | awk '$1 == "Mem:" {print $3}')
memory_usage_percent=$(free --mega | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')

# DISK
total_disk_space=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_t += $2} END {printf ("%.1fGb\n"), disk_t/1024}')
used_disk_space=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} END {print disk_u}')
disk_usage_percent=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} {disk_t += $2} END {printf("%d"), disk_u/disk_t*100}')

# CPU load
inactive_cpu=$(vmstat 1 2 | tail -1 | awk '{printf $15}')
cpu_usage=$(expr 100 - $inactive_cpu)
formatted_cpu=$(printf "%.1f" $cpu_usage)

# LAST BOOT
last_boot=$(who -b | awk '$1 == "system" {print $3 " " $4}')

# LVM USE
lvm_use=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)

# TCP CONNECTIONS
tcp_connections=$(ss -ta | grep ESTAB | wc -l)

# USER LOG
user_log=$(users | wc -w)

# NETWORK
ip_net=$(hostname -I)
mac=$(ip link | grep "link/ether" | awk '{print $2}')

# SUDO COMMANDS
sudo_commands=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

# Wall message
wall "	# Architecture: $architecture
	# CPU physical: $cpu_phy
	# vCPU: $vcpus
	# Memory Usage: $used_memory/${total_memory}MB ($memory_usage_percent%)
	# Disk Usage: $used_disk_space/${total_disk_space} ($disk_usage_percent%)
	# CPU load: $formatted_cpu%
	# Last boot: $last_boot
	# LVM use: $lvm_use
	# TCP Connections: $tcp_connections ESTABLISHED
	# User log: $user_log
	# Network: IP $ip_net ($mac)
	# Sudo: $sudo_commands cmd"
```

➤ Ejecución del script:

<img width="622" alt="" src="img/script.png">


## 6- Crontab

➤ **Cron** es un programa en sistemas Unix que ejecuta automáticamente scripts y comandos en horarios o ciclos predefinidos.

➤ En este proyecto, debes publicar un mensaje cada 10 minutos. Para ello, crea un script con la información que deseas ejecutar y utiliza el siguiente comando para abrir crontab:

```bash
sudo crontab -u root -e
```
<img width="798" alt="Captura de pantalla 2022-08-03 a las 4 40 18" src="https://user-images.githubusercontent.com/66915274/182512395-eaebabc2-5866-4ae3-966c-1a80818cde07.png">

### Formato de Crontab:

➤ **m**  Minuto de ejecución (0-59).
➤ **h**  Hora de ejecución (0-23).
➤ **dom**  Día del mes (puedes especificar un día, como 15).
➤ **dow**  Día de la semana (0-7, donde 0 y 7 son domingo) o las primeras tres letras del día en inglés: mon, tue, wed, thu, fri, sat, sun.
➤ **user**  Usuario que ejecuta el comando (root u otro con permisos).
➤ **command**  Comando o ruta absoluta del script a ejecutar.
## 7- Signature.txt 📝

➤ Ejecuta `shasum nombremaquina.vdi` para obtener la firma. Añade el resultado a **signature.txt** y súbelo al repositorio. No vuelvas a abrir la máquina para evitar cambios en la firma. Para realizar correcciones, clona la máquina, así podrás encenderla sin riesgo de modificar la firma.

<img width="834" alt="Captura de pantalla 2022-08-03 a las 4 47 32" src="https://user-images.githubusercontent.com/66915274/182513283-1cfc319f-982d-47cf-a596-8475d4c96616.png">

➤ Ubica el .vdi de tu máquina virtual y ejecuta nuevamente `shasum nombremaquina.vdi`. Añade la firma generada a **signature.txt** para subirla al repositorio. Recuerda **no volver a abrir la máquina**, ya que se modificará la firma.
➤ Para correcciones, clona la máquina para encenderla sin riesgo.

➤ **shasum**: Comando que verifica la integridad de un archivo mediante la suma de comprobación del hash SHA-1.



## 9-1 Evaluación

### ▪️ Qué es una máquina virtual?

➤ Es un software que simula un sistema de computación y puede ejecutar programas como si fuese una computadora real. Permite crear múltiples entornos simulados o recursos dedicados desde un solo sistema de hardware físico.
➤ Existen varias ventajas de tener una máquina virtual:

	- Económica
	- Ahorro de espacio físico (almacenamiento)
	- Menor mantenimiento que una máquina física
	- Respaldo de datos simplificado
	- Mayor seguridad

### ▪️ Por qué te decantaste por Debian?

 ➤ Es más sencillo y hay multitud de información.

### ▪️ Diferencias básicas entre Rocky y Debian

### 1. **Origen y Propósito**
➤ **Rocky Linux**: Alternativa a CentOS, basada en RHEL, enfocada en estabilidad para servidores.
➤ **Debian**: Distribución antigua y respetada, centrada en la libertad del software y la estabilidad.

### 2. **Gestión de Paquetes**
➤ **Rocky Linux**: Usa `yum`/`dnf` con paquetes RPM.
➤ **Debian**: Usa `apt` con paquetes DEB.

### 3. **Ciclos de Lanzamiento**
➤ **Rocky Linux**: Versiones LTS, actualizaciones regulares.
➤ **Debian**: Ciclo flexible con versiones estables, inestables y de prueba.

### 4. **Filosofía y Comunidad**
➤ **Rocky Linux**: Basado en la comunidad, influenciado por RHEL, mantenido por una fundación.
➤ **Debian**: Completamente comunitaria, regida por el "Debian Social Contract".

### 5. **Usos Comunes**
➤ **Rocky Linux**: Ideal para servidores y aplicaciones críticas.
➤ **Debian**: Usado en servidores y escritorios, flexible y personalizable.

### 6. **Entornos de Escritorio**
➤ **Rocky Linux**: Más común en servidores, se puede instalar un entorno de escritorio.
➤ **Debian**: Ofrece múltiples entornos de escritorio en la instalación.

### 7. **Configuración y Personalización**
➤ **Rocky Linux**: Conservador en cambios, ideal para estabilidad.
➤ **Debian**: Mayor flexibilidad y opciones de personalización.

### ▪️ Propósito de las máquinas virtuales

➤ Proporcionan un entorno de ejecución independiente de hardware y sistema operativo, ocultando los detalles de la plataforma subyacente para que un programa se ejecute de la misma forma en cualquier plataforma.

### ▪️ Diferencias entre apt y aptitude

➤ **Aptitude** es una versión mejorada de **apt**. Apt es un administrador de paquetes de nivel inferior, mientras que Aptitude es de alto nivel, ofreciendo más funcionalidades y características.

### ▪️ Qué es APPArmor?

➤ Es un módulo de seguridad del kernel Linux que permite restringir las capacidades de un programa.

### ▪️ Qué es LVM?

➤ Es un gestor de volúmenes lógicos que asigna espacio en dispositivos de almacenamiento masivo de manera más flexible que los esquemas de particionado convencionales.

## 9-2 Comandos de evaluación

1. **Verificar interfaces gráficas en uso:**
   `ls /usr/bin/*session` (no debe aparecer nada).

2. **Comprobar estado del servicio UFW:**
   `sudo ufw status`
   `sudo service ufw status`

3. **Comprobar estado del servicio SSH:**
   `sudo service ssh status`

4. **Verificar sistema operativo (Debian o CentOS):**
   `uname -v` o `uname --kernel-version`

5. **Verificar pertenencia a grupos "sudo" y "user42":**
   `getent group sudo`
   `getent group user42`

6. **Crear nuevo usuario con política de contraseñas:**
   `sudo adduser name_user` (usar contraseña que cumpla la política).

7. **Crear grupo "evaluating":**
   `sudo addgroup evaluating`

8. **Añadir usuario al grupo:**
   `sudo adduser name_user evaluating`

9. **Comprobar hostname:**
   `hostname` (debe ser login42).

10. **Modificar hostname:**
    Editar `/etc/hostname` y `/etc/hosts` para reemplazar login por student42, luego reiniciar la máquina.

11. **Comprobar particiones:**
    `lsblk`

    <img width="632" alt="lsblk" src="img/arbol (1).png">

13. **Verificar si sudo está instalado:**
    `which sudo` o `dpkg -s sudo`

14. **Agregar nuevo usuario al grupo sudo:**
    `sudo adduser name_user sudo`
    Verificar pertenencia al grupo.

15. **Mostrar aplicación de reglas de sudo.**

16. **Verificar existencia de /var/log/sudo/:**
    Comprobar que contenga al menos un fichero de historial de comandos utilizados con sudo.

17. **Verificar instalación y estado de UFW:**
    `dpkg -s ufw`
    `sudo service ufw status`

18. **Listar reglas activas en UFW:**
    `sudo ufw status numbered`

19. **Crear y eliminar regla para puerto 8080:**
    `sudo ufw allow 8080`
    `sudo ufw status numbered`
    `sudo ufw delete num_rule` (comprobar eliminación).

20. **Comprobar estado de SSH y puerto 4242:**
    `which ssh`
    `sudo service ssh status`

21. **Iniciar sesión con el nuevo usuario via SSH:**
    `ssh newuser@localhost -p 4242`
    (intentar con usuario root y verificar que no se puede).

22. **Modificar tiempo de ejecución del script a 1 minuto:**
    `sudo crontab -u root -e` y cambiar el primer parámetro a 1.

23. **Detener ejecución del script al iniciar el servidor:**
   - No utiliceis esto aparte de detener todas las tareas que puedan estar ejecutandose en cron `sudo /etc/init.d/cron stop`
   no sirve de nada porque al reiniciar el script estará de nuevo funcionando.
   podeis entrar en:
   ```bash
sudo crontab -u root -e
```
y comentar la linea donde hace referencia a nuestro ```monitoring.sh```


