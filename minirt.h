/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 13:55:11 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/12/20 15:16:44 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include "get_next_line/get_next_line.h"
# include "minilibx_mms_20200219/mlx.h"

typedef struct	s_vector{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_rgb{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct	s_count
{
	int			r;
	int			a;
	int			c;
	int			l;
	int			pl;
	int			sp;
	int			sq;
	int			cy;
	int			tr;
}				t_count;

typedef struct	s_screen
{
	void		*mlx;
	void		*mlx_win;
	int			width;
	int			height;
	int			x;
	int			y;
	double		wx;
	double		wy;
	int			cam_id;
}				t_screen;

typedef struct	s_ambient{
	double		ratio;
	double		rgb[3];
}				t_ambient;

typedef struct	s_light{
	t_vector	pos;
	double		rad;
	double		rgb[3];
}				t_light;

typedef struct	s_camera{
	t_vector	pos;
	t_vector	ray;
	t_vector	look;
	t_vector	vup;
	t_vector	x;
	t_vector	y;
	t_vector	z;
	int			fov;
}				t_camera;

typedef struct	s_angle
{
	t_vector	inter;
	t_vector	normal;
	t_vector	incident;
}				t_angle;

typedef struct	s_var_list
{
	t_vector	inter;
	t_vector	normal;
	t_vector	incident;
	double		t;
	double		cosa;
	double		cosg;
	double		rgb[3];
}				t_var_list;

typedef struct	s_plane{
	t_vector	pos;
	t_angle		angle;
	t_var_list	var;
}				t_plane;

typedef struct	s_square{
	t_vector	pos;
	double		size;
	t_var_list	var;
	t_vector	ver;
	t_vector	hor;
}				t_square;

typedef struct	s_cylinder{
	t_vector	pos;
	t_vector	norm;
	t_var_list	var;
	double		r;
	double		height;
}				t_cylinder;

typedef struct	s_triangle{
	t_vector	p[3];
	t_var_list	var;
}				t_triangle;

typedef struct	s_quadratic{
	double		a;
	double		b;
	double		c;
	double		d;
}				t_quadratic;

typedef struct	s_sphere{
	t_vector	pos;
	double		rad;
	double		d;
	t_var_list	var;
}				t_sphere;

typedef struct	s_list
{
	t_count		*cnt;
	t_screen	*scn;
	t_sphere	*sp;
	t_ambient	*amb;
	t_camera	*cam;
	t_light		*l;
	t_plane		*pl;
	t_square	*sq;
	t_cylinder	*cy;
	t_triangle	*tr;
	t_rgb		*pixels;
	t_camera	base_cam;

	t_rgb		**rgb;
	void		**img;
	char		**add;

	void		*targ;
	int			type;
}				t_list;
/*
** vector_operators.c
*/
t_vector		vector_add(t_vector v1, t_vector v2);
t_vector		vector_sub(t_vector dest, t_vector start);
t_vector		vector_mlt(t_vector base, double times);
double			inner(t_vector v1, t_vector v2);
double			norm(t_vector v);
/*
** vector_operators2.c
*/
t_vector		cross(t_vector a, t_vector b);
t_vector		normalize(t_vector vec);
t_vector		get_incident_vec(t_var_list var, t_vector l_pos);
/*
** sphere.c
*/
double			get_t_sp(t_sphere sp, t_vector pos, t_vector ray);
t_vector		get_tangent(t_camera camera, double t);
double			get_cosa(t_var_list ls);
double			get_cosg(t_var_list ls, t_camera cam);
/*
** plane.c
*/
double			get_t_pl(t_plane pl, t_vector pos, t_vector ray);
/*
** square.c
*/
double			get_t_sq(t_square sq, t_vector pos, t_vector ray);
int				inside_sq(t_square sq, t_vector p);
void			set_basis_sq(t_list *ls, t_square *sq);
/*
** triangle.c
*/
double			get_t_plane(t_vector p, t_vector normal, \
t_vector pos, t_vector ray);
int				p_test_tr(t_triangle tr, t_vector p);
double			get_t_tr(t_triangle tr, t_vector pos, t_vector ray);
void			set_normal_tr(t_triangle *tr, \
t_vector pos0, t_vector pos1, t_vector pos2);
/*
** cylinder.c
*/
double			get_t_cy(t_cylinder cy, t_vector ray, t_vector c);
t_vector		get_normal_cy(t_cylinder cy, t_vector p);
double			large_t_cy(t_cylinder cy, t_vector ray, t_vector c);
/*
** len_tests_cy.c
*/
int				check_len_cy(t_cylinder cy, t_vector p);
int				len_cy(t_list *ls, t_cylinder *cy);
int				len_test_cy(t_list *ls, t_cylinder *cy, int *min, int i);
/*
** cos_pl.c
*/
double			get_cosa_pl(t_var_list *var);
double			get_cosg_pl(t_var_list var, t_camera cam);
/*
** cos_tr.c
*/
double			get_cosa_tr(t_var_list *var);
double			get_cosg_tr(t_var_list var, t_camera cam);
/*
** get_byid.c
*/
double			get_r_byid(t_list *ls, int min);
double			get_g_byid(t_list *ls, int min);
double			get_b_byid(t_list *ls, int min);
double			get_cosa_byid(t_list *ls, int min);
double			get_cosg_byid(t_list *ls, int min);
/*
** id.c
*/
int				convert_min(int min, int type, t_count cnt);
int				type(t_count cnt, int id);
int				id_id(t_count cnt, int id);
int				item_num(t_list *ls);
/*
** init.c
*/
t_vector		init_vector(double x, double y, double z);
t_sphere		init_sphere(t_vector pos, double radius);
t_camera		init_camera(t_vector	pos);
t_light			init_light(t_vector		pos);
t_screen		init_screen(int width, int height);
/*
** init2.c
*/
t_rgb			init_rgb(int r, int g, int b);
/*
** parse_objects.c
*/
void			parse_sp(t_list *ls, char *line);
void			parse_pl(t_list *ls, char *line);
void			parse_sq(t_list *ls, char *line);
void			parse_tr(t_list *ls, char *line);
void			parse_cy(t_list *ls, char *line);
/*
** parse_objects2.c
*/
void			parse_r(t_list *ls, char *line);
void			parse_a(t_list *ls, char *line);
void			parse_c(t_list *ls, char *line);
void			parse_l(t_list *ls, char *line);
/*
** parse_utils.c
*/
int				atoishift(char **line);
double			decshift(char **line);
int				cisspace(char c);
double			nextnum(char **line, double min, double max);
t_vector		get_vectors(char **line, double min, double max);
/*
** parse_utils2.c
*/
void			check_normal(t_vector n);
void			skip_to_num(char **line);
/*
** parse_check.c
*/
int				check_null(size_t size, void *p);
int				check_path(char *path);
void			check_capital(t_count *cnt);
/*
** parse.c
*/
t_list			*parse(char *path);
/*
** bitmap.c
*/
void			bitmap_generator(t_list *ls);
/*
** color.c
*/
void			new_pixel_put(t_screen s, int x, int y, t_rgb rgb);
double			get_trgb_fromid(t_list *ls, int id);
int				create_trgb(int t, int r, int g, int b);
/*
** get_pixels.c
*/
t_rgb			*get_pixels(t_list *ls);
/*
** collision_objects.c
*/
double			collision_sp(t_list *ls, int id);
double			collision_pl(t_list *ls, int id);
double			collision_tr(t_list *ls, int id);
double			collision_sq(t_list *ls, int id);
double			collision_cy(t_list *ls, int id);
/*
** check_collision.c
*/
int				check_collision(t_list *ls);
/*
** set_var_objects.c
*/
void			set_var_sp(t_sphere *sp, t_camera cam, t_light l);
void			set_var_pl(t_var_list *var, t_camera cam, t_light l);
void			set_var_sq(t_var_list *var, t_camera cam, t_light l);
void			set_var(t_var_list *var, t_camera cam, t_light l);
void			set_var_cy(t_cylinder *cy, t_camera cam, t_light l);
/*
** is_shadow.c
*/
int				is_shadow(t_list *ls, t_light light, int id);
/*
** shadow_manager.c
*/
t_rgb			shadow_manager(t_list *ls, int min, t_camera cam);
/*
** shadow_objects.c
*/
int				shadow_sp(t_list *ls, t_vector ray, t_light light, int id);
int				shadow_pl(t_list *ls, t_vector ray, t_light light, int id);
int				shadow_sq(t_list *ls, t_vector ray, t_light light, int id);
int				shadow_cy(t_list *ls, t_vector ray, t_light light, int id);
int				shadow_tr(t_list *ls, t_vector ray, t_light light, int id);
/*
** shadow_utils.c
*/
double			*add_brightness_d(t_list *ls, int min, t_light l, double *var);
double			*add_brightness_s(t_list *ls, int min, t_light l, double *var);
/*
** utils.c
*/
void			*ft_memset(void *buf, int ch, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t n, size_t size);
int				ft_strcmp(const char *s1, const char *s2);
/*
** utils2.c
*/
double			ft_max(double a, double b);
double			ft_min(double a, double b);
int				cisnum(char c);
size_t			ft_strlen_new(const char *str);
void			ft_putstr(char *s);
/*
** utils3.c
*/
char			*get_fname(char *index);
/*
** init_scn.c
*/
t_screen		*init_scn(t_list *ls, int argc);
/*
** get_next_line.c
*/
/*
** main.c
*/
void			exit_error(char *msg);
/*
** project_window.c
*/
void			project_window(t_list *ls);
void			create_images(t_list *ls);

# define CAM 0
# define LGT 1
# define SP 2
# define PL 3
# define SQ 4
# define CY 5
# define TR 6
# define KEY_PRESS	2
# define WIN_MIN	9
# define WIN_CLOSE	17
# define KEY_TAB	48
# define KEY_ESC	53
# define KEY_TAB_VM	65289
# define KEY_ESC_VM	65307
# define EPSILON	1E-9

#endif
