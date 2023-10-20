/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:21:25 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/09 16:25:27 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *buffer;
    size_t size = 256;  // Tamaño inicial del búfer

    buffer = (char *)malloc(size);
    if (buffer == NULL)
	{
        perror("Error al asignar memoria para el búfer");
        return 1;
    }
	getcwd(buffer, size);
    printf("Directorio de trabajo actual: %s\n", buffer);
    free(buffer); // Liberar la memoria asignada
    return 0;
}
