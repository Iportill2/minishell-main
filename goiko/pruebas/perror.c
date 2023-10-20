/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:05:49 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/09 18:06:32 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void)
{
    FILE *archivo = fopen("archivo_inexistente.txt", "r");

    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        //exit(EXIT_FAILURE);
    }

    // Realizar operaciones en el archivo

    fclose(archivo);

    return 0;
}