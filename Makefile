SERVER = server
CLIENT = client

CFLAGS = -Wall -Wextra -Werror
CC = gcc
PRINTF = ft_printf

all:
	@make -C $(PRINTF)  # Compile ft_printf first
	@gcc $(CFLAGS) server.c $(PRINTF)/libftprintf.a -o $(SERVER)  # Link the library
	@gcc $(CFLAGS) client.c $(PRINTF)/libftprintf.a -o $(CLIENT)  # Link the library
	@echo "Server And Client Are Ready!"

clean:
	@make clean -C $(PRINTF)

fclean: clean
	@make fclean -C $(PRINTF)
	@rm -f $(SERVER) $(CLIENT)
	@echo "Server and Client Have Been Cleaned Successfully"

re: fclean all

