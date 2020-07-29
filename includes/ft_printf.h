/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:58:20 by jgroleo           #+#    #+#             */
/*   Updated: 2020/01/14 17:54:39 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_FT_PRINTF_H
# define PRINTF_FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct			s_settings
{
	int					result;
	int					i;
	int					flag;
	int					flagplus;
	int					flagminus;
	int					flagspace;
	int					flagzero;
	int					flaghash;
	char				type;
	int					width;
	int					precision;
	unsigned char		size;
	int					len;
	int					negative;
	int					zerocount;
	int					cnull;
	int					firstlen;
	int					x_is_zero;
	int					str_move;
}						t_settings;

int						ft_strcmp(const char *s1, const char *s2);
int						len_base(unsigned long long int nbr, int base);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strnew(size_t size);
char					*ft_itoa_base(unsigned long long int nbr, int base);
int						len(long long int nb);
int						ft_isdigit(int c);
size_t					ft_strlen(const char *s);
int						ulen(unsigned long long int nb);
void					ft_initialiazatoin(t_settings *settings);
char					*ft_itoa_ull(unsigned long long int nb);
char					*ft_itoa_ll(long long int nb);
int						ft_atoi(const char *str);
char					*ft_ftoa2(long double digit, t_settings *settings);
char					*ft_ftoa(long double digit, t_settings *settings);
char					*ft_strcat(char *s1, char *s2);
void					ft_putchar(char c);
void					ft_putstr_plus_help(char *s, t_settings *settings,
		int *i, int *len);
void					ft_putstr_plus(char *s, t_settings *settings);
size_t					ft_strlen_b(const char *s);
int						ft_check_next_flags(char *s);
int						ft_check_next_pers(char *s);
int						ft_stop(int len, char *s);
char					*ft_cut_str3(char *string);
void					ft_gettype(char **str, t_settings *settings);
void					ft_getflag(char **str, t_settings *settings);
int						ft_getwidth(char **str, t_settings *settings);
void					ft_getprecision(char **str, t_settings *settings);
void					ft_getsize_help(char **str, t_settings *settings);
void					ft_getsize(char **str, t_settings *settings);
long long int			ft_find_di_size(t_settings *settings, va_list ap);
char					*ft_int_to_str(va_list ap, t_settings *settings);
unsigned long long int	ft_find_p_size(t_settings *settings, va_list ap);
unsigned long long int	ft_find_ou_size(t_settings *settings, va_list ap);
void					ft_x_to_x(char *str);
char					*ft_p_zerostr(void);
char					*ft_add_0x(char *doublestr, t_settings *settings);
char					*ft_ou_to_str(va_list ap, t_settings *settings);
long double				ft_find_f_size(t_settings *settings, va_list ap);
char					*ft_strjoin(char *s1, char *s2);
void					ft_afterdot(long double fpart, char **res,
		t_settings *settings);
long double				ft_round_f2(int prec);
void					ft_mod_digit2(long double *digit, t_settings *settings);
char					*ft_kost(long double digit);
char					*ft_after_point(long double digit, int precision);
char					*ft_f_to_str(va_list ap, t_settings *settings);
void					ft_flagminus_1(char **finalstr, t_settings *settings);
void					ft_flagminus_0(char **finalstr, t_settings *settings);
int						ft_check_space(char *str);
void					ft_add_plus(char **finalstr, t_settings *settings);
void					ft_add_space(char **finalstr, t_settings *settings);
void					ft_place_zero(char **finalstr, t_settings *settings);
void					ft_move_has_xx2(char *str);
void					ft_move_has_xx(char *str, t_settings *settings);
void					ft_flag_hash_xx_b(char *finalstr, char *str,
		t_settings *settings);
void					ft_flag_hash_xx_zero(char *finalstr, char *str,
		t_settings *settings);
char					*ft_flag_hash_xx(char *finalstr, t_settings *settings);
void					ft_flag_hash(char **finalstr, t_settings *settings);
void					ft_place_minus(char *str, int *i, int *j);
void					ft_place_zero2(char *str, int *i, int *j);
void					ft_place_zero3(char *str, int *i, int *j);
char					*ft_prec_diouxx(char *string, t_settings *settings);
char					*ft_prec_f(char *string);
void					ft_prec_s(char *str, char **finalstr,
		t_settings *settings);
char					*ft_precision(char **finalstr, t_settings *settings);
char					*ft_precision2(char **finalstr, t_settings *settings);
void					ft_dif_negative(char **finalstr, t_settings *settings);
void					ft_str_mod2(char **finalstr, t_settings *settings);
void					ft_str_mod3(char **doublestr, t_settings *settings);
char					*ft_char_to_str(va_list ap);
char					*ft_void_to_str(va_list ap, t_settings *settings);
void					ft_change_flags(t_settings *settings);
void					ft_type_c(t_settings *settings, char **doublestr);
void					ft_prepare_str(t_settings *settings, va_list ap);
void					ft_unflag(char **doublestr, t_settings *settings);
void					ft_analyze_2(char **doublestr, t_settings *settings);
int						ft_analyze(char *string, t_settings *settings,
		va_list ap);
int						ft_printf(char *param, ...);
void					ft_cut_str3_h(char *str, char *string, int len);
void					ft_ftoa_help(long double *digit, t_settings
		*settings, char **str);

#endif
