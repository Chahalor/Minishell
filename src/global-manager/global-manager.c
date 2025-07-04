/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global-manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:48:15 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/26 08:11:33 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_global_manager.h"

/* -----| Modules   |----- */
#include "global_manager.h"

#pragma endregion Header
#pragma region Fonctions

/** */
__attribute__((always_inline, used)) static inline t_global_manager	_init(void)
{
	t_global_manager	manager;

	manager = (t_global_manager){0};
	getcwd(manager.current_path, sizeof(manager.current_path));
	return (manager);
}

/** */
__attribute__((hot, used)) static const void	*_manager(
	const int access,
	void *ptr
)
{
	static t_global_manager	manager = {0};

	if (access == _get_last_child)
		return (&manager.last_child);
	else if (access == _set_last_child)
		return (manager.last_child = *(pid_t *)ptr, NULL);
	else if (access == _get_current_path)
		return (manager.current_path);
	else if (access == _set_current_path)
		return (getcwd(manager.current_path, sizeof(manager.current_path)),
			NULL);
	else if (__builtin_expect(access == _do_init, unexpected))
		return (manager = _init(), NULL);
	return (NULL);
}

/** */
__attribute__((hot, used)) int	get_last_child(void)
{
	return (*(int *)_manager(_get_last_child, NULL));
}

/** */
__attribute__((hot, used)) int	set_last_child(
	pid_t pid
)
{
	return (_manager(_set_last_child, &pid) == NULL);
}

/**
 * @note: should be use after chdir()
*/
__attribute__((hot, used)) int	set_current_path(void)
{
	return (_manager(_set_current_path, NULL) == NULL);
}

#pragma endregion Fonctions