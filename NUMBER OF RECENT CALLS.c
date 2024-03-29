#include<stdio.h>
typedef struct
{
int before;
int now;
int ping[10000];
} RecentCounter;
RecentCounter *recentCounterCreate()
{
RecentCounter *obj = malloc(sizeof(RecentCounter));
memset(&obj->ping, 0, 10000);
obj->before = 0;
obj->now = 0;
return obj;
}
int recentCounterPing(RecentCounter *obj, int t)
{
obj->ping[obj->now++] = t;
while (obj->ping[obj->before] < t - 3000) obj->before++;
return obj->now - obj->before;
}
void recentCounterFree(RecentCounter *obj)
{
free(obj);
}
