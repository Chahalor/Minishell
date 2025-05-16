/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:01:06 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/04/18 19:04:48 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

///*** TESTER_H *************************************************************///

/* To ignore the format flag within the main */
#pragma GCC diagnostic ignored "-Wformat"
#pragma GCC diagnostic ignored "-Wformat-overflow"
#pragma GCC diagnostic ignored "-Wformat-zero-length"
#pragma GCC diagnostic ignored "-Wnonnull"

/* Macros to clean the code */
#define TEST(CALL, INFO) prefix(); suffix(CALL, INFO)

#define RUN_TEST(ARGS, INFO) \
	TEST(printf ARGS, INFO); TEST(ft_printf ARGS, INFO);

/* libs */
#include <stdio.h>
#include <limits.h>

// FT_PRINT
int			ft_printf(const char *f, ...);

// UTILS
static void	main_title(void);
static void	title(const char *title);
static void	prefix(void);
static void	suffix(int len, const char *info);

// TESTS
void		run_basic_test(void);
void		run_common_test(void);
void		run_extreme_test(void);
///**************************************************************************///

/*
*
 *
*
 *
*
 *
*
 *
*/

///*** TESTER ***************************************************************///
int	main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);

	main_title();

	run_basic_test();
	run_common_test();
	run_extreme_test();

	return (0);
}
///**************************************************************************///

/*
*
 *
*
 *
*
 *
*
 *
*/

///*** TESTS ****************************************************************///

// RUN_TEST((PRINTF CONTENT), "COMMENT/INFO");

void	run_basic_test(void)
{
	title("Basic Tests (%cspdiuxX)");

	RUN_TEST(("Hello, World!"), "");
	RUN_TEST(("%%"), "%%");
	RUN_TEST(("%c", 42), "%c");
	RUN_TEST(("%s", "hi"), "%s");
	RUN_TEST(("%p", ""), "%p");
	RUN_TEST(("%d", 42), "%d");
	RUN_TEST(("%i", 42), "%i");
	RUN_TEST(("%u", 42), "%u");
	RUN_TEST(("%x", 42), "%x");
	RUN_TEST(("%X", 42), "%X");
}

void	run_common_test(void)
{
	title("Common Tests");

	RUN_TEST(("%s", ""), "%s empty string");
	RUN_TEST(("%s", NULL), "%s NULL string");
	RUN_TEST(("%i", INT_MAX), "%i INT_MAX");
	RUN_TEST(("%d", INT_MIN), "%d INT_MIN");
	RUN_TEST(("%i", 0), "%i zero");
	RUN_TEST(("%p", (void *)1), "%p small address");
	RUN_TEST(("%p", (void *)LONG_MAX), "%p LONG_MAX");
	RUN_TEST(("%p", (void *)LONG_MIN), "%p LONG_MIN");
	RUN_TEST(("%p", NULL), "%p NULL address");
	RUN_TEST(("%u", UINT_MAX), "%u UINT_MAX");
	RUN_TEST(("%x", UINT_MAX), "%x UINT_MAX");
	RUN_TEST(("%X", 0), "%X 0");
	RUN_TEST(("%x", INT_MAX), "%x INT_MAX");
	RUN_TEST(("%X", INT_MIN), "%X INT_MIN");
	RUN_TEST(("%c %s %p %d %i %u %x %X %%",
			'Z', "(O-O)", (void *)42, 128, -74, -13, 66, 99), "mixed formats");
}

void	run_extreme_test(void)
{
	title("Extreme Tests 😈");

	RUN_TEST((""), "empty format string");
	RUN_TEST((NULL), "NULL format string");
	RUN_TEST(("Hello, 世界! 👋🏼 😀 äëïöü âêîôû こんにちは 안녕하세요 🌍"), "UTF8");
	RUN_TEST(("%s", "Hello, 世界! 👋🏼 😀 äëïöü âêîôû こんにちは 안녕하세요 🌍"), "UTF8 in %s");
	RUN_TEST(("%i", "LOL"), "%i with a string");
	RUN_TEST(("%"), "only %");
	RUN_TEST(("end%"), "ending by %");
	RUN_TEST(("Hello %k World!"), "invalid %k format");
	RUN_TEST(("Hello %👹 World!"), "invalid %👹 format");
	RUN_TEST(("hehe %  s !", "ça marche ça"), "'%  s' format");
}
///**************************************************************************///

/*
*
 *
*
 *
*
 *
*
 *
*/

///*** UTILS ****************************************************************///

// COLORS
#define C1 "\033[38;2;111;255;0m"
#define C2 "\033[38;2;0;222;255m"
#define CC "\033[38;2;111;123;255m"
#define MT "\033[1;38;2;200;255;0m"
#define T1 "\033[1;38;2;255;111;0m"
#define T2 "\033[0;38;2;255;111;0m"
#define NC "\033[0m"

static void	prefix(void)
{
	static int	i = 1;
	const char	*label = (i % 2) ? "printf   " : "ft_printf";
	const char	*color = (i++ % 2) ? C1 : C2;

	printf("%s%s:  '%s", color, label, NC);
}

static void	suffix(int len, const char *info)
{
	static int	i = 1;

	if (i % 2)
	{
		if (info && *info)
			printf("%s'  [%s%d%s]. %s/* %s */\n%s", C1, NC, len, C1, CC, info, NC);
		else
			printf("%s'  [%s%d%s].\n%s", C1, NC, len, C1, NC);
	}
	else
		printf("%s'  [%s%d%s].\n%s\n%s", C2, NC, len, C2, CC, NC);
	i++;
}

static void	title(const char *title)
{
	static int	i = 1;

	printf("%sTEST (%d) :    %s%s%s\n\n", T1, i++, T2, title, NC);
}

static void	main_title(void)
{
	printf(MT "\n");
	printf(" ┌──────────────────────────────┐\n");
	printf(" │%s ft_printf tests: by ugwentzi %s│\n", NC, MT);
	printf(" └──────────────────────────────┘\n");
	printf(NC "\n");
}
///**************************************************************************///
