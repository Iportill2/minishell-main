/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_add_clear_history.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:52:21 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/09 17:01:45 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() 
{
    char *input;

    // Inicializar la biblioteca readline
    rl_initialize();

    while (1) {
        // Leer una línea de entrada
        input = readline("Ingrese un texto: ");

        // Verificar si se ha llegado al final de la entrada
        if (input == NULL) {
            printf("\nSaliendo...\n");
            break;
        }

        // Hacer algo con la línea de entrada, por ejemplo, imprimirlo
        printf("Ingresaste: %s\n", input);

        // Agregar la línea de entrada al historial
        add_history(input);

        // Liberar la memoria asignada por readline
        free(input);
    }

    // Limpiar el historial de comandos antes de salir
    //rl_clear_history();

    return 0;
}
