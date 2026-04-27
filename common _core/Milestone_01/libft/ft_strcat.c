/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:21:16 by cmarques          #+#    #+#             */
/*   Updated: 2026/04/27 18:44:00 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t	ft_strlen(const char *s);

char *ft_strcat(char *restrict dst, const char *restrict src){
    size_t i;
    size_t len;
    
    i = 0;
    len = ft_strlen(dst);
    while(src[i]){
        dst[i+len] = src[i];
        i++;
    }
    dst[i+len] = '\0';
    return(dst);
}

/*int main(void){
    int i;
    char *result;
    
    char dst[20] = "Olá";
    i = 0;
    result = ft_strcat(dst, "123");

    while(result[i]){
        printf("%c", result[i]);
        i++;
    }
    return(0);
}*/