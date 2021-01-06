/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:29:33 by ijuhae            #+#    #+#             */
/*   Updated: 2021/01/06 15:29:37 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libasm.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#define TRUE		1
#define FALSE		0
#define ERROR		-1

typedef int			t_bool;

void				ft_bzero(void *ptr, size_t byte)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)ptr;
	i = 0;
	while (i < byte)
	{
		str[i] = '\0';
		i++;
	}
}

void			test_strlen(void)
{
	printf("######################### FT_STRLEN #########################\n");
	printf("My 'ft_strlen' will be compared to 'strlen' in <string.h>.\n");
	printf("\n");
	sleep(1);
	printf("Prototype : size_t\tft_strlen(const char *s);\n");
	printf("\n");
	sleep(1);

	printf("TESTCASE 1 | strlen(\"Hello\")\n");
	printf("MY : %zu\n", ft_strlen("Hello"));
	printf("PC : %zu\n", strlen("Hello"));
	printf("\n");
	sleep(1);

	printf("TESTCASE 2 | strlen(\"Wingardium Levioooooosa\")\n");
	printf("MY : %zu\n", ft_strlen("Wingardium Levioooooosa"));
	printf("PC : %zu\n", strlen("Wingardium Levioooooosa"));
	printf("\n");
	sleep(1);

	printf("TESTCASE 3 | strlen(\"\")\n");
	printf("MY : %zu\n", ft_strlen(""));
	printf("PC : %zu\n", strlen(""));
	printf("\n");
	sleep(1);

	printf("TESTCASE 4 | strlen(\"\\xff\\xfe\\xfd\")\n");
	printf("MY : %zu\n", ft_strlen("\xff\xfe\xfd"));
	printf("PC : %zu\n", strlen("\xff\xfe\xfd"));
	printf("\n");
	sleep(1);

	printf("TESTCASE 5 | strlen(\"PPAP\\0PPAP\")\n");
	printf("MY : %zu\n", ft_strlen("PPAP\0PPAP"));
	printf("PC : %zu\n", strlen("PPAP\0PPAP"));
	printf("\n");
	sleep(1);

	printf("ETC CASES | \n");
	printf("strlen(NULL) : Segfault\n");
	printf("\n");
	sleep(1);
	printf("####################### FT_STRLEN END ########################\n");
	printf("\n");
	sleep(1);
}

void			test_strcpy(void)
{
	char		dst[1000];
	char		*src;

	printf("######################### FT_STRCPY #########################\n");
	printf("My 'ft_strcpy' will be compared to 'strcpy' in <string.h>.\n");
	printf("\n");
	sleep(1);
	printf("Prototype : char\t*ft_strcpy(char *dst, const char *src);\n");
	printf("\n");
	sleep(1);
	printf("Notes : type of dst is char [1000], type of src is char *\n");
	printf("\n");
	sleep(1);

	printf("TESTCASE 1 | dst : \"\", src : \"4242\"\n");
	ft_bzero(dst, 1000);
	src = NULL;
	src = "4242";
	printf("MY : %s\n", ft_strcpy(dst, src));
	ft_bzero(dst, 1000);
	src = NULL;
	src = "4242";
	printf("PC : %s\n", strcpy(dst, src));
	printf("\n");
	sleep(1);

	printf("TESTCASE 2 | dst : \"ABCDEFG\", src : \"4242\"\n");
	ft_bzero(dst, 1000);
	strcpy(dst, "ABCDEFG");
	src = NULL;
	src = "4242";
	printf("MY : %s\n", ft_strcpy(dst, src));
	ft_bzero(dst, 1000);
	strcpy(dst, "ABCDEFG");
	src = NULL;
	src = "4242";
	printf("PC : %s\n", strcpy(dst, src));
	printf("\n");
	sleep(1);

	printf("TESTCASE 3 | dst : \"ABCDEFG\", src : \"\"\n");
	ft_bzero(dst, 1000);
	strcpy(dst, "ABCDEFG");
	src = NULL;
	src = "";
	printf("MY : %s\n", ft_strcpy(dst, src));
	ft_bzero(dst, 1000);
	strcpy(dst, "ABCDEFG");
	src = NULL;
	src = "";
	printf("PC : %s\n", strcpy(dst, src));
	printf("\n");
	sleep(1);

	printf("TESTCASE 4 | dst : \"\", src : \"PPAP\\0PPAP\"\n");
	ft_bzero(dst, 1000);
	src = NULL;
	src = "PPAP\0PPAP";
	printf("MY : %s\n", ft_strcpy(dst, src));
	ft_bzero(dst, 1000);
	src = NULL;
	src = "PPAP\0PPAP";
	printf("PC : %s\n", strcpy(dst, src));
	printf("\n");
	sleep(1);

	printf("ETC CASES | \n");
	printf("strcpy(NULL, \"!\") : Segfault\n");
	printf("strcpy(\"!\", NULL) : Segfault\n");
	printf("\n");
	sleep(1);

	printf("####################### FT_STRCPY END ########################\n");
	printf("\n");
	sleep(1);
}


void			test_strcmp(void)
{
	printf("######################### FT_STRCMP #########################\n");
	printf("My 'ft_strcmp' will be compared to 'strcmp' in <string.h>.\n");
	printf("\n");
	sleep(1);
	printf("Prototype : int\tft_strcmp(const char *s1, const char *s2);\n");
	printf("\n");
	sleep(1);

	printf("TESTCASE 1 | strcmp(\"1234\", \"1239\")\n");
	printf("MY : %d\n", ft_strcmp("1234", "1239"));
	printf("PC : %d\n", strcmp("1234", "1239"));
	printf("\n");
	sleep(1);

	printf("TESTCASE 2 | strcmp(\"HERO\", \"HER\")\n");
	printf("MY : %d\n", ft_strcmp("HERO", "HER"));
	printf("PC : %d\n", strcmp("HERO", "HER"));
	printf("\n");
	sleep(1);

	printf("TESTCASE 3 | strcmp(\"\", \"\")\n");
	printf("MY : %d\n", ft_strcmp("", ""));
	printf("PC : %d\n", strcmp("", ""));
	printf("\n");
	sleep(1);

	printf("TESTCASE 4 | strcmp(\"\\xff\\xff\", \"\\xff\\xfa\")\n");
	printf("MY : %d\n", ft_strcmp("\xff\xff", "\xff\xfa"));
	printf("PC : %d\n", strcmp("\xff\xff", "\xff\xfa"));
	printf("\n");
	sleep(1);

	printf("ETC CASES | \n");
	printf("strcmp(NULL, \"!\") : Segfault\n");
	printf("strcmp(\"!\", NULL) : Segfault\n");
	printf("\n");
	sleep(1);

	printf("####################### FT_STRCMP END ########################\n");
	printf("\n");
	sleep(1);
}


void			test_write(void)
{
	char		buf[100];

	errno = 0;
	printf("######################### FT_WRITE #########################\n");
	printf("My 'ft_write' will be compared to 'write' in <unistd.h>.\n");
	printf("\n");
	sleep(1);
	printf("Prototype : ssize_t\tft_write(int fd, const void *buf, size_t nbyte);\n");
	printf("\n");
	sleep(1);

	printf("TESTCASE 1 | write(1, \"HELLO, FRIENDS!\", strlen(\"HELLO, FRIENDS!\"))\n");
	printf("MY : %zd\n", ft_write(1, "HELLO, FRIENDS!", strlen("HELLO, FRIENDS!")));
	printf("PC : %zd\n", write(1, "HELLO, FRIENDS!", strlen("HELLO, FRIENDS!")));
	printf("\n");
	sleep(1);

	printf("TESTCASE 2 | write(1, \"HELLO, FRIENDS!\\n\", strlen(\"HELLO, FRIENDS!\\n\") - 5)\n");
	printf("MY : %zd\n", ft_write(1, "HELLO, FRIENDS!\n", strlen("HELLO, FRIENDS!\n") - 5));
	printf("PC : %zd\n", write(1, "HELLO, FRIENDS!\n", strlen("HELLO, FRIENDS!\n") - 5));
	printf("\n");
	sleep(1);

	printf("TESTCASE 3 | write(2, \"HELLO, FRIENDS!\\n\", strlen(\"HELLO, FRIENDS!\\n\") - 5)\n");
	printf("MY : %zd\n", ft_write(2, "HELLO, FRIENDS!\n", strlen("HELLO, FRIENDS!\n") - 5));
	printf("PC : %zd\n", write(2, "HELLO, FRIENDS!\n", strlen("HELLO, FRIENDS!\n") - 5));
	printf("\n");
	sleep(1);

	printf("TESTCASE 4 | write(1, NULL, 10)\n");
	printf("MY : %zd\t\t", ft_write(1, NULL, 10));
	printf("Error No.%d : %s\n", errno, strerror(errno));
	errno = 0;
	printf("PC : %zd\t\t", write(1, NULL, 10));
	printf("Error No.%d : %s\n", errno, strerror(errno));
	errno = 0;
	printf("\n");
	sleep(1);

	printf("TESTCASE 5 | write(10, \"4242\", 10)\n");
	printf("MY : %zd\t\t", ft_write(10, "4242", 10));
	printf("Error No.%d : %s\n", errno, strerror(errno));
	errno = 0;
	printf("PC : %zd\t\t", write(10, "4242", 10));
	printf("Error No.%d : %s\n", errno, strerror(errno));
	errno = 0;
	printf("\n");
	sleep(1);

	printf("TESTCASE 6 | write(1, \"4242\", -1)\n");
	printf("MY : %zd\t\t", ft_write(1, "4242", -1));
	printf("Error No.%d : %s\n", errno, strerror(errno));
	errno = 0;
	printf("PC : %zd\t\t", write(1, "4242", -1));
	printf("Error No.%d : %s\n", errno, strerror(errno));
	errno = 0;
	printf("\n");
	sleep(1);

	printf("####################### FT_WRITE END ########################\n");
	printf("\n");
	sleep(1);
}

void			test_read(void)
{
	char		buf[100];
	int			fd;

	errno = 0;
	ft_bzero(buf, 100);
	fd = open("info.txt", O_RDONLY);
	printf("########################## FT_READ ##########################\n");
	printf("My 'ft_read' will be compared to 'read' in <unistd.h>.\n");
	printf("\n");
	sleep(1);
	printf("Prototype : ssize_t\tft_read(int fd, void *buf, size_t nbyte);\n");
	printf("\n");
	sleep(1);

	printf("TESTCASE 1 | read(fd, buf, 42)\n");
	printf("MY : %zd\n", ft_read(fd, buf, 42));
	printf("buf : %s\n", buf);
	ft_bzero(buf, 100);
	lseek(fd, 0, SEEK_SET);
	printf("PC : %zd\n", read(fd, buf, 42));
	printf("buf : %s\n", buf);
	ft_bzero(buf, 100);
	lseek(fd, 0, SEEK_SET);
	printf("\n");
	sleep(1);

	printf("TESTCASE 2 | read(fd, buf, 0)\n");
	printf("MY : %zd\n", ft_read(fd, buf, 0));
	printf("buf : %s\n", buf);
	ft_bzero(buf, 100);
	lseek(fd, 0, SEEK_SET);
	printf("PC : %zd\n", read(fd, buf, 0));
	printf("buf : %s\n", buf);
	ft_bzero(buf, 100);
	lseek(fd, 0, SEEK_SET);
	printf("\n");
	sleep(1);

	printf("TESTCASE 3 | read(-1, buf, 42)\n");
	printf("MY : %zd\t\t", ft_read(-1, buf, 42));
	printf("Error No.%d : %s\n", errno, strerror(errno));
	errno = 0;
	printf("PC : %zd\t\t", read(-1, buf, 42));
	printf("Error No.%d : %s\n", errno, strerror(errno));
	errno = 0;
	printf("\n");
	sleep(1);


	printf("TESTCASE 4 | read(fd, NULL, 42)\n");
	printf("MY : %zd\t\t", ft_read(fd, NULL, 42));
	printf("Error No.%d : %s\n", errno, strerror(errno));
	errno = 0;
	printf("PC : %zd\t\t", read(fd, NULL, 42));
	printf("Error No.%d : %s\n", errno, strerror(errno));
	errno = 0;
	printf("\n");
	sleep(1);

	printf("TESTCASE 5 | read(fd, buf, -1)\n");
	printf("MY : %zd\t\t", ft_read(fd, buf, -1));
	printf("Error No.%d : %s\n", errno, strerror(errno));
	errno = 0;
	printf("PC : %zd\t\t", read(fd, buf, -1));
	printf("Error No.%d : %s\n", errno, strerror(errno));
	errno = 0;
	printf("\n");
	sleep(1);

	printf("######################## FT_READ END #########################\n");
	printf("\n");
	sleep(1);
}


void			test_strdup(void)
{
	char		*my;
	char		*pc;

	my = NULL;
	pc = NULL;
	printf("######################### FT_STRDUP #########################\n");
	printf("My 'ft_strdup' will be compared to 'strdup' in <string.h>.\n");
	printf("\n");
	sleep(1);
	printf("Prototype : char\t*ft_strdup(const char *s1);\n");
	printf("\n");
	sleep(1);

	printf("TESTCASE 1 | strdup(\"Expecto Patronum\")\n");
	printf("MY : %s\n", ft_strdup("Expecto Patronum"));
	printf("PC : %s\n", strdup("Expecto Patronum"));
	free(my);
	free(pc);
	printf("\n");
	sleep(1);

	printf("TESTCASE 2 | strdup(\"\")\n");
	printf("MY : %s\n", ft_strdup(""));
	printf("PC : %s\n", strdup(""));
	free(my);
	free(pc);
	printf("\n");
	sleep(1);

	printf("ETC CASES | \n");
	printf("strdup(NULL) : Segfault\n");
	printf("\n");
	sleep(1);

	printf("####################### FT_STRDUP END ########################\n");
	printf("\n");
	sleep(1);
}

int				main(void)
{
	printf(">>>>>>>>>>>>>>>>>>>>>>> TEST START <<<<<<<<<<<<<<<<<<<<<<<\n");
	printf("\n");
	sleep(1);

	test_strlen();
	test_strcpy();
	test_strcmp();
	test_write();
	test_read();
	test_strdup();

	printf(">>>>>>>>>>>>>>>>>>>>> TEST END <<<<<<<<<<<<<<<<<<<<<\n");
	printf("\n");
	sleep(1);

	return (0);
}
