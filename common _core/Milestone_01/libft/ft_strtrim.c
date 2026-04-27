/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:50:12 by cmarques          #+#    #+#             */
/*   Updated: 2026/04/27 22:24:26 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str);

char *ft_strtrim(char const *s1, char const *set){
    int i;
    int j;
    char *result;
    int len1;
    int len2;
    int c;
    
    len1 = ft_strlen((char *)s1);
    len2 = ft_strlen((char *)set);
    i = 0;
    j = 0;
    c = 0;
    while()
        i++;
    while(s1[len-i+j]==set[j] && set[j])
        j++;
    result = malloc((i+j)*sizeof(char));
    if(!result)
        return(NULL);
    while(c <= len - (j + i)){
        result[c] = s1[c+i];
        c++;
    }
    result[c] = '\0';
    return(result);
}

int main(void){
    char *result;

    result = ft_strtrim(" 7Teste 8 ", " 7 ");
    printf("%s\n", result);
}