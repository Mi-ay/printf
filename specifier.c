#include "main.h"

/**
* our_specifier - format function
* @s: string
* Return: bytes printed
*/

int (*our_specifier(char *s))(va_list p, params_t *params)

{
specifier_t specifiers[] = {
{"c", print_char},
{"d", print_int},
{"i", print_int},
{"s", print_string},
{"%", print_percent},
{"b", print_binary},
{"o", print_octal},
{"u", print_unsigned},
{"x", print_hex},
{"X", print_HEX},
{"p", print_address},
{"S", print_Speci},
{"r", print_strev},
{"R", print_rot13},
{NULL, NULL}
};

int d = 0;

while (specifiers[d].specifier)
{
if (*s == specifiers[d].specifier[0])
{
return (specifiers[d].f);
}
d++;
}
return (NULL);
}

/**
* our_print_func - format
* @s: string
* @p: pointer
* @params: parameters struct
* Return: bytes printed
*/
int our_print_func(char *s, va_list p, params_t *params)
{
int (*f)(va_list, params_t *) = our_specifier(s);

if (f)
return (f(p, params));
return (0);
}

/**
* our_flag - flag functions
* @s: format string
* @params: the parameters struct
* Return: flag valid
*/
int our_flag(char *s, params_t *params)
{
int d = 0;

switch (*s)
{
case '+':
d = params->plus_flag = 1;
break;
case ' ':
d = params->space_flag = 1;
break;
case '#':
d = params->hashtag_flag = 1;
break;
case '-':
d = params->minus_flag = 1;
break;
case '0':
d = params->zero_flag = 1;
break;
}
return (d);
}

/**
* our_modifier - modifier function
* @s: string
* @params: structure
* Return: modifier
*/
int our_modifier(char *s, params_t *params)
{
int d = 0;

switch (*s)
{
case 'h':
d = params->h_modifier = 1;
break;
case 'l':
d = params->l_modifier = 1;
break;
}
return (d);
}

/**
* our_width - width
* @s: string
* @params: the parameters struct
* @p: pointer
* Return: pointer
*/
char *our_width(char *s, params_t *params, va_list p)
{
int width_number = 0;

if (*s == '*')
{
width_number = va_arg(p, int);
s++;
}
else
{
while (_isdigit(*s))
width_number = width_number * 10 + (*s++ - '0');
}
params->width = width_number;
return (s);
}
