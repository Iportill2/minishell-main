/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_redisplay.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:48:44 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/09 13:50:04 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    char *input = readline("Ingrese una línea: "); // Lee una línea de entrada

    // Vuelve a mostrar la línea actual en la terminal
    rl_redisplay();
	rl_redisplay();
	rl_redisplay();

    add_history(input); // Agrega la línea de entrada a la historia de Readline

    // Aquí puedes procesar la entrada de usuario, realizar acciones adicionales, etc.

    free(input); // Libera la memoria asignada para la entrada
    return 0;
}
