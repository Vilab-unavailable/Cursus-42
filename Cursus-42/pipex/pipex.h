/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:49:27 by vilabard          #+#    #+#             */
/*   Updated: 2025/08/13 17:57:57 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len);
void	ft_freetable(char **tab);
char	**ft_get_paths(char **envp);
char	*ft_which_path(char *cmd, char **envp);
void	ft_execute(char *str_cmd, char **envp);

#endif
