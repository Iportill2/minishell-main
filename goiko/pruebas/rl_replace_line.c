/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_replace_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:34:03 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/09 13:46:01 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int main()
{
    char *input = readline("Ingrese una línea: "); // Lee una línea de entrada
    rl_replace_line("Nueva línea reemplazada", 0); // Reemplaza la línea actual con "Nueva línea reemplazada"
    //rl_redisplay(); // Vuelve a mostrar la línea reemplazada
    add_history(input); // Agrega la línea de entrada a la historia de Readline

    // Aquí puedes procesar la entrada de usuario, realizar acciones adicionales, etc.

    free(input); // Libera la memoria asignada para la entrada
    return 0;
}
