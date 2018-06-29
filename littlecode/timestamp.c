#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
/* time stamp */
    /*%Y-%m-%d %H:%M:%S*/
#if 0
    char date[26];
    time_t timep;
    struct tm* tm_info;
    time (&timep);
    tm_info =  gmtime(&timep);
    strftime(date, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    json_object_object_add(jobj, "date", json_object_new_string(date));
#endif
    /* millisecondsSinceEpoch */
    struct timeval tv;
    gettimeofday(&tv, NULL);
    unsigned long long millisecondsSinceEpoch =
        (unsigned long long)(tv.tv_sec) * 1000 +
        (unsigned long long)(tv.tv_usec) / 1000;

    const int n = snprintf(NULL, 0, "%llu", millisecondsSinceEpoch);
    char timep[n+1];
    int c = snprintf(timep, n+1, "%llu", millisecondsSinceEpoch);
    //printf("llu:%llu str:%s\n", timep);
    json_object_object_add(jobj, "date", json_object_new_string(timep));
}
