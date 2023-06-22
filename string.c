#include "shell.h"

/**
 * _strlen - length of a string
 * @p: string length to check
 *
 * Return: length interger of string
 */

int _strlen(char *p)
{
        int m = 0;
        if (!p)
                return (0);
        while (*p++)
                m++;
        return (m);
}

/**
 * _strcmp - executes comparison of two strings
 * @p1: first string
 * @p2: second string
 *
 * Return: negative if p1 < p2, positive if p1 > p2, zero if p1 == p2
 */

int _strcmp(char *p1, char *p2)
{
        while (*p1 && *p2)

        {
                if (*p1 != *p2)
                        return (*p1 - *p2);
                p1++;
                p2++;
        }
        if (*p1 == *p2)
                return (0);
        else
                return (*p1 < *p2 ? -1 : 1);
}

/**
 * starts_with - will check needle starts with haystack
 * @haystack: string to look up
 * @needle: the substring to locate
 *
 * Return: address of next characater of haystack or 0
 */

char *starts_with(const char *haystack, const char *needle)

{
        while (*needle)
                if (*needle++ != *haystack++)
                        return (NULL);
        return ((char *)haystack);
}

/**
 * _strcat - conjugates two strings
 * @dest: destination of buffer
 * @src: source of buffer
 *
 * Return: points to destination buffer
 */

char *_strcat(char *dest, char *src)
{
        char *ret = dest;
        while (*dest)
                dest++;
        while (*src)
                *dest++ = *src++;
        *dest = *src;
        return (ret);
}
