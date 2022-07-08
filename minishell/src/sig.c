/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:15:50 by meudier           #+#    #+#             */
/*   Updated: 2022/07/08 10:04:54 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

void handler_sigint(int sig)
{
	if (sig == SIGINT)
	{
        write(1, "\n", 1); 
        //rl_replace_line("", 0);
        //rl_on_new_line();
        //rl_redisplay();
		kill(getpid(), SIGCONT);
	}
	if (sig == SIGQUIT)
		printf("ok");
}

void	sig_init(void)
{
	struct sigaction sa;

	sa.sa_flags = SA_RESTART;
	sa.sa_handler = &handler_sigint;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}
