#include <stdio.h>

/* our strlcpy implementation */
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i = 0;

	if (size == 0)
	{
		while (src[i] != '\0')
			i++;
		return (i);
	}

	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';

	while (src[i] != '\0')
		i++;

	return (i);
}

int main(void)
{
	unsigned int ret;

	/* SCENARIO 1: buffer bigger than source */
	char buf1[20];
	ret = ft_strlcpy(buf1, "hello", 20);
	printf("1️⃣ buf1 = \"%s\"\n", buf1);
	printf("   return = %u\n\n", ret);

	/* SCENARIO 2: buffer exactly fits */
	char buf2[6];
	ret = ft_strlcpy(buf2, "hello", 6);
	printf("2️⃣ buf2 = \"%s\"\n", buf2);
	printf("   return = %u\n\n", ret);

	/* SCENARIO 3: buffer too small (TRUNCATION) */
	char buf3[5];
	ret = ft_strlcpy(buf3, "hello world", 5);
	printf("3️⃣ buf3 = \"%s\"\n", buf3);
	printf("   return = %u\n\n", ret);

	/* SCENARIO 4: size == 0 */
	char buf4[10];
	ret = ft_strlcpy(buf4, "hello", 0);
	printf("4️⃣ buf4 unchanged (size = 0)\n");
	printf("   return = %u\n\n", ret);

	return (0);
}
