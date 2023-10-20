/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:31:34 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/09 16:53:47 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(void) {
    const char *newDir = "/Users/jgoikoet/Desktop"; // Reemplaza con la ruta que desees

    char *currentDir = getcwd(NULL, 0); // Obtener el directorio de trabajo actual

    if (currentDir == NULL) {
        perror("Error al obtener el directorio de trabajo actual");
        return 1;
    }

    printf("Directorio de trabajo actual antes del cambio: %s\n", currentDir);

    if (chdir(newDir) == 0) {
        printf("Cambiado al directorio: %s\n", newDir);
    } else {
        perror("Error al cambiar de directorio");
        free(currentDir); // Liberar la memoria asignada para currentDir
        return 1;
    }

    free(currentDir); // Liberar la memoria asignada para currentDir

    // Verificar el directorio de trabajo después del cambio
    currentDir = getcwd(NULL, 0);

    if (currentDir == NULL) {
        perror("Error al obtener el directorio de trabajo actual");
        return 1;
    }

    printf("Directorio de trabajo actual después del cambio: %s\n", currentDir);

    free(currentDir); // Liberar la memoria asignada para currentDir

    // Realiza operaciones en el nuevo directorio

    return 0;
}


/* int main()
{
    const char *newDir = "/Users/jgoikoet/Desktop"; // Reemplaza con la ruta que desees

    if (chdir(newDir) == 0) {
        printf("Cambiado al directorio: %s\n", newDir);
    } else {
        perror("Error al cambiar de directorio");
        return 1;
    }

    // Realiza operaciones en el nuevo directorio

    return 0;
} */
