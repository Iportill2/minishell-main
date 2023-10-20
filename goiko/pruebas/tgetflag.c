/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tgetflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:28:42 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/10 10:36:12 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <termcap.h> // Incluye la biblioteca termcap para tgetflag

int main() {
    char *flag_name = "ul"; // Nombre de la bandera a verificar (puede variar según la terminal)

    // Obtener el valor de la bandera
    int flag_value = tgetflag(flag_name);

    if (flag_value == 1) {
        printf("La bandera %s está habilitada.\n", flag_name);
    } else if (flag_value == 0) {
        printf("La bandera %s está deshabilitada.\n", flag_name);
    } else {
        printf("La bandera %s no está definida o se produjo un error.\n", flag_name);
    }

    return 0;
}
