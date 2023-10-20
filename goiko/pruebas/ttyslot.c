/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttyslot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:17:55 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/09 18:18:07 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main()
{
    int tty_slot;

    tty_slot = ttyslot();

    if (tty_slot == -1) {
        perror("Error al obtener el índice del terminal");
        return 1;
    }

    printf("El índice del terminal en la base de datos de nombres de usuario es: %d\n", tty_slot);

    return 0;
}
