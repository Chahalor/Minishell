/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formating.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:16:49 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/11 16:53:19 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMATING_H
# define FORMATING_H

# pragma once

// string

# define ERROR	"Error: "
# define USAGE	"Usage: "
# define PADD	"    └──"
# define PADD5	"    ├──"
# define PADD0	"│  "
# define PADD2	"│  ├──"
# define PADD3	"│  │  "
# define PADD4	"│  └──"

# ifndef HEADER
#  define HEADER	" \
╔═══════════════════════════════════════════════════════════════════════════════\
═════════════╗\n \
║                                                                               \
             ║\n \
║       ________        ___  ___          ___          ___               _______\
_            ║\n \
║      |\\   __  \\      |\\  \\|\\  \\        |\\  \\        |\\  \\           \
  |\\   __  \\           ║\n \
║      \\ \\  \\|\\  \\     \\ \\  \\ \\  \\       \\ \\  \\       \\ \\  \\    \
        \\ \\  \\|\\  \\          ║\n \
║       \\ \\   ____\\     \\ \\   __  \\       \\ \\  \\       \\ \\  \\       \
     \\ \\  \\ \\  \\         ║\n \
║        \\ \\  \\___|      \\ \\  \\ \\  \\       \\ \\  \\       \\ \\  \\____\
        \\ \\  \\ \\  \\        ║\n \
║         \\ \\__\\          \\ \\__\\ \\__\\       \\ \\__\\       \\ \\_______\
\\       \\ \\_______\\       ║\n \
║          \\|__|           \\|__|\\|__|        \\|__|        \\|_______|       \
 \\|_______|       ║\n \
║                                                                               \
             ║\n \
║    By: nduvoid <nduvoid@student.42mulhouse.fr>                                \
             ║\n \
║    A 42 cursus Project                                                        \
             ║\n \
╚═══════════════════════════════════════════════════════════════════════════════\
═════════════╝\n"	/* We all love the norm xD */
# endif

// colors

# define BLACK			"\033[30m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"
# define WHITE			"\033[37m"

// formatting

# define RESET			"\033[0m"
# define BOLD			"\033[1m"
# define FAINT			"\033[2m"
# define ITALIC			"\033[3m"
# define UNDERLINE		"\033[4m"
# define BLINK			"\033[5m"
# define REVERSE		"\033[6m"
# define REVERSED		"\033[7m"
# define HIDDEN			"\033[8m"
# define STRIKETHROUGH	"\033[9m"

// background colors
//...

// cmd management

# define FULL_CLEAN		"\033[H\033[2J\033[3J"
# define CLEAR_SCREEN	"\033[2J\033[1;1H"
# define CURSOR_UP		"\033[1A"
# define CURSOR_DOWN	"\033[1B"
# define CURSOR_LEFT	"\033[1D"
# define CURSOR_RIGHT	"\033[1C"
# define CURSOR_HOME	"\033[H"

#endif	/* FORMATING_H */