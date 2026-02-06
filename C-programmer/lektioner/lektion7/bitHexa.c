#include <stdio.h>

int main(void){
    int z = 0x53;

    printf("HEX   a: %x\n", z);
    printf("DEC   a: %d\n\n", z);

    //Hexadecimal mønsteret er 01010011 i bit
    //https://laml.cs.aau.dk/cgi-bin/video2/get/show-video.cgi?video-id=video-bitvise-operatorer&course-id=impr-cph&lecture-number=7&course-year=2024&video-width=640&lang=dk&video-start-time=00:00&auto-play=0
    // skifter 2 pladser til højre 
    // så det bliver til 00010100
    // 0x14 = 20

    z >>= 2;

    printf("HEX   a: %x\n", z);
    printf("DEC   a: %d\n\n", z);

    int a = 0x53,
        b = 0xf9,
        c;

    c = a << 8 | b;

    printf("c: %x %d\n", c, c);

    int d = 0x53;

    printf("d: %x %d\n", d, d);
    printf("~d: %x %d\n", ~d, ~d);

}