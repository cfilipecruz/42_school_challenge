#include <stdio.h>
#include "libft.h"

void test_int(char *name, int expected, int got)
{
	printf("%s -> expected: %d | got: %d\n", name, expected, got);
}

void test_str(char *name, char *expected, char *got)
{
	printf("%s -> expected: %s | got: %s\n", name, expected, got);
}

int main(void)
{
	// ================= CHAR CHECKS =================
	test_int("isalpha A", 1, ft_isalpha('A'));
	test_int("isalpha 1", 0, ft_isalpha('1'));

	test_int("isdigit 5", 1, ft_isdigit('5'));
	test_int("isdigit A", 0, ft_isdigit('A'));

	test_int("isalnum a", 1, ft_isalnum('a'));
	test_int("isalnum ?", 0, ft_isalnum('?'));

	test_int("isascii 127", 1, ft_isascii(127));
	test_int("isascii 200", 0, ft_isascii(200));

	test_int("isprint space", 1, ft_isprint(' '));
	test_int("isprint \\n", 0, ft_isprint('\n'));

	// ================= STRLEN =================
	test_int("strlen hello", 5, ft_strlen("hello"));
	test_int("strlen empty", 0, ft_strlen(""));

	// ================= MEMSET =================
	char s1[10] = "abcdef";
	ft_memset(s1, 'X', 3);
	test_str("memset", "XXXdef", s1);

	// ================= BZERO =================
	char s2[10] = "abcdef";
	ft_bzero(s2, 3);
	test_str("bzero", "\\0\\0\\0def", s2);

	// ================= MEMCPY =================
	char s3[20];
	ft_memcpy(s3, "hello", 6);
	test_str("memcpy", "hello", s3);

	// ================= MEMMOVE =================
	char s4[20] = "abcdef";
	ft_memmove(s4 + 2, s4, 4);
	test_str("memmove overlap", "ababcd", s4);

	char s5[20] = "abcdef";
	ft_memmove(s5, s5 + 2, 4);
	test_str("memmove reverse", "cdefef", s5);

	// ================= STRCHR =================
	test_str("strchr l", "llo", ft_strchr("hello", 'l'));
	test_str("strchr z", "(null)", ft_strchr("hello", 'z'));

	// ================= STRRCHR =================
	test_str("strrchr l", "lo", ft_strrchr("hello", 'l'));

	// ================= STRNCMP =================
	test_int("strncmp abc abd", -1, ft_strncmp("abc", "abd", 3));
	test_int("strncmp abc abc", 0, ft_strncmp("abc", "abc", 3));

	// ================= MEMCHR =================
	test_str("memchr d", "def", ft_memchr("abcdef", 'd', 6));
	test_str("memchr x", "(null)", ft_memchr("abcdef", 'x', 6));

	// ================= MEMCMP =================
	test_int("memcmp abc abd", -1, ft_memcmp("abc", "abd", 3));
	test_int("memcmp abc abc", 0, ft_memcmp("abc", "abc", 3));

	// ================= STRNSTR =================
	test_str("strnstr world", "world",
		ft_strnstr("hello world", "world", 11));

	test_str("strnstr fail", "(null)",
		ft_strnstr("hello", "world", 5));

	// ================= ATOI =================
	test_int("atoi -42", -42, ft_atoi("   -42abc"));
	test_int("atoi +123", 123, ft_atoi("123"));

	// ================= CASE =================
	test_int("toupper a", 'A', ft_toupper('a'));
	test_int("tolower A", 'a', ft_tolower('A'));

	return 0;
}