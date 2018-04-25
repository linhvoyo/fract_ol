
#gcc -I ./minilibx_macos  -L ./minilibx_macos -l mlx -framework OpenGL -framework AppKit
gcc  -lpthread -Wall -Wextra -Werror src/*.c -I ./includes -I ./libs/libft/includes -L ./libs/libft/ -l ft -I ./libs/minilibx_macos -L ./libs/minilibx_macos -l mlx -framework OpenGL -framework AppKit -o fractol
