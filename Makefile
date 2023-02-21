NAMESERVER = server
NAMECLIENT = client
NAMESERVERBNS = server_bonus
NAMECLIENTBNS = client_bonus
NAME = none.c
LIB = ./ft_printf/libftprintf.a
SRCSERVER = server.c
SRCCLIENT = client.c
SRCSERVERBNS = server_bonus.c
SRCCLIENTBNS = client_bonus.c
FLAGS = -Wall -Wextra -Werror
CC = gcc
OBJSERVER = $(SRCSERVER:.c=.o)
OBJCLIENT = $(SRCCLIENT:.c=.o)
OBJSERVERBNS = $(SRCSERVERBNS:.c=.o)
OBJCLIENTBNS = $(SRCCLIENTBNS:.c=.o)

all: $(LIB) $(NAMESERVER) $(NAMECLIENT)

$(NAME) : all

bonus: $(LIB) $(NAMESERVERBNS) $(NAMECLIENTBNS)

$(LIB):
	make all -C ./ft_printf

$(NAMESERVER) : $(OBJSERVER)
	$(CC) $(OBJSERVER) -o $(NAMESERVER) $(LIB)

$(NAMECLIENT) : $(OBJCLIENT)
	$(CC) $(OBJCLIENT) -o $(NAMECLIENT) $(LIB)

$(NAMESERVERBNS) : $(OBJSERVERBNS)
	$(CC) $(OBJSERVERBNS) -o $(NAMESERVERBNS) $(LIB)

$(NAMECLIENTBNS) : $(OBJCLIENTBNS)
	$(CC) $(OBJCLIENTBNS) -o $(NAMECLIENTBNS) $(LIB)

clean:
	rm -rf $(OBJSERVER) $(OBJCLIENT) $(OBJSERVERBNS) $(OBJCLIENTBNS)

fclean: clean
	rm -rf $(NAMESERVER) $(NAMECLIENT) $(NAMESERVERBNS) $(NAMECLIENTBNS)

ffclean: fclean
	make fclean -C ./ft_printf

.c.o:
	$(CC) $(FLAGS) -c $^ -o $@

re:fclean all

.PHONY : re fclean clean all ffclean