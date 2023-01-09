#include "philo.h"

int	main(int ac, char **argv)
{
	t_context	context;
	t_philo		*philos;

	philos = NULL;
	if (ft_check_args(ac - 1, argv + 1))
	{
		context = ft_init_context(argv + 1, ac -1);
		philos = ft_init_tab_philo(context);
		if (philos)
			ft_philo(philos);
		else
			printf("FAILURE\n");
	}
	else
		printf("salut:.\n");
	return (EXIT_SUCCESS);
}
