/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:01:26 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/09 15:41:49 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void customHandler(int signum)
{
    printf("Se recibió la señal SIGINT (%d)\n", signum);
    exit(1);
}

int main(void)
{
    // Configurar un manejador personalizado para SIGINT
    signal(SIGINT, customHandler);

    printf("Presiona Ctrl+C para generar una señal SIGINT...\n");

    while (1)
    {
        // El programa espera hasta que se reciba la señal SIGINT
    }

    return 0;
}
