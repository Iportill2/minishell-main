/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:39:39 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/09 16:46:16 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int main(void)
{
    char *input;

    // Inicializar la biblioteca readline
   //rl_initialize();

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

        // Liberar la memoria asignada por readline
        free(input);
    }
    return 0;
}
