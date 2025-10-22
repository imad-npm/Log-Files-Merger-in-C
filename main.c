#include <stdio.h>
#include <string.h>

typedef struct log
{
    char timestamp[100];
    char message[100];
} Log;



Log *mergeSorted(Log *list1,int l1 , Log *list2 ,int l2, Log * sorted)
{
    int idx1=0, idx2=0;
    int k = 0;

    while (idx1 < l1 && idx2 < l2)
    {
        /* code */
        if (strcmp(list1[idx1].timestamp ,list2[idx2].timestamp )< 1 )
        {
            sorted[k] = list1[idx1];
            idx1++ ;
        }
        else
        {
            sorted[k] = list2[idx2];
            idx2++ ;
        }
        k++ ;
    }
       while (idx1 < l1 )
    {
      
            sorted[k] = list1[idx1];
            idx1++ ;
            k++ ;
       
    }
          while (idx2 < l2 )
    {
      
            sorted[k] = list2[idx2];
            idx2++ ;
            k++ ;
       
    }
    return sorted ;
}


Log *get_logs(FILE *f, Log* logs)
{

    char line[100];
    Log log;
    int l = 0;
    while (fgets(line, 100, f) != NULL)
    {
        int t = 0;
        int m = 0;
        int is_time_part = 1;

        for (int i = 0; i < strlen(line); i++)
        {
            if (line[i] == ' ' && is_time_part==1)
            {
                is_time_part = 0;
                continue;
            }
            if (is_time_part)
            {
                log.timestamp[t] = line[i];
                t++;
            }
            else
            {
                log.message[m] = line[i];
                m++;
            }

            /* code */
        }
        log.timestamp[t] = '\0';
        log.message[m] = '\0';

        logs[l] = log;
        l++;
    }
    rewind(f) ;
    return logs;
}

int get_lines_count(FILE *f)
{
    int count = 0;
    int l = 0;
    char line[100];

    while (fgets(line, 100, f) != NULL)
    {
        count++;
    }
    rewind(f) ;

    return count;
}

void print_logs(Log logs[], int count)
{
    for (int i = 0; i < count; i++)
    {
        if (logs[i].timestamp != NULL && logs[i].message != NULL)
            printf("[%s] %s\n", logs[i].timestamp, logs[i].message);
        else
            printf("(incomplete log entry)\n");
    }
}

void write_to_file(Log * sorted,int count){
        FILE *f = fopen("sorted.log", "w");
        char line[100] ;          
    for (int i = 0; i < count; i++)
    {
        snprintf(line ,100,"%s  %s",sorted[i].timestamp,sorted[i].message) ;
        fputs(line,f) ;
    }
    rewind(f) ;

}

int main()
{
    FILE *f1 = fopen("server1.log", "r");
    FILE *f2 = fopen("server2.log", "r");
    int l1 =get_lines_count(f1) ;
    int l2 =get_lines_count(f2) ;

     Log logs1[l1];
     Log logs2[l2];
     Log sorted[l1+l2] ;

    get_logs(f1,logs1);
    get_logs(f2,logs2);
    mergeSorted(logs1,l1,logs2,l2,sorted) ;

    print_logs(sorted, l1+l2);
    write_to_file(sorted,l1+l2) ;

    
}