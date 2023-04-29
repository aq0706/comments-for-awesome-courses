#include "cachelab.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <getopt.h>
#include <string.h>

int h, v, s, E, b, S;

int hit_count, miss_count, eviction_count;

char t[1000];

typedef struct
{
    int valid;
    int tag;
    int time;
} cache_line, *cache_asso, **cache;

cache _cache_ = NULL;

void printUsage()
{
    printf("Usage: ./csim-ref [-hv] -s <num> -E <num> -b <num> -t <file>\n"
           "Options:\n"
           "  -h         Print this help message.\n"
           "  -v         Optional verbose flag.\n"
           "  -s <num>   Number of set index bits.\n"
           "  -E <num>   Number of lines per set.\n"
           "  -b <num>   Number of block offset bits.\n"
           "  -t <file>  Trace file.\n\n"
           "Examples:\n"
           "  linux>  ./csim-ref -s 4 -E 1 -b 4 -t traces/yi.trace\n"
           "  linux>  ./csim-ref -v -s 8 -E 2 -b 4 -t traces/yi.trace\n");
}

void init_cache()
{
    _cache_ = (cache)malloc(sizeof(cache_asso) * S);
    for (int i = 0; i < S; ++i)
    {
        _cache_[i] = (cache_asso)malloc(sizeof(cache_line) * E);
        for (int j = 0; j < E; ++j)
        {
            _cache_[i][j].valid = 0;
            _cache_[i][j].tag = -1;
            _cache_[i][j].time = -1;
        }
    }
}

void update(unsigned int address)
{
    int setindex = (address >> b) & ((1 << s) - 1);
    int tag = address >> (b + s);

    int max_time = INT_MIN;
    int max_time_index = -1;

    for (int i = 0; i < E; i++)
    {
        if (_cache_[setindex][i].tag == tag)
        {
            _cache_[setindex][i].time = 0;
            hit_count++;
            return;
        }
    }

    for (int i = 0; i < E; i++)
    {
        if (_cache_[setindex][i].valid == 0)
        {
            _cache_[setindex][i].valid = 1;
            _cache_[setindex][i].tag = tag;
            _cache_[setindex][i].time = 0;
            miss_count++;
            return;
        }
    }

    for (int i = 0; i < E; i++)
    {
        if (_cache_[setindex][i].time > max_time)
        {
            max_time = _cache_[setindex][i].time;
            max_time_index = i;
        }
    }
    _cache_[setindex][max_time_index].tag = tag;
    _cache_[setindex][max_time_index].time = 0;
    miss_count++;
    eviction_count++;
}

void update_stamp()
{
    for (int i = 0; i < S; ++i)
    {
        for (int j = 0; j < E; ++j)
        {
            if (_cache_[i][j].valid == 1)
                _cache_[i][j].time++;
        }
    }
}

void parse_trace()
{
    FILE *fp = fopen(t, "r");
    if (fp == NULL)
    {
        printf("open file error\n");
        exit(-1);
    }

    char operation;
    unsigned int address;
    int size;
    while (fscanf(fp, " %c %xu,%d\n", &operation, &address, &size) > 0) 
    {
        switch (operation)
        {
        case 'I':
            break;
        case 'L':
        case 'S':
            update(address);
            break;
        case 'M':
            update(address);
            update(address);
            break;
        default:
            break;
        }
        update_stamp();
    }

    fclose(fp);
    for (int i = 0; i < S; ++i)
        free(_cache_[i]);
    free(_cache_);
}

int main(int argc, char *argv[])
{
    h = 0;
    v = 0;
    hit_count = miss_count = eviction_count = 0;
    int opt; // 接收getopt的返回值

    while (-1 != (opt = (getopt(argc, argv, "hvs:E:b:t:"))))
    {
        switch (opt)
        {
        case 'h':
            h = 1;
            printUsage();
            break;
        case 'v':
            v = 1;
            printUsage();
            break;
        case 's':
            s = atoi(optarg);
            break;
        case 'E':
            E = atoi(optarg);
            break;
        case 'b':
            b = atoi(optarg);
            break;
        case 't':
            strcpy(t, optarg);
            break;
        default:
            printUsage();
            break;
        }
    }

    if (s <= 0 || E <= 0 || b <= 0 || t == NULL)
    {
        printf("%s: Missing required command line argument\n", argv[0]);
        printUsage();
        return -1;
    }
    S = 1 << s;

    FILE *fp = fopen(t, "r");
    if (fp == NULL)
    {
        printf("open file error\n");
        return -1;
    }

    init_cache();
    parse_trace();

    printSummary(hit_count, miss_count, eviction_count);
    return 0;
}
