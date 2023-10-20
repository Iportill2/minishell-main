/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tgetstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:47:53 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/10 10:54:23 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <termcap.h> // Incluye la biblioteca termcap para tgetstr

int main(void) {
    char *capability_name = "cl"; // Nombre de la capacidad para mover el cursor

    // Área de memoria para almacenar la secuencia de escape
    char **sequence = NULL;

    // Obtener la secuencia de escape para mover el cursor
    char *cursor_move = tgetstr(capability_name, sequence);

    if (cursor_move) {
        // La secuencia de escape para mover el cursor está disponible
        printf("Secuencia de escape para mover el cursor: %s\n", cursor_move);
    } else {
        printf("La capacidad %s no está definida o se produjo un error.\n", capability_name);
    }

    return 0;
}
