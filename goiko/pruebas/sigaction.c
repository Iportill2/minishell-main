/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigaction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:55:21 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/09 15:56:38 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void customHandler(int signum) {
    printf("Se recibió la señal SIGINT (%d)\n", signum);
    // Realiza cualquier acción necesaria antes de finalizar
    // ...
    exit(1);
}

int main(void) {
    struct sigaction new_action;
    struct sigaction old_action;

    // Configurar un manejador personalizado para SIGINT
    new_action.sa_handler = customHandler;
    sigemptyset(&new_action.sa_mask);
    new_action.sa_flags = 0;

    if (sigaction(SIGINT, &new_action, &old_action) != 0) {
        perror("Error al configurar el manejador de señales");
        return 1;
    }

    printf("Presiona Ctrl+C para generar una señal SIGINT...\n");

    while (1) {
        // El programa espera hasta que se reciba la señal SIGINT
    }

    return 0;
}
