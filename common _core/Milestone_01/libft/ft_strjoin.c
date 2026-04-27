/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:13:04 by cmarques          #+#    #+#             */
/*   Updated: 2026/04/27 18:49:31 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

size_t	ft_strlen(const char *s);
char *ft_strcat(char *restrict dst, const char *restrict src);

char *ft_strjoin(char const *s1, char const *s2){

    size_t len1;
    size_t len2;
    char *result;

    len1 =    ft_strlen(s1);
    len2 =    ft_strlen(s2);
    
    result = malloc((len1 + len2 + 1) * sizeof(char));
    if(!result)
        return(NULL);
    result[0] = '\0';
    
    ft_strcat(result, s1);
    ft_strcat(result, s2);

    return(result);
}

/*int main(void){
    char *result;
    int i;
    i = 0;
    result = ft_strjoin("Teste join", "124523");
    while(result[i]){
        printf("%c",result[i]);
        i++;
    }
    return(0);
}*/
