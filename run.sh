
#gcc -I ./minilibx_macos main.c -L ./minilibx_macos -l mlx -framework OpenGL -framework AppKit
gcc -Wall -Wextra -Werror src/*.c -I ./includes -I libft/includes -L libft/ -l ft -I ./minilibx_macos -L ./minilibx_macos -l mlx -framework OpenGL -framework AppKit -o fractol
