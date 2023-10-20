/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fstat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:43:00 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/09 17:45:31 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char *nombre_archivo = "1.txt"; // Reemplaza con el nombre del archivo que desees examinar
    int fd;
    struct stat info;

    // Abrir el archivo
    fd = open(nombre_archivo, O_RDONLY);

    if (fd == -1) {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Obtener información sobre el archivo a través de su descriptor
    if (fstat(fd, &info) == 0) {
        printf("Información sobre el archivo: %s\n", nombre_archivo);
        printf("Tamaño: %lld bytes\n", info.st_size);
        printf("Permisos: %o\n", info.st_mode & 0777); // Muestra los permisos en octal
        printf("Número de inodo: %llu\n", info.st_ino);
        // Puedes acceder a otros campos de 'info' según tus necesidades
    } else {
        perror("Error al obtener información del archivo");
        close(fd); // Cerrar el archivo
        return 1;
    }

    // Cerrar el archivo
    close(fd);

    return 0;
}
