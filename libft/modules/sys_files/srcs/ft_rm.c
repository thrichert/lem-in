/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 14:18:21 by apopinea          #+#    #+#             */
/*   Updated: 2018/02/26 14:35:43 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_sys_files.h"

/*
** wlf_rm_file -> libft/main/ft_rm.c
**		la fonction supprime un fichier pointe par son
**		path.
**
**	unlink 	->	unistd.h
**		|--> supprime le nom du fichier du filesystem
**	ft_error_d -> libft
**		|--> renvoi FAIL et affiche message d'erreur
*/

static char	ft_rm_file(char *path)
{
	errno = 0;
	if (unlink(path) < 0)
	{
		return (ft_error_d(2, "RFLssnEn", FI_, FU_, LI_,
			"can't delete file : ", path, errno));
	}
	return (SUCCESS);
}

/*
** wlf_rm_file -> libft/main/ft_rm.c
**		la fonction supprime un dossier pointe par son
**		path.
**
**	rmdir 	->	unistd.h
**		|--> supprime le nom du dossier du filesystem
**	ft_error_d -> libft
**		|--> renvoi FAIL et affiche message d'erreur
*/

static char	ft_rm_dir(char *path)
{
	errno = 0;
	if (rmdir(path) < 0)
	{
		return (ft_error_d(2, "RFLssnEn", FI_, FU_, LI_,
			"can't delete directory : ", path, errno));
	}
	return (SUCCESS);
}

/*
** 	wlf_rm	--> libft/main/ft_rm.c
**		la fonction supprime un fichier ou un dossier pointe
**		par son path.
**
**	wlf_rm_file -> utilities/srcs/wlf_remove.c
**		|--> supprime un fichier
**	wlf_rm_dir -> utilities/srcs/wlf_remove.c
**		|--> supprime un dossier
**	ft_error_d -> libft
**		|--> renvoi FAIL et affiche message d'erreur
*/

char		ft_rm(char *path)
{
	struct stat file_stat;

	if (!path)
		return (ft_error_d(2, "RFLsn", FFL, "No path provided"));
	if (stat(path, &file_stat) < 0)
	{
		return (ft_error_d(2, "RFLsssnEn", FI_, FU_, LI_,
			"File : ", path, " ,does not exist", errno));
	}
	if (S_ISREG(file_stat.st_mode))
		ft_rm_file(path);
	else if (S_ISDIR(file_stat.st_mode))
		ft_rm_dir(path);
	else
	{
		return (ft_error_d(2, "RFLssnEn", FI_, FU_, LI_,
			"path point to either a File nor a Directory\n path : ",
			path, errno));
	}
	return (SUCCESS);
}
