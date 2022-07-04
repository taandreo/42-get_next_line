.PHONY: libft.a all clean fclean re log bonus

CC = clang
CFLAGS = -Wall -Wextra -Werror -I . -g3
MAIN = get_next_line.c get_next_line_utils.c main.c
OUT = get_next_line
DOCKER_IMAGE = 42/debian-clang:1.0
BUFFER_SIZE = 42
VALGRIND = valgrind --leak-check=full -v

all:
	$(CC) $(CFLAGS) $(MAIN) -D BUFFER_SIZE=$(BUFFER_SIZE) -o $(OUT) -arch x86_64

clean: 
	rm -f $(OUT)

exec: all
	./$(OUT)

valgrind: all
	$(VALGRIND) ./$(OUT)

docker:
	@docker rm -f $(OUT) > /dev/null 2>&1 || true
	@docker run --name $(OUT) -dti -v $(shell pwd):/project $(DOCKER_IMAGE)
	@docker exec -ti $(OUT) make valgrind

fclean: clean

re: fclean all

log:
	@echo $(MAIN)