#include<fcntl.h>
int main(int argc, char *argv[])
{
    //if(access(argv[1], R_OK)<0)
     //printf("the file has no read pression\n");
    //else 
     //printf("file can read\n");
    //if(open(argv[1], O_RDONLY)<0)
        //printf("change the file pression failed\n");
    char buffer[2046];
    int numFound = 0;
    int fd = open("/proc/meminfo", O_RDONLY);
    if (fd < 0) {
        printf("Unable to open /proc/meminfo\n");
        return;
    }
    int len = read(fd, buffer, sizeof(buffer)-1);
    close(fd);
    if (len < 0) {
        printf("Empty /proc/meminfo\n");
        return;
    }
    buffer[len] = 0;
    int i = 0;
    printf("/proc/meminfo:len = %d\n",len);
    for(i = 0;i<len;i++) {
      printf("%c",buffer[i]);
    }
    //printf("\n");
    static const char* const tags[] = {
            "MemTotal:",
            "MemFree:",
            "Buffers:",
            "Cached:",
            "Shmem:",
            "Slab:",
            "SwapTotal:",
            "SwapFree:",
            "ZRam:",
            "Mapped:",
            "VmallocUsed:",
            "PageTables:",
            "KernelStack:",
            0
    };
    static const int tagsLen[] = {
            9,
            8,
            8,
            7,
            6,
            5,
            10,
            9,
            5,
            7,
            12,
            11,
            12,
            0
    };
    long mem[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    char* p = buffer;
    printf("sizeof(tagsLen) = %d\n",sizeof(tagsLen)); //sizeof 加数组名是数组在内存占用的字节的长度.
    printf("sizeof(tagsLen[0]) = %d\n",sizeof(tagsLen[0]));//数组中每个元素的的字节长度
    while (*p && numFound < (sizeof(tagsLen) / sizeof(tagsLen[0]))) {
        int i = 0;
        while (tags[i]) {
            if (strncmp(p, tags[i], tagsLen[i]) == 0) {
                p += tagsLen[i];
                while (*p == ' ') p++;
                char* num = p;
                while (*p >= '0' && *p <= '9') p++;
                if (*p != 0) {
                    *p = 0;
                    p++;
                }
                mem[i] = atoll(num);
                printf("tags[%d]: %s = ",i,tags[i]);
                printf("%d KB\n",mem[i]);
                numFound++;
                break;
            }
            i++;
        }
        while (*p && *p != '\n') {
            p++;
        }
        if (*p) p++;
    }
    

    return 0;
}
































