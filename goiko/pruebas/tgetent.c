/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tgetent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:01:23 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/10 10:25:19 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <curses.h> // Incluye la biblioteca ncurses para tgetent
#include <term.h>
#include <unistd.h>
//#include <termcap.h> 

int main(void)
{
    char term_buffer[1024]; // Buffer para almacenar información de la terminal
	int fd = STDOUT_FILENO; // Descriptor de archivo para la salida estándar (por lo general, un terminal)
    char *terminal_name;

    terminal_name = ttyname(fd);
	printf("%s\n", terminal_name);
    // Llamar a tgetent para cargar la información de la terminal actual
    int result = tgetent(term_buffer, "ttys005");

    if (result == 1) {
        // Éxito: la información de la terminal se ha cargado correctamente

        // Obtener la secuencia de escape para mover el cursor a la fila 5 y columna 10
        char *cursor_move = tgetstr("cm", NULL);

        // Obtener la secuencia de escape para cambiar el color del texto a rojo
        char *color_red = tgetstr("AF", NULL);

        // Comprobar si se obtuvieron las secuencias de escape
        if (cursor_move && color_red) {
            // Imprimir una cadena en la posición 5, 10 y cambiar el color a rojo
            printf("%s%sHello, World!\033[m\n", cursor_move, color_red);
        } else {
            printf("No se pudieron obtener las secuencias de escape necesarias.\n");
        }
    } else if (result == 0) {
        // No se encontró la entrada para la terminal en la base de datos
        printf("No se encontró la entrada para la terminal.\n");
    } else {
        // Error al cargar la información de la terminal
        printf("Error al cargar la información de la terminal.\n");
    }
    return (0);
}
