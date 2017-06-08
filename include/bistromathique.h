/*
** bistromathique.h for  in /home/partou_a/rendu/Piscine_C_bistromathique
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Sun Nov  1 15:23:52 2015 Robin Partouche
** Last update Sun Nov  1 20:52:06 2015 Robin Partouche
*/

#ifndef BISTROMATHIQUE_H_
# define BISTROMATHIQUE_H_

# include "mylist.h"
# include "bistro.h"

# define OP_SPACE 32
# define OP_OPEN_BRACKET 40
# define OP_CLOSE_BRACKET 41
# define OP_OPEN_PARENT_IDX 0
# define OP_CLOSE_PARENT_IDX 1
# define OP_PLUS_IDX 2
# define OP_SUB_IDX 3
# define OP_NEG_IDX 3
# define OP_MULT_IDX 4
# define OP_DIV_IDX 5
# define OP_MOD_IDX 6

# define SYNTAXE_ERROR_MSG "syntax error"
# define ERROR_MSG "error"

void	*xmalloc(int n);
char	*add_less(char *str);
char	*boucle(char *n1, char *n2, char *res, int retenue);
char	*boucle_neg(char *n1, char *n2, char *res, int retenue);
char	*_init_res(char *n1, char *n2);
char	*add_inf(char *n1, char *n2, int i, int j);
char	*if_complicated(char *n1, char *n2, int i, int j);
char	*if_simple(char *n1, char *n2, int i, int j);
char	*last_function(char *n1, char *n2);
char	*calc_op(char *x, char *y, char operator, char *str);
int	validate_nbr(int j, char *x, struct s_list **pile);
int	calc_expr(int i, int j, char *str, struct s_list **pile);
char	*eval_expr(char *str);
char	*less_inf(char *n1, char *n2, int i, int j);
char	*if_complicated2(char *n1, char *n2, int i, int j);
char	*if_simple2(char *n1, char *n2, int i, int j);
char	*last_function2(char *n1, char *n2);
char	*my_catch_in_list(struct s_list **pile);
char	my_catch_char_in_list(struct s_list **pile);
char	*nbr_to_eval_expr(char *str);
char	*less_space_echo(char *echoint);
int	check_strlen_compo(char *nb);
int	first_base_char(char *echo, char *operator, char *base);
char	*add_opandbase(char *base, char *operator);
void	bistromatique(char *base, char *operator, char *nbchar, char *echo);
int     check_strlen_compo(char *nb);
int     first_base_char(char *echo, char *operator, char *base);
char    *add_opandbase(char *base, char *operator);
void    bistromatique(char *base, char *operator, char *nbchar, char *echo);
void    check_echo_parenthese(char *echoint);
int     check_echo_compo(char *echoint, char *reference);
int     check_echo_doublon(char *echoint, int i, char *reference);
int     check_echo(char *echoint, char *reference);
char    *correct_zero(char *echoint);
char    *add_space_cho(char *echoint, char *operator, int i);
int     check_doublon1(char *base, char *operator);
int     check_doublon2(char *str1);
char    *check_doublon(char *base, char *operator);
int     check_strlen_compo(char *nb);
char    *transform_op1(char *echo, unsigned int index);
char    *transform_op2(char *all, char *echo, char *reference);
int     check_strlen_compo(char *nb);
int     first_base_char(char *echo, char *operator, char *base);
char    *add_opandbase(char *base, char *operator);
void    bistromatique(char *base, char *operator, char *nbchar, char *echo);
void    check_echo_parenthese(char *echoint);
int     check_echo_compo(char *echoint, char *reference);
int     check_echo_doublon(char *echoint, int i, char *reference);
int     check_echo(char *echoint, char *reference);
char    *correct_zero(char *echoint);
char    *add_space_cho(char *echoint, char *operator, int i);
int     check_doublon1(char *base, char *operator);
int     check_doublon2(char *str1);
char    *check_doublon(char *base, char *operator);
int     check_strlen_compo(char *nb);
char    *transform_op1(char *echo, unsigned int index);
char    *transform_op2(char *all, char *echo, char *reference);
int     check_strlen_compo(char *nb);
int     first_base_char(char *echo, char *operator, char *base);
char    *add_opandbase(char *base, char *operator);
void    bistromatique(char *base, char *operator, char *nbchar, char *echo);
void    check_echo_parenthese(char *echoint);
int     check_echo_compo(char *echoint, char *reference);
int     check_echo_doublon(char *echoint, int i, char *reference);
int     check_echo(char *echoint, char *reference);
char    *correct_zero(char *echoint);
char    *add_space_cho(char *echoint, char *operator, int i);
int     check_doublon1(char *base, char *operator);
int     check_doublon2(char *str1);
char    *check_doublon(char *base, char *operator);
int     check_strlen_compo(char *nb);
char    *transform_op1(char *echo, unsigned int index);
char    *transform_op2(char *all, char *echo, char *reference);
void	check_echo_parenthese(char *echoint);
int	check_echo_compo(char *echoint, char *reference);
int	check_echo_doublon(char *echoint, int i, char *reference);
int	check_echo(char *echoint, char *reference);
char	*correct_zero(char *echoint);
char	*add_space_echo(char *echoint, char *operator, int i);
int	check_doublon1(char *base, char *operator);
int	check_doublon2(char *str1);
char	*check_doublon(char *base, char *operator);
int	check_strlen_compo(char *nb);
char	*transform_op1(char *echo, unsigned int index);
char	*transform_op2(char *all, char *echo, char *reference);
static void	check_base(char *b);
static char	*get_expr(unsigned int size);
static void	check_ops(char *ops);
void	_init_number(t_number *n, char *str);
int	_init_result_and_tmp(t_operation *op);
void    _multiply(t_operation *op);
void	_add_tmp_to_result(t_operation *op);
void	_process_operation(t_operation *op);
char	*inf_mul(char *n1, char *n2);
char	*correct_zero(char *echoint);
char	*div_inf(char *n1, char *n2);
char	*del_less(char *str, int *less);
char	*mod_inf(char *n1, char *n2);
char	*_init_result2(char *str);
char    *put_operator(char x, char *str_list1, int *j, struct s_list **pile);
char    verif_prio(char **str_list, int i, int *j, struct s_list **pile);
char    *unpile_all(char *str, struct s_list **pile, int *j);

#endif /* !BISTROMATHIQUE_H_ */
