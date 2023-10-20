/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:54:50 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/09 18:59:17 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *nombre_variable = "PATH"; // Reemplaza con el nombre de la variable de entorno que deseas consultar
    char *valor_variable;

    valor_variable = getenv(nombre_variable);

    if (valor_variable != NULL)
	{
        printf("El valor de la variable de entorno %s es: %s\n", nombre_variable, valor_variable);
    }
	else
	{
        printf("La variable de entorno %s no está definida.\n", nombre_variable);
    }
    return 0;
}
