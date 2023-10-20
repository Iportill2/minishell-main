/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcsetattr_tcgetattr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:35:13 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/09 19:38:07 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

int main(void)
{
    int fd = STDIN_FILENO; // Descriptor de archivo para la entrada estándar (terminal)
    struct termios nuevo_attr, original_attr;

    // Obtener los atributos actuales del terminal
    if (tcgetattr(fd, &original_attr) == -1) {
        perror("Error al obtener los atributos del terminal");
        return 1;
    }

    // Copiar los atributos actuales a una estructura temporal
    nuevo_attr = original_attr;

    // Configurar la velocidad de baudios a 9600
    cfsetispeed(&nuevo_attr, B9600);
    cfsetospeed(&nuevo_attr, B9600);

    // Aplicar los cambios de inmediato
    if (tcsetattr(fd, TCSANOW, &nuevo_attr) == -1) {
        perror("Error al configurar los atributos del terminal");
        return 1;
    }

    printf("Velocidad de baudios configurada a 9600 bps.\n");

    // Restaurar los atributos originales del terminal
    if (tcsetattr(fd, TCSANOW, &original_attr) == -1) {
        perror("Error al restaurar los atributos originales del terminal");
        return 1;
    }

    return (0);
}
