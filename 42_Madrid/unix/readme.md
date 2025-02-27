
#### **Información del Sistema**
| Comando | Descripción |
|---|---|
| `uname` | Muestra información básica del sistema Unix. |
| `uname –a` | Muestra información detallada del sistema Unix. |
| `uname –r` | Muestra la versión del kernel. |
| `uptime` | Muestra cuánto tiempo lleva el sistema funcionando y la carga del sistema. |
| `who` | Muestra quién ha iniciado sesión en el sistema. |
| `w` | Muestra los usuarios en línea y qué están haciendo. |
| `users` | Lista los usuarios actuales en el sistema. |
| `whoami` | Muestra el usuario con el que has iniciado sesión. |
| `su` | Permite ejecutar comandos como superusuario (root). |
| `cal` | Muestra un calendario con la fecha actual resaltada. |
| `date` | Muestra la fecha y hora actual del sistema. |
| `halt` | Detiene el sistema inmediatamente. |
| `shutdown` | Apaga el sistema. |
| `reboot` | Reinicia el sistema. |
| `last reboot` | Muestra el historial de reinicios del sistema. |
| `man COMANDO` | Muestra el manual de un COMANDO específico. Presiona `q` para salir. |

#### **Redirección de Entrada/Salida**
| Comando | Descripción |
|---|---|
| `echo TEXTO` | Muestra una línea de TEXTO o el contenido de una variable. |
| `echo -e TEXTO` | Interpreta caracteres de escape en el TEXTO (ej. `\n` = nueva línea). |
| `echo -n TEXTO` | Omite el salto de línea al final del TEXTO. |
| `cmd1 | cmd2` | Canaliza la salida de `cmd1` como entrada de `cmd2`. |
| `cmd > archivo` | Redirige la salida de `cmd` a un archivo (sobrescribe el contenido). |
| `cmd >> archivo` | Añade la salida de `cmd` al final de un archivo. |
| `cmd < archivo` | Lee la entrada de `cmd` desde un archivo. |
| `cmd << delim` | Lee la entrada hasta encontrar el delimitador `delim`. |

---

### **Gestión de Archivos**
| Comando | Descripción |
|---|---|
| `*` | Comodín para cualquier secuencia de caracteres (ej. `*.txt`). |
| `?` | Comodín para un solo carácter (ej. `Doc?.docx`). |
| `ls` | Lista archivos y carpetas en el directorio actual. |
| `ls -l` | Muestra detalles de cada archivo (permisos, fecha de modificación). |
| `ls -a` | Incluye archivos ocultos en la lista. |
| `ls -t` | Ordena los archivos por fecha de modificación (más reciente primero). |
| `cd CARPETA` | Cambia al directorio `CARPETA` (ej. `cd ..` sube un nivel). |
| `pwd` | Muestra la ruta del directorio actual. |
| `mkdir X` | Crea un directorio llamado `X`. |
| `mv A B` | Mueve o renombra un archivo de `A` a `B`. |
| `cp A B` | Copia un archivo de `A` a `B`. |
| `cp -r Y Z` | Copia recursivamente el directorio `Y` a `Z`. |
| `rm X` | Elimina el archivo `X` permanentemente. |
| `rm -r Y` | Elimina recursivamente el directorio `Y` y su contenido. |
| `rm -f X` | Fuerza la eliminación sin confirmación. |
| `touch X` | Crea un archivo vacío `X` o actualiza su marca de tiempo. |
| `cat X` | Muestra el contenido del archivo `X`. |
| `cat -b X` | Muestra el contenido con números de línea. |
| `wc X` | Muestra el número de líneas, palabras y caracteres en `X`. |
| `head X` | Muestra las primeras líneas de `X`. |
| `tail X` | Muestra las últimas líneas de `X`. |

---

### **Búsqueda y Filtrado**
| Comando | Descripción |
|---|---|
| `grep patrón X` | Busca un patrón de texto en el archivo `X`. |
| `grep -v patrón X` | Muestra líneas que **no** coinciden con el patrón. |
| `grep -i patrón X` | Búsqueda sin distinguir mayúsculas/minúsculas. |
| `find /ruta -name "*.sh"` | Busca archivos `.sh` en `/ruta`. |
| `locate nombre` | Busca archivos por nombre. |
| `sort X` | Ordena líneas de texto en `X` alfabética o numéricamente. |

---

### **Archivos Comprimidos**
| Comando | Descripción |
|---|---|
| `tar -cf archivo.tar Y` | Crea un archivo TAR con el contenido de `Y`. |
| `tar -xf archivo.tar` | Extrae un archivo TAR. |
| `tar -czf archivo.tar.gz Y` | Crea un TAR comprimido con gzip. |
| `tar -xzf archivo.tar.gz` | Extrae un TAR comprimido con gzip. |
| `zip -r Z.zip Y` | Comprime `Y` en un archivo ZIP. |
| `unzip Z.zip` | Descomprime un archivo ZIP. |

---

### **Transferencia de Archivos**
| Comando | Descripción |
|---|---|
| `ssh usuario@servidor` | Conecta a un servidor remoto como `usuario`. |
| `scp -r origen destino` | Copia recursivamente archivos entre servidores. |
| `sftp usuario@servidor` | Conexión segura para transferencia de archivos. |

---

### **Permisos de Archivos**
| Comando | Descripción |
|---|---|
| `chmod permisos archivo` | Cambia los permisos de un archivo (ej. `chmod 755 script.sh`). |
| `chown usuario archivo` | Cambia el propietario de un archivo. |
| `chgrp grupo archivo` | Cambia el grupo de un archivo. |

**Permisos en Octal**  
| Octal | Permisos | Descripción |
|---|---|---|
| `0` | `---` | Sin permisos. |
| `4` | `r--` | Solo lectura. |
| `7` | `rwx` | Lectura, escritura y ejecución. |

---

### **Gestión de Procesos**
| Comando | Descripción |
|---|---|
| `ps` | Muestra los procesos en ejecución. |
| `ps aux | grep python3` | Filtra procesos relacionados con `python3`. |
| `kill PID` | Termina un proceso por su ID. |
| `top` | Muestra procesos en tiempo real. |

---

### **Editor Vi**
| Comando | Descripción |
|---|---|
| `i` | Entra en modo inserción. |
| `:wq` | Guarda y sale. |
| `dd` | Elimina la línea actual. |
| `/texto` | Busca `texto` en el archivo. |

---

#### **Variables**
| Sintaxis | Descripción |
|---|---|
| `VAR="valor"` | Define una variable. |
| `echo $VAR` | Muestra el valor de `VAR`. |

#### **Estructuras de Control**
```sh
if [ condición ]; then
  # Código si es verdadero
else
  # Código si es falso
fi
```

#### **Bucles**
```sh
for i in 1 2 3; do
  echo $i
done
```

---
