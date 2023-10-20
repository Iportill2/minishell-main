/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tgetnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:40:26 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/10 10:45:16 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <termcap.h> // Incluye la biblioteca termcap para tgetnum

int main() {
    char *capability_name = "co"; // Nombre de la capacidad para el número de columnas

    // Obtener el número de columnas disponibles en la terminal
    int num_columns = tgetnum(capability_name);

    if (num_columns != -1) {
        printf("Número de columnas disponibles: %d\n", num_columns);
    } else {
        printf("La capacidad %s no está definida o se produjo un error.\n", capability_name);
    }

    return 0;
}
