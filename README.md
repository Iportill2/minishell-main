# Minishell

Minishell es un proyecto de la escuela 42 cuyo objetivo es crear una shell propia, inspirada en bash, capaz de interpretar y ejecutar comandos, gestionar pipes, redirecciones y varios built-ins.

---

## 📁 Estructura del proyecto

- **src/**: Código fuente principal de la shell.
- **Libft/**: Librería propia con funciones estándar de C reimplementadas.
- **gnl/**: Implementación de get_next_line para lectura de entrada.
- **include/**: Cabeceras del proyecto.
- **Makefile**: Script de compilación.
- **bonus/**: Versión bonus (si aplica).

---

## ⚙️ Compilación

Asegúrate de tener las dependencias necesarias (`readline`, `gcc`, `make`).

```bash
make
```

Esto generará el ejecutable `minishell`.

---

## 🚀 Uso

Lanza la shell con:

```bash
./minishell
```

Ejecuta comandos como en bash:

- `echo hola mundo`
- `ls -l | grep minishell`
- `export VAR=42`
- `cd ..`
- `pwd`
- `exit`

---

## 🛠️ Funcionalidades principales

- Ejecución de comandos con rutas relativas y absolutas.
- Pipes (`|`) y redirecciones (`>`, `<`, `>>`, `<<`).
- Built-ins: `cd`, `echo`, `pwd`, `export`, `unset`, `env`, `exit`.
- Gestión de variables de entorno.
- Manejo de señales (Ctrl+C, Ctrl+D).
- Soporte para comillas simples y dobles.
- Soporte para variables de entorno (`$VAR`).

---

## 📦 Dependencias

- [readline](https://tiswww.case.edu/php/chet/readline/rltop.html)
- gcc, make

---

## 🧑‍💻 Autores

- jgoikoet@student.42urduliz.com
- iportill@student.42urduliz.com

---

## 📄 Notas

- El proyecto sigue la normativa de 42: norminette, sin memory leaks, Makefile funcional, etc.
- Para más detalles, consulta el PDF del enunciado de 42 o la cabecera de cada archivo fuente.

---

## 📸 Ejemplo de uso

```bash
$ ./minishell
Minitxel > echo Hola mundo
Hola mundo
Minitxel > export VAR=42
Minitxel > echo $VAR
42
Minitxel > ls | grep minishell
minishell
Minitxel > exit
```

---


