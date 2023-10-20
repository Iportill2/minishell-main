/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isatty.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:09:50 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/09 18:10:13 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int fd = STDOUT_FILENO; // Descriptor de archivo para la salida estándar (por lo general, un terminal)

    if (isatty(fd)) {
        printf("La salida estándar está conectada a un terminal.\n");
    } else {
        printf("La salida estándar no está conectada a un terminal.\n");
    }

    return (0);
}
