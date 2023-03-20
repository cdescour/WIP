/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:49:40 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/20 12:00:26 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <math.h>
# include <float.h>
# include <mlx.h>

# include "../Libft/libft.h"


# define true 1
# define false 0

# define RESOLUTION_D 1
# define AMBIENT_D 2
# define CAMERA_D 3
# define LIGHT_D 4
# define SPHERE_D 5
# define PLANE_D 6
//# define SQUARE_D 7
# define CYLINDER_D 8
//# define TRIANGLE_D 9
//setings
# define RX 1920
# define RY 1080

//E1->argcheck an objects
# define E1001 "Error\nNot enough arguments\n"
# define E1002 "Error\nToo many arguments\n"
# define E1003 "Error\nFile name not defined\n"
# define E1004 "Error\nFile can not be found\n"
# define E1005 "Error\nWrong place for negative sign\n"
# define E1006 "Error\nHas more than one dot\n"
# define E1007 "Error\nContains invalid symbols\n"
# define E1008 "Error\nCan't have nothing after dot :(\n"
# define E1009 "Error\nWrong orientation vector range on x\n"
# define E1010 "Error\nWrong orientation vector range on y\n"
# define E1011 "Error\nWrong orientation vector ranke on z\n"
# define E1012 "Error\nLuminosity ratio out of range\n"
# define E1013 "Error\nFOV out of range\n"
# define E1014 "Error\nCoordinates of 'x' out of the zone!\n"
# define E1015 "Error\nCoordinates of 'y' out of the zone!\n"
# define E1016 "Error\nCoordinates of 'z' out of the zone!\n"
# define E1017 "Error\nToo many elements!\n"
# define E1018 "Error\nCan't have them all at 0...\n"
# define E1019 "Error\nInvalid colors input\n"
# define E1020 "Error\nWrong amount of elements for A content\n"
# define E1021 "Error\nWrong amount of elements for C content\n"
# define E1022 "Error\nWrong amount of elements for L content\n"
# define E1023 "Error\nWrong amount of elements for sp content\n"
# define E1024 "Error\nWrong amount of elements for pl content\n"
# define E1025 "Error\nWrong amount of elements for cy content\n"
# define E1026 "Error\nAt least one coordinate is out of range\n"

typedef struct s_sphere t_sphere;
typedef struct s_plan t_plan;
typedef struct s_cyl t_cyl;
typedef struct s_amb t_amb;
typedef struct s_color t_color;

typedef struct	s_vector
{
	double x;
	double y;
	double z;
}				t_vector;

typedef struct	s_varcal
{
	double		a;
	double		b;
	double		c;
	double		delta;
	double		u;
	double		v;
	double		t;
	double		t1;
	double		t2;
	t_vector	edge1;
	t_vector	edge2;
	t_vector	oc;
}				t_varcal;

typedef struct	s_camera
{
	t_vector		pos;
	t_vector		ort_vec;
	double			fov;
	t_vector		pixel;
	t_vector		n;
	t_vector		u;
	t_vector		v;
	t_vector		l;
	t_vector		r_dir;
	t_vector		translation;
	t_vector		rotation;
	struct s_camera	*previous;
	struct s_camera	*next;
}				t_camera;

typedef struct	s_colour
{
	double r;
	double g;
	double b;
}				t_colour;

typedef struct	s_info
{
	char	**pos;
	char	**pos1;
	char	**pos2;
	char	**colour;
	char	**vector;
	double	radius;
	double	height;
	char	**translation;
	char	**rotation;
	double	fov;
	double	int_light;
}				t_info;

typedef struct	s_objet
{
	int				type;
	t_vector		pos;
	t_vector		pos1;
	t_vector		pos2;
	double			radius;
	t_colour		colour;
	t_vector		point;
	t_vector		normal;
	t_vector		v;
	t_vector		reflection;
	t_vector		light;
	t_vector		view;
	t_vector		translation;
	t_vector		rotation;
	double			height;
	double			t;
	double			test;
	int				i;
	struct s_objet	*previous;
	struct s_objet	*next;
}				t_objet;

typedef struct	s_shadow
{
	double	degre;
	double	intersect;
}				t_shadow;

typedef struct	s_tools
{
	int		index;
	int		type;
	int		intersect;
	int		bmp;
	int		tran_rot;
}				t_tools;

typedef struct	s_parcing
{
	int	check;
	int	indice;
	int	error;
	int	r;
	int	a;
	int c;
}				t_parcing;

typedef struct	s_ray
{
	t_vector	origin;
	double		lenght;
	t_vector	direction;
}				t_ray;

typedef struct	s_light
{
	t_vector		pos;
	t_colour		rgb_light;
	double			int_light;
	t_vector		translation;
	struct s_light	*previous;
	struct s_light	*next;
}				t_light;

typedef struct	s_ambient
{
	t_colour	rgb_amb;
	double		int_amb;
}				t_ambient;

typedef struct	s_phong
{
	t_colour	diffuse;
	t_colour	specular;
	t_colour	ambiant;
}				t_phong;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*img_data;
	int		size_line;
	int		bpp;
	int		*tab;
}				t_mlx;

typedef struct	s_resolution
{
	int		x;
	int		y;
	int		width;
	int		height;
	double	half_height;
	double	half_width;
}				t_resolution;

typedef struct	s_data
{
	t_vector		vector;
	t_objet			*objet;
	t_tools			tool;
	t_ray			ray;
	t_colour		colour;
	t_mlx			mlx;
	t_light			*light;
	t_ambient		ambient;
	t_camera		*camera;
	t_resolution	rsl;
	t_phong			phong;
	t_parcing		parcing;
	t_shadow		shad;
	int				nb_cam;
	int				nb_amb;
	int				nb_spt;
}				t_data;

//////////////////////////////////////////////////////
int	get_next_line(int fd, char **line);
t_colour	make_rrange(int rgb);
void		sphere_p_n(t_data *type);
void		plane_p_n(t_data *type);
void		square_p_n(t_data *type);
void		cylinder_p_n(t_data *type);
void		triangle_p_n(t_data *type);
double		hit_sphere(t_objet *objet, t_ray *ray);
double		hit_plane(t_objet *objet, t_ray *ray);
double		hit_square(t_objet *objet, t_ray *ray);
void		calcul_delta_cy(t_objet *objet, t_ray *ray, t_varcal *var);
double		hit_cylinder(t_objet *objet, t_ray *ray);
double		hit_triangle(t_objet *objet, t_ray *ray);
void		hit_objet2(t_data *type, t_ray *ombre, t_objet *tmp);
void		hit_objet(t_data *type, double *t1);
void		ray(t_data *type);
void		half_w_h(t_data *type);
void		calcul_pixel(t_data *type);
void		mapper_pixel(t_data *type);
void		camera_setting(t_data *type);
t_colour	phong(t_data *type, t_colour shadow);

int		check_sphere(t_data *type, char **parc);
int		check_plane(t_data *type, char **parc);
int		check_square(t_data *type, char **parc);
int		check_cylinder(t_data *type, char **parc);
int		check_triangle(t_data *type, char **parc);
int		check_resolution(t_data *type, char **parc);
int		check_ambient(t_data *type, char **parc);
int		check_light(t_data *type, char **parc);
int		check_camera(t_data *type, char **parc);
int		check_numb(char *str);
int		check_double(char *str);
int		check_rotation(char *parc);
int		check_rgb(char *parc);
int		check_pos(char *parc);
int		check_vec_ort(char *parc);
int		miss_or_out(t_data *type, int object, int wich);
int		wrong_pos(t_data *type, int object);
int		wrong_vec_ort(t_data *type, int object);
int		wrong_rgb(t_data *type, int object);
int		wrong_trans_rot(t_data *type, int object, int wich);
void	ft_print(t_data *type, char *name, int number);
void	ft_print_cont(t_data *type, char *name, int object, int error);
void	print_error_type(t_data *type);
void		check_type(t_data *type, char **parc);
int			check_element(t_data *type, char **parc, int check);
t_colour	coleur(t_data *type);
int			merge(t_colour *data);
void		minirt(t_data *type);
t_colour	shadows(t_data *type, t_objet *tmp);
double		ft_atod(const char *str);
char		**ft_space_split(char const *s);
void		ft_mlx(t_data *type, int wich);
int			key_press(int keycode, t_data *type);
int			ft_close(t_data *type);
int			mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);
t_colour	colour_create(t_colour v1);
void		parcing(t_data *type, char **av, int ac);
void		parcing_check(t_data *type, char *line);
void		parcing_tool(t_data *type, int indice, char *line);
void		parc_sphere(t_data *type, char *line);
void		parc_plane(t_data *type, char *line);
void		parc_square(t_data *type, char *line);
void		parc_cylinder(t_data *type, char *line);
void		parc_triangle(t_data *type, char *line);
void		parc_resl(t_data *type);//, char *line);
void		parc_amb(t_data *type, char *line);
void		parc_camera(t_data *type, char *line);
void		parc_light(t_data *type, char *line);
t_light		*add_light(t_data *type, t_info object);
t_camera	*add_camera(t_data *type, t_info object);
t_objet		*add_sphere(t_data *type, t_info object);
t_objet		*add_plane(t_data *type, t_info object);
t_objet		*add_square(t_data *type, t_info object);
t_objet		*add_cylinder(t_data *type, t_info object);
t_objet		*add_triangle(t_data *type, t_info object);
void		trans_rot(t_data *type, t_objet *new_object, t_info object);
t_vector	rot_vector(t_vector vect_ort, t_vector angle);
double		ft_atod(const char *str);
int			ft_2strlen(char **str);
t_colour	r_g_b(char *r, char *g, char *b);
t_vector	x_y_z(char *x, char *y, char *z);
int			free_exit(t_data *type, int wich);
void		calcul_delta_cy(t_objet *objet, t_ray *ray, t_varcal *var);
void		witch_object(t_objet *objet, t_ray *ray, double *has_inter);
double		max(double a, double b);
double		min(double a, double b);
double		vector_dot(t_vector v1, t_vector v2);
t_vector	vector_sub(t_vector v1, t_vector v2);
t_vector	vector_scal(double c, t_vector v);
t_vector	vector_add(t_vector v1, t_vector v2);
t_vector	vector_cross(t_vector v1, t_vector v2);
t_vector	unit_vector(t_vector v);
double		vector_length(t_vector v);
t_vector	vector_prd(t_vector v1, t_vector v2);
t_vector	make_pos(double x, double y, double z);
t_colour	colour_add(t_colour v1, t_colour v2);
t_colour	colour_prd(t_colour col1, t_colour col2);
t_colour	colour_scal(double nbr, t_colour rgb);
t_vector	get_color(t_data *type, int nbrbonds);
t_colour	min_max(t_colour rgb);
t_colour	make_number(double nbr);
t_colour	make_range(t_colour rgb);
int			create_bmp(t_data *type);

#endif
