/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:50:12 by cmarques          #+#    #+#             */
/*   Updated: 2026/04/28 09:41:09 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str);

int checkchar(char c, char *set){
    int i;
    
    i= 0;
    while(set[i]){
        if(set[i] == c)
            return(1);
        i++;
    }
    return(0);
}

char *ft_strtrim(char const *s1, char const *set){
    int i;
    int j;
    char *result;
    int len;
    int c;
    
    len = ft_strlen((char *)s1);
    i = 0;
    j = 0;
    c = 0;
    
    while(checkchar(s1[i], (char *)set))
        i++;
    printf("%i\n", i);
    printf("%i\n", len);
    printf("%i\n", len - j);
    while(checkchar(s1[len - j], (char *)set)){
        printf("%i\n", len - j);
        j++;
    }
    printf("%i\n", j);
    
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

    result = ft_strtrim(" 78Teste 87", "87 ");
    printf("%s\n", result);
}