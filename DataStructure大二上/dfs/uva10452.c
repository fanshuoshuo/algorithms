/* http://www.technix.tk/test/uva10452.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GO_UP       "forth"
#define GO_LEFT     "left"
#define GO_RIGHT    "right"
#define KEY_STRING  "@IEHOVA#"

void path(int width, int height, char **map)
{
    static char *steps = KEY_STRING;
    
    /*set the starting point*/
    char *step = steps;
    int currentx = 0;
    int currenty = height - 1;
    currentx = strchr(map[currenty], *step) - map[currenty];
    step++;
    /*run the steps - simple pathfinding*/
    while (1)
    {
        if (currenty > 0 && map[currenty - 1][currentx] == *step) /*up*/
        {
            currenty--;
            printf(GO_UP);
        }
        else if (currentx > 0 && map[currenty][currentx - 1] == *step) /*left*/
        {
            currentx--;
            printf(GO_LEFT);
        }
        else if (currentx < width && map[currenty][currentx + 1] == *step) /*right*/
        {
            currentx++;
            printf(GO_RIGHT);
        }
        if (*step == '#') /*done*/
        {
            putchar('\n');
            return;
        }
        else
            putchar(' ');
        step++;
    }
}

int main(void)
{
    int cases, height, width;
    char **buf;
    scanf("%d", &cases);
    
    while(cases--)
    {
        int i;
        scanf("%d%d", &height, &width);
        
        buf = (char **)calloc(height, sizeof(char *)); /*get memory - no core dumping*/
        for (i = 0; i < height; i++)
        {
            buf[i] = (char *)calloc((width + 1), sizeof(char));
            scanf("%s", buf[i]);
        }
        
        path(width, height, buf);
        
        for (i = 0; i < height; i++)
            free(buf[i]);
        free((void *)buf);
    }
    
    return 0;
}

