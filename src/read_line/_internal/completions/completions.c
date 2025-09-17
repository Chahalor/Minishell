/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:21:34 by nduvoid           #+#    #+#             */
/*   Updated: 2025/09/17 10:50:01 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE

/* -----| Internals |----- */
#include "_read_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

/* -----| Modules   |----- */
#include "read_line.h"

extern char	*_get_dir(
				const char *const restrict path
				);

extern char	*_get_file(
				const char *const restrict path
				);

extern void	_add_builtin(
				t_rl_completion *const restrict completion,
				const char *const restrict path_file
				);

extern int	_add_cmds(
				const char *const restrict word,
				t_rl_completion *const restrict dt
				);

extern int	_add_paths(
				const char *const restrict word,
				t_rl_completion *const restrict dt
				);

/**
 *  @brief	Display the completion entries in the terminal.
 * 
 *  @param	completion	The completion data containing entries to display.
 *  @param	data		The read line data structure for prompt and result.
 * 
 * @return	Returns 0
 * 
 * @version 1.0
 */
static inline int	_show(
	t_rl_completion *const restrict completion,
	t_rl_data *const restrict data
)
{
	register int	i;
	t_file_type		type;

	write(STDOUT_FILENO, "\r\n", 2);
	i = -1;
	while (++i < completion->nb_entries)
	{
		type = check_path(completion->entry[i]->d_name, F_OK | X_OK);
		if (type == e_directory)
			ft_printf(BOLD BLUE "%s/ " RESET, completion->entry[i]->d_name);
		else if (type == e_symlink)
			ft_printf(BOLD MAGENTA "%s@ " RESET, completion->entry[i]->d_name);
		else if (type == e_executable)
			ft_printf(BOLD GREEN "%s* " RESET, completion->entry[i]->d_name);
		else
			ft_printf(BOLD "%s " RESET, completion->entry[i]->d_name);
	}
	if (_LIKELY(i))
		ft_printf("\r\n%s%s", data->prompt, data->result);
	return (0);
}

__attribute__((always_inline, used, malloc))
static inline char	*__sub_str(
	t_rl_completion *const restrict completion,
	const char *const restrict str
)
{
	char			*_result;
	register int	__len;
	register int	__i;
	register int	__cmp;

	(void)str;
	__len = ft_strlen(completion->entry[0]->d_name);
	__i = 0;
	while (__i < completion->nb_entries - 1)
	{
		__cmp = 0;
		while (completion->entry[__i]->d_name[__cmp]
			== completion->entry[__i + 1]->d_name[__cmp] && __cmp < __len)
			++__cmp;
		if (__cmp < __len)
			__len = __cmp;
		++__i;
	}
	_result = mm_alloc(__len + 1);
	if (_UNLIKELY(!_result))
		return (NULL);
	ft_memcpy(_result, completion->entry[0]->d_name, __len);
	_result[__len] = '\0';
	return (_result);
}

/**
 * @brief	Replace the last word in the result with the completion word.
 * 
 *  @param	completion	The completion data containing the word to replace.
 *  @param	data		The read line data structure for prompt and result.
 * 
 *  @return	Returns 0
 */
static inline int	_replace(
	t_rl_completion *const restrict completion,
	t_rl_data *const restrict data,
	const char *const restrict sub
)
{
	char				*_sub_str;
	register int		i;

	i = data->line_length;
	while (i > 0 && data->result[i - 1] != ' ' && data->result[i - 1] != '/')
		--i;
	_neutral(data->result + i, data->line_length - i);
	data->cursor_pos = i;
	data->line_length = i;
	_sub_str = __sub_str(completion, sub);
	_rl_add(data, _sub_str, rl_str);
	if (completion->entry[0]->d_type == DT_DIR && completion->nb_entries == 1)
		_rl_add(data, "/", rl_chr);
	ft_printf("\033[2K\r%s%s", data->prompt, data->result);
	mm_free(_sub_str);
	return (0);
}

/**
 *  @brief	Handle the completion of the last word in the result.
 * 
 *  @param	data	The read line data structure containing the result.
 * 
 *  @return	Returns 0 on success, -1 on error.
 *  @retval		+0 on success
 *  @retval		-1 on error (memory allocation failure or no entries found).
 * 
 *  @version 1.1
*/
int	completion(
	t_rl_data *const restrict data
)
{
	char			**words;
	register int	nb_words;
	t_rl_completion	completion;

	_neutral(&completion, sizeof(t_rl_completion));
	words = ft_split(data->result, ' ');
	if (_UNLIKELY(!words))
		return (-1);
	nb_words = arraylen((const void *const *)words);
	_add_paths(words[nb_words - 1], &completion);
	_add_cmds(words[nb_words - 1], &completion);
	if (completion.nb_entries > 0)
	{
		_replace(&completion, data, words[nb_words - 1]);
		_show(&completion, data);
	}
	return (free_tab(words), _rl_free_completion__(&completion), 0);
}
