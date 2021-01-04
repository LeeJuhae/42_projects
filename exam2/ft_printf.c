#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

# define F	r += ft_printf
// # define F	r += printf

typedef struct s_flag
{
	int	i;
	int	len;
	int	width;
	int	have_precision;
	int	precision;
	int negative;
	int zero_count;
	int output;
	va_list arg;
}				t_flag;

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

void init_flag(t_flag *flag)
{
	flag->i = 0;
	flag->output = 0;
}

void clear_flag(t_flag *flag)
{
	flag->len = 0;
	flag->width = 0;
	flag->have_precision = 0;
	flag->precision = 0;
	flag->negative = 0;
	flag->zero_count = 0;
}

void print_until(const char *s, char c, t_flag *flag)
{
	while (s[flag->i] && s[flag->i] != c)
	{
		write(1, &s[flag->i], 1);
		flag->i++;
		flag->output++;
	}
}

void get_flag(const char *s, t_flag *flag)
{
	flag->i++;
	if (s[flag->i] >= '0' && s[flag->i] <= '9')
	{
		while (s[flag->i] >= '0' && s[flag->i] <= '9')
		{
			flag->width = (flag->width * 10) + (s[flag->i] - '0');
			flag->i++;
		}
	}
	if (s[flag->i] == '.')
	{
		flag->have_precision = 1;
		flag->i++;
		while (s[flag->i] >= '0' && s[flag->i] <= '9')
		{
			flag->precision = (flag->precision * 10) + (s[flag->i] - '0');
			flag->i++;
		}
	}
}

void print_ch(int cnt, char ch, t_flag **flag)
{
	int	i;

	i = 0;
	while (i < cnt)
	{
		write(1, &ch, 1);
		(**flag).output++;
		i++;
	}
}

int get_len_base(long num, int base)
{
	int	i;

	i = 1;
	while (num >= base)
	{
		num /= base;
		i++;
	}
	return (i);
}

void putnbr_base(long num, int base_len, char *base)
{
	if (num >= base_len)
	{
		putnbr_base(num / base_len, base_len, base);
		putnbr_base(num % base_len, base_len, base);
	}
	else
	{
		write(1, &base[num], 1);
	}
}

void print_s(t_flag *flag)
{
	char *s;

	flag->i++;
	s = va_arg(flag->arg, char *);
	if (!s)
		s = "(null)";
	flag->len = ft_strlen(s);
	if (flag->have_precision && flag->precision < flag->len)
		flag->len = flag->precision;
	print_ch(flag->width - flag->len, ' ', &flag);
	write(1, s, flag->len);
	flag->output += flag->len;
}

void print_d(t_flag *flag)
{
	long num;

	flag->i++;
	num = va_arg(flag->arg, int);
	if (num < 0)
	{
		flag->negative = 1;
		num *= -1;
	}
	flag->len = get_len_base(num, 10);
	if (num == 0 && flag->have_precision) //
		flag->len = 0;
	if (flag->have_precision && flag->precision > flag->len)
		flag->zero_count = flag->precision - flag->len;
	if (flag->negative)
		flag->len++;
	print_ch(flag->width - flag->zero_count - flag->len, ' ', &flag);
	if (flag->negative)
		write(1, "-", 1);
	print_ch(flag->zero_count, '0', &flag);
	if (flag->have_precision && num == 0)
		return;
	putnbr_base(num, 10, "0123456789");
	flag->output += flag->len;
}

void print_x(t_flag *flag)
{
	unsigned int num;

	flag->i++;
	num = va_arg(flag->arg, unsigned int);
	flag->len = get_len_base(num, 16);
	if (num == 0 && flag->have_precision)
		flag->len = 0;
	if (flag->have_precision && flag->precision > flag->len)
		flag->zero_count = flag->precision - flag->len;
	print_ch(flag->width - flag->zero_count - flag->len, ' ', &flag);
	print_ch(flag->zero_count, '0', &flag);
	if (flag->have_precision && num == 0)
		return ;
	putnbr_base(num, 16, "0123456789abcdef");
	flag->output += flag->len;
}

int ft_printf(const char *fmt, ...)
{
	t_flag flag;

	init_flag(&flag);
	va_start(flag.arg, fmt);
	while (fmt[flag.i])
	{
		clear_flag(&flag);
		print_until(fmt, '%', &flag);
		if (fmt[flag.i])
		{
			get_flag(fmt, &flag);
			if (fmt[flag.i] == 's')
				print_s(&flag);
			else if (fmt[flag.i] == 'd')
				print_d(&flag);
			else if (fmt[flag.i] == 'x')
				print_x(&flag);
		}
	}
	return (flag.output);
}


int main(void)
{
	int	r;

	r = 0;
	F("Simple test\n");
	F("");
	F("--Format---");
	F("\n");
	F("%d", 0);
	F("%d", 42);
	F("%d", 1);
	F("%d", 5454);
	F("%d", (int)2147483647);
	F("%d", (int)2147483648);
	F("%d", (int)-2147483648);
	F("%d", (int)-2147483649);
	F("\n");
	F("%x", 0);
	F("%x", 42);
	F("%x", 1);
	F("%x", 5454);
	F("%x", (int)2147483647);
	F("%x", (int)2147483648);
	F("%x", (int)-2147483648);
	F("%x", (int)-2147483649);
	F("%s", "");
	F("%s", "toto");
	F("%s", "wiurwuyrhwrywuier");
	F("%s", NULL);
	F("-%s-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier", NULL);
	F("\n--Mixed---\n");
	F("%d%x%d%x%d%x%d%x\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
	F("-%d-%x-%d-%x-%d-%x-%d-%x-\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
	F("\n");
	F("%s%s%s%s\n", "", "toto", "wiurwuyrhwrywuier", NULL);
	F("-%s-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier", NULL);
	F("--1 Flag--\n");
	F("d0w %0d %0d %0d %0d %0d %0d %0d %0d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	F("d4w %4d %4d %4d %4d %4d %4d %4d %4d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	F("d10w %10d %10d %10d %10d %10d %10d %10d %10d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	F("d0p %.0d %.0d %.0d %.0d %.0d %.0d %.0d %.0d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	F("d4p %.4d %.4d %.4d %.4d %.4d %.4d %.4d %.4d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	F("d10p %.10d %.10d %.10d %.10d %.10d %.10d %.10d %.10d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	F("x0w %0x %0x %0x %0x %0x %0x %0x %0x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	F("x4w %4x %4x %4x %4x %4x %4x %4x %4x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	F("x10w %10x %10x %10x %10x %10x %10x %10x %10x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	F("x0p %.0x %.0x %.0x %.0x %.0x %.0x %.0x %.0x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	F("x4p %.4x %.4x %.4x %.4x %.4x %.4x %.4x %.4x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	F("x10p %.10x %.10x %.10x %.10x %.10x %.10x %.10x %.10x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	F("s0p ~%.0s` ~%.0s` ~%.0s` ~%.0s` ~%.0s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	F("s4w ~%4s` ~%4s` ~%4s` ~%4s` ~%4s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	F("s4p ~%.4s` ~%.4s` ~%.4s` ~%.4s` ~%.4s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	F("s10w ~%10s` ~%10s` ~%10s` ~%10s` ~%10s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	F("s10p ~%.10s` ~%.10s` ~%.10s` ~%.10s` ~%.10s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	F("--2 Flags--\n");
	F("d0w0p %0.0d %0.0d %0.0d %0.0d %0.0d %0.0d %0.0d %0.0d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	F("x0w0p %0.0x %0.0x %0.0x %0.0x %0.0x %0.0x %0.0x %0.0x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	F("--Precision--\n");
	F("d0w4p %0.4d %0.4d %0.4d %0.4d %0.4d %0.4d %0.4d %0.4d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	F("d0w10p %0.10d %0.10d %0.10d %0.10d %0.10d %0.10d %0.10d %0.10d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	F("x0w4p %0.4x %0.4x %0.4x %0.4x %0.4x %0.4x %0.4x %0.4x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	F("x0w10p %0.10x %0.10x %0.10x %0.10x %0.10x %0.10x %0.10x %0.10x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	F("--Width--\n");
	F("d4w0p %4.0d %4.0d %4.0d %4.0d %4.0d %4.0d %4.0d %4.0d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	F("d10w0p %10.0d %10.0d %10.0d %10.0d %10.0d %10.0d %10.0d %10.0d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	F("x4w0p %4.0x %4.0x %4.0x %4.0x %4.0x %4.0x %4.0x %4.0x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	F("x10w0p %10.0x %10.0x %10.0x %10.0x %10.0x %10.0x %10.0x %10.0x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	F("s4w0p ~%4.s` ~%4.s` ~%4.s` ~%4.s` ~%4.s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	F("s10w0p ~%10.0s` ~%10.0s` ~%10.0s` ~%10.0s` ~%10.0s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	F("--Width and Precision--\n");
	F("d10w4p %10.4d %10.4d %10.4d %10.4d %10.4d %10.4d %10.4d %10.4d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	F("d10w10p %10.10d %10.10d %10.10d %10.10d %10.10d %10.10d %10.10d %10.10d\n", 0, 1, 42, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	F("d4w4p %4.4d %4.4d %4.4d %4.4d %4.4d %4.4d %4.4d %4.4d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	F("d4w10p %4.10d %4.10d %4.10d %4.10d %4.10d %4.10d %4.10d %4.10d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	F("x10w4p %10.4x %10.4x %10.4x %10.4x %10.4x %10.4x %10.4x %10.4x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	F("x10w10p %10.10x %10.10x %10.10x %10.10x %10.10x %10.10x %10.10x %10.10x\n", 0, 1, 42, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	F("x4w4p %4.4x %4.4x %4.4x %4.4x %4.4x %4.4x %4.4x %4.4x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	F("x4w10p %4.10x %4.10x %4.10x %4.10x %4.10x %4.10x %4.10x %4.10x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	F("s10w4p ~%10.4s` ~%10.4s` ~%10.4s` ~%10.4s` ~%10.4s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	F("s10w10p ~%10.10s` ~%10.10s` ~%10.10s` ~%10.10s` ~%10.10s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	F("s4w4p ~%4.4s` ~%4.4s` ~%4.4s` ~%4.4s` ~%4.4s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	F("s4w10p ~%10.10s` ~%10.10s` ~%10.10s` ~%10.10s` ~%10.10s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	printf("written: %d\n", r);
}
