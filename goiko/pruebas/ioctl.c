/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ioctl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:47:00 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/09 18:48:44 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>

int main() {
    int fd;
    int resultado;

    // Abre un dispositivo o archivo especial (reemplaza con tu propio descriptor)
    fd = open("1.txt", O_RDWR);

    if (fd == -1) {
        perror("Error al abrir el dispositivo");
        return 1;
    }

    // Ejemplo de comando ioctl (debes reemplazarlo con un comando real)
    resultado = ioctl(fd, CMD_ESPECIFICO, argumentos);

    if (resultado == -1) {
        perror("Error al ejecutar ioctl");
        close(fd);
        return 1;
    }

    // Cierra el dispositivo o archivo especial
    close(fd);

    return 0;
}
