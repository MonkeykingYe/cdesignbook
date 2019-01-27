#include <stdio.h>
#include <stdlib.h>

#define R_INT         (128)
#define F_INT         (100000000)

// getr - �õ� rand() ����ֵ, ��д�뵽�ļ���
static int getr(long long *pnt) {
    static int cnt;

    int r = rand();
    long long t = *pnt + 1;
    
    // ÿ�ε���������һ��
    if(t % F_INT == 0)
        fprintf(stdout, "%d ������������[%d, %lld]\n", F_INT, cnt, t);

    if(t < 0) { // ���ݳ�����
        ++cnt;

        fprintf(stderr, "Now %d T > %lld\n", cnt, t - 1);
        *pnt = 0; // ���¿�ʼһ��
    }
    *pnt = t;
    return r;
}

// main - ��֤ rand ����������
int main(int argc, char* argv[]) {
    int base[R_INT];
    int r, i = -1;
    long long cnt = 0;


    // �Ȳ����������
    while(++i < R_INT)
        base[i] = getr(&cnt);

    // ���￪ʼ�����
    for(;;) {
        r = getr(&cnt);
        if (r != base[0])
            continue;

        // ����ƥ�����
        for(i = 1; i < R_INT; ++i) {
            r = getr(&cnt);
            if(r != base[i]) 
                break;
        }

        // �Ҽ�������
        if(i == R_INT) {
            printf("Now T = %lld\n", cnt);
            break;
        }
    }

    return EXIT_SUCCESS;
}
