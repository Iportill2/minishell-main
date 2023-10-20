/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttyname.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:13:25 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/09 18:13:48 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int fd = STDOUT_FILENO; // Descriptor de archivo para la salida estándar (por lo general, un terminal)
    char *terminal_name;

    terminal_name = ttyname(fd);

    if (terminal_name != NULL) {
        printf("El terminal asociado al descriptor %d es: %s\n", fd, terminal_name);
    } else {
        printf("El descriptor %d no se refiere a un terminal.\n", fd);
    }

    return 0;
}
