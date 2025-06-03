/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:48:00 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/03 11:50:04 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../args/args.h"

int main(int argc, char const *argv[])
{
	t_args	args;

	args = args_parser(argc, argv);
	return (args.error != 0);
}
