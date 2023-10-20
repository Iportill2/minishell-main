/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opendir_readdir_closedir.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:50:46 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/09 17:52:59 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
    const char *directorio = "pepe"; // Reemplaza con la ruta del directorio que deseas abrir
    DIR *dp;
    struct dirent *entry;

    // Abrir el directorio
    dp = opendir(directorio);

    if (dp == NULL) {
        perror("Error al abrir el directorio");
        return 1;
    }

    // Leer y mostrar los nombres de los archivos en el directorio
    while ((entry = readdir(dp))) {
        printf("Nombre del archivo: %s\n", entry->d_name);
    }

    // Cerrar el directorio
    closedir(dp);

    return 0;
}
