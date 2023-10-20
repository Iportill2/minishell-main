/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tgoto.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:56:25 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/10 10:58:46 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <termcap.h> // Incluye la biblioteca termcap para tgoto

int main(void) {
    const char *capability_name = "cm"; // Capacidad para mover el cursor
    int column = 40; // Columna a la que deseas mover el cursor
    int row = 15; // Fila a la que deseas mover el cursor

    // Construir la secuencia de escape para mover el cursor
    char *cursor_move_sequence = tgoto(capability_name, column, row);

    if (cursor_move_sequence) {
        // Imprimir la secuencia de escape para mover el cursor
        printf("Secuencia de escape para mover el cursor: %s\n", cursor_move_sequence);
    } else {
        printf("La capacidad %s no está definida o se produjo un error.\n", capability_name);
    }

    return 0;
}
