/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:59:09 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/09 17:13:49 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    const char *archivo = "getcwd.c"; // Reemplaza con el nombre del archivo que desees examinar
    struct stat info;

    if (stat(archivo, &info) == 0)
	{
        printf("Información sobre el archivo: %s\n", archivo);
        printf("Tamaño: %lld bytes\n", info.st_size);
        printf("Permisos: %o\n", info.st_mode & 0777); // Muestra los permisos en octal
        printf("Número de inodo: %llu\n", info.st_ino);
        // Puedes acceder a otros campos de 'info' según tus necesidades
    }
	else
	{
        perror("Error al obtener información del archivo");
        return 1;
    }
    return 0;
}
